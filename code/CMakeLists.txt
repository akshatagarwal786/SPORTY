cmake_minimum_required(VERSION 3.1)
project(sem)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(sem 
	ItemAdding.cpp
        Application.cpp
        AvailableItems.cpp
        header.h
        Watchman.cpp
        main.cpp
        OutstandingItems.cpp
        Secretary.cpp
        Student.cpp
        ControlStudent.cpp
        ControlDuesOfStudent.cpp
        HomepageStudent.cpp
	Homepage.cpp
        ItemIssue.cpp
        Login.cpp
        ReturnItem.cpp
        TotalItems.cpp
        View.cpp
        PendingDues.cpp)
include_directories(${CMAKE_CURRENT_LIST_DIR}/mysql-headers)
target_link_libraries(sem mysqlclient)
