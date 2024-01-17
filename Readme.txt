Inventory Management With focus on Sports Complex of IITJ

This software system is designed to increase the efficiency and performance of the administration for proper allocation and management of the sports items in Sports Complex,Hostels and all other possible inventories. This software can be used by any institute to manage items in there respective inventories, sports complexes and hostels.

Prerequisites
A computer with Linux Operating system or any WSL linke Ubuntu in windows.
An active internet connectivity.
cmake, make and mysqlclient library (if not available follow instructions given below to install)

Installing cmake
use below given command to install cmake if not available
sudo apt-get install cmake

Installing make
use below given command to install make if not available
sudo apt-get install make

Installing mysqlclient library
use below given commands to install mysqlclient library

sudo apt-get update -y
sudo apt-get install libmysqlclient-dev

Installing and running code
First change the directory to the folder in which sem file is present in ubuntu or linux terminal.
Then run the following command -
./sem
(for example if it is in C drive in Downloads folder enter cd /mnt/c/Downloads and then run ./sem) 

Note - minimum cmake version required is 3.1 , if below version is available than make changes in the CMakeLists.txt file accordingly. Note - if directory name code is changes to something else or location is changed after running than delete CMakeCache.txt file and follow the above steps to run it successfully.

Languages Used -
CPP
C
MakeFile
CMake

Database stored in -
freesqldatabase.com

As this site provides database storage og 5mb for free, the we have used this for our project.
