#include "Airport.h"

Airport::Airport(string code, string name, string city, string country, Coordinate* coordinate) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->coordinate = coordinate;
}

const string &Airport::getCode() const {
    return code;
}

const string &Airport::getCity() const {
    return city;
}

const Coordinate *Airport::getCoordinate() const {
    return this->coordinate;
}

const string &Airport::getCountry() const {
    return country;
}
