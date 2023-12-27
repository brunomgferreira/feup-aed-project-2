#include "Airport.h"

Airport::Airport(string code, string name, string city, Coordinate* coordinate) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->coordinate = coordinate;
}

const string &Airport::getCode() const {
    return code;
}

void Airport::setCode(const string &code) {
    Airport::code = code;
}

const string &Airport::getName() const {
    return name;
}

void Airport::setName(const string &name) {
    Airport::name = name;
}

const string &Airport::getCity() const {
    return city;
}

void Airport::setCity(const string &city) {
    Airport::city = city;
}

const Coordinate &Airport::getCoordinate() const {
    return coordinate;
}

void Airport::setCoordinate(const Coordinate &coordinate) {
    Airport::coordinate = coordinate;
}
