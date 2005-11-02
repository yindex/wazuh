/*   $OSSEC, agentd.c, v0.2, 2005/06/30, Daniel B. Cid$   */

/* Copyright (C) 2004,2005 Daniel B. Cid <dcid@ossec.net>
 * All right reserved.
 *
 * This program is a free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation
 */

/* Part of the OSSEC HIDS
 * Available at http://www.ossec.net/hids/
 */


/* agent daemon.
 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef LOGCLIENT
   #define LOGCLIENT
#endif

#ifndef ARGV0
   #define ARGV0 "ossec-agentd"
#endif

#include "agentd.h"

#include "os_net/os_net.h"

#include "shared.h"
#include "sec.h"


/* manager threads */
void *start_mgr(void *arg);
void *notify_mgr(void *arg);

/* _startit v0.1, 2005/01/30
 * Internal Function. Does all the socket/ queueing
 * manipulation.
 * Maximum allowed input is 1024 bytes.
 */
void _startit(char *dir, int uid, int gid)
{
    int pid;
    int m_queue = 0;
    int _ssize;    
    
    char crypt_msg[OS_MAXSTR +1];
        
    unsigned int port = 0;
    

    /* Giving the default port if none is available */
    if((logr->port == NULL) || (port = atoi(logr->port) <= 0))
    {
        port = DEFAULT_SECURE;
    }

    /* Setting group ID */
    if(Privsep_SetGroup(gid) < 0)
        ErrorExit(SETGID_ERROR,ARGV0,gid);

    /* chrooting */
    if(Privsep_Chroot(dir) < 0)
        ErrorExit(CHROOT_ERROR,ARGV0,dir);

    
    nowChroot();


    if(Privsep_SetUser(uid) < 0)
        ErrorExit(SETUID_ERROR,ARGV0,uid);


    /* Create the queue. In this case we are going to create
     * and read from it
     * Exit if fails.
     */
    if((m_queue = StartMQ(DEFAULTQUEUE,READ)) < 0)
        ErrorExit(QUEUE_ERROR,ARGV0,DEFAULTQUEUE);



    /* Going daemon */
    pid = getpid();
    nowDaemon();
    goDaemon();


    /* Creating PID file */	
    if(CreatePID(ARGV0, getpid()) < 0)
        merror(PID_ERROR,ARGV0);


    /* Reading the private keys  */
    ReadKeys(&keys);

    
    /* Initial random numbers */
    srand( time(0) + getpid() + pid + getppid() );
    rand();


    /* Connecting UDP */
    logr->sock = OS_ConnectUDP(port,logr->rip);
    if(logr->sock < 0)
        ErrorExit(CONNS_ERROR,ARGV0,logr->rip);



    /* Starting manager - thread to receive messages
     * from the server.
     */
    if(CreateThread(start_mgr, (void *)&logr->sock) != 0)
    {
        ErrorExit(THREAD_ERROR, ARGV0);
    }

    /* Starting notification thread.
     * Sends file information to the server
     */
    if(CreateThread(notify_mgr, (void *)&logr->sock) != 0)
    {
        ErrorExit(THREAD_ERROR, ARGV0);
    }

    /* Initializing variables */
    _ssize = 0;
    memset(crypt_msg, '\0', OS_MAXSTR +1);
    
    
    /* daemon loop */	
    for(;;)
    {
        char *msg = NULL;

        /* Receiving from the unix queue */
        if((msg = OS_RecvUnix(m_queue, OS_MAXSTR)) != NULL)
        {
            _ssize = CreateSecMSG(&keys, msg, crypt_msg, 0);
            
            /* Returns NULL if can't create encrypted message */
            if(_ssize == 0)
            {
                merror(SEC_ERROR,ARGV0);
                free(msg);
                continue;
            }

            /* Send _ssize of crypt_msg */
            if(OS_SendUDPbySize(logr->sock, _ssize, crypt_msg) < 0)
                merror(SEND_ERROR,ARGV0);

            /* No need to set them to null */
            free(msg);
        }
    }
}


/* main, v0.1, 2005/01/30
 */
int main(int argc, char **argv)
{
    int c = 0;
    int binds = 0;
    
    char *dir = DEFAULTDIR;
    char *user = USER;
    char *group = GROUPGLOBAL;
    
    int uid = 0;
    int gid = 0;


    while((c = getopt(argc, argv, "dhu:g:D:")) != -1){
        switch(c){
            case 'h':
                help();
                break;
            case 'd':
                nowDebug();
                break;
            case 'u':
                if(!optarg)
                    ErrorExit("%s: -u needs an argument",ARGV0);
                user = optarg;
                break;
            case 'g':
                if(!optarg)
                    ErrorExit("%s: -g needs an argument",ARGV0);
                group = optarg;
                break;		
            case 'D':
                if(!optarg)
                    ErrorExit("%s: -D needs an argument",ARGV0);
                dir = optarg;
                break;
        }
    }

    debug1(STARTED_MSG, ARGV0);

    logr = (agent *)calloc(1, sizeof(agent));
    if(!logr)
    {
        ErrorExit(MEM_ERROR, ARGV0);
    }

    
    /* Reading config */
    if((binds = ClientConf(DEFAULTCPATH)) == 0)
        ErrorExit(CLIENT_ERROR,ARGV0);


    else if(binds < 0)
        ErrorExit(CONFIG_ERROR,ARGV0);


    /* Check if the user/group given are valid */
    uid = Privsep_GetUser(user);
    gid = Privsep_GetGroup(group);
    if((uid < 0)||(gid < 0))
        ErrorExit(USER_ERROR,ARGV0,user,group);



    /* Starting the signal manipulation */
    StartSIG(ARGV0);	


   
    _startit(dir, uid, gid);

    
    return(0);
}

/* EOF */
