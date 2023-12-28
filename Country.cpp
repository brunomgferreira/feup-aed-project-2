#include "Country.h"

const string &Country::getName() const {
    return name;
}

void Country::setName(const string &name) {
    this->name = name;
}

const unordered_set <string> &Country::getCities() const {
    return cities;
}

void Country::setCities(const unordered_set <string> &cities) {
    this->cities = cities;
}