#include "City.h"

City::City(const string &name, const string &countryName, const string &airportCode)
    : name(name), countryName(countryName) {
    airports.insert(airportCode);
}

const string &City::getName() const {
    return name;
}

void City::setName(const string &name) {
    this->name = name;
}

const string &City::getCountryName() const {
    return countryName;
}

void City::setCountryName(const string &countryName) {
    this->countryName = countryName;
}

const unordered_set<string> &City::getAirports() const {
    return airports;
}

void City::addAirport(const string &airportCode) {
    airports.insert(airportCode);
}

void City::setAirports(const unordered_set<string> &airports) {
    this->airports = airports;
}