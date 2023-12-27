#ifndef FLIGHT_MANAGEMENT_SYSTEM_COUNTRY_H
#define FLIGHT_MANAGEMENT_SYSTEM_COUNTRY_H


using namespace std;

#include <string>
#include <unordered_set>
#include "City.h"

class Country {
private:
    string name;
    unordered_set<City> cities;
public:
    const string &getName() const;

    void setName(const string &name);

    const unordered_set<City> &getCities() const;

    void setCities(const unordered_set<City> &cities);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_COUNTRY_H
