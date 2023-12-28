#ifndef FLIGHT_MANAGEMENT_SYSTEM_DATA_H
#define FLIGHT_MANAGEMENT_SYSTEM_DATA_H


using namespace std;

#include <unordered_map>
#include "Airline.h"
#include "Airport.h"
#include "Graph.h"
#include "City.h"
#include "Country.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Data {
private:
    unordered_map<string , Airline* > airlines;
    unordered_map<string , Airport* > airports;
    unordered_map<string , City* > cities;
    unordered_map<string , Country* > countries;
    Graph g;
public:
    Data();
    void readFileAirlines();
    void readFileAirports();
    void readFileFlights();
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_DATA_H
