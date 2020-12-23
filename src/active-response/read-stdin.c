#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BUFFERSIZE 100

int main(void)
{
    FILE *f = fopen("file.txt", "w");

    char buffer[BUFFERSIZE];

    fgets(buffer, BUFFERSIZE, stdin);

    fprintf(f, "Text: %s\n", buffer);

    return 0;
}
