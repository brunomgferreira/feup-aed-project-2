#include "Country.h"

Country::Country(const string &name, const string &cityName)
    : name(name) {
    cities.insert(cityName);
}

const unordered_set <string> &Country::getCities() const {
    return cities;
}

void Country::addCity(const string &cityName) {
    cities.insert(cityName);
}