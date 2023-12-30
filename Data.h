#ifndef FLIGHT_MANAGEMENT_SYSTEM_DATA_H
#define FLIGHT_MANAGEMENT_SYSTEM_DATA_H


using namespace std;

#include <unordered_map>
#include "Airline.h"
#include "Airport.h"
#include "Graph.h"
#include "City.h"
#include "Country.h"
#include "States/Utils/LocationInfo.h"
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
    bool countryExists(const string& basicString);
    bool cityExists(const string& basicString);
    bool airlineExists(const string& basicString);
    bool airportExists(const string& basicString);


    //Global
    void numberOfAirports();
    void numberOfCities();
    void numberOfCountries();
    void numberOfAirlines();
    void numberOfFlights();


    //Country
    void numberOfAirportsCountry(const string& countryName);
    void numberOfCitiesCountry(const string& countryName);
    unordered_set<string> airportsInCountry(const string& countryName) const;
    void numberOfAirlinesCountry(const string& countryName);
    void numberOfFlightsCountry(const string& countryName);
    void numberOfDestinationsCountry(const string& countryName);
    void numberOfDestinationsXStopsCountry(const string& countryName, int stops);


    //City
    void numberOfAirportsCity(const string& cityName);
    void numberOfCountriesCity(const string& cityName);
    void numberOfAirlinesCity(const string& cityName);
    void numberOfFlightsCity(const string& cityName);
    void numberOfDestinationsCity(const string& cityName);
    void numberOfDestinationsXStopsCity(const string& cityName, int stops);
    unordered_set<string> airportsInCity(const string& cityName) const;

    //Airline
    void numberOfFlightsAirline(const string& airlineCode);
    void numberOfDestinationsAirline(const string& airlineCode);


    //Airport
    void numberOfFlightsAirport(const string& basicString);
    void numberOfAirlinesAirport(const string& airportCode);
    void numberOfCountriesAirport(const string& airportCode);
    void numberOfDestinationsAirport(const string& airportCode);
    void numberOfDestinationsXStopsAirport(const string& airportCode, int stops);

    string airportNearCoordinate(Coordinate coordinate) const;
    unordered_set<string> airportsInLocation(Coordinate coordinate, double radius);

    // Flights
    void getFlights(const LocationInfo& originLocation, const LocationInfo& destinyLocation,unordered_set<string> airlineSet, bool unwantedAirlines, bool minimizeAirlines);
private:
    list<list<string>> processFlights(const string& destiny, const unordered_map<string, pair<list<string>, int>>& airportTrack) const;
    pair<list<list<string>>, int> minimalAirlines(const list<list<string>>& flights) const;
    // Location
    unordered_set<string> convertLocation(const LocationInfo& location);
public:

    //Othermethods
    void maximumTrip();
    void topKAirports(int k);
    void essentialAirports();


    //Sortmethod
    static bool sortTopAirports(const pair<string, int>& a, const pair<string, int>& b);

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_DATA_H
