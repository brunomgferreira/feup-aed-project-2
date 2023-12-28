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


    //Confirm Existence
    bool countryExists(string basicString);
    bool cityExists(string basicString);
    bool airlineExists(string basicString);
    bool airportExists(string basicString);


    //Global
    void numberOfAirports();
    void numberOfCities();
    void numberOfCountries();
    void numberOfAirlines();
    void numberOfFlights();


    //Country
    void numberOfAirportsCountry(string basicString);
    void numberOfCitiesCountry(string basicString);

    //City
    void numberOfFlightsCity(string cityName);
    void numberOfCountriesCity(string cityName);

    //Airline
    void numberOfFlightsAirline(string airlineCode);

    //Airport
    void numberOfFlightsAirport(string basicString);
    void numberOfAirlinesAirport(string airportCode);
    void numberOfCountriesAirport(string airportCode);
    void numberOfDestinationsAirport(string airportCode); //mudar bf
    void numberOfDestinationsXStopsAirport(string airportCode, int stops); //mudar bf
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_DATA_H
