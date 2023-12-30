cmake_minimum_required(VERSION 3.27)
project(Flight_Management_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Flight_Management_System
        dataset/airlines.csv
        dataset/airports.csv
        dataset/flights.csv
        main.cpp
        App.cpp
        States/State.cpp
        States/MainMenuState.cpp
        States/Statistics/StatisticsMenuState.cpp
        States/Statistics/Global/GlobalStatisticsMenuState.cpp
        States/Statistics/Country/CountryStatisticsMenuState.cpp
        States/Statistics/City/CityStatisticsMenuState.cpp
        States/Statistics/Airport/AirportStatisticsMenuState.cpp
        States/Statistics/Airline/AirlineStatisticsMenuState.cpp
        States/GetFlight/GetFlightOriginMenuState.cpp
        States/GetFlight/GetFlightDestinationMenuState.cpp
        States/GetFlight/GetFlightFilterMenuState.cpp
        States/OtherMethods/OtherMethodsMenuState.cpp
        States/Utils/TryAgainState.cpp
        States/Utils/GetCountryState.cpp
        States/Utils/GetCityState.cpp
        States/Utils/GetAirportState.cpp
        States/Utils/GetAirlineState.cpp
        States/Utils/GetCoordinatesState.cpp
        States/Utils/GetRadiusState.cpp
        States/Utils/LocationInfo.cpp
        Airline.cpp
        City.cpp
        Airport.cpp
        Coordinate.cpp
        Country.cpp
        Data.cpp
        Graph.cpp
        States/Utils/GetStopsState.cpp
        States/Utils/GetStopsState.h
        States/Utils/GetTopState.cpp
        States/Utils/GetTopState.h)
