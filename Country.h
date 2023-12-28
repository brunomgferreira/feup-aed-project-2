#ifndef FLIGHT_MANAGEMENT_SYSTEM_COUNTRY_H
#define FLIGHT_MANAGEMENT_SYSTEM_COUNTRY_H


using namespace std;

#include <string>
#include <unordered_set>
#include "City.h"

class Country {
private:
    string name;
    unordered_set<string> cities;
public:
    Country(const string &name, const string &cityName);
    const string &getName() const;
    void setName(const string &name);
    const unordered_set<string> &getCities() const;
    void addCity(const string &cityName);
    void setCities(const unordered_set<string> &cities);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_COUNTRY_H
