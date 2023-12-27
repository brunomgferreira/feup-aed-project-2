#include "Airline.h"

Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

const string &Airline::getCode() const {
    return code;
}

void Airline::setCode(const string &code) {
    Airline::code = code;
}

const string &Airline::getName() const {
    return name;
}

void Airline::setName(const string &name) {
    Airline::name = name;
}

const string &Airline::getCallsign() const {
    return callsign;
}

void Airline::setCallsign(const string &callsign) {
    Airline::callsign = callsign;
}

const string &Airline::getCountry() const {
    return country;
}

void Airline::setCountry(const string &country) {
    Airline::country = country;
}