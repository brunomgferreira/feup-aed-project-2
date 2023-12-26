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
        States/Statistics/StatisticsMenuState.cpp
        States/GetFlight/GetFlightOriginMenuState.cpp
        States/Statistics/Global/GlobalStatisticsMenuState.cpp
        States/Statistics/Country/CountryStatisticsMenuState.cpp
        States/Statistics/City/CityStatisticsMenuState.cpp
        States/Statistics/Airport/AirportStatisticsMenuState.cpp
        States/Statistics/Airline/AirlineStatisticsMenuState.cpp
        States/GetFlight/GetFlightDestinationMenuState.cpp
        States/OtherMethods/OtherMethodsMenuState.cpp
        States/GetFlight/GetFlightFilterMenuState.cpp
        States/GetFlight/GetFlightFilterMenuState.h)
