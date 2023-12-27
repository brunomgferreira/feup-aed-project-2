#include "City.h"


const string &City::getName() const {
    return name;
}

void City::setName(const string &name) {
    City::name = name;
}

const string &City::getCountry() const {
    return country;
}

void City::setCountry(const string &country) {
    City::country = country;
}

const vector <string> &City::getAirports() const {
    return airports;
}

void City::setAirports(const vector <string> &airports) {
    City::airports = airports;
}