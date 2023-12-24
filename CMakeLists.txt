cmake_minimum_required(VERSION 3.27)
project(Flight_Management_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Flight_Management_System
        dataset/airlines.csv
        dataset/airports.csv
        dataset/flights.csv
        Graph.h
        main.cpp
        App.cpp
        States/State.cpp
        States/MainMenuState.cpp
        States/SubMenuState.cpp)
