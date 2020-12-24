# Change Log
All notable changes to this project will be documented in this file.

## [v4.1.0]

### Added

- **Core:**
  - Allow negation of expressions in rules. ([#6258](https://github.com/wazuh/wazuh/pull/6258))
  - Support for PCRE2 regular expressions in rules and decoders. ([#6480](https://github.com/wazuh/wazuh/pull/6480))
  - Added new **ruleset test module**. Allow testing and verification of rules and decoders using Wazuh User Interface. ([#5337](https://github.com/wazuh/wazuh/issues/5337))
  - Added new **upgrade module**. WPK upgrade feature has been moved to this module, which offers support for cluster architecture and simultaneous upgrades. ([#5387](https://github.com/wazuh/wazuh/issues/5387))
  - Added new **task module**. This module stores and manages all the tasks that are executed in the agents or managers. ([#5386](https://github.com/wazuh/wazuh/issues/5386))
  - Let the time interval to detect that an agent got disconnected configurable. Deprecate parameter `DISCON_TIME`. ([#6396](https://github.com/wazuh/wazuh/pull/6396))
  - Added support to macOS in Vulnerability Detector. ([#6532](https://github.com/wazuh/wazuh/pull/6532))
  - Added the capability to perform FIM on values in the Windows Registry. ([#6735](https://github.com/wazuh/wazuh/pull/6735))

- **API:**
  - Added endpoints to query and manage Rootcheck data. ([#6496](https://github.com/wazuh/wazuh/pull/6496))
  - Added new endpoint to check status of tasks. ([#6029](https://github.com/wazuh/wazuh/issues/6029))
  - Added new endpoints to run the logtest tool and delete a logtest session. ([#5984](https://github.com/wazuh/wazuh/pull/5984))
  - Added debug2 mode for API log and improved debug mode. ([#6822](https://github.com/wazuh/wazuh/pull/6822))

- **AWS Module:**
  - Added support for AWS load balancers (Application Load Balancer, Classic Load Balancer and Network Load Balancer). ([#6034](https://github.com/wazuh/wazuh/issues/6034))

- **Framework:**
  - Added new framework modules to use the logtest tool. ([#5870](https://github.com/wazuh/wazuh/pull/5870))
  - Improved `q` parameter on rules, decoders and cdb-lists modules to allow multiple nested fields. ([#6560](https://github.com/wazuh/wazuh/pull/6560))

### Changed

- **Core:**
  - Removed the limit of agents that a manager can support. ([#6097](https://github.com/wazuh/wazuh/issues/6097))
    - Migration of rootcheck results to Wazuh DB to remove the files with the results of each agent. ([#6096](https://github.com/wazuh/wazuh/issues/6096))
    - Designed new mechanism to close RIDS files when agents are disconnected. ([#6112](https://github.com/wazuh/wazuh/issues/6112))
  - Moved CA configuration section to verify WPK signatures from `active-response` section to `agent-upgrade` section. ([#5929](https://github.com/wazuh/wazuh/issues/5929))
  - Changed error message to debug when multiple daemons attempt to remove an agent simultaneously ([#6185](https://github.com/wazuh/wazuh/pull/6185))
  - Changed error message to warning when the agent fails to reach a module. ([#5817](https://github.com/wazuh/wazuh/pull/5817))

- **API:**
  - Changed the `status` parameter behavior in the `DELETE /agents` endpoint to enhance security. ([#6829](https://github.com/wazuh/wazuh/pull/6829))
  - Changed upgrade endpoints to accept a list of agents, maximum 100 agents per request. ([#5336](https://github.com/wazuh/wazuh/issues/5536))
  - Improved input validation regexes for `names` and `array_names`. ([#7015](https://github.com/wazuh/wazuh/issues/7015))

- **Framework:**
  - Refactored framework to work with new upgrade module. ([#5537](https://github.com/wazuh/wazuh/issues/5537))
  - Refactored agent upgrade CLI to work with new ugprade module. It distributes petitions in a clustered environment. ([#5675](https://github.com/wazuh/wazuh/issues/5675))
  - Changed rule and decoder details structure to support PCRE2. ([#6318](https://github.com/wazuh/wazuh/issues/6318))
  - Changed access to agent's status. ([#6326](https://github.com/wazuh/wazuh/issues/6326))
  - Improved AWS Config integration to avoid performance issues by removing alert fields with variables such as Instance ID in its name. ([#6537](https://github.com/wazuh/wazuh/issues/6537))

### Fixed

- Fixed a `cluster_control` bug that caused an error message when running `wazuh-clusterd` in foreground. ([#6724](https://github.com/wazuh/wazuh/pull/6724))

- **API:**
  - Fixed an error with `/groups/{group_id}/config` endpoints (GET and PUT) when using complex `localfile` configurations. ([#6276](https://github.com/wazuh/wazuh/pull/6383))
- **Core:**
  - Fixed error in Analysisd when getting the ossec group ID. ([#6688](https://github.com/wazuh/wazuh/pull/6688))
  - Prevented FIM from reporting configuration error when setting patterns that match no files. ([#6187](https://github.com/wazuh/wazuh/pull/6187))
  - Fixed the array parsing when building JSON alerts. ([#6687](https://github.com/wazuh/wazuh/pull/6687))
  - Added Firefox ESR to the CPE helper to distinguish it from Firefox when looking for vulnerabilities. ([#6610](https://github.com/wazuh/wazuh/pull/6610))
  - Fixed the evaluation of packages from external sources with the official vendor feeds in Vulnerability Detector. ([#6611](https://github.com/wazuh/wazuh/pull/6611))
  - Fixed the handling of duplicated tags in the Vulnerability Detector configuration. ([#6683](https://github.com/wazuh/wazuh/pull/6683))
  - Fixed the validation of hotfixes gathered by Syscollector. ([#6706](https://github.com/wazuh/wazuh/pull/6706))
  - Fixed the reading of the Linux OS version when `/etc/os-release` doesn't provide it. ([#6674](https://github.com/wazuh/wazuh/pull/6674))
  - Fixed a false positive when comparing the minor target of CentOS packages in Vulnerability Detector. ([#6709](https://github.com/wazuh/wazuh/pull/6709))
  - Fixed a zombie process leak in Modulesd when using commands without a timeout. ([#6719](https://github.com/wazuh/wazuh/pull/6719))
  - Fixed a race condition in Remoted that might create agent-group files with wrong permissions. ([#6833](https://github.com/wazuh/wazuh/pull/6833))
  - Fixed a warning log in Wazuh DB when upgrading the global database. ([#6697](https://github.com/wazuh/wazuh/pull/6697))
  - Fixed a bug in FIM on Windows that caused false positive due to changes in the host timezone or the daylight saving time when monitoring files in a FAT32 filesystem. ([#6801](https://github.com/wazuh/wazuh/pull/6801))


## [v4.0.3] - 2020-11-30

### Fixed

- **API:**
  - Fixed a problem with certain API calls exceeding timeout in highly loaded cluster environments. ([#6753](https://github.com/wazuh/wazuh/pull/6753))


## [v4.0.2] - 2020-11-24

### Added

- **Core:**
  - Added macOS Big Sur version detection in the agent. ([#6603](https://github.com/wazuh/wazuh/pull/6603))

### Changed

- **API:**
  - `GET /agents/summary/os`, `GET /agents/summary/status` and `GET /overview/agents` will no longer consider `000` as an agent. ([#6574](https://github.com/wazuh/wazuh/pull/6574))
  - Increased to 64 the maximum number of characters that can be used in security users, roles, rules, and policies names. ([#6657](https://github.com/wazuh/wazuh/issues/6657))

### Fixed

- **API:**
  - Fixed an error with `POST /security/roles/{role_id}/rules` when removing role-rule relationships with admin resources. ([#6594](https://github.com/wazuh/wazuh/issues/6594))
  - Fixed a timeout error with `GET /manager/configuration/validation` when using it in a slow environment. ([#6530](https://github.com/wazuh/wazuh/issues/6530))
- **Framework:**
  - Fixed an error with some distributed requests when the cluster configuration is empty. ([#6612](https://github.com/wazuh/wazuh/pull/6612))
  - Fixed special characters in default policies. ([#6575](https://github.com/wazuh/wazuh/pull/6575))
- **Core:**
  - Fixed a bug in Remoted that limited the maximum agent number to `MAX_AGENTS-3` instead of `MAX_AGENTS-2`. ([#4560](https://github.com/wazuh/wazuh/pull/4560))
  - Fixed an error in the network library when handling disconnected sockets. ([#6444](https://github.com/wazuh/wazuh/pull/6444))
  - Fixed an error in FIM when handling temporary files and registry keys exceeding the path size limit. ([#6538](https://github.com/wazuh/wazuh/pull/6538))
  - Fixed a bug in FIM that stopped monitoring folders pointed by a symbolic link. ([#6613](https://github.com/wazuh/wazuh/pull/6613))
  - Fixed a race condition in FIM that could cause Syscheckd to stop unexpectedly. ([#6696](https://github.com/wazuh/wazuh/pull/6696))


## [v4.0.1] - 2020-11-11

### Changed

- **Framework:**
  - Updated Python's cryptography library to version 3.2.1 ([#6442](https://github.com/wazuh/wazuh/issues/6442))

### Fixed

- **API:**
  - Added missing agent:group resource to RBAC's catalog. ([6427](https://github.com/wazuh/wazuh/issues/6427))
  - Changed `limit` parameter behaviour in `GET sca/{agent_id}/checks/{policy_id}` endpoint and fixed some loss of information when paginating `wdb`. ([#6464](https://github.com/wazuh/wazuh/pull/6464))
  - Fixed an error with `GET /security/users/me` when logged in with `run_as`. ([#6506](https://github.com/wazuh/wazuh/pull/6506))
- **Framework:**
  - Fixed zip files compression and handling in cluster integrity synchronization. ([#6367](https://github.com/wazuh/wazuh/issues/6367))
- **Core**
  - Fixed version matching when assigning feed in Vulnerability Detector. ([#6505](https://github.com/wazuh/wazuh/pull/6505))
  - Prevent unprivileged users from accessing the Wazuh Agent folder in Windows. ([#3593](https://github.com/wazuh/wazuh/pull/3593))
  - Fix a bug that may lead the agent to crash when reading an invalid Logcollector configuration. ([#6463](https://github.com/wazuh/wazuh/pull/6463))


## [v4.0.0] - 2020-10-23

### Added

- Added **enrollment capability**. Agents are now able to request a key from the manager if current key is missing or wrong. ([#5609](https://github.com/wazuh/wazuh/pull/5609))
- Migrated the agent-info data to Wazuh DB. ([#5541](https://github.com/wazuh/wazuh/pull/5541))
- **API:**
  - Embedded Wazuh API with Wazuh Manager, there is no need to install Wazuh API. ([9860823](https://github.com/wazuh/wazuh/commit/9860823d568f5e6d93550d9b139507c04d2c2eb9))
  - Migrated Wazuh API server from nodejs to python. ([#2640](https://github.com/wazuh/wazuh/pull/2640))
  - Added asynchronous aiohttp server for the Wazuh API. ([#4474](https://github.com/wazuh/wazuh/issues/4474))
  - New Wazuh API is approximately 5 times faster on average. ([#5834](https://github.com/wazuh/wazuh/issues/5834))
  - Added OpenAPI based Wazuh API specification. ([#2413](https://github.com/wazuh/wazuh/issues/2413))
  - Improved Wazuh API reference documentation based on OpenAPI spec using redoc. ([#4967](https://github.com/wazuh/wazuh/issues/4967))
  - Added new yaml Wazuh API configuration file. ([#2570](https://github.com/wazuh/wazuh/issues/2570))
  - Added new endpoints to manage API configuration and deprecated configure_api.sh. ([#2570](https://github.com/wazuh/wazuh/issues/4822))
  - Added RBAC support to Wazuh API. ([#3287](https://github.com/wazuh/wazuh/issues/3287))
  - Added new endpoints for Wazuh API security management. ([#3410](https://github.com/wazuh/wazuh/issues/3410))
  - Added SQLAlchemy ORM based database for RBAC. ([#3375](https://github.com/wazuh/wazuh/issues/3375))
  - Added new JWT authentication method. ([7080ac3](https://github.com/wazuh/wazuh/commit/7080ac352774bb0feaf07cab76df58ea5503ff4b))
  - Wazuh API up and running by default in all nodes for a clustered environment.
  - Added new and improved error handling. ([#2843](https://github.com/wazuh/wazuh/issues/2843) ([#5345](https://github.com/wazuh/wazuh/issues/5345))
  - Added tavern and docker based Wazuh API integration tests. ([#3612](https://github.com/wazuh/wazuh/issues/3612))
  - Added new and unified Wazuh API responses structure. ([3421015](https://github.com/wazuh/wazuh/commit/34210154016f0a63211a81707744dce0ec0a54f9))
  - Added new endpoints for Wazuh API users management. ([#3280](https://github.com/wazuh/wazuh/issues/3280))
  - Added new endpoint to restart agents which belong to a node. ([#5381](https://github.com/wazuh/wazuh/issues/5381))
  - Added and improved q filter in several endpoints. ([#5431](https://github.com/wazuh/wazuh/pull/5431))
  - Tested and improved Wazuh API security. ([#5318](https://github.com/wazuh/wazuh/issues/5318))
    - Added DDOS blocking system. ([#5318](https://github.com/wazuh/wazuh/issues/5318#issuecomment-654303933))
    - Added brute force attack blocking system. ([#5318](https://github.com/wazuh/wazuh/issues/5318#issuecomment-652892858))
    - Added content-type validation. ([#5318](https://github.com/wazuh/wazuh/issues/5318#issuecomment-654807980))
- **Vulnerability Detector:**
  - Redhat vulnerabilities are now fetched from OVAL benchmarks. ([#5352](https://github.com/wazuh/wazuh/pull/5352))
  - Debian vulnerable packages are now fetched from the Security Tracker. ([#5304](https://github.com/wazuh/wazuh/pull/5304))
  - The Debian Security Tracker feed can be loaded from a custom location. ([#5449](https://github.com/wazuh/wazuh/pull/5449))
  - The package vendor is used to discard vulnerabilities. ([#5330](https://github.com/wazuh/wazuh/pull/5330))
  - Allow compressed feeds for offline updates. ([#5745](https://github.com/wazuh/wazuh/pull/5745))
  - The manager now updates the MSU feed automatically. ([#5678](https://github.com/wazuh/wazuh/pull/5678))
  - CVEs with no affected version defined in all the feeds are now reported. ([#5284](https://github.com/wazuh/wazuh/pull/5284))
  - CVEs vulnerable for the vendor and missing in the NVD are now reported. ([#5305](https://github.com/wazuh/wazuh/pull/5305))
- **File Integrity Monitoring:**
  - Added options to limit disk usage using report changes option in the FIM module. ([#5157](https://github.com/wazuh/wazuh/pull/5157))
- Added and updated framework unit tests to increase coverage. ([#3287](https://github.com/wazuh/wazuh/issues/3287))
- Added improved support for monitoring paths from environment variables. ([#4961](https://github.com/wazuh/wazuh/pull/4961))
- Added `base64_log` format to the log builder for Logcollector. ([#5273](https://github.com/wazuh/wazuh/pull/5273))

### Changed

- Changed the default manager-agent connection protocol to **TCP**. ([#5696](https://github.com/wazuh/wazuh/pull/5696))
- Disable perpetual connection attempts to modules. ([#5622](https://github.com/wazuh/wazuh/pull/5622))
- Unified the behaviour of Wazuh daemons when reconnecting with unix sockets. ([#4510](https://github.com/wazuh/wazuh/pull/4510))
- Changed multiple Wazuh API endpoints. ([#2640](https://github.com/wazuh/wazuh/pull/2640)) ([#2413](https://github.com/wazuh/wazuh-documentation/issues/2413))
- Refactored framework module in SDK and core. ([#5263](https://github.com/wazuh/wazuh/issues/5263))
- Refactored FIM Windows events handling. ([#5144](https://github.com/wazuh/wazuh/pull/5144))
- Changed framework to access global.db using wazuh-db. ([#6095](https://github.com/wazuh/wazuh/pull/6095))
- Changed agent-info synchronization task in Wazuh cluster. ([#5585](https://github.com/wazuh/wazuh/issues/5585))
- Use the proper algorithm name for SHA-256 inside Prelude output. Thanks to François Poirotte (@fpoirotte). ([#5004](https://github.com/wazuh/wazuh/pull/5004))
- Elastic Stack configuration files have been adapted to Wazuh v4.x. ([#5796](https://github.com/wazuh/wazuh/pull/5796))
- Explicitly use Bash for the Pagerduty integration. Thanks to Chris Kruger (@montdidier). ([#4641](https://github.com/wazuh/wazuh/pull/4641))

### Fixed

- **Vulnerability Detector:**
  - Vulnerabilities of Windows Server 2019 which not affects to Windows 10 were not being reported. ([#5524](https://github.com/wazuh/wazuh/pull/5524))
  - Vulnerabilities patched by a Microsoft update with no supersedence were not being reported. ([#5524](https://github.com/wazuh/wazuh/pull/5524))
  - Vulnerabilities patched by more than one Microsoft update were not being evaluated agains all the patches. ([#5717](https://github.com/wazuh/wazuh/pull/5717))
  - Duplicated alerts in Windows 10. ([#5600](https://github.com/wazuh/wazuh/pull/5600))
  - Syscollector now discards hotfixes that are not fully installed. ([#5792](https://github.com/wazuh/wazuh/pull/5792))
  - Syscollector now collects hotfixes that were not being parsed. ([#5792](https://github.com/wazuh/wazuh/pull/5792))
  - Update Windows databases when `run_on_start` is disabled. ([#5335](https://github.com/wazuh/wazuh/pull/5335))
  - Fixed the NVD version comparator to remove undesired suffixes. ([#5362](https://github.com/wazuh/wazuh/pull/5362))
  - Fixed not escaped single quote in vuln detector SQL query. ([#5570](https://github.com/wazuh/wazuh/pull/5570))
  - Unified alerts title. ([#5826](https://github.com/wazuh/wazuh/pull/5826))
  - Fixed potential error in the GZlib when uncompressing NVD feeds. ([#5989](https://github.com/wazuh/wazuh/pull/5989))
- **File Integrity Monitoring:**
  - Fixed an error with last scan time in Syscheck API endpoints. ([a9acd3a](https://github.com/wazuh/wazuh/commit/a9acd3a216a7e0075a8efa5a91b2587659782fd8))
  - Fixed support for monitoring directories which contain commas. ([#4961](https://github.com/wazuh/wazuh/pull/4961))
  - Fixed a bug where configuring a directory to be monitored as real-time and whodata resulted in real-time prevailing. ([#4961](https://github.com/wazuh/wazuh/pull/4961))
  - Fixed using an incorrect mutex while deleting inotify watches. ([#5126](https://github.com/wazuh/wazuh/pull/5126))
  - Fixed a bug which could cause multiple FIM threads to request the same temporary file. ([#5213](https://github.com/wazuh/wazuh/issues/5213))
  - Fixed a bug where deleting a file permanently in Windows would not trigger an alert. ([#5144](https://github.com/wazuh/wazuh/pull/5144))
  - Fixed a typo in the file monitoring options log entry. ([#5591](https://github.com/wazuh/wazuh/pull/5591))
  - Fixed an error where monitoring a drive in Windows under scheduled or realtime mode would generate alerts from the recycle bin. ([#4771](https://github.com/wazuh/wazuh/pull/4771))
  - When monitoring a drive in Windows in the format `U:`, it will monitor `U:\` instead of the agent's working directory. ([#5259](https://github.com/wazuh/wazuh/pull/5259))
  - Fixed a bug where monitoring a drive in Windows with `recursion_level` set to 0 would trigger alerts from files inside its subdirectories. ([#5235](https://github.com/wazuh/wazuh/pull/5235))
- Fixed an Azure wodle dependency error. The package azure-storage-blob>12.0.0 does not include a component used. ([#6109](https://github.com/wazuh/wazuh/pull/6109))
- Fixed bugs reported by GCC 10.1.0. ([#5119](https://github.com/wazuh/wazuh/pull/5119))
- Fixed compilation errors with `USE_PRELUDE` enabled. Thanks to François Poirotte (@fpoirotte). ([#5003](https://github.com/wazuh/wazuh/pull/5003))
- Fixed default gateway data gathering in Syscollector on Linux 2.6. ([#5548](https://github.com/wazuh/wazuh/pull/5548))
- Fixed the Eventchannel collector to keep working when the Eventlog service is restarted. ([#5496](https://github.com/wazuh/wazuh/pull/5496))
- Fixed the OpenSCAP script to work over Python 3. ([#5317](https://github.com/wazuh/wazuh/pull/5317))
- Fixed the launcher.sh generation in macOS source installation. ([#5922](https://github.com/wazuh/wazuh/pull/5922))

### Removed

- Removed Wazuh API cache endpoints. ([#3042](https://github.com/wazuh/wazuh/pull/3042))
- Removed Wazuh API rootcheck endpoints. ([#5246](https://github.com/wazuh/wazuh/issues/5246))
- Deprecated Debian Jessie and Wheezy for Vulnerability Detector (EOL). ([#5660](https://github.com/wazuh/wazuh/pull/5660))
- Removed references to `manage_agents` in the installation process. ([#5840](https://github.com/wazuh/wazuh/pull/5840))
- Removed compatibility with deprecated configuration at Vulnerability Detector. ([#5879](https://github.com/wazuh/wazuh/pull/5879))

## [v3.13.2] - 2020-09-21

### Fixed

- Updated the default NVD feed URL from 1.0 to 1.1 in Vulnerability Detector. ([#6056](https://github.com/wazuh/wazuh/pull/6056))


## [v3.13.1] - 2020-07-14

### Added

- Added two new settings <max_retries> and <retry_interval> to adjust the agent failover interval. ([#5433](https://github.com/wazuh/wazuh/pull/5433))

### Fixed

- Fixed a crash in Modulesd caused by Vulnerability Detector when skipping a kernel package if the agent has OS info disabled. ([#5467](https://github.com/wazuh/wazuh/pull/5467))


## [v3.13.0] - 2020-06-29

### Added

- Vulnerability Detector improvements. ([#5097](https://github.com/wazuh/wazuh/pull/5097))
  - Include the NVD as feed for Linux agents in Vulnerability Detector.
  - Improve the Vulnerability Detector engine to correlate alerts between different feeds.
  - Add Vulnerability Detector module unit testing for Unix source code.
  - A timeout has been added to the updates of the vulnerability detector feeds to prevent them from getting hung up. ([#5153](https://github.com/wazuh/wazuh/pull/5153))
- New option for the JSON decoder to choose the treatment of Array structures. ([#4836](https://github.com/wazuh/wazuh/pull/4836))
- Added mode value (real-time, Who-data, or scheduled) as a dynamic field in FIM alerts. ([#5051](https://github.com/wazuh/wazuh/pull/5051))
- Set a configurable maximum limit of files to be monitored by FIM. ([#4717](https://github.com/wazuh/wazuh/pull/4717))
- New integration for pull logs from Google Cloud Pub/Sub. ([#4078](https://github.com/wazuh/wazuh/pull/4078))
- Added support for MITRE ATT&CK knowledge base. ([#3746](https://github.com/wazuh/wazuh/pull/3746))
- Microsoft Software Update Catalog used by vulnerability detector added as a dependency. ([#5101](https://github.com/wazuh/wazuh/pull/5101))
- Added support for `aarch64` and `armhf` architectures. ([#5030](https://github.com/wazuh/wazuh/pull/5030))

### Changed

- Internal variable rt_delay configuration changes to 5 milliseconds. ([#4760](https://github.com/wazuh/wazuh/pull/4760))
- Who-data includes new fields: process CWD, parent process id, and CWD of parent process. ([#4782](https://github.com/wazuh/wazuh/pull/4782))
- FIM opens files with shared deletion permission. ([#5018](https://github.com/wazuh/wazuh/pull/5018))
- Extended the statics fields comparison in the ruleset options. ([#4416](https://github.com/wazuh/wazuh/pull/4416))
- The state field was removed from vulnerability alerts. ([#5211](https://github.com/wazuh/wazuh/pull/5211))
- The NVD is now the primary feed for the vulnerability detector in Linux. ([#5097](https://github.com/wazuh/wazuh/pull/5097))
- Removed OpenSCAP policies installation and configuration block. ([#5061](https://github.com/wazuh/wazuh/pull/5061))
- Changed the internal configuration of Analysisd to be able to register by default a number of agents higher than 65536. ([#4332](https://github.com/wazuh/wazuh/pull/4332))
- Changed `same/different_systemname` for `same/different_system_name` in Analysisd static filters. ([#5131](https://github.com/wazuh/wazuh/pull/5131))
- Updated the internal Python interpreter from v3.7.2 to v3.8.2. ([#5030](https://github.com/wazuh/wazuh/pull/5030))

### Fixed

- Fixed a bug that, in some cases, kept the memory reserved when deleting monitored directories in FIM. ([#5115](https://github.com/wazuh/wazuh/issues/5115))
- Freed Inotify watches moving directories in the real-time mode of FIM. ([#4794](https://github.com/wazuh/wazuh/pull/4794))
- Fixed an error that caused deletion alerts with a wrong path in Who-data mode. ([#4831](https://github.com/wazuh/wazuh/pull/4831))
- Fixed generating alerts in Who-data mode when moving directories to the folder being monitored in Windows. ([#4762](https://github.com/wazuh/wazuh/pull/4762))
- Avoid truncating the full log field of the alert when the path is too long. ([#4792](https://github.com/wazuh/wazuh/pull/4792))
- Fixed the change of monitoring from Who-data to real-time when there is a failure to set policies in Windows. ([#4753](https://github.com/wazuh/wazuh/pull/4753))
- Fixed an error that prevents restarting Windows agents from the manager. ([#5212](https://github.com/wazuh/wazuh/pull/5212))
- Fixed an error that impedes the use of the tag URL by configuring the NVD in a vulnerability detector module. ([#5165](https://github.com/wazuh/wazuh/pull/5165))
- Fixed TOCTOU condition in Clusterd when merging agent-info files. ([#5159](https://github.com/wazuh/wazuh/pull/5159))
- Fixed race condition in Analysisd when handling accumulated events. ([#5091](https://github.com/wazuh/wazuh/pull/5091))
- Avoided to count links when generating alerts for ignored directories in Rootcheck. Thanks to Artur Molchanov (@Hexta). ([#4603](https://github.com/wazuh/wazuh/pull/4603))
- Fixed typo in the path used for logging when disabling an account. Thanks to Fontaine Pierre (@PierreFontaine). ([#4839](https://github.com/wazuh/wazuh/pull/4839))
- Fixed an error when receiving different Syslog events in the same TCP packet. ([#5087](https://github.com/wazuh/wazuh/pull/5087))
- Fixed a bug in Vulnerability Detector on Modulesd when comparing Windows software versions. ([#5168](https://github.com/wazuh/wazuh/pull/5168))
- Fixed a bug that caused an agent's disconnection time not to be displayed correctly. ([#5142](https://github.com/wazuh/wazuh/pull/5142))
- Optimized the function to obtain the default gateway. Thanks to @WojRep
- Fixed host verification when signing a certificate for the manager. ([#4963](https://github.com/wazuh/wazuh/pull/4963))
- Fixed possible duplicated ID on 'client.keys' adding new agent through the API with a specific ID. ([#4982](https://github.com/wazuh/wazuh/pull/4982))
- Avoid duplicate descriptors using wildcards in 'localfile' configuration. ([#4977](https://github.com/wazuh/wazuh/pull/4977))
- Added guarantee that all processes are killed when service stops. ([#4975](https://github.com/wazuh/wazuh/pull/4975))
- Fixed mismatch in integration scripts when the debug flag is set to active. ([#4800](https://github.com/wazuh/wazuh/pull/4800))


## [v3.12.3] - 2020-04-30

### Changed

- Disable WAL in databases handled by Wazuh DB to save disk space. ([#4949](https://github.com/wazuh/wazuh/pull/4949))

### Fixed

- Fixed a bug in Remoted that could prevent agents from connecting in UDP mode. ([#4897](https://github.com/wazuh/wazuh/pull/4897))
- Fixed a bug in the shared library that caused daemons to not find the ossec group. ([#4873](https://github.com/wazuh/wazuh/pull/4873))
- Prevent Syscollector from falling into an infinite loop when failed to collect the Windows hotfixes. ([#4878](https://github.com/wazuh/wazuh/pull/4878))
- Fixed a memory leak in the system scan by Rootcheck on Windows. ([#4948](https://github.com/wazuh/wazuh/pull/4948))
- Fixed a bug in Logcollector that caused the out_format option not to apply for the agent target. ([#4942](https://github.com/wazuh/wazuh/pull/4942))
- Fixed a bug that caused FIM to not handle large inode numbers correctly. ([#4914](https://github.com/wazuh/wazuh/pull/4914))
- Fixed a bug that made ossec-dbd crash due to a bad mutex initialization. ([#4552](https://github.com/wazuh/wazuh/pull/4552))


## [v3.12.2] - 2020-04-09

### Fixed

- Fixed a bug in Vulnerability Detector that made wazuh-modulesd crash when parsing the version of a package from a RHEL feed. ([#4885](https://github.com/wazuh/wazuh/pull/4885))


## [v3.12.1] - 2020-04-08

### Changed

- Updated MSU catalog on 31/03/2020. ([#4819](https://github.com/wazuh/wazuh/pull/4819))

### Fixed

- Fixed compatibility with the Vulnerability Detector feeds for Ubuntu from Canonical, that are available in a compressed format. ([#4834](https://github.com/wazuh/wazuh/pull/4834))
- Added missing field ‘database’ to the FIM on-demand configuration report. ([#4785](https://github.com/wazuh/wazuh/pull/4785))
- Fixed a bug in Logcollector that made it forward a log to an external socket infinite times. ([#4802](https://github.com/wazuh/wazuh/pull/4802))
- Fixed a buffer overflow when receiving large messages from Syslog over TCP connections. ([#4778](https://github.com/wazuh/wazuh/pull/4778))
- Fixed a malfunction in the Integrator module when analyzing events without a certain field. ([#4851](https://github.com/wazuh/wazuh/pull/4851))
- Fix XML validation with paths ending in `\`. ([#4783](https://github.com/wazuh/wazuh/pull/4783))

### Removed

- Removed support for Ubuntu 12.04 (Precise) in Vulneratiliby Detector as its feed is no longer available.


## [v3.12.0] - 2020-03-24

### Added

- Add synchronization capabilities for FIM. ([#3319](https://github.com/wazuh/wazuh/issues/3319))
- Add SQL database for the FIM module. Its storage can be switched between disk and memory. ([#3319](https://github.com/wazuh/wazuh/issues/3319))
- Add support for monitoring AWS S3 buckets in GovCloud regions. ([#3953](https://github.com/wazuh/wazuh/issues/3953))
- Add support for monitoring Cisco Umbrella S3 buckets. ([#3890](https://github.com/wazuh/wazuh/issues/3890))
- Add automatic reconnection with the Eventchannel service when it is restarted. ([#3836](https://github.com/wazuh/wazuh/pull/3836))
- Add a status validation when starting Wazuh. ([#4237](https://github.com/wazuh/wazuh/pull/4237))
- Add FIM module unit testing for Unix source code. ([#4688](https://github.com/wazuh/wazuh/pull/4688))
- Add multi-target support for unit testing. ([#4564](https://github.com/wazuh/wazuh/pull/4564))
- Add FIM module unit testing for Windows source code. ([#4633](https://github.com/wazuh/wazuh/pull/4633))

### Changed

- Move the FIM logic engine to the agent. ([#3319](https://github.com/wazuh/wazuh/issues/3319))
- Make Logcollector continuously attempt to reconnect with the agent daemon. ([#4435](https://github.com/wazuh/wazuh/pull/4435))
- Make Windows agents to send the keep-alive independently. ([#4077](https://github.com/wazuh/wazuh/pull/4077))
- Do not enforce source IP checking by default in the registration process. ([#4083](https://github.com/wazuh/wazuh/pull/4083))
- Updated API manager/configuration endpoint to also return the new synchronization and whodata syscheck fields ([#4241](https://github.com/wazuh/wazuh/pull/4241))
- Disabled the chroot jail in Agentd on UNIX.

### Fixed

- Avoid reopening the current socket when Logcollector fails to send a event. ([#4696](https://github.com/wazuh/wazuh/pull/4696))
- Prevent Logcollector from starving when has to reload files. ([#4730](https://github.com/wazuh/wazuh/pull/4730))
- Fix a small memory leak in clusterd. ([#4465](https://github.com/wazuh/wazuh/pull/4465))
- Fix a crash in the fluent forwarder when SSL is not enabled. ([#4675](https://github.com/wazuh/wazuh/pull/4675))
- Replace non-reentrant functions to avoid race condition hazards. ([#4081](https://github.com/wazuh/wazuh/pull/4081))
- Fixed the registration of more than one agent as `any` when forcing to use the source IP. ([#2533](https://github.com/wazuh/wazuh/pull/2533))
- Fix Windows upgrades in custom directories. ([#2534](https://github.com/wazuh/wazuh/pull/2534))
- Fix the format of the alert payload passed to the Slack integration. ([#3978](https://github.com/wazuh/wazuh/pull/3978))


## [v3.11.4] - 2020-02-25

### Changed

- Remove chroot in Agentd to allow it resolve DNS at any time. ([#4652](https://github.com/wazuh/wazuh/issues/4652))


## [v3.11.3] - 2020-01-28

### Fixed

- Fixed a bug in the Windows agent that made Rootcheck report false positives about file size mismatch. ([#4493](https://github.com/wazuh/wazuh/pull/4493))


## [v3.11.2] - 2020-01-22

### Changed

- Optimized memory usage in Vulnerability Detector when fetching the NVD feed. ([#4427](https://github.com/wazuh/wazuh/pull/4427))

### Fixed

- Rootcheck scan produced a 100% CPU peak in Syscheckd because it applied `<readall>` option even when disabled. ([#4415](https://github.com/wazuh/wazuh/pull/4415))
- Fixed a handler leak in Rootcheck and SCA on Windows agents. ([#4456](https://github.com/wazuh/wazuh/pull/4456))
- Prevent Remoted from exiting when a client closes a connection prematurely. ([#4390](https://github.com/wazuh/wazuh/pull/4390))
- Fixed crash in Slack integration when handling an alert with no description. ([#4426](https://github.com/wazuh/wazuh/pull/4426))
- Fixed Makefile to allow running scan-build for Windows agents. ([#4314](https://github.com/wazuh/wazuh/pull/4314))
- Fixed a memory leak in Clusterd. ([#4448](https://github.com/wazuh/wazuh/pull/4448))
- Disable TCP keepalive options at os_net library to allow building Wazuh on OpenBSD. ([#4462](https://github.com/wazuh/wazuh/pull/4462))


## [v3.11.1] - 2020-01-03

### Fixed

- The Windows Eventchannel log decoder in Analysisd maxed out CPU usage due to an infinite loop. ([#4412](https://github.com/wazuh/wazuh/pull/4412))


## [v3.11.0] - 2019-12-23

### Added

- Add support to Windows agents for vulnerability detector. ([#2787](https://github.com/wazuh/wazuh/pull/2787))
- Add support to Debian 10 Buster for vulnerability detector (by @aderumier). ([#4151](https://github.com/wazuh/wazuh/pull/4151))
- Make the Wazuh service to start after the network systemd unit (by @VAdamec). ([#1106](https://github.com/wazuh/wazuh/pull/1106))
- Add process inventory support for Mac OS X agents. ([#3322](https://github.com/wazuh/wazuh/pull/3322))
- Add port inventory support for MAC OS X agents. ([#3349](https://github.com/wazuh/wazuh/pull/3349))
- Make Analysisd compile the CDB list upon start. ([#3488](https://github.com/wazuh/wazuh/pull/3488))
- New rules option `global_frequency` to make frequency rules independent from the event source. ([#3931](https://github.com/wazuh/wazuh/pull/3931))
- Add a validation for avoiding agents to keep trying to connect to an invalid address indefinitely. ([#3951](https://github.com/wazuh/wazuh/pull/3951))
- Add the condition field of SCA checks to the agent databases. ([#3631](https://github.com/wazuh/wazuh/pull/3631))
- Display a warning message when registering to an unverified manager. ([#4207](https://github.com/wazuh/wazuh/pull/4207))
- Allow JSON escaping for logs on Logcollector's output format. ([#4273](https://github.com/wazuh/wazuh/pull/4273))
- Add TCP keepalive support for Fluent Forwarder. ([#4274](https://github.com/wazuh/wazuh/pull/4274))
- Add the host's primary IP to Logcollector's output format. ([#4380](https://github.com/wazuh/wazuh/pull/4380))

### Changed

- Now EventChannel alerts include the full message with the translation of coded fields. ([#3320](https://github.com/wazuh/wazuh/pull/3320))
- Changed `-G` agent-auth description in help message. ([#3856](https://github.com/wazuh/wazuh/pull/3856))
- Unified the Makefile flags allowed values. ([#4034](https://github.com/wazuh/wazuh/pull/4034))
- Let Logcollector queue file rotation and keepalive messages. ([#4222](https://github.com/wazuh/wazuh/pull/4222))
- Changed default paths for the OSQuery module in Windows agents. ([#4148](https://github.com/wazuh/wazuh/pull/4148))
- Fluent Forward now packs the content towards Fluentd into an object. ([#4334](https://github.com/wazuh/wazuh/pull/4334))

### Fixed

- Fix frequency rules to be increased for the same agent by default. ([#3931](https://github.com/wazuh/wazuh/pull/3931))
- Fix `protocol`, `system_name`, `data` and `extra_data` static fields detection. ([#3591](https://github.com/wazuh/wazuh/pull/3591))
- Fix overwriting agents by `Authd` when `force` option is less than 0. ([#3527](https://github.com/wazuh/wazuh/pull/3527))
- Fix Syscheck `nodiff` option for substring paths. ([#3015](https://github.com/wazuh/wazuh/pull/3015))
- Fix Logcollector wildcards to not detect directories as log files. ([#3788](https://github.com/wazuh/wazuh/pull/3788))
- Make Slack integration work with agentless alerts (by @dmitryax). ([#3971](https://github.com/wazuh/wazuh/pull/3971))
- Fix bugs reported by Clang analyzer. ([#3887](https://github.com/wazuh/wazuh/pull/3887))
- Fix compilation errors on OpenBSD platform. ([#3105](https://github.com/wazuh/wazuh/pull/3105))
- Fix on-demand configuration labels section to obtain labels attributes. ([#3490](https://github.com/wazuh/wazuh/pull/3490))
- Fixed race condition between `wazuh-clusterd` and `wazuh-modulesd` showing a 'No such file or directory' in `cluster.log` when synchronizing agent-info files in a cluster environment ([#4007](https://github.com/wazuh/wazuh/issues/4007))
- Fixed 'ConnectionError object has no attribute code' error when package repository is not available ([#3441](https://github.com/wazuh/wazuh/issues/3441))
- Fix the blocking of files monitored by Who-data in Windows agents. ([#3872](https://github.com/wazuh/wazuh/pull/3872))
- Fix the processing of EventChannel logs with unexpected characters. ([#3320](https://github.com/wazuh/wazuh/pull/3320))
- Active response Kaspersky script now logs the action request in _active-responses.log_ ([#2748](https://github.com/wazuh/wazuh/pull/2748))
- Fix service's installation path for CentOS 8. ([#4060](https://github.com/wazuh/wazuh/pull/4060))
- Add macOS Catalina to the list of detected versions. ([#4061](https://github.com/wazuh/wazuh/pull/4061))
- Prevent FIM from producing false negatives due to wrong checksum comparison. ([#4066](https://github.com/wazuh/wazuh/pull/4066))
- Fix `previous_output` count for alerts when matching by group. ([#4097](https://github.com/wazuh/wazuh/pull/4097))
- Fix event iteration when evaluating contextual rules. ([#4106](https://github.com/wazuh/wazuh/pull/4106))
- Fix the use of `prefilter_cmd` remotely by a new local option `allow_remote_prefilter_cmd`. ([#4178](https://github.com/wazuh/wazuh/pull/4178) & [4194](https://github.com/wazuh/wazuh/pull/4194))
- Fix restarting agents by group using the API when some of them are in a worker node. ([#4226](https://github.com/wazuh/wazuh/pull/4226))
- Fix error in Fluent Forwarder that requests an user and pass although the server does not need it. ([#3910](https://github.com/wazuh/wazuh/pull/3910))
- Fix FTS data length bound mishandling in Analysisd. ([#4278](https://github.com/wazuh/wazuh/pull/4278))
- Fix a memory leak in Modulesd and Agentd when Fluent Forward parses duplicate options. [#4334](https://github.com/wazuh/wazuh/pull/4334))
- Fix an invalid memory read in Agentd when checking a remote configuration containing an invalid stanza inside `<labels>`. [#4334](https://github.com/wazuh/wazuh/pull/4334))
- Fix error using force_reload and the eventchannel format in UNIX systems. [#4294](https://github.com/wazuh/wazuh/pull/4294))


## [v3.10.2] - 2019-09-23

### Fixed

- Fix error in Logcollector when reloading localfiles with timestamp wildcards. ([#3995](https://github.com/wazuh/wazuh/pull/3995))


## [v3.10.1] - 2019-09-19

### Fixed

- Fix error after removing a high volume of agents from a group using the Wazuh API. ([#3907](https://github.com/wazuh/wazuh/issues/3907))
- Fix error in Remoted when reloading agent keys (busy resource). ([#3988](https://github.com/wazuh/wazuh/issues/3988))
- Fix invalid read in Remoted counters. ([#3989](https://github.com/wazuh/wazuh/issues/3989))


## [v3.10.0] - 2019-09-16

### Added

- Add framework function to obtain full summary of agents. ([#3842](https://github.com/wazuh/wazuh/pull/3842))
- SCA improvements. ([#3286](https://github.com/wazuh/wazuh/pull/3286))
  - Refactor de SCA internal logic and policy syntax. ([#3249](https://github.com/wazuh/wazuh/issues/3249))
  - Support to follow symbolic links. ([#3228](https://github.com/wazuh/wazuh/issues/3228))
  - Add numerical comparator for SCA rules. ([#3374](https://github.com/wazuh/wazuh/issues/3374))
  - Add SCA decoded events count to global stats. ([#3623](https://github.com/wazuh/wazuh/issues/3623))
- Extend duplicate file detection for LogCollector. ([#3867](https://github.com/wazuh/wazuh/pull/3867))
- Add HIPAA and NIST 800 53 compliance mapping as rule groups.([#3411](https://github.com/wazuh/wazuh/pull/3411) & [#3420](https://github.com/wazuh/wazuh/pull/3420))
- Add SCA compliance groups to rule groups in alerts. ([#3427](https://github.com/wazuh/wazuh/pull/3427))
- Add IPv6 loopback address to localhost list in DB output module (by @aquerubin). ([#3140](https://github.com/wazuh/wazuh/pull/3140))
- Accept `]` and `>` as terminal prompt characters for Agentless. ([#3209](https://github.com/wazuh/wazuh/pull/3209))

### Changed

- Modify logs for agent authentication issues by Remoted. ([#3662](https://github.com/wazuh/wazuh/pull/3662))
- Make Syscollector logging messages more user-friendly. ([#3397](https://github.com/wazuh/wazuh/pull/3397))
- Make SCA load by default all present policies at the default location. ([#3607](https://github.com/wazuh/wazuh/pull/3607))
- Increase IPSIZE definition for IPv6 compatibility (by @aquerubin). ([#3259](https://github.com/wazuh/wazuh/pull/3259))
- Replace local protocol definitions with Socket API definitions (by @aquerubin). ([#3260](https://github.com/wazuh/wazuh/pull/3260))
- Improved error message when some of required Wazuh daemons are down. Allow restarting cluster nodes except when `ossec-execd` is down. ([#3496](https://github.com/wazuh/wazuh/pull/3496))
- Allow existing aws_profile argument to work with vpcflowlogs in AWS wodle configuration. Thanks to Adam Williams (@awill1988). ([#3729](https://github.com/wazuh/wazuh/pull/3729))

### Fixed

- Fix exception handling when using an invalid bucket in AWS wodle ([#3652](https://github.com/wazuh/wazuh/pull/3652))
- Fix error message when an AWS bucket is empty ([#3743](https://github.com/wazuh/wazuh/pull/3743))
- Fix error when getting profiles in custom AWS buckets ([#3786](https://github.com/wazuh/wazuh/pull/3786))
- Fix SCA integrity check when switching between manager nodes. ([#3884](https://github.com/wazuh/wazuh/pull/3884))
- Fix alert email sending when no_full_log option is set in a rule. ([#3174](https://github.com/wazuh/wazuh/pull/3174))
- Fix error in Windows who-data when handling the directories list. ([#3883](https://github.com/wazuh/wazuh/pull/3883))
- Fix error in the hardware inventory collector for PowerPC architectures. ([#3624](https://github.com/wazuh/wazuh/pull/3624))
- Fix the use of mutexes in the `OS_Regex` library. ([#3533](https://github.com/wazuh/wazuh/pull/3533))
- Fix invalid read in the `OS_Regex` library. ([#3815](https://github.com/wazuh/wazuh/pull/3815))
- Fix compilation error on FreeBSD 13 and macOS 10.14. ([#3832](https://github.com/wazuh/wazuh/pull/3832))
- Fix typo in the license of the files. ([#3779](https://github.com/wazuh/wazuh/pull/3779))
- Fix error in `execd` when upgrading agents remotely while auto-restarting. ([#3437](https://github.com/wazuh/wazuh/pull/3437))
- Prevent integrations from inheriting descriptors. ([#3514](https://github.com/wazuh/wazuh/pull/3514))
- Overwrite rules label fix and rules features tests. ([#3414](https://github.com/wazuh/wazuh/pull/3414))
- Fix typo: replace `readed` with `read`. ([#3328](https://github.com/wazuh/wazuh/pull/3328))
- Introduce global mutex for Rootcheck decoder. ([#3530](https://github.com/wazuh/wazuh/pull/3530))
- Fix errors reported by scan-build. ([#3452](https://github.com/wazuh/wazuh/pull/3452) & [#3785](https://github.com/wazuh/wazuh/pull/3785))
- Fix the handling of `wm_exec()` output.([#3486](https://github.com/wazuh/wazuh/pull/3486))
- Fix FIM duplicated entries in Windows. ([#3504](https://github.com/wazuh/wazuh/pull/3504))
- Remove socket deletion from epoll. ([#3432](https://github.com/wazuh/wazuh/pull/3432))
- Let the sources installer support NetBSD. ([#3444](https://github.com/wazuh/wazuh/pull/3444))
- Fix error message from openssl v1.1.1. ([#3413](https://github.com/wazuh/wazuh/pull/3413))
- Fix compilation issue for local installation. ([#3339](https://github.com/wazuh/wazuh/pull/3339))
- Fix exception handling when /tmp have no permissions and tell the user the problem. ([#3401](https://github.com/wazuh/wazuh/pull/3401))
- Fix who-data alerts when audit logs contain hex fields. ([#3909](https://github.com/wazuh/wazuh/pull/3909))
- Remove useless `select()` calls in Analysisd decoders. ([#3964](https://github.com/wazuh/wazuh/pull/3964))


## [v3.9.5] - 2019-08-08

### Fixed

- Fixed a bug in the Framework that prevented Cluster and API from handling the file _client.keys_ if it's mounted as a volume on Docker.
- Fixed a bug in Analysisd that printed the millisecond part of the alerts' timestamp without zero-padding. That prevented Elasticsearch 7 from indexing those alerts. ([#3814](https://github.com/wazuh/wazuh/issues/3814))


## [v3.9.4] - 2019-08-07

### Changed

- Prevent agent on Windows from including who-data on FIM events for child directories without who-data enabled, even if it's available. ([#3601](https://github.com/wazuh/wazuh/issues/3601))
- Prevent Rootcheck configuration from including the `<ignore>` settings if they are empty. ([#3634](https://github.com/wazuh/wazuh/issues/3634))
- Wazuh DB will delete the agent DB-related files immediately when removing an agent. ([#3691](https://github.com/wazuh/wazuh/issues/3691))

### Fixed

- Fixed bug in Remoted when correlating agents and their sockets in TCP mode. ([#3602](https://github.com/wazuh/wazuh/issues/3602))
- Fix bug in the agent that truncated its IP address if it occupies 15 characters. ([#3615](https://github.com/wazuh/wazuh/issues/3615))
- Logcollector failed to overwrite duplicate `<localfile>` stanzas. ([#3616](https://github.com/wazuh/wazuh/issues/3616))
- Analysisd could produce a double free if an Eventchannel message contains an invalid XML member. ([#3626](https://github.com/wazuh/wazuh/issues/3626))
- Fixed defects in the code reported by Coverity. ([#3627](https://github.com/wazuh/wazuh/issues/3627))
- Fixed bug in Analysisd when handling invalid JSON input strings. ([#3648](https://github.com/wazuh/wazuh/issues/3648))
- Fix handling of SCA policies with duplicate ID in Wazuh DB. ([#3668](https://github.com/wazuh/wazuh/issues/3668))
- Cluster could fail synchronizing some files located in Docker volumes. ([#3669](https://github.com/wazuh/wazuh/issues/3669))
- Fix a handler leak in the FIM whodata engine for Windows. ([#3690](https://github.com/wazuh/wazuh/issues/3690))
- The Docker listener module was storing and ignoring the output of the integration. ([#3768](https://github.com/wazuh/wazuh/issues/3768))
- Fixed memory leaks in Syscollector for macOS agents. ([#3795](https://github.com/wazuh/wazuh/pull/3795))
- Fix dangerous mutex initialization in Windows hosts. ([#3805](https://github.com/wazuh/wazuh/issues/3805))


## [v3.9.3] - 2019-07-08

### Changed

- Windows Eventchannel log collector will no longer report bookmarked events by default (those that happened while the agent was stopped). ([#3485](https://github.com/wazuh/wazuh/pull/3485))
- Remoted will discard agent-info data not in UTF-8 format. ([#3581](https://github.com/wazuh/wazuh/pull/3581))

### Fixed

- Osquery integration did not follow the osquery results file (*osqueryd.results.log*) as of libc 2.28. ([#3494](https://github.com/wazuh/wazuh/pull/3494))
- Windows Eventchannnel log collector did not update the bookmarks so it reported old events repeatedly. ([#3485](https://github.com/wazuh/wazuh/pull/3485))
- The agent sent invalid info data in the heartbeat message if it failed to get the host IP address. ([#3555](https://github.com/wazuh/wazuh/pull/3555))
- Modulesd produced a memory leak when being queried for its running configuration. ([#3564](https://github.com/wazuh/wazuh/pull/3564))
- Analysisd and Logtest crashed when trying rules having `<different_geoip>` and no `<not_same_field>` stanza. ([#3587](https://github.com/wazuh/wazuh/pull/3587))
- Vulnerability Detector failed to parse the Canonical's OVAL feed due to a syntax change. ([#3563](https://github.com/wazuh/wazuh/pull/3563))
- AWS Macie events produced erros in Elasticsearch. ([#3608](https://github.com/wazuh/wazuh/pull/3608))
- Rules with `<list lookup="address_match_key" />` produced a false match if the CDB list file is missing. ([#3609](https://github.com/wazuh/wazuh/pull/3609))
- Remote configuration was missing the `<ignore>` stanzas for Syscheck and Rootcheck when defined as sregex. ([#3617](https://github.com/wazuh/wazuh/pull/3617))


## [v3.9.2] 2019-06-10

### Added

- Added support for Ubuntu 12.04 to the SCA configuration template. ([#3361](https://github.com/wazuh/wazuh/pull/3361))

### Changed

- Prevent the agent from stopping if it fails to resolve the manager's hostname on startup. ([#3405](https://github.com/wazuh/wazuh/pull/3405))
- Prevent Remoted from logging agent connection timeout as an error, now it's a debugging log. ([#3426](https://github.com/wazuh/wazuh/pull/3426))

### Fixed

- A configuration request to Analysisd made it crash if the option `<white_list>` is empty. ([#3383](https://github.com/wazuh/wazuh/pull/3383))
- Fixed error when uploading some configuration files through API in wazuh-docker environments. ([#3335](https://github.com/wazuh/wazuh/issues/3335))
- Fixed error deleting temporary files during cluster synchronization. ([#3379](https://github.com/wazuh/wazuh/issues/3379))
- Fixed bad permissions on agent-groups files synchronized via wazuh-clusterd. ([#3438](https://github.com/wazuh/wazuh/issues/3438))
- Fixed bug in the database module that ignored agents registered with a network mask. ([#3351](https://github.com/wazuh/wazuh/pull/3351))
- Fixed a memory bug in the CIS-CAT module. ([#3406](https://github.com/wazuh/wazuh/pull/3406))
- Fixed a bug in the agent upgrade tool when checking the version number. ([#3391](https://github.com/wazuh/wazuh/pull/3391))
- Fixed error checking in the Windows Eventchannel log collector. ([#3393](https://github.com/wazuh/wazuh/pull/3393))
- Prevent Analysisd from crashing at SCA decoder due to a race condition calling a thread-unsafe function. ([#3466](https://github.com/wazuh/wazuh/pull/3466))
- Fix a file descriptor leak in Modulesd on timeout when running a subprocess. ([#3470](https://github.com/wazuh/wazuh/pull/3470))
  - OpenSCAP.
  - CIS-CAT.
  - Command.
  - Azure.
  - SCA.
  - AWS.
  - Docker.
- Prevent Modulesd from crashing at Vulnerability Detector when updating a RedHat feed. ([3458](https://github.com/wazuh/wazuh/pull/3458))


## [v3.9.1] 2019-05-21

### Added

- Added directory existence checking for SCA rules. ([#3246](https://github.com/wazuh/wazuh/pull/3246))
- Added line number to error messages when parsing YAML files. ([#3325](https://github.com/wazuh/wazuh/pull/3325))
- Enhanced wildcard support for Windows Logcollector. ([#3236](https://github.com/wazuh/wazuh/pull/3236))

### Changed

- Changed the extraction point of the package name in the Vulnerability Detector OVALs. ([#3245](https://github.com/wazuh/wazuh/pull/3245))

### Fixed

- Fixed SCA request interval option limit. ([#3254](https://github.com/wazuh/wazuh/pull/3254))
- Fixed SCA directory checking. ([#3235](https://github.com/wazuh/wazuh/pull/3235))
- Fixed potential out of bounds memory access. ([#3285](https://github.com/wazuh/wazuh/pull/3285))
- Fixed CIS-CAT XML report parser. ([#3261](https://github.com/wazuh/wazuh/pull/3261))
- Fixed .ssh folder permissions for Agentless. ([#2660](https://github.com/wazuh/wazuh/pull/2660))
- Fixed repeated fields in SCA summary events. ([#3278](https://github.com/wazuh/wazuh/pull/3278))
- Fixed command output treatment for the SCA module. ([#3297](https://github.com/wazuh/wazuh/pull/3297))
- Fixed _agent_upgrade_ tool to set the manager version as the default one. ([#2721](https://github.com/wazuh/wazuh/pull/2721))
- Fixed execd crash when timeout list is not initialized. ([#3316](https://github.com/wazuh/wazuh/pull/3316))
- Fixed support for reading large files on Windows Logcollector. ([#3248](https://github.com/wazuh/wazuh/pull/3248))
- Fixed the manager restarting process via API on Docker. ([#3273](https://github.com/wazuh/wazuh/pull/3273))
- Fixed the _agent_info_ files synchronization between cluster nodes. ([#3272](https://github.com/wazuh/wazuh/pull/3272))

### Removed

- Removed 5-second reading timeout for File Integrity Monitoring scan. ([#3366](https://github.com/wazuh/wazuh/pull/3366))


## [v3.9.0] 2019-05-02

### Added

- New module to perform **Security Configuration Assessment** scans. ([#2598](https://github.com/wazuh/wazuh/pull/2598))
- New **Logcollector** features. ([#2929](https://github.com/wazuh/wazuh/pull/2929))
  - Let Logcollector filter files by content. ([#2796](https://github.com/wazuh/wazuh/issues/2796))
  - Added a pattern exclusion option to Logcollector. ([#2797](https://github.com/wazuh/wazuh/issues/2797))
  - Let Logcollector filter files by date. ([#2799](https://github.com/wazuh/wazuh/issues/2799))
  - Let logcollector support wildcards on Windows. ([#2898](https://github.com/wazuh/wazuh/issues/2898))
- **Fluent forwarder** for agents. ([#2828](https://github.com/wazuh/wazuh/issues/2828))
- Collect network and port inventory for Windows XP/Server 2003. ([#2464](https://github.com/wazuh/wazuh/pull/2464))
- Included inventory fields as dynamic fields in events to use them in rules. ([#2441](https://github.com/wazuh/wazuh/pull/2441))
- Added an option _startup_healthcheck_ in FIM so that the the who-data health-check is optional. ([#2323](https://github.com/wazuh/wazuh/pull/2323))
- The real agent IP is reported by the agent and shown in alerts and the App interface. ([#2577](https://github.com/wazuh/wazuh/pull/2577))
- Added support for organizations in AWS wodle. ([#2627](https://github.com/wazuh/wazuh/pull/2627))
- Added support for hot added symbolic links in _Whodata_. ([#2466](https://github.com/wazuh/wazuh/pull/2466))
- Added `-t` option to `wazuh-clusterd` binary ([#2691](https://github.com/wazuh/wazuh/pull/2691)).
- Added options `same_field` and `not_same_field` in rules to correlate dynamic fields between events. ([#2689](https://github.com/wazuh/wazuh/pull/2689))
- Added optional daemons start by default. ([#2769](https://github.com/wazuh/wazuh/pull/2769))
- Make the Windows installer to choose the appropriate `ossec.conf` file based on the System version. ([#2773](https://github.com/wazuh/wazuh/pull/2773))
- Added writer thread preference for Logcollector. ([#2783](https://github.com/wazuh/wazuh/pull/2783))
- Added database deletion from Wazuh-DB for removed agents. ([#3123](https://github.com/wazuh/wazuh/pull/3123))

### Changed

- Introduced a network buffer in Remoted to cache incomplete messages from agents. This improves the performance by preventing Remoted from waiting for complete messages. ([#2528](https://github.com/wazuh/wazuh/pull/2528))
- Improved alerts about disconnected agents: they will contain the data about the disconnected agent, although the alert is actually produced by the manager. ([#2379](https://github.com/wazuh/wazuh/pull/2379))
- PagerDuty integration plain text alert support (by @spartantri). ([#2403](https://github.com/wazuh/wazuh/pull/2403))
- Improved Remoted start-up logging messages. ([#2460](https://github.com/wazuh/wazuh/pull/2460))
- Let _agent_auth_ warn when it receives extra input arguments. ([#2489](https://github.com/wazuh/wazuh/pull/2489))
- Update the who-data related SELinux rules for Audit 3.0. This lets who-data work on Fedora 29. ([#2419](https://github.com/wazuh/wazuh/pull/2419))
- Changed data source for network interface's MAC address in Syscollector so that it will be able to get bonded interfaces' MAC. ([#2550](https://github.com/wazuh/wazuh/pull/2550))
- Migrated unit tests from Check to TAP (Test Anything Protocol). ([#2572](https://github.com/wazuh/wazuh/pull/2572))
- Now labels starting with `_` are reserved for internal use. ([#2577](https://github.com/wazuh/wazuh/pull/2577))
- Now AWS wodle fetches aws.requestParameters.disableApiTermination with an unified format ([#2614](https://github.com/wazuh/wazuh/pull/2614))
- Improved overall performance in cluster ([#2575](https://github.com/wazuh/wazuh/pull/2575))
- Some improvements has been made in the _vulnerability-detector_ module. ([#2603](https://github.com/wazuh/wazuh/pull/2603))
- Refactor of decoded fields from the Windows eventchannel decoder. ([#2684](https://github.com/wazuh/wazuh/pull/2684))
- Deprecate global option `<queue_size>` for Analysisd. ([#2729](https://github.com/wazuh/wazuh/pull/2729))
- Excluded noisy events from Windows Eventchannel. ([#2763](https://github.com/wazuh/wazuh/pull/2763))
- Replaced `printf` functions in `agent-authd`. ([#2830](https://github.com/wazuh/wazuh/pull/2830))
- Replaced `strtoul()` using NULL arguments with `atol()` in wodles config files. ([#2801](https://github.com/wazuh/wazuh/pull/2801))
- Added a more descriptive message for SSL error when agent-auth fails. ([#2941](https://github.com/wazuh/wazuh/pull/2941))
- Changed the starting Analysisd messages about loaded rules from `info` to `debug` level. ([#2881](https://github.com/wazuh/wazuh/pull/2881))
- Re-structured messages for FIM module. ([#2926](https://github.com/wazuh/wazuh/pull/2926))
- Changed `diff` output in Syscheck for Windows. ([#2969](https://github.com/wazuh/wazuh/pull/2969))
- Replaced OSSEC e-mail subject with Wazuh in `ossec-maild`. ([#2975](https://github.com/wazuh/wazuh/pull/2975))
- Added keepalive in TCP to manage broken connections in `ossec-remoted`. ([#3069](https://github.com/wazuh/wazuh/pull/3069))
- Change default restart interval for Docker listener module to one minute. ([#2679](https://github.com/wazuh/wazuh/pull/2679))

### Fixed

- Fixed error in Syscollector for Windows older than Vista when gathering the hardware inventory. ([#2326](https://github.com/wazuh/wazuh/pull/2326))
- Fixed an error in the OSQuery configuration validation. ([#2446](https://github.com/wazuh/wazuh/pull/2446))
- Prevent Integrator, Syslog Client and Mail forwarded from getting stuck while reading _alerts.json_. ([#2498](https://github.com/wazuh/wazuh/pull/2498))
- Fixed a bug that could make an Agent running on Windows XP close unexpectedly while receiving a WPK file. ([#2486](https://github.com/wazuh/wazuh/pull/2486))
- Fixed _ossec-control_ script in Solaris. ([#2495](https://github.com/wazuh/wazuh/pull/2495))
- Fixed a compilation error when building Wazuh in static linking mode with the Audit library enabled. ([#2523](https://github.com/wazuh/wazuh/pull/2523))
- Fixed a memory hazard in Analysisd on log pre-decoding for short logs (less than 5 bytes). ([#2391](https://github.com/wazuh/wazuh/pull/2391))
- Fixed defects reported by Cppcheck. ([#2521](https://github.com/wazuh/wazuh/pull/2521))
  - Double free in GeoIP data handling with IPv6.
  - Buffer overlay when getting OS information.
  - Check for successful memory allocation in Syscollector.
- Fix out-of-memory error in Remoted when upgrading an agent with a big data chunk. ([#2594](https://github.com/wazuh/wazuh/pull/2594))
- Re-registered agent are reassigned to correct groups when the multigroup is empty. ([#2440](https://github.com/wazuh/wazuh/pull/2440))
- Wazuh manager starts regardless of the contents of _local_decoder.xml_. ([#2465](https://github.com/wazuh/wazuh/pull/2465))
- Let _Remoted_ wait for download module availability. ([#2517](https://github.com/wazuh/wazuh/pull/2517))
- Fix duplicate field names at some events for Windows eventchannel. ([#2500](https://github.com/wazuh/wazuh/pull/2500))
- Delete empty fields from Windows Eventchannel alerts. ([#2492](https://github.com/wazuh/wazuh/pull/2492))
- Fixed memory leak and crash in Vulnerability Detector. ([#2620](https://github.com/wazuh/wazuh/pull/2620))
- Prevent Analysisd from crashing when receiving an invalid Syscollector event. ([#2621](https://github.com/wazuh/wazuh/pull/2621))
- Fix a bug in the database synchronization module that left broken references of removed agents to groups. ([#2628](https://github.com/wazuh/wazuh/pull/2628))
- Fixed restart service in AIX. ([#2674](https://github.com/wazuh/wazuh/pull/2674))
- Prevent Execd from becoming defunct when Active Response disabled. ([#2692](https://github.com/wazuh/wazuh/pull/2692))
- Fix error in Syscollector when unable to read the CPU frequency on agents. ([#2740](https://github.com/wazuh/wazuh/pull/2740))
- Fix Windows escape format affecting non-format messages. ([#2725](https://github.com/wazuh/wazuh/pull/2725))
- Avoid a segfault in mail daemon due to the XML tags order in the `ossec.conf`. ([#2711](https://github.com/wazuh/wazuh/pull/2711))
- Prevent the key updating thread from starving in Remoted. ([#2761](https://github.com/wazuh/wazuh/pull/2761))
- Fixed error logging on Windows agent. ([#2791](https://github.com/wazuh/wazuh/pull/2791))
- Let CIS-CAT decoder reuse the Wazuh DB connection socket. ([#2800](https://github.com/wazuh/wazuh/pull/2800))
- Fixed issue with `agent-auth` options without argument. ([#2808](https://github.com/wazuh/wazuh/pull/2808))
- Fixed control of the frequency counter in alerts. ([#2854](https://github.com/wazuh/wazuh/pull/2854))
- Ignore invalid files for agent groups. ([#2895](https://github.com/wazuh/wazuh/pull/2895))
- Fixed invalid behaviour when moving files in Whodata mode. ([#2888](https://github.com/wazuh/wazuh/pull/2888))
- Fixed deadlock in Remoted when updating the `keyentries` structure. ([#2956](https://github.com/wazuh/wazuh/pull/2956))
- Fixed error in Whodata when one of the file permissions cannot be extracted. ([#2940](https://github.com/wazuh/wazuh/pull/2940))
- Fixed System32 and SysWOW64 event processing in Whodata. ([#2935](https://github.com/wazuh/wazuh/pull/2935))
- Fixed Syscheck hang when monitoring system directories. ([#3059](https://github.com/wazuh/wazuh/pull/3059))
- Fixed the package inventory for MAC OS X. ([#3035](https://github.com/wazuh/wazuh/pull/3035))
- Translated the Audit Policy fields from IDs for Windows events. ([#2950](https://github.com/wazuh/wazuh/pull/2950))
- Fixed broken pipe error when Wazuh-manager closes TCP connection. ([#2965](https://github.com/wazuh/wazuh/pull/2965))
- Fixed whodata mode on drives other than the main one. ([#2989](https://github.com/wazuh/wazuh/pull/2989))
- Fixed bug occurred in the database while removing an agent. ([#2997](https://github.com/wazuh/wazuh/pull/2997))
- Fixed duplicated alerts for Red Hat feed in `vulnerability-detector`. ([#3000](https://github.com/wazuh/wazuh/pull/3000))
- Fixed bug when processing symbolic links in Whodata. ([#3025](https://github.com/wazuh/wazuh/pull/3025))
- Fixed option for ignoring paths in rootcheck. ([#3058](https://github.com/wazuh/wazuh/pull/3058))
- Allow Wazuh service on MacOSX to be available without restart. ([#3119](https://github.com/wazuh/wazuh/pull/3119))
- Ensure `internal_options.conf` file is overwritten on Windows upgrades. ([#3153](https://github.com/wazuh/wazuh/pull/3153))
- Fixed the reading of the setting `attempts` of the Docker module. ([#3067](https://github.com/wazuh/wazuh/pull/3067))
- Fix a memory leak in Docker listener module. ([#2679](https://github.com/wazuh/wazuh/pull/2679))


## [v3.8.2] 2019-01-30

### Fixed

- Analysisd crashed when parsing a log from OpenLDAP due to a bug in the option `<accumulate>`. ([#2456](https://github.com/wazuh/wazuh/pull/2456))
- Modulesd closed unexpectedly if a command was defined without a `<tag>` option. ([#2470](https://github.com/wazuh/wazuh/pull/2470))
- The Eventchannel decoder was not being escaping backslashes correctly. ([#2483](https://github.com/wazuh/wazuh/pull/2483))
- The Eventchannel decoder was leaving spurious trailing spaces in some fields.  ([#2484](https://github.com/wazuh/wazuh/pull/2484))


## [v3.8.1] 2019-01-25

### Fixed

- Fixed memory leak in Logcollector when reading Windows eventchannel. ([#2450](https://github.com/wazuh/wazuh/pull/2450))
- Fixed script parsing error in Solaris 10. ([#2449](https://github.com/wazuh/wazuh/pull/2449))
- Fixed version comparisons on Red Hat systems. (By @orlando-jamie) ([#2445](https://github.com/wazuh/wazuh/pull/2445))


## [v3.8.0] 2019-01-19

### Added

- Logcollector **extension for Windows eventchannel logs in JSON format.** ([#2142](https://github.com/wazuh/wazuh/pull/2142))
- Add options to detect **attribute and file permission changes** for Windows. ([#1918](https://github.com/wazuh/wazuh/pull/1918))
- Added **Audit health-check** in the Whodata initialization. ([#2180](https://github.com/wazuh/wazuh/pull/2180))
- Added **Audit rules auto-reload** in Whodata. ([#2180](https://github.com/wazuh/wazuh/pull/2180))
- Support for **new AWS services** in the AWS wodle ([#2242](https://github.com/wazuh/wazuh/pull/2242)):
    - AWS Config
    - AWS Trusted Advisor
    - AWS KMS
    - AWS Inspector
    - Add support for IAM roles authentication in EC2 instances.
- New module "Agent Key Polling" to integrate agent key request to external data sources. ([#2127](https://github.com/wazuh/wazuh/pull/2127))
  - Look for missing or old agent keys when Remoted detects an authorization failure.
  - Request agent keys by calling a defined executable or connecting to a local socket.
- Get process inventory for Windows natively. ([#1760](https://github.com/wazuh/wazuh/pull/1760))
- Improved vulnerability detection in Red Hat systems. ([#2137](https://github.com/wazuh/wazuh/pull/2137))
- Add retries to download the OVAL files in vulnerability-detector. ([#1832](https://github.com/wazuh/wazuh/pull/1832))
- Auto-upgrade FIM databases in Wazuh-DB. ([#2147](https://github.com/wazuh/wazuh/pull/2147))
- New dedicated thread for AR command running on Windows agent. ([#1725](https://github.com/wazuh/wazuh/pull/1725))
  -  This will prevent the agent from delaying due to an AR execution.
- New internal option to clean residual files of agent groups. ([#1985](https://github.com/wazuh/wazuh/pull/1985))
- Add a manifest to run `agent-auth.exe` with elevated privileges. ([#1998](https://github.com/wazuh/wazuh/pull/1998))
- Compress `last-entry` files to check differences by FIM. ([#2034](https://github.com/wazuh/wazuh/pull/2034))
- Add error messages to integration scripts. ([#2143](https://github.com/wazuh/wazuh/pull/2143))
- Add CDB lists building on install. ([#2167](https://github.com/wazuh/wazuh/pull/2167))
- Update Wazuh copyright for internal files. ([#2343](https://github.com/wazuh/wazuh/pull/2343))
- Added option to allow maild select the log file to read from. ([#977](https://github.com/wazuh/wazuh/pull/977))
- Add table to control the metadata of the vuln-detector DB. ([#2402](https://github.com/wazuh/wazuh/pull/2402))

### Changed

- Now Wazuh manager can be started with an empty configuration in ossec.conf. ([#2086](https://github.com/wazuh/wazuh/pull/2086))
- The Authentication daemon is now enabled by default. ([#2129](https://github.com/wazuh/wazuh/pull/2129))
- Make FIM show alerts for new files by default. ([#2213](https://github.com/wazuh/wazuh/pull/2213))
- Reduce the length of the query results from Vulnerability Detector to Wazuh DB. ([#1798](https://github.com/wazuh/wazuh/pull/1798))
- Improved the build system to automatically detect a big-endian platform. ([#2031](https://github.com/wazuh/wazuh/pull/2031))
  - Building option `USE_BIG_ENDIAN` is not already needed on Solaris (SPARC) or HP-UX.
- Expanded the regex pattern maximum size from 2048 to 20480 bytes. ([#2036](https://github.com/wazuh/wazuh/pull/2036))
- Improved IP address validation in the option `<white_list>` (by @pillarsdotnet). ([#1497](https://github.com/wazuh/wazuh/pull/1497))
- Improved rule option `<info>` validation (by @pillarsdotnet). ([#1541](https://github.com/wazuh/wazuh/pull/1541))
- Deprecated the Syscheck option `<remove_old_diff>` by making it mandatory. ([#1915](https://github.com/wazuh/wazuh/pull/1915))
- Fix invalid error "Unable to verity server certificate" in _ossec-authd_ (server). ([#2045](https://github.com/wazuh/wazuh/pull/2045))
- Remove deprecated flag `REUSE_ID` from the Makefile options. ([#2107](https://github.com/wazuh/wazuh/pull/2107))
- Syscheck first queue error message changed into a warning. ([#2146](https://github.com/wazuh/wazuh/pull/2146))
- Do the DEB and RPM package scan regardless of Linux distribution. ([#2168](https://github.com/wazuh/wazuh/pull/2168))
- AWS VPC configuration in the AWS wodle ([#2242](https://github.com/wazuh/wazuh/pull/2242)).
- Hide warning log by FIM when cannot open a file that has just been removed. ([#2201](https://github.com/wazuh/wazuh/pull/2201))
- The default FIM configuration will ignore some temporary files. ([#2202](https://github.com/wazuh/wazuh/pull/2202))

### Fixed

- Fixed error description in the osquery configuration parser (by @pillarsdotnet). ([#1499](https://github.com/wazuh/wazuh/pull/1499))
- The FTS comment option `<ftscomment>` was not being read (by @pillarsdotnet). ([#1536](https://github.com/wazuh/wazuh/pull/1536))
- Fixed error when multigroup files are not found. ([#1792](https://github.com/wazuh/wazuh/pull/1792))
- Fix error when assigning multiple groups whose names add up to more than 4096 characters. ([#1792](https://github.com/wazuh/wazuh/pull/1792))
- Replaced "getline" function with "fgets" in vulnerability-detector to avoid compilation errors with older versions of libC. ([#1822](https://github.com/wazuh/wazuh/pull/1822))
- Fix bug in Wazuh DB when trying to store multiple network interfaces with the same IP from Syscollector. ([#1928](https://github.com/wazuh/wazuh/pull/1928))
- Improved consistency of multigroups. ([#1985](https://github.com/wazuh/wazuh/pull/1985))
- Fixed the reading of the OS name and version in HP-UX systems. ([#1990](https://github.com/wazuh/wazuh/pull/1990))
- Prevent the agent from producing an error on platforms that don't support network timeout. ([#2001](https://github.com/wazuh/wazuh/pull/2001))
- Logcollector could not set the maximum file limit on HP-UX platform. ([2030](https://github.com/wazuh/wazuh/pull/2030))
- Allow strings up to 64KB long for log difference analysis. ([#2032](https://github.com/wazuh/wazuh/pull/2032))
- Now agents keep their registration date when upgrading the manager. ([#2033](https://github.com/wazuh/wazuh/pull/2033))
- Create an empty `client.keys` file on a fresh installation of a Windows agent. ([2040](https://github.com/wazuh/wazuh/pull/2040))
- Allow CDB list keys and values to have double quotes surrounding. ([#2046](https://github.com/wazuh/wazuh/pull/2046))
- Remove file `queue/db/.template.db` on upgrade / restart. ([2073](https://github.com/wazuh/wazuh/pull/2073))
- Fix error on Analysisd when `check_value` doesn't exist. ([2080](https://github.com/wazuh/wazuh/pull/2080))
- Prevent Rootcheck from looking for invalid link count in agents running on Solaris (by @ecsc-georgew). ([2087](https://github.com/wazuh/wazuh/pull/2087))
- Fixed the warning messages when compiling the agent on AIX. ([2099](https://github.com/wazuh/wazuh/pull/2099))
- Fix missing library when building Wazuh with MySQL support. ([#2108](https://github.com/wazuh/wazuh/pull/2108))
- Fix compile warnings for the Solaris platform. ([#2121](https://github.com/wazuh/wazuh/pull/2121))
- Fixed regular expression for audit.key in audit decoder. ([#2134](https://github.com/wazuh/wazuh/pull/2134))
- Agent's ossec-control stop should wait a bit after killing a process. ([#2149](https://github.com/wazuh/wazuh/pull/2149))
- Fixed error ocurred while monitoring symbolic links in Linux. ([#2152](https://github.com/wazuh/wazuh/pull/2152))
- Fixed some bugs in Logcollector: ([#2154](https://github.com/wazuh/wazuh/pull/2154))
  - If Logcollector picks up a log exceeding 65279 bytes, that log may lose the null-termination.
  - Logcollector crashes if multiple wildcard stanzas resolve the same file.
  - An error getting the internal file position may lead to an undefined condition.
- Execd daemon now runs even if active response is disabled ([#2177](https://github.com/wazuh/wazuh/pull/2177))
- Fix high precision timestamp truncation in rsyslog messages. ([#2128](https://github.com/wazuh/wazuh/pull/2128))
- Fix missing Whodata section to the remote configuration query. ([#2173](https://github.com/wazuh/wazuh/pull/2173))
- Bugfixes in AWS wodle ([#2242](https://github.com/wazuh/wazuh/pull/2242)):
    - Fixed bug in AWS Guard Duty alerts when there were multiple remote IPs.
    - Fixed bug when using flag `remove_from_bucket`.
    - Fixed bug when reading buckets generating more than 1000 logs in the same day.
    - Increase `qty` of `aws.eventNames` and remove usage of `aws.eventSources`.
- Fix bug in cluster configuration when using Kubernetes ([#2227](https://github.com/wazuh/wazuh/pull/2227)).
- Fix network timeout setup in agent running on Windows. ([#2185](https://github.com/wazuh/wazuh/pull/2185))
- Fix default values for the `<auto_ignore>` option. ([#2210](https://github.com/wazuh/wazuh/pull/2210))
- Fix bug that made Modulesd and Remoted crash on ARM architecture. ([#2214](https://github.com/wazuh/wazuh/pull/2214))
- The regex parser included the next character after a group:
  - If the input string just ends after that character. ([#2216](https://github.com/wazuh/wazuh/pull/2216))
  - The regex parser did not accept a group terminated with an escaped byte or a class. ([#2224](https://github.com/wazuh/wazuh/pull/2224))
- Fixed buffer overflow hazard in FIM when performing change report on long paths on macOS platform. ([#2285](https://github.com/wazuh/wazuh/pull/2285))
- Fix sending of the owner attribute when a file is created in Windows. ([#2292](https://github.com/wazuh/wazuh/pull/2292))
- Fix audit reconnection to the Whodata socket ([#2305](https://github.com/wazu2305h/wazuh/pull/2305))
- Fixed agent connection in TCP mode on Windows XP. ([#2329](https://github.com/wazuh/wazuh/pull/2329))
- Fix log shown when a command reaches its timeout and `ignore_output` is enabled. ([#2316](https://github.com/wazuh/wazuh/pull/2316))
- Analysisd and Syscollector did not detect the number of cores on Raspberry Pi. ([#2304](https://github.com/wazuh/wazuh/pull/2304))
- Analysisd and Syscollector did not detect the number of cores on CentOS 5. ([#2340](https://github.com/wazuh/wazuh/pull/2340))


## [v3.7.2] 2018-12-17

### Changed

- Logcollector will fully read a log file if it reappears after being deleted. ([#2041](https://github.com/wazuh/wazuh/pull/2041))

### Fixed

- Fix some bugs in Logcollector: ([#2041](https://github.com/wazuh/wazuh/pull/2041))
  - Logcollector ceases monitoring any log file containing a binary zero-byte.
  - If a local file defined with wildcards disappears, Logcollector incorrectly shows a negative number of remaining open attempts.
  - Fixed end-of-file detection for text-based file formats.
- Fixed a bug in Analysisd that made it crash when decoding a malformed FIM message. ([#2089](https://github.com/wazuh/wazuh/pull/2089))


## [v3.7.1] 2018-12-05

### Added

- New internal option `remoted.guess_agent_group` allowing agent group guessing by Remoted to be optional. ([#1890](https://github.com/wazuh/wazuh/pull/1890))
- Added option to configure another audit keys to monitor. ([#1882](https://github.com/wazuh/wazuh/pull/1882))
- Added option to create the SSL certificate and key with the install.sh script. ([#1856](https://github.com/wazuh/wazuh/pull/1856))
- Add IPv6 support to `host-deny.sh` script. (by @iasdeoupxe). ([#1583](https://github.com/wazuh/wazuh/pull/1583))
- Added tracing information (PID, function, file and line number) to logs when debugging is enabled. ([#1866](https://github.com/wazuh/wazuh/pull/1866))

### Changed

- Change errors messages to descriptive warnings in Syscheck when a files is not reachable. ([#1730](https://github.com/wazuh/wazuh/pull/1730))
- Add default values to global options to let the manager start. ([#1894](https://github.com/wazuh/wazuh/pull/1894))
- Improve Remoted performance by reducing interaction between threads. ([#1902](https://github.com/wazuh/wazuh/pull/1902))

### Fixed

- Prevent duplicates entries for denied IP addresses by `host-deny.sh`. (by @iasdeoupxe). ([#1583](https://github.com/wazuh/wazuh/pull/1583))
- Fix issue in Logcollector when reaching the file end before getting a full line. ([#1744](https://github.com/wazuh/wazuh/pull/1744))
- Throw an error when a nonexistent CDB file is added in the ossec.conf file. ([#1783](https://github.com/wazuh/wazuh/pull/1783))
- Fix bug in Remoted that truncated control messages to 1024 bytes. ([#1847](https://github.com/wazuh/wazuh/pull/1847))
- Avoid that the attribute `ignore` of rules silence alerts. ([#1874](https://github.com/wazuh/wazuh/pull/1874))
- Fix race condition when decoding file permissions. ([#1879](https://github.com/wazuh/wazuh/pull/1879)
- Fix to overwrite FIM configuration when directories come in the same tag separated by commas. ([#1886](https://github.com/wazuh/wazuh/pull/1886))
- Fixed issue with hash table handling in FTS and label management. ([#1889](https://github.com/wazuh/wazuh/pull/1889))
- Fixed id's and description of FIM alerts. ([#1891](https://github.com/wazuh/wazuh/pull/1891))
- Fix log flooding by Logcollector when monitored files disappear. ([#1893](https://github.com/wazuh/wazuh/pull/1893))
- Fix bug configuring empty blocks in FIM. ([#1897](https://github.com/wazuh/wazuh/pull/1897))
- Let the Windows agent reset the random generator context if it's corrupt. ([#1898](https://github.com/wazuh/wazuh/pull/1898))
- Prevent Remoted from logging errors if the cluster configuration is missing or invalid. ([#1900](https://github.com/wazuh/wazuh/pull/1900))
- Fix race condition hazard in Remoted when handling control messages. ([#1902](https://github.com/wazuh/wazuh/pull/1902))
- Fix uncontrolled condition in the vulnerability-detector version checker. ([#1932](https://github.com/wazuh/wazuh/pull/1932))
- Restore support for Amazon Linux in vulnerability-detector. ([#1932](https://github.com/wazuh/wazuh/pull/1932))
- Fixed starting wodles after a delay specified in `interval` when `run_on_start` is set to `no`, on the first run of the agent. ([#1906](https://github.com/wazuh/wazuh/pull/1906))
- Prevent `agent-auth` tool from creating the file _client.keys_ outside the agent's installation folder. ([#1924](https://github.com/wazuh/wazuh/pull/1924))
- Fix symbolic links attributes reported by `syscheck` in the alerts. ([#1926](https://github.com/wazuh/wazuh/pull/1926))
- Added some improvements and fixes in Whodata. ([#1929](https://github.com/wazuh/wazuh/pull/1929))
- Fix FIM decoder to accept Windows user containing spaces. ([#1930](https://github.com/wazuh/wazuh/pull/1930))
- Add missing field `restrict` when querying the FIM configuration remotely. ([#1931](https://github.com/wazuh/wazuh/pull/1931))
- Fix values of FIM scan showed in agent_control info. ([#1940](https://github.com/wazuh/wazuh/pull/1940))
- Fix agent group updating in database module. ([#2004](https://github.com/wazuh/wazuh/pull/2004))
- Logcollector prevents vmhgfs from synchronizing the inode. ([#2022](https://github.com/wazuh/wazuh/pull/2022))
- File descriptor leak that may impact agents running on UNIX platforms. ([#2021](https://github.com/wazuh/wazuh/pull/2021))
- CIS-CAT events were being processed by a wrong decoder. ([#2014](https://github.com/wazuh/wazuh/pull/2014))


## [v3.7.0] - 2018-11-10

### Added

- Adding feature to **remotely query agent configuration on demand.** ([#548](https://github.com/wazuh/wazuh/pull/548))
- **Boost Analysisd performance with multithreading.** ([#1039](https://github.com/wazuh/wazuh/pull/1039))
- Adding feature to **let agents belong to multiple groups.** ([#1135](https://github.com/wazuh/wazuh/pull/1135))
  - API support for multiple groups. ([#1300](https://github.com/wazuh/wazuh/pull/1300) [#1135](https://github.com/wazuh/wazuh/pull/1135))
- **Boost FIM decoding performance** by storing data into Wazuh DB using SQLite databases. ([#1333](https://github.com/wazuh/wazuh/pull/1333))
  - FIM database is cleaned after restarting agent 3 times, deleting all entries that left being monitored.
  - Added script to migrate older Syscheck databases to WazuhDB. ([#1504](https://github.com/wazuh/wazuh/pull/1504)) ([#1333](https://github.com/wazuh/wazuh/pull/1333))
- Added rule testing output when restarting manager. ([#1196](https://github.com/wazuh/wazuh/pull/1196))
- New wodle for **Azure environment log and process collection.** ([#1306](https://github.com/wazuh/wazuh/pull/1306))
- New wodle for **Docker container monitoring.** ([#1368](https://github.com/wazuh/wazuh/pull/1368))
- Disconnect manager nodes in cluster if no keep alive is received or sent during two minutes. ([#1482](https://github.com/wazuh/wazuh/pull/1482))
- API requests are forwarded to the proper manager node in cluster. ([#885](https://github.com/wazuh/wazuh/pull/885))
- Centralized configuration pushed from manager overwrite the configuration of directories that exist with the same path in ossec.conf. ([#1740](https://github.com/wazuh/wazuh/pull/1740))

### Changed

- Refactor Python framework code to standardize database requests and support queries. ([#921](https://github.com/wazuh/wazuh/pull/921))
- Replaced the `execvpe` function by `execvp` for the Wazuh modules. ([#1207](https://github.com/wazuh/wazuh/pull/1207))
- Avoid the use of reference ID in Syscollector network tables. ([#1315](https://github.com/wazuh/wazuh/pull/1315))
- Make Syscheck case insensitive on Windows agent. ([#1349](https://github.com/wazuh/wazuh/pull/1349))
- Avoid conflicts with the size of time_t variable in wazuh-db. ([#1366](https://github.com/wazuh/wazuh/pull/1366))
- Osquery integration updated: ([#1369](https://github.com/wazuh/wazuh/pull/1369))
  - Nest the result data into a "osquery" object.
  - Extract the pack name into a new field.
  - Include the query name in the alert description.
  - Minor fixes.
- Increased AWS S3 database entry limit to 5000 to prevent reprocessing repeated events. ([#1391](https://github.com/wazuh/wazuh/pull/1391))
- Increased the limit of concurrent agent requests: 1024 by default, configurable up to 4096. ([#1473](https://github.com/wazuh/wazuh/pull/1473))
- Change the default vulnerability-detector interval from 1 to 5 minutes. ([#1729](https://github.com/wazuh/wazuh/pull/1729))
- Port the UNIX version of Auth client (_agent_auth_) to the Windows agent. ([#1790](https://github.com/wazuh/wazuh/pull/1790))
  - Support of TLSv1.2 through embedded OpenSSL library.
  - Support of SSL certificates for agent and manager validation.
  - Unify Auth client option set.

### Fixed

- Fixed email_alerts configuration for multiple recipients. ([#1193](https://github.com/wazuh/wazuh/pull/1193))
- Fixed manager stopping when no command timeout is allowed. ([#1194](https://github.com/wazuh/wazuh/pull/1194))
- Fixed getting RAM memory information from mac OS X and FreeBSD agents. ([#1203](https://github.com/wazuh/wazuh/pull/1203))
- Fixed mandatory configuration labels check. ([#1208](https://github.com/wazuh/wazuh/pull/1208))
- Fix 0 value at check options from Syscheck. ([1209](https://github.com/wazuh/wazuh/pull/1209))
- Fix bug in whodata field extraction for Windows. ([#1233](https://github.com/wazuh/wazuh/issues/1233))
- Fix stack overflow when monitoring deep files. ([#1239](https://github.com/wazuh/wazuh/pull/1239))
- Fix typo in whodata alerts. ([#1242](https://github.com/wazuh/wazuh/issues/1242))
- Fix bug when running quick commands with timeout of 1 second. ([#1259](https://github.com/wazuh/wazuh/pull/1259))
- Prevent offline agents from generating vulnerability-detector alerts. ([#1292](https://github.com/wazuh/wazuh/pull/1292))
- Fix empty SHA256 of rotated alerts and log files. ([#1308](https://github.com/wazuh/wazuh/pull/1308))
- Fixed service startup on error. ([#1324](https://github.com/wazuh/wazuh/pull/1324))
- Set connection timeout for Auth server ([#1336](https://github.com/wazuh/wazuh/pull/1336))
- Fix the cleaning of the temporary folder. ([#1361](https://github.com/wazuh/wazuh/pull/1361))
- Fix check_mtime and check_inode views in Syscheck alerts. ([#1364](https://github.com/wazuh/wazuh/pull/1364))
- Fixed the reading of the destination address and type for PPP interfaces. ([#1405](https://github.com/wazuh/wazuh/pull/1405))
- Fixed a memory bug in regex when getting empty strings. ([#1430](https://github.com/wazuh/wazuh/pull/1430))
- Fixed report_changes with a big ammount of files. ([#1465](https://github.com/wazuh/wazuh/pull/1465))
- Prevent Logcollector from null-terminating socket output messages. ([#1547](https://github.com/wazuh/wazuh/pull/1547))
- Fix timeout overtaken message using infinite timeout. ([#1604](https://github.com/wazuh/wazuh/pull/1604))
- Prevent service from crashing if _global.db_ is not created. ([#1485](https://github.com/wazuh/wazuh/pull/1485))
- Set new agent.conf template when creating new groups. ([#1647](https://github.com/wazuh/wazuh/pull/1647))
- Fix bug in Wazuh Modules that tried to delete PID folders if a subprocess call failed. ([#1836](https://github.com/wazuh/wazuh/pull/1836))


## [v3.6.1] 2018-09-07

### Fixed

- Fixed ID field length limit in JSON alerts, by @gandalfn. ([#1052](https://github.com/wazuh/wazuh/pull/1052))
- Fix segmentation fault when the agent version is empty in Vulnerability Detector. ([#1191](https://github.com/wazuh/wazuh/pull/1191))
- Fix bug that removes file extensions in rootcheck. ([#1197](https://github.com/wazuh/wazuh/pull/1197))
- Fixed incoherence in Client Syslog between plain-text and JSON alert input in `<location>` filter option. ([#1204](https://github.com/wazuh/wazuh/pull/1204))
- Fixed missing agent name and invalid predecoded hostname in JSON alerts. ([#1213](https://github.com/wazuh/wazuh/pull/1213))
- Fixed invalid location string in plain-text alerts. ([#1213](https://github.com/wazuh/wazuh/pull/1213))
- Fixed default stack size in threads on AIX and HP-UX. ([#1215](https://github.com/wazuh/wazuh/pull/1215))
- Fix socket error during agent restart due to daemon start/stop order. ([#1221](https://github.com/wazuh/wazuh/issues/1221))
- Fix bug when checking agent configuration in logcollector. ([#1225](https://github.com/wazuh/wazuh/issues/1225))
- Fix bug in folder recursion limit count in FIM real-time mode. ([#1226](https://github.com/wazuh/wazuh/issues/1226))
- Fixed errors when parsing AWS events in Elasticsearch. ([#1229](https://github.com/wazuh/wazuh/issues/1229))
- Fix bug when launching osquery from Wazuh. ([#1230](https://github.com/wazuh/wazuh/issues/1230))


## [v3.6.0] - 2018-08-29

### Added

- Add rescanning of expanded files with wildcards in logcollector ([#332](https://github.com/wazuh/wazuh/pull/332))
- Parallelization of logcollector ([#627](https://github.com/wazuh/wazuh/pull/672))
  - Now the input of logcollector is multithreaded, reading logs in parallel.
  - A thread is created for each type of output socket.
  - Periodically rescan of new files.
  - New options have been added to internal_options.conf file.
- Added statistical functions to remoted. ([#682](https://github.com/wazuh/wazuh/pull/682))
- Rootcheck and Syscheck (FIM) will run independently. ([#991](https://github.com/wazuh/wazuh/pull/991))
- Add hash validation for binaries executed by the wodle `command`. ([#1027](https://github.com/wazuh/wazuh/pull/1027))
- Added a recursion level option to Syscheck to set the directory scanning depth. ([#1081](https://github.com/wazuh/wazuh/pull/1081))
- Added inactive agent filtering option to agent_control, syscheck_control and rootcheck control_tools. ([#1088](https://github.com/wazuh/wazuh/pull/1088))
- Added custom tags to FIM directories and registries. ([#1096](https://github.com/wazuh/wazuh/pull/1096))
- Improved AWS CloudTrail wodle by @UranusBytes ([#913](https://github.com/wazuh/wazuh/pull/913) & [#1105](https://github.com/wazuh/wazuh/pull/1105)).
- Added support to process logs from more AWS services: Guard Duty, IAM, Inspector, Macie and VPC. ([#1131](https://github.com/wazuh/wazuh/pull/1131)).
- Create script for blocking IP's using netsh-advfirewall. ([#1172](https://github.com/wazuh/wazuh/pull/1172)).

### Changed

- The maximum log length has been extended up to 64 KiB. ([#411](https://github.com/wazuh/wazuh/pull/411))
- Changed logcollector analysis message order. ([#675](https://github.com/wazuh/wazuh/pull/675))
- Let hostname field be the name of the agent, without the location part. ([#1080](https://github.com/wazuh/wazuh/pull/1080))
- The internal option `syscheck.max_depth` has been renamed to `syscheck.default_max_depth`. ([#1081](https://github.com/wazuh/wazuh/pull/1081))
- Show warning message when configuring vulnerability-detector for an agent. ([#1130](https://github.com/wazuh/wazuh/pull/1130))
- Increase the minimum waiting time from 0 to 1 seconds in Vulnerability-Detector. ([#1132](https://github.com/wazuh/wazuh/pull/1132))
- Prevent Windows agent from not loading the configuration if an AWS module block is found. ([#1143](https://github.com/wazuh/wazuh/pull/1143))
- Set the timeout to consider an agent disconnected to 1800 seconds in the framework. ([#1155](https://github.com/wazuh/wazuh/pull/1155))

### Fixed

- Fix agent ID zero-padding in alerts coming from Vulnerability Detector. ([#1083](https://github.com/wazuh/wazuh/pull/1083))
- Fix multiple warnings when agent is offline. ([#1086](https://github.com/wazuh/wazuh/pull/1086))
- Fixed minor issues in the Makefile and the sources installer on HP-UX, Solaris on SPARC and AIX systems. ([#1089](https://github.com/wazuh/wazuh/pull/1089))
- Fixed SHA256 changes messages in alerts when it is disabled. ([#1100](https://github.com/wazuh/wazuh/pull/1100))
- Fixed empty configuration blocks for Wazuh modules. ([#1101](https://github.com/wazuh/wazuh/pull/1101))
- Fix broken pipe error in Wazuh DB by Vulnerability Detector. ([#1111](https://github.com/wazuh/wazuh/pull/1111))
- Restored firewall-drop AR script for Linux. ([#1114](https://github.com/wazuh/wazuh/pull/1114))
- Fix unknown severity in Red Hat systems. ([#1118](https://github.com/wazuh/wazuh/pull/1118))
- Added a building flag to compile the SQLite library externally for the API. ([#1119](https://github.com/wazuh/wazuh/issues/1119))
- Fixed variables length when storing RAM information by Syscollector. ([#1124](https://github.com/wazuh/wazuh/pull/1124))
- Fix Red Hat vulnerability database update. ([#1127](https://github.com/wazuh/wazuh/pull/1127))
- Fix allowing more than one wodle command. ([#1128](https://github.com/wazuh/wazuh/pull/1128))
- Fixed `after_regex` offset for the decoding algorithm. ([#1129](https://github.com/wazuh/wazuh/pull/1129))
- Prevents some vulnerabilities from not being checked for Debian. ([#1166](https://github.com/wazuh/wazuh/pull/1166))
- Fixed legacy configuration for `vulnerability-detector`. ([#1174](https://github.com/wazuh/wazuh/pull/1174))
- Fix active-response scripts installation for Windows. ([#1182](https://github.com/wazuh/wazuh/pull/1182)).
- Fixed `open-scap` deadlock when opening large files. ([#1206](https://github.com/wazuh/wazuh/pull/1206)). Thanks to @juergenc for detecting this issue.


### Removed

- The 'T' multiplier has been removed from option `max_output_size`. ([#1089](https://github.com/wazuh/wazuh/pull/1089))


## [v3.5.0] 2018-08-10

### Added

- Improved configuration of OVAL updates. ([#416](https://github.com/wazuh/wazuh/pull/416))
- Added selective agent software request in vulnerability-detector. ([#404](https://github.com/wazuh/wazuh/pull/404))
- Get Linux packages inventory natively. ([#441](https://github.com/wazuh/wazuh/pull/441))
- Get Windows packages inventory natively. ([#471](https://github.com/wazuh/wazuh/pull/471))
- Supporting AES encryption for manager and agent. ([#448](https://github.com/wazuh/wazuh/pull/448))
- Added Debian and Ubuntu 18 support in vulnerability-detector. ([#470](https://github.com/wazuh/wazuh/pull/470))
- Added Rids Synchronization. ([#459](https://github.com/wazuh/wazuh/pull/459))
- Added option for setting the group that the agent belongs to when registering it with authd ([#460](https://github.com/wazuh/wazuh/pull/460))
- Added option for setting the source IP when the agent registers with authd ([#460](https://github.com/wazuh/wazuh/pull/460))
- Added option to force the vulnerability detection in unsupported OS. ([#462](https://github.com/wazuh/wazuh/pull/462))
- Get network inventory natively. ([#546](https://github.com/wazuh/wazuh/pull/546))
- Add arch check for Red Hat's OVAL in vulnerability-detector. ([#625](https://github.com/wazuh/wazuh/pull/625))
- Integration with Osquery. ([#627](https://github.com/wazuh/wazuh/pull/627))
    - Enrich osquery configuration with pack files aggregation and agent labels as decorators.
    - Launch osquery daemon in background.
    - Monitor results file and send them to the manager.
    - New option in rules `<location>` to filter events by osquery.
    - Support folders in shared configuration. This makes easy to send pack folders to agents.
    - Basic ruleset for osquery events and daemon logs.
- Boost Remoted performance with multithreading. ([#649](https://github.com/wazuh/wazuh/pull/649))
    - Up to 16 parallel threads to decrypt messages from agents.
    - Limit the frequency of agent keys reloading.
    - Message input buffer in Analysisd to prevent control messages starvation in Remoted.
- Module to download shared files for agent groups dinamically. ([#519](https://github.com/wazuh/wazuh/pull/519))
    - Added group creation for files.yml if the group does not exist. ([#1010](https://github.com/wazuh/wazuh/pull/1010))
- Added scheduling options to CIS-CAT integration. ([#586](https://github.com/wazuh/wazuh/pull/586))
- Option to download the wpk using http in `agent_upgrade`. ([#798](https://github.com/wazuh/wazuh/pull/798))
- Add `172.0.0.1` as manager IP when creating `global.db`. ([#970](https://github.com/wazuh/wazuh/pull/970))
- New requests for Syscollector. ([#728](https://github.com/wazuh/wazuh/pull/728))
- `cluster_control` shows an error if the status does not exist. ([#1002](https://github.com/wazuh/wazuh/pull/1002))
- Get Windows hardware inventory natively. ([#831](https://github.com/wazuh/wazuh/pull/831))
- Get processes and ports inventory by the Syscollector module.
- Added an integration with Kaspersky Endpoint Security for Linux via Active Response. ([#1056](https://github.com/wazuh/wazuh/pull/1056))

### Changed

- Add default value for option -x in agent_control tool.
- External libraries moved to an external repository.
- Ignore OverlayFS directories on Rootcheck system scan.
- Extracts agent's OS from the database instead of the agent-info.
- Increases the maximum size of XML parser to 20KB.
- Extract CVE instead of RHSA codes into vulnerability-detector. ([#549](https://github.com/wazuh/wazuh/pull/549))
- Store CIS-CAT results into Wazuh DB. ([#568](https://github.com/wazuh/wazuh/pull/568))
- Add profile information to CIS-CAT reports. ([#658](https://github.com/wazuh/wazuh/pull/658))
- Merge external libraries into a unique shared library. ([#620](https://github.com/wazuh/wazuh/pull/620))
- Cluster log rotation: set correct permissions and store rotations in /logs/ossec. ([#667](https://github.com/wazuh/wazuh/pull/667))
- `Distinct` requests don't allow `limit=0` or `limit>maximun_limit`. ([#1007](https://github.com/wazuh/wazuh/pull/1007))
- Deprecated arguments -i, -F and -r for Authd. ([#1013](https://github.com/wazuh/wazuh/pull/1013))
- Increase the internal memory for real-time from 12 KiB to 64 KiB. ([#1062](https://github.com/wazuh/wazuh/pull/1062))

### Fixed

- Fixed invalid alerts reported by Syscollector when the event contains the word "error". ([#461](https://github.com/wazuh/wazuh/pull/461))
- Silenced Vuls integration starting and ending alerts. ([#541](https://github.com/wazuh/wazuh/pull/541))
- Fix problem comparing releases of ubuntu packages. ([#556](https://github.com/wazuh/wazuh/pull/556))
- Windows delete pending active-responses before reset agent. ([#563](https://github.com/wazuh/wazuh/pull/563))
- Fix bug in Rootcheck for Windows that searches for keys in 32-bit mode only. ([#566](https://github.com/wazuh/wazuh/pull/566))
- Alert when unmerge files fails on agent. ([#731](https://github.com/wazuh/wazuh/pull/731))
- Fixed bugs reading logs in framework. ([#856](https://github.com/wazuh/wazuh/pull/856))
- Ignore uppercase and lowercase sorting an array in framework. ([#814](https://github.com/wazuh/wazuh/pull/814))
- Cluster: reject connection if the client node has a different cluster name. ([#892](https://github.com/wazuh/wazuh/pull/892))
- Prevent `the JSON object must be str, not 'bytes'` error. ([#997](https://github.com/wazuh/wazuh/pull/997))
- Fix long sleep times in vulnerability detector.
- Fix inconsistency in the alerts format for the manager in vulnerability-detector.
- Fix bug when processing the packages in vulnerability-detector.
- Prevent to process Syscollector events by the JSON decoder. ([#674](https://github.com/wazuh/wazuh/pull/674))
- Stop Syscollector data storage into Wazuh DB when an error appears. ([#674](https://github.com/wazuh/wazuh/pull/674))
- Fix bug in Syscheck that reported false positive about removed files. ([#1044](https://github.com/wazuh/wazuh/pull/1044))
- Fix bug in Syscheck that misinterpreted no_diff option. ([#1046](https://github.com/wazuh/wazuh/pull/1046))
- Fixes in file integrity monitoring for Windows. ([#1062](https://github.com/wazuh/wazuh/pull/1062))
  - Fix Windows agent crash if FIM fails to extract the file owner.
  - Prevent FIM real-time mode on Windows from stopping if the internal buffer gets overflowed.
- Prevent large logs from flooding the log file by Logcollector. ([#1067](https://github.com/wazuh/wazuh/pull/1067))
- Fix allowing more than one wodle command and compute command timeout when ignore_output is enabled. ([#1102](https://github.com/wazuh/wazuh/pull/1102))

### Removed

- Deleted Lua language support.
- Deleted integration with Vuls. ([#879](https://github.com/wazuh/wazuh/issues/879))
- Deleted agent_list tool, replaced by agent_control. ([ba0265b](https://github.com/wazuh/wazuh/commit/ba0265b6e9e3fed133d60ef2df3450fdf26f7da4#diff-f57f2991a6aa25fe45d8036c51bf8b4d))

## [v3.4.0] 2018-07-24

### Added

- Support for SHA256 checksum in Syscheck (by @arshad01). ([#410](https://github.com/wazuh/wazuh/pull/410))
- Added an internal option for Syscheck to tune the RT alerting delay. ([#434](https://github.com/wazuh/wazuh/pull/434))
- Added two options in the tag <auto_ignore> `frequency` and `timeframe` to hide alerts when they are played several times in a given period of time. ([#857](https://github.com/wazuh/wazuh/pull/857))
- Include who-data in Syscheck for file integrity monitoring. ([#756](https://github.com/wazuh/wazuh/pull/756))
  - Linux Audit setup and monitoring to watch directories configured with who-data.
  - Direct communication with Auditd on Linux to catch who-data related events.
  - Setup of SACL for monitored directories on Windows.
  - Windows Audit events monitoring through Windows Event Channel.
  - Auto setup of audit configuration and reset when the agent quits.
- Syscheck in frequency time show alerts from deleted files. ([#857](https://github.com/wazuh/wazuh/pull/857))
- Added an option `target` to customize output format per-target in Logcollector. ([#863](https://github.com/wazuh/wazuh/pull/863))
- New option for the JSON decoder to choose the treatment of NULL values. ([#677](https://github.com/wazuh/wazuh/pull/677))
- Remove old snapshot files for FIM. ([#872](https://github.com/wazuh/wazuh/pull/872))
- Distinct operation in agents. ([#920](https://github.com/wazuh/wazuh/pull/920))
- Added support for unified WPK. ([#865](https://github.com/wazuh/wazuh/pull/865))
- Added missing debug options for modules in the internal options file. ([#901](https://github.com/wazuh/wazuh/pull/901))
- Added recursion limits when reading directories. ([#947](https://github.com/wazuh/wazuh/pull/947))

### Changed

- Renamed cluster _client_ node type to ___worker___ ([#850](https://github.com/wazuh/wazuh/pull/850)).
- Changed a descriptive message in the alert showing what attributes changed. ([#857](https://github.com/wazuh/wazuh/pull/857))
- Change visualization of Syscheck alerts. ([#857](https://github.com/wazuh/wazuh/pull/857))
- Add all the available fields in the Syscheck messages from the Wazuh configuration files. ([#857](https://github.com/wazuh/wazuh/pull/857))
- Now the no_full_log option only affects JSON alerts. ([#881](https://github.com/wazuh/wazuh/pull/881))
- Delete temporary files when stopping Wazuh. ([#732](https://github.com/wazuh/wazuh/pull/732))
- Send OpenSCAP checks results to a FIFO queue instead of temporary files. ([#732](https://github.com/wazuh/wazuh/pull/732))
- Default behavior when starting Syscheck and Rootcheck components. ([#829](https://github.com/wazuh/wazuh/pull/829))
  - They are disabled if not appear in the configuration.
  - They can be set up as empty blocks in the configuration, applying their default values.
  - Improvements of error and information messages when they start.
- Improve output of `DELETE/agents` when no agents were removed. ([#868](https://github.com/wazuh/wazuh/pull/868))
- Include the file owner SID in Syscheck alerts.
- Change no previous checksum error message to information log. ([#897](https://github.com/wazuh/wazuh/pull/897))
- Changed default Syscheck scan speed: 100 files per second. ([#975](https://github.com/wazuh/wazuh/pull/975))
- Show network protocol used by the agent when connecting to the manager. ([#980](https://github.com/wazuh/wazuh/pull/980))

### Fixed

- Syscheck RT process granularized to make frequency option more accurate. ([#434](https://github.com/wazuh/wazuh/pull/434))
- Fixed registry_ignore problem on Syscheck for Windows when arch="both" was used. ([#525](https://github.com/wazuh/wazuh/pull/525))
- Allow more than 256 directories in real-time for Windows agent using recursive watchers. ([#540](https://github.com/wazuh/wazuh/pull/540))
- Fix weird behavior in Syscheck when a modified file returns back to its first state. ([#434](https://github.com/wazuh/wazuh/pull/434))
- Replace hash value xxx (not enabled) for n/a if the hash couldn't be calculated. ([#857](https://github.com/wazuh/wazuh/pull/857))
- Do not report uid, gid or gname on Windows (avoid user=0). ([#857](https://github.com/wazuh/wazuh/pull/857))
- Several fixes generating sha256 hash. ([#857](https://github.com/wazuh/wazuh/pull/857))
- Fixed the option report_changes configuration. ([#857](https://github.com/wazuh/wazuh/pull/857))
- Fixed the 'report_changes' configuration when 'sha1' option is not set. ([#857](https://github.com/wazuh/wazuh/pull/857))
- Fix memory leak reading logcollector config. ([#884](https://github.com/wazuh/wazuh/pull/884))
- Fixed crash in Slack integration for alerts that don't have full log. ([#880](https://github.com/wazuh/wazuh/pull/880))
- Fixed active-responses.log definition path on Windows configuration. ([#739](https://github.com/wazuh/wazuh/pull/739))
- Added warning message when updating Syscheck/Rootcheck database to restart the manager. ([#817](https://github.com/wazuh/wazuh/pull/817))
- Fix PID file creation checking. ([#822](https://github.com/wazuh/wazuh/pull/822))
  - Check that the PID file was created and written.
  - This would prevent service from running multiple processes of the same daemon.
- Fix reading of Windows platform for 64 bits systems. ([#832](https://github.com/wazuh/wazuh/pull/832))
- Fixed Syslog output parser when reading the timestamp from the alerts in JSON format. ([#843](https://github.com/wazuh/wazuh/pull/843))
- Fixed filter for `gpg-pubkey` packages in Syscollector. ([#847](https://github.com/wazuh/wazuh/pull/847))
- Fixed bug in configuration when reading the `repeated_offenders` option in Active Response. ([#873](https://github.com/wazuh/wazuh/pull/873))
- Fixed variables parser when loading rules. ([#855](https://github.com/wazuh/wazuh/pull/855))
- Fixed parser files names in the Rootcheck scan. ([#840](https://github.com/wazuh/wazuh/pull/840))
- Removed frequency offset in rules. ([#827](https://github.com/wazuh/wazuh/pull/827)).
- Fix memory leak reading logcollector config. ([#884](https://github.com/wazuh/wazuh/pull/884))
- Fixed sort agents by status in `GET/agents` API request. ([#810](https://github.com/wazuh/wazuh/pull/810))
- Added exception when no agents are selected to restart. ([#870](https://github.com/wazuh/wazuh/pull/870))
- Prevent files from remaining open in the cluster. ([#874](https://github.com/wazuh/wazuh/pull/874))
- Fix network unreachable error when cluster starts. ([#800](https://github.com/wazuh/wazuh/pull/800))
- Fix empty rules and decoders file check. ([#887](https://github.com/wazuh/wazuh/pull/887))
- Prevent to access an unexisting hash table from 'whodata' thread. ([#911](https://github.com/wazuh/wazuh/pull/911))
- Fix CA verification with more than one 'ca_store' definitions. ([#927](https://github.com/wazuh/wazuh/pull/927))
- Fix error in syscollector API calls when Wazuh is installed in a directory different than `/var/ossec`. ([#942](https://github.com/wazuh/wazuh/pull/942)).
- Fix error in CentOS 6 when `wazuh-cluster` is disabled. ([#944](https://github.com/wazuh/wazuh/pull/944)).
- Fix Remoted connection failed warning in TCP mode due to timeout. ([#958](https://github.com/wazuh/wazuh/pull/958))
- Fix option 'rule_id' in syslog client. ([#979](https://github.com/wazuh/wazuh/pull/979))
- Fixed bug in legacy agent's server options that prevented it from setting port and protocol.

## [v3.3.1] 2018-06-18

### Added

- Added `total_affected_agents` and `total_failed_ids` to the `DELETE/agents` API request. ([#795](https://github.com/wazuh/wazuh/pull/795))

### Changed

- Management of empty blocks in the configuration files. ([#781](https://github.com/wazuh/wazuh/pull/781))
- Verify WPK with Wazuh CA by default. ([#799](https://github.com/wazuh/wazuh/pull/799))

### Fixed

- Windows prevents agent from renaming file. ([#773](https://github.com/wazuh/wazuh/pull/773))
- Fix manager-agent version comparison in remote upgrades. ([#765](https://github.com/wazuh/wazuh/pull/765))
- Fix log flooding when restarting agent while the merged file is being receiving. ([#788](https://github.com/wazuh/wazuh/pull/788))
- Fix issue when overwriting rotated logs in Windows agents. ([#776](https://github.com/wazuh/wazuh/pull/776))
- Prevent OpenSCAP module from running on Windows agents (incompatible). ([#777](https://github.com/wazuh/wazuh/pull/777))
- Fix issue in file changes report for FIM on Linux when a directory contains a backslash. ([#775](https://github.com/wazuh/wazuh/pull/775))
- Fixed missing `minor` field in agent data managed by the framework. ([#771](https://github.com/wazuh/wazuh/pull/771))
- Fixed missing `build` and `key` fields in agent data managed by the framework. ([#802](https://github.com/wazuh/wazuh/pull/802))
- Fixed several bugs in upgrade agents ([#784](https://github.com/wazuh/wazuh/pull/784)):
    - Error upgrading an agent with status `Never Connected`.
    - Fixed API support.
    - Sockets were not closing properly.
- Cluster exits showing an error when an error occurs. ([#790](https://github.com/wazuh/wazuh/pull/790))
- Fixed bug when cluster control or API cannot request the list of nodes to the master. ([#762](https://github.com/wazuh/wazuh/pull/762))
- Fixed bug when the `agent.conf` contains an unrecognized module. ([#796](https://github.com/wazuh/wazuh/pull/796))
- Alert when unmerge files fails on agent. ([#731](https://github.com/wazuh/wazuh/pull/731))
- Fix invalid memory access when parsing ruleset configuration. ([#787](https://github.com/wazuh/wazuh/pull/787))
- Check version of python in cluster control. ([#760](https://github.com/wazuh/wazuh/pull/760))
- Removed duplicated log message when Rootcheck is disabled. ([#783](https://github.com/wazuh/wazuh/pull/783))
- Avoid infinite attempts to download CVE databases when it fails. ([#792](https://github.com/wazuh/wazuh/pull/792))


## [v3.3.0] 2018-06-06

### Added

- Supporting multiple socket output in Logcollector. ([#395](https://github.com/wazuh/wazuh/pull/395))
- Allow inserting static field parameters in rule comments. ([#397](https://github.com/wazuh/wazuh/pull/397))
- Added an output format option for Logcollector to build custom logs. ([#423](https://github.com/wazuh/wazuh/pull/423))
- Included millisecond timing in timestamp to JSON events. ([#467](https://github.com/wazuh/wazuh/pull/467))
- Added an option in Analysisd to set input event offset for plugin decoders. ([#512](https://github.com/wazuh/wazuh/pull/512))
- Allow decoders mix plugin and multiregex children. ([#602](https://github.com/wazuh/wazuh/pull/602))
- Added the option to filter by any field in `get_agents_overview`, `get_agent_group` and `get_agents_without_group` functions of the Python framework. ([#743](https://github.com/wazuh/wazuh/pull/743))

### Changed

- Add default value for option -x in agent_upgrade tool.
- Changed output of agents in cluster control. ([#741](https://github.com/wazuh/wazuh/pull/741))

### Fixed

- Fix bug in Logcollector when removing duplicate localfiles. ([#402](https://github.com/wazuh/wazuh/pull/402))
- Fix memory error in Logcollector when using wildcards.
- Prevent command injection in Agentless daemon. ([#600](https://github.com/wazuh/wazuh/pull/600))
- Fixed bug getting the agents in cluster control. ([#741](https://github.com/wazuh/wazuh/pull/741))
- Prevent Logcollector from reporting an error when a path with wildcards matches no files.
- Fixes the feature to group with the option multi-line. ([#754](https://github.com/wazuh/wazuh/pull/754))


## [v3.2.4] 2018-06-01

### Fixed
- Fixed segmentation fault in maild when `<queue-size>` is included in the global configuration.
- Fixed bug in Framework when retrieving mangers logs. ([#644](https://github.com/wazuh/wazuh/pull/644))
- Fixed bug in clusterd to prevent the synchronization of `.swp` files. ([#694](https://github.com/wazuh/wazuh/pull/694))
- Fixed bug in Framework parsing agent configuration. ([#681](https://github.com/wazuh/wazuh/pull/681))
- Fixed several bugs using python3 with the Python framework. ([#701](https://github.com/wazuh/wazuh/pull/701))


## [v3.2.3] 2018-05-28

### Added

- New internal option to enable merged file creation by Remoted. ([#603](https://github.com/wazuh/wazuh/pull/603))
- Created alert item for GDPR and GPG13. ([#608](https://github.com/wazuh/wazuh/pull/608))
- Add support for Amazon Linux in vulnerability-detector.
- Created an input queue for Analysisd to prevent Remoted starvation. ([#661](https://github.com/wazuh/wazuh/pull/661))

### Changed

- Set default agent limit to 14.000 and file descriptor limit to 65.536 per process. ([#624](https://github.com/wazuh/wazuh/pull/624))
- Cluster improvements.
    - New protocol for communications.
    - Inverted communication flow: clients start communications with the master.
    - Just the master address is required in the `<nodes>` list configuration.
    - Improved synchronization algorithm.
    - Reduced the number of processes to one: `wazuh-clusterd`.
- Cluster control tool improvements: outputs are the same regardless of node type.
- The default input queue for remote events has been increased to 131072 events. ([#660](https://github.com/wazuh/wazuh/pull/660))
- Disconnected agents will no longer report vulnerabilities. ([#666](https://github.com/wazuh/wazuh/pull/666))

### Fixed

- Fixed agent wait condition and improve logging messages. ([#550](https://github.com/wazuh/wazuh/pull/550))
- Fix race condition in settings load time by Windows agent. ([#551](https://github.com/wazuh/wazuh/pull/551))
- Fix bug in Authd that prevented it from deleting agent-info files when removing agents.
- Fix bug in ruleset that did not overwrite the `<info>` option. ([#584](https://github.com/wazuh/wazuh/issues/584))
- Fixed bad file descriptor error in Wazuh DB ([#588](https://github.com/wazuh/wazuh/issues/588))
- Fixed unpredictable file sorting when creating merged files. ([#599](https://github.com/wazuh/wazuh/issues/599))
- Fixed race condition in Remoted when closing connections.
- Fix epoch check in vulnerability-detector.
- Fixed hash sum in logs rotation. ([#636](https://github.com/wazuh/wazuh/issues/636))
- Fixed cluster CPU usage.
- Fixed invalid deletion of agent timestamp entries. ([#639](https://github.com/wazuh/wazuh/issues/639))
- Fixed segmentation fault in logcollector when multi-line is applied to a remote configuration. ([#641](https://github.com/wazuh/wazuh/pull/641))
- Fixed issue in Syscheck that may leave the process running if the agent is stopped quickly. ([#671](https://github.com/wazuh/wazuh/pull/671))

### Removed

- Removed cluster database and internal cluster daemon.


## [v3.2.2] 2018-05-07

### Added

- Created an input queue for Remoted to prevent agent connection starvation. ([#509](https://github.com/wazuh/wazuh/pull/509))

### Changed

- Updated Slack integration. ([#443](https://github.com/wazuh/wazuh/pull/443))
- Increased connection timeout for remote upgrades. ([#480](https://github.com/wazuh/wazuh/pull/480))
- Vulnerability-detector does not stop agents detection if it fails to find the software for one of them.
- Improve the version comparator algorithm in vulnerability-detector. ([#508](https://github.com/wazuh/wazuh/pull/508))

### Fixed

- Fixed bug in labels settings parser that may make Agentd or Logcollector crash.
- Fixed issue when setting multiple `<server-ip>` stanzas in versions 3.0 - 3.2.1. ([#433](https://github.com/wazuh/wazuh/pull/433))
- Fixed bug when socket database messages are not sent correctly. ([#435](https://github.com/wazuh/wazuh/pull/435))
- Fixed unexpected stop in the sources installer when overwriting a previous corrupt installation.
- Added a synchronization timeout in the cluster to prevent it from blocking ([#447](https://github.com/wazuh/wazuh/pull/447))
- Fixed issue in CSyslogd when filtering by rule group. ([#446](https://github.com/wazuh/wazuh/pull/446))
- Fixed error on DB daemon when parsing rules with options introduced in version 3.0.0.
- Fixed unrecognizable characters error in Windows version name. ([#478](https://github.com/wazuh/wazuh/pull/478))
- Fix Authd client in old versions of Windows ([#479](https://github.com/wazuh/wazuh/pull/479))
- Cluster's socket management improved to use persistent connections ([#481](https://github.com/wazuh/wazuh/pull/481))
- Fix memory corruption in Syscollector decoder and memory leaks in Vulnerability Detector. ([#482](https://github.com/wazuh/wazuh/pull/482))
- Fixed memory corruption in Wazuh DB autoclosing procedure.
- Fixed dangling db files at DB Sync module folder. ([#489](https://github.com/wazuh/wazuh/pull/489))
- Fixed agent group file deletion when using Authd.
- Fix memory leak in Maild with JSON input. ([#498](https://github.com/wazuh/wazuh/pull/498))
- Fixed remote command switch option. ([#504](https://github.com/wazuh/wazuh/pull/504))

## [v3.2.1] 2018-03-03

### Added

- Added option in Makefile to disable CIS-CAT module. ([#381](https://github.com/wazuh/wazuh/pull/381))
- Added field `totalItems` to `GET/agents/purgeable/:timeframe` API call. ([#385](https://github.com/wazuh/wazuh/pull/385))

### Changed

- Giving preference to use the selected Java over the default one in CIS-CAT wodle.
- Added delay between message delivery for every module. ([#389](https://github.com/wazuh/wazuh/pull/389))
- Verify all modules for the shared configuration. ([#408](https://github.com/wazuh/wazuh/pull/408))
- Updated OpenSSL library to 1.1.0g.
- Insert agent labels in JSON archives no matter the event matched a rule.
- Support for relative/full/network paths in the CIS-CAT configuration. ([#419](https://github.com/wazuh/wazuh/pull/419))
- Improved cluster control to give more information. ([#421](https://github.com/wazuh/wazuh/pull/421))
- Updated rules for CIS-CAT.
- Removed unnecessary compilation of vulnerability-detector in agents.
- Increased wazuh-modulesd's subprocess pool.
- Improved the agent software recollection by Syscollector.

### Fixed

- Fixed crash in Agentd when testing Syscollector configuration from agent.conf file.
- Fixed duplicate alerts in Vulnerability Detector.
- Fixed compiling issues in Solaris and HP-UX.
- Fixed bug in Framework when listing directories due to permissions issues.
- Fixed error handling in CIS-CAT module. ([#401](https://github.com/wazuh/wazuh/pull/401))
- Fixed some defects reported by Coverity. ([#406](https://github.com/wazuh/wazuh/pull/406))
- Fixed OS name detection in macOS and old Linux distros. ([#409](https://github.com/wazuh/wazuh/pull/409))
- Fixed linked in HP-UX.
- Fixed Red Hat detection in vulnerability-detector.
- Fixed segmentation fault in wazuh-cluster when files path is too long.
- Fixed a bug getting groups and searching by them in `GET/agents` API call. ([#390](https://github.com/wazuh/wazuh/pull/390))
- Several fixes and improvements in cluster.
- Fixed bug in wazuh-db when closing exceeded databases in transaction.
- Fixed bug in vulnerability-detector that discarded valid agents.
- Fixed segmentation fault in Windows agents when getting OS info.
- Fixed memory leaks in vulnerability-detector and CIS-CAT wodle.
- Fixed behavior when working directory is not found in CIS-CAT wodle.

## [v3.2.0] 2018-02-13

### Added
- Added support to synchronize custom rules and decoders in the cluster.([#344](https://github.com/wazuh/wazuh/pull/344))
- Add field `status` to `GET/agents/groups/:group_id` API call.([#338](https://github.com/wazuh/wazuh/pull/338))
- Added support for Windows to CIS-CAT integration module ([#369](https://github.com/wazuh/wazuh/pull/369))
- New Wazuh Module "aws-cloudtrail" fetching logs from S3 bucket. ([#351](https://github.com/wazuh/wazuh/pull/351))
- New Wazuh Module "vulnerability-detector" to detect vulnerabilities in agents and managers.

### Fixed
- Fixed oscap.py to support new versions of OpenSCAP scanner.([#331](https://github.com/wazuh/wazuh/pull/331))
- Fixed timeout bug when the cluster port was closed. ([#343](https://github.com/wazuh/wazuh/pull/343))
- Improve exception handling in `cluster_control`. ([#343](https://github.com/wazuh/wazuh/pull/343))
- Fixed bug in cluster when receive an error response from client. ([#346](https://github.com/wazuh/wazuh/pull/346))
- Fixed bug in framework when the manager is installed in different path than /var/ossec. ([#335](https://github.com/wazuh/wazuh/pull/335))
- Fixed predecoder hostname field in JSON event output.
- Several fixes and improvements in cluster.

## [v3.1.0] 2017-12-22

### Added

- New Wazuh Module "command" for asynchronous command execution.
- New field "predecoder.timestamp" for JSON alerts including timestamp from logs.
- Added reload action to ossec-control in local mode.
- Add duration control of a cluster database synchronization.
- New internal option for agents to switch applying shared configuration.
- Added GeoIP address finding for input logs in JSON format.
- Added alert and archive output files rotation capabilities.
- Added rule option to discard field "firedtimes".
- Added VULS integration for running vulnerability assessments.
- CIS-CAT Wazuh Module to scan CIS policies.

### Changed

- Keepping client.keys file permissions when modifying it.
- Improve Rootcheck formula to select outstanding defects.
- Stop related daemon when disabling components in ossec-control.
- Prevented cluster daemon from starting on RHEL 5 or older.
- Let Syscheck report file changes on first scan.
- Allow requests by node name in cluster_control binary.
- Improved help of cluster_control binary.
- Integrity control of files in the cluster.

### Fixed

- Fixed netstat command in localfile configuration.
- Fixed error when searching agents by ID.
- Fixed syslog format pre-decoder for logs with missing (optional) space after tag.
- Fixed alert ID when plain-text alert output disabled.
- Fixed Monitord freezing when a sendmail-like executable SMTP server is set.
- Fixed validation of Active Response used by agent_control.
- Allow non-ASCII characters in Windows version string.

## [v3.0.0] 2017-12-12

### Added

- Added group property for agents to customize shared files set.
- Send shared files to multiple agents in parallel.
- New decoder plugin for logs in JSON format with dynamic fields definition.
- Brought framework from API to Wazuh project.
- Show merged files MD5 checksum by agent_control and framework.
- New reliable request protocol for manager-agent communication.
- Remote agent upgrades with signed WPK packages.
- Added option for Remoted to prevent it from writing shared merged file.
- Added state for Agentd and Windows agent to notify connection state and metrics.
- Added new JSON log format for local file monitoring.
- Added OpenSCAP SSG datastream content for Ubuntu Trusty Tahr.
- Field "alert_id" in JSON alerts (by Dan Parriott).
- Added support of "any" IP address to OSSEC batch manager (by Jozef Reisinger).
- Added ossec-agent SElinux module (by kreon).
- Added previous output to JSON output (by João Soares).
- Added option for Authd to specify the allowed cipher list (by James Le Cuirot).
- Added option for cipher suites in Authd settings.
- Added internal option for Remoted to set the shared configuration reloading time.
- Auto restart agents when new shared configuration is pushed from the manager.
- Added native support for Systemd.
- Added option to register unlimited agents in Authd.
- New internal option to limit the number of file descriptors in Analysisd and Remoted.
- Added new state "pending" for agents.
- Added internal option to disable real-time DB synchronization.
- Allow multiple manager stanzas in Agentd settings.
- New internal option to limit the receiving time in TCP mode.
- Added manager hostname data to agent information.
- New option for rotating internal logs by size.
- Added internal option to enable or disable daily rotation of internal logs.
- Added command option for Monitord to overwrite 'day_wait' parameter.
- Adding templates and sample alert for Elasticsearch 6.0.
- Added option to enable/disable Authd on install and auto-generate certificates.
- Pack secure TCP messages into a single packet.
- Added function to install SCAP policies depending on OS version.
- Added integration with Virustotal.
- Added timeout option for TCP sockets in Remoted and Agentd.
- Added option to start the manager after installing.
- Added a cluster of managers (`wazuh-clusterd`) and a script to control it (`cluster_control`).

### Changed

- Increased shared file delivery speed when using TCP.
- Increased TCP listening socket backlog.
- Changed Windows agent UI panel to show revision number instead of installation date.
- Group every decoded field (static and dynamic fields) into a data object for JSON alerts.
- Reload shared files by Remoted every 10 minutes.
- Increased string size limit for XML reader to 4096 bytes.
- Updated Logstash configuration and Elasticsearch mappings.
- Changed template fields structure for Kibana dashboards.
- Increased dynamic field limit to 1024, and default to 256.
- Changed agent buffer 'length' parameter to 'queue_size'.
- Changed some Rootcheck error messages to verbose logs.
- Removed unnecessary message by manage_agents advising to restart Wazuh manager.
- Update PF tables Active response (by d31m0).
- Create the users and groups as system users and groups in specs (by Dan Parriott).
- Show descriptive errors when an agent loses the connection using TCP.
- Prevent agents with the same name as the manager host from getting added.
- Changed 'message' field to 'data' for successful agent removing response in Authd API.
- Changed critical error to standard error in Syslog Remoted when no access list has been configured.
- Ignore hidden files in shared folder for merged file.
- Changed agent notification time values: notify time to 1 minute and reconnect time to 5 minutes.
- Prevent data field from being inserted into JSON alerts when it's empty.
- Spelling corrections (by Josh Soref).
- Moved debug messages when updating shared files to level 2.
- Do not create users ossecm or ossecr on agents.
- Upgrade netstat command in Logcollector.
- Prevent Monitord and DB sync module from dealing with agent files on local installations.
- Speed up DB syncing by keeping databases opened and an inotify event queue.
- Merge server's IP and hostname options to one setting.
- Enabled Active Response by default in both Windows and UNIX.
- Make Monitord 'day_wait' internal option affect log rotation.
- Extend Monitord 'day_wait' internal option range.
- Prevent Windows agent from log error when the manager disconnected.
- Improve Active Response filtering options.
- Use init system (Systemd/SysVinit) to restart Wazuh when upgrading.
- Added possibility of filtering agents by manager hostname in the Framework.
- Prevent installer from overwriting agent.conf file.
- Cancel file sending operation when agent socket is closed.
- Clean up agent shared folder before unmerging shared configuration.
- Print descriptive error when request socket refuses connection due to AR disabled.
- Extend Logcollector line burst limit range.
- Fix JSON alert file reloading when the file is rotated.
- Merge IP and Hostname server configuration into "Address" field.
- Improved TCP transmission performance by packing secure messages.

### Fixed

- Fixed wrong queries to get last Syscheck and Rootcheck date.
- Prevent Logcollector keep-alives from being stored on archives.json.
- Fixed length of random message within keep-alives.
- Fixed Windows version detection for Windows 8 and newer.
- Fixed incorrect CIDR writing on client.keys by Authd.
- Fixed missing buffer flush by Analysisd when updating Rootcheck database.
- Stop Wazuh service before removing folder to reinstall.
- Fixed Remoted service for Systemd (by Phil Porada).
- Fixed Administrator account mapping in Windows agent installation (by andrewm0374@gmail.com).
- Fixed MySQL support in dbd (by andrewm0374@gmail.com).
- Fixed incorrect warning when unencrypting messages (by Dan Parriott).
- Fixed Syslog mapping for alerts via Csyslogd (by Dan Parriott).
- Fixed syntax error in the creation of users in Solaris 11.2 (by Pedro Flor).
- Fixed some warnings that appeared when compiling on Fedora 26.
- Fixed permission issue in logs folder.
- Fixed issue in Remoted that prevented it from send shared configuration when it changed.
- Fixed Windows agent compilation compability with CentOS.
- Supporting different case from password prompt in Agentless (by Jesus Fidalgo).
- Fix bad detection of inotify queue overflowed.
- Fix repetitive error when a rule's diff file is empty.
- Fixed log group permission when created by a daemon running as root.
- Prevented Agentd from logging too many errors when restarted while receiving the merged file.
- Prevented Remoted from sending data to disconnected agents in TCP mode.
- Fixed alerts storage in PostgreSQL databases.
- Fixed invalid previous output data in JSON alerts.
- Fixed memory error in modulesd for invalid configurations.
- Fixed default Auth configuration to support custom install directory.
- Fixed directory transversal vulnerability in Active response commands.
- Fixed Active response timeout accuracy.
- Fixed race conditions in concurrent transmissions over TCP.

### Removed

- Removed Picviz support (by Dan Parriott).


## [v2.1.1] - 2017-09-21

### Changed

- Improved errors messages related to TCP connection queue.
- Changed info log about unsupported FS checking in Rootcheck scan to debug messages.
- Prevent Modules daemon from giving critical error when no wodles are enabled.

### Fixed

- Fix endianess incompatibility in agents on SPARC when connecting via TCP.
- Fix bug in Authd that made it crash when removing keys.
- Fix race condition in Remoted when writing logs.
- Avoid repeated errors by Remoted when sending data to a disconnected agent.
- Prevented Monitord from rotating non-existent logs.
- Some fixes to support HP-UX.
- Prevent processes from sending events when TCP connection is lost.
- Fixed output header by Syslog client when reading JSON alerts.
- Fixed bug in Integrator settings parser when reading rules list.

## [v2.1.0] - 2017-08-14

### Added

- Rotate and compress log feature.
- Labeling data for agents to be shown in alerts.
- New 'auth' configuration template.
- Make manage_agents capable of add and remove agents via Authd.
- Implemented XML configuration for Authd.
- Option -F for Authd to force insertion if it finds duplicated name.
- Local auth client to manage agent keys.
- Added OS name and version into global.db.
- Option for logging in JSON format.
- Allow maild to send through a sendmail-like executable (by James Le Cuirot).
- Leaky bucket-like buffer for agents to prevent network flooding.
- Allow Syslog client to read JSON alerts.
- Allow Mail reporter to read JSON alerts.
- Added internal option to tune Rootcheck sleep time.
- Added route-null Active Response script for Windows 2012 (by @CrazyLlama).

### Changed

- Updated SQLite library to 3.19.2.
- Updated zlib to 1.2.11.
- Updated cJSON library to 1.4.7.
- Change some manage_agents option parameters.
- Run Auth in background by default.
- Log classification as debug, info, warning, error and critical.
- Limit number of reads per cycle by Logcollector to prevent log starvation.
- Limit OpenSCAP module's event forwarding speed.
- Increased debug level of repeated Rootcheck messages.
- Send events when OpenSCAP starts and finishes scans.
- Delete PID files when a process exits not due to a signal.
- Change error messages due to SSL handshake failure to debug messages.
- Force group addition on installation for compatibility with LDAP (thanks to Gary Feltham).

### Fixed

- Fixed compiling error on systems with no OpenSSL.
- Fixed compiling warning at manage_agents.
- Fixed ossec-control enable/disable help message.
- Fixed unique aperture of random device on Unix.
- Fixed file sum comparison bug at Syscheck realtime engine. (Thanks to Arshad Khan)
- Close analysisd if alert outputs are disabled for all formats.
- Read Windows version name for versions newer than Windows 8 / Windows Server 2012.
- Fixed error in Analysisd that wrote Syscheck and Rootcheck databases of re-added agents on deleted files.
- Fixed internal option to configure the maximum labels' cache time.
- Fixed Auth password parsing on client side.
- Fix bad agent ID assignation in Authd on i686 architecture.
- Fixed Logcollector misconfiguration in Windows agents.

### Removed

- Remove unused message queue to send alerts from Authd.


## [v2.0.1] - 2017-07-19

### Changed

- Changed random data generator for a secure OS-provided generator.
- Changed Windows installer file name (depending on version).
- Linux distro detection using standard os-release file.
- Changed some URLs to documentation.
- Disable synchronization with SQLite databases for Syscheck by default.
- Minor changes at Rootcheck formatter for JSON alerts.
- Added debugging messages to Integrator logs.
- Show agent ID when possible on logs about incorrectly formatted messages.
- Use default maximum inotify event queue size.
- Show remote IP on encoding format errors when unencrypting messages.
- Remove temporary files created by Syscheck changes reports.
- Remove temporary Syscheck files for changes reporting by Windows installer when upgrading.

### Fixed

- Fixed resource leaks at rules configuration parsing.
- Fixed memory leaks at rules parser.
- Fixed memory leaks at XML decoders parser.
- Fixed TOCTOU condition when removing directories recursively.
- Fixed insecure temporary file creation for old POSIX specifications.
- Fixed missing agentless devices identification at JSON alerts.
- Fixed FIM timestamp and file name issue at SQLite database.
- Fixed cryptographic context acquirement on Windows agents.
- Fixed debug mode for Analysisd.
- Fixed bad exclusion of BTRFS filesystem by Rootcheck.
- Fixed compile errors on macOS.
- Fixed option -V for Integrator.
- Exclude symbolic links to directories when sending FIM diffs (by Stephan Joerrens).
- Fixed daemon list for service reloading at ossec-control.
- Fixed socket waiting issue on Windows agents.
- Fixed PCI_DSS definitions grouping issue at Rootcheck controls.
- Fixed segmentation fault bug when stopping on CentOS 5.
- Fixed compatibility with AIX.
- Fixed race conditions in ossec-control script.
- Fixed compiling issue on Windows.
- Fixed compatibility with Solaris.
- Fixed XML parsing error due to byte stashing issue.
- Fixed false error by Syscheck when creating diff snapshots of empty files.
- Fixed segmentation fault in Authd on i386 platform.
- Fixed agent-auth exit code for controlled server's errors.
- Fixed incorrect OVAL patch results classification.

## [v2.0] - 2017-03-14

### Added

- Wazuh modules manager.
- Wazuh module for OpenSCAP.
- Ruleset for OpenSCAP alerts.
- Kibana dashboards for OpenSCAP.
- Option at agent_control to restart all agents.
- Dynamic fields to rules and decoders.
- Dynamic fields to JSON in alerts/archives.
- CDB list lookup with dynamic fields.
- FTS for dynamic fields.
- Logcollector option to set the frequency of file checking.
- GeoIP support in Alerts (by Scott R Shinn).
- Internal option to output GeoIP data on JSON alerts.
- Matching pattern negation (by Daniel Cid).
- Syscheck and Rootcheck events on SQLite databases.
- Data migration tool to SQLite databases.
- Jenkins QA.
- 64-bit Windows registry keys support.
- Complete FIM data output to JSON and alerts.
- Username, date and inode attributes to FIM events on Unix.
- Username attribute to FIM events on Windows.
- Report changes (FIM file diffs) to Windows agent.
- File diffs to JSON output.
- Elastic mapping updated for new FIM events.
- Title and file fields extracted at Rootcheck alerts.
- Rule description formatting with dynamic field referencing.
- Multithreaded design for Authd server for fast and reliable client dispatching, with key caching and write scheduling.
- Auth registration client for Windows (by Gael Muller).
- Auth password authentication for Windows client.
- New local decoder file by default.
- Show server certificate and key paths at Authd help.
- New option for Authd to verify agent's address.
- Added support for new format at predecoder (by Brad Lhotsky).
- Agentless passlist encoding to Base64.
- New Auditd-specific log format for Logcollector.
- Option for Authd to auto-choose TLS/SSL method.
- Compile option for Authd to make it compatible with legacy OSs.
- Added new templates layout to auto-compose configuration file.
- New wodle for SQLite database syncing (agent information and fim/pm data).
- Added XML settings options to exclude some rules or decoders files.
- Option for agent_control to broadcast AR on all agents.
- Extended FIM event information forwarded by csyslogd (by Sivakumar Nellurandi).
- Report Syscheck's new file events on real time.

### Changed

- Isolated logtest directory from analysisd.
- Remoted informs Analysisd about agent ID.
- Updated Kibana dashboards.
- Syscheck FIM attributes to dynamic fields.
- Force services to exit if PID file creation fails.
- Atomic writing of client.keys through temporary files.
- Disabled remote message ID verification by default.
- Show actual IP on debug message when agents get connected.
- Enforce rules IDs to max 6 digits.
- OSSEC users and group as system (UI-hidden) users (by Dennis Golden).
- Increases Authd connection pool size.
- Use general-purpose version-flexible SSL/TLS methods for Authd registration.
- Enforce minimum 3-digit agent ID format.
- Exclude BTRFS from Rootcheck searching for hidden files inside directories (by Stephan Joerrens).
- Moved OSSEC and Wazuh decoders to one directory.
- Prevent manage_agents from doing invalid actions (such methods for manager at agent).
- Disabled capturing of security events 5145 and 5156 on Windows agent.
- Utilities to rename an agent or change the IP address (by Antonio Querubin).
- Added quiet option for Logtest (by Dan Parriott).
- Output decoder information onto JSON alerts.
- Enable mail notifications by default for server installation.
- Agent control option to restart all agents' Syscheck will also restart manager's Syscheck.
- Make ossec-control to check Authd PID.
- Enforce every rule to contain a description.
- JSON output won't contain field "agentip" if tis value is "any".
- Don't broadcast Active Response messages to disconnected agents.
- Don't print Syscheck logs if it's disabled.
- Set default Syscheck and Rootcheck frequency to 12 hours.
- Generate FIM new file alert by default.
- Added option for Integrator to set the maximum log length.
- JSON output nested objects modelling through dynamic fields.
- Disable TCP for unsupported OSs.
- Show previous log on JSON alert.
- Removed confirmation prompt when importing an agent key successfully.
- Made Syscheck not to ignore files that change more than 3 times by default.
- Enabled JSON output by default.
- Updated default syscheck configuration for Windows agents.
- Limited agent' maximum connection time for notification time.
- Improved client.keys changing detection method by remoted: use date and inode.
- Changed boot service name to Wazuh.
- Active response enabled on Windows agents by default.
- New folder structure for rules and decoders.
- More descriptive logs about syscheck real-time monitoring.
- Renamed XML tags related to rules and decoders inclusion.
- Set default maximum agents to 8000.
- Removed FTS numeric bitfield from JSON output.
- Fixed ID misassignment by manage_agents when the greatest ID exceeds 32512.
- Run Windows Registry Syscheck scan on first stage when scan_on_start enabled.
- Set all Syscheck delay stages to a multiple of internal_options.conf/syscheck.sleep value.
- Changed JSON timestamp format to ISO8601.
- Overwrite @timestamp field from Logstash with the alert timestamp.
- Moved timestamp JSON field to the beginning of the object.
- Changed random data generator for a secure OS-provided generator.

### Fixed

- Logcollector bug that inhibited alerts about file reduction.
- Memory issue on string manipulation at JSON.
- Memory bug at JSON alerts.
- Fixed some CLang warnings.
- Issue on marching OSSEC user on installing.
- Memory leaks at configuration.
- Memory leaks at Analysisd.
- Bugs and memory errors at agent management.
- Mistake with incorrect name for PID file (by Tickhon Clearscale).
- Agent-auth name at messages (it appeared to be the server).
- Avoid Monitord to log errors when the JSON alerts file doesn't exists.
- Agents numbering issue (minimum 3 digits).
- Avoid no-JSON message at agent_control when client.keys empty.
- Memory leaks at manage_agents.
- Authd error messages about connection to queue passed to warning.
- Issue with Authd password checking.
- Avoid ossec-control to use Dash.
- Fixed false error about disconnected agent when trying to send it the shared files.
- Avoid Authd to close when it reaches the maximum concurrency.
- Fixed memory bug at event diff execution.
- Fixed resource leak at file operations.
- Hide help message by useadd and groupadd on OpenBSD.
- Fixed error that made Analysisd to crash if it received a missing FIM file entry.
- Fixed compile warnings at cJSON library.
- Fixed bug that made Active Response to disable all commands if one of them was disabled (by Jason Thomas).
- Fixed segmentation fault at logtest (by Dan Parriott).
- Fixed SQL injection vulnerability at Database.
- Fixed Active Response scripts for Slack and Twitter.
- Fixed potential segmentation fault at file queue operation.
- Fixed file permissions.
- Fixed failing test for Apache 2.2 logs (by Brad Lhotsky).
- Fixed memory error at net test.
- Limit agent waiting time for retrying to connect.
- Fixed compile warnings on i386 architecture.
- Fixed Monitord crash when sending daily report email.
- Fixed script to null route an IP address on Windows Server 2012+ (by Theresa Meiksner).
- Fixed memory leak at Logtest.
- Fixed manager with TCP support on FreeBSD (by Dave Stoddard).
- Fixed Integrator launching at local-mode installation.
- Fixed issue on previous alerts counter (rules with if_matched_sid option).
- Fixed compile and installing error on Solaris.
- Fixed segmentation fault on syscheck when no configuration is defined.
- Fixed bug that prevented manage_agents from removing syscheck/rootcheck database.
- Fixed bug that made agents connected on TCP to hang if they are rejected by the manager.
- Fixed segmentation fault on remoted due to race condition on managing keystore.
- Fixed data lossing at remoted when reloading keystore.
- Fixed compile issue on MacOS.
- Fixed version reading at ruleset updater.
- Fixed detection of BSD.
- Fixed memory leak (by Byron Golden).
- Fixed misinterpretation of octal permissions given by Agentless (by Stephan Leemburg).
- Fixed mistake incorrect openssl flag at Makefile (by Stephan Leemburg).
- Silence Slack integration transmission messages (by Dan Parriott).
- Fixed OpenSUSE Systemd misconfiguration (By Stephan Joerrens).
- Fixed case issue on JSON output for Rootcheck alerts.
- Fixed potential issue on duplicated agent ID detection.
- Fixed issue when creating agent backups.
- Fixed hanging problem on Windows Auth client when negotiation issues.
- Fixed bug at ossec-remoted that mismatched agent-info files.
- Fixed resource leaks at rules configuration parsing.
- Fixed memory leaks at rules parser.
- Fixed memory leaks at XML decoders parser.
- Fixed TOCTOU condition when removing directories recursively.
- Fixed insecure temporary file creation for old POSIX specifications.
- Fixed missing agentless devices identification at JSON alerts.

### Removed

- Deleted link to LUA sources.
- Delete ZLib generated files on cleaning.
- Removed maximum lines limit from diff messages (that remain limited by length).

## [v1.1.1] - 2016-05-12

### Added

- agent_control: maximum number of agents can now be extracted using option "-m".
- maild: timeout limitation, preventing it from hang in some cases.
- Updated decoders, ruleset and rootchecks from Wazuh Ruleset v1.0.8.
- Updated changes from ossec-hids repository.

### Changed

- Avoid authd to rename agent if overplaced.
- Changed some log messages.
- Reordered directories for agent backups.
- Don't exit when client.keys is empty by default.
- Improved client.keys reloading capabilities.

### Fixed

- Fixed JSON output at rootcheck_control.
- Fixed agent compilation on OS X.
- Fixed memory issue on removing timestamps.
- Fixed segmentation fault at reported.
- Fixed segmentation fault at logcollector.

### Removed

- Removed old rootcheck options.

## [v1.1] - 2016-04-06

### Added

- Re-usage of agent ID in manage_agents and authd, with time limit.
- Added option to avoid manager from exiting when there are no keys.
- Backup of the information about an agent that's going to be deleted.
- Alerting if Authd can't add an agent because of a duplicated IP.
- Integrator with Slack and PagerDuty.
- Simplified keywords for the option "frequency".
- Added custom Reply-to e-mail header.
- Added option to syscheck to avoid showing diffs on some files.
- Created agents-timestamp file to save the agents' date of adding.

### Changed

- client.keys: No longer overwrite the name of an agent with "#-#-#-" to mark it as deleted. Instead, the name will appear with a starting "!".
- API: Distinction between duplicated and invalid name for agent.
- Stop the "ERROR: No such file or directory" for Apache.
- Changed defaults to analysisd event counter.
- Authd won't use password by default.
- Changed name of fields at JSON output from binaries.
- Upgraded rules to Wazuh Ruleset v1.07

### Fixed

- Fixed merged.mg push on Windows Agent
- Fixed Windows agent compilation issue
- Fixed glob broken implementation.
- Fixed memory corruption on the OSSEC alert decoder.
- Fixed command "useradd" on OpenBSD.
- Fixed some PostgreSQL issues.
- Allow to disable syscheck:check_perm after enable check_all.

## [v1.0.4] - 2016-02-24
​
### Added

- JSON output for manage_agents.
- Increased analysis daemon's memory size.
- Authd: Added password authorization.
- Authd: Boost speed performance at assignation of ID for agents
- Authd: New option -f *sec*. Force addding new agent (even with duplicated IP) if it was not active for the last *sec* seconds.
- manage_agents: new option -d. Force adding new agent (even with duplicated IP)
- manage_agents: Printing new agent ID on adding.

### Changed

- Authd and manage_agents won't add agents with duplicated IP.

### Fixed

- Solved duplicate IP conflicts on client.keys which prevented the new agent to connect.
- Hashing files in binary mode. Solved some problems related to integrity checksums on Windows.
- Fixed issue that made console programs not to work on Windows.

### Removed

- RESTful API no longer included in extensions/api folder. Available now at https://github.com/wazuh/wazuh-api


## [v1.0.3] - 2016-02-11

### Added

- JSON CLI outputs: ossec-control, rootcheck_control, syscheck_control, ossec-logtest and more.
- Preparing integration with RESTful API
- Upgrade version scripts
- Merge commits from ossec-hids
- Upgraded rules to Wazuh Ruleset v1.06

### Fixed

- Folders are no longer included on etc/shared
- Fixes typos on rootcheck files
- Kibana dashboards fixes

## [v1.0.2] - 2016-01-29

### Added

- Added Wazuh Ruleset updater
- Added extensions files to support ELK Stack latest versions (ES 2.x, LS 2.1, Kibana 4.3)

### Changed

- Upgraded rules to Wazuh Ruleset v1.05
- Fixed crash in reportd
- Fixed Windows EventChannel syntaxis issue
- Fixed manage_agents bulk option bug. No more "randombytes" errors.
- Windows deployment script improved

## [v1.0.1] - 2015-12-10

### Added

- Wazuh version info file
- ossec-init.conf now includes wazuh version
- Integrated with wazuh OSSEC ruleset updater
- Several new fields at JSON output (archives and alerts)
- Wazuh decoders folder

### Changed

- Decoders are now splitted in differents files.
- jsonout_out enable by default
- JSON groups improvements
- Wazuh ruleset updated to 1.0.2
- Extensions: Improved Kibana dashboards
- Extensions: Improved Windows deployment script

## [v1.0] - 2015-11-23
- Initial Wazuh version v1.0
