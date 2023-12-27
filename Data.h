#ifndef FLIGHT_MANAGEMENT_SYSTEM_DATA_H
#define FLIGHT_MANAGEMENT_SYSTEM_DATA_H


using namespace std;

#include <unordered_map>
#include "Airline.h"
#include "Airport.h"
#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Data {
private:
    unordered_map<string , Airline* > airlines;
    unordered_map<string , Airport* > airports;
    Graph g;

public:
    void readFileAirlines();
    void readFileAirports();
    void readFileFlights();



};


#endif //FLIGHT_MANAGEMENT_SYSTEM_DATA_H
