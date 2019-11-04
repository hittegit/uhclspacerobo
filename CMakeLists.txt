cmake_minimum_required(VERSION 3.9)
project(src)

set(CMAKE_CXX_STANDARD 11)

add_executable(src
        Controller.h
        DriveController-3.cpp
        DriveController.cpp
        DriveController.h
        DropOffController.cpp
        DropOffController.h
        LogicController.cpp
        LogicController.h
        ManualWaypointController.cpp
        ManualWaypointController.h
        ObstacleController.cpp
        ObstacleController.h
        PickUpController.cpp
        PickUpController.h
        PID.cpp
        PID.h
        Point.h
        RangeController.cpp
        RangeController.h
        Result.h
        ROSAdapter-2.cpp
        ROSAdapter.cpp
        SearchController.cpp
        SearchController.h
        Tag.cpp
        Tag.h)
