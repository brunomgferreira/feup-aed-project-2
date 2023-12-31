#include "City.h"

City::City(const string &name, const string &countryName, const string &airportCode)
    : name(name), countryName(countryName) {
    airports.insert(airportCode);
}

const unordered_set<string> &City::getAirports() const {
    return airports;
}

void City::addAirport(const string &airportCode) {
    airports.insert(airportCode);
}