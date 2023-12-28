#include "Country.h"

Country::Country(const string &name, const string &cityName)
    : name(name) {
    cities.insert(cityName);
}

const string &Country::getName() const {
    return name;
}

void Country::setName(const string &name) {
    this->name = name;
}

const unordered_set <string> &Country::getCities() const {
    return cities;
}

void Country::addCity(const string &cityName) {
    cities.insert(cityName);
}

void Country::setCities(const unordered_set <string> &cities) {
    this->cities = cities;
}