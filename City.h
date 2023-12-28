#ifndef FLIGHT_MANAGEMENT_SYSTEM_CITY_H
#define FLIGHT_MANAGEMENT_SYSTEM_CITY_H


using namespace std;

#include <string>
#include <vector>
#include <unordered_set>

class City {
private:
    string name;
    string countryName;
    unordered_set<string> airports;
public:
    City(const string &name, const string &countryName, const string &airportCode);
    const string &getName() const;
    void setName(const string &name);
    const string &getCountryName() const;
    void setCountryName(const string &countryName);
    const unordered_set<string> &getAirports() const;
    void addAirport(const string &airportCode);
    void setAirports(const unordered_set<string> &airports);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_CITY_H
