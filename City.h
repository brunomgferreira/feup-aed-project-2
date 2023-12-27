#ifndef FLIGHT_MANAGEMENT_SYSTEM_CITY_H
#define FLIGHT_MANAGEMENT_SYSTEM_CITY_H


using namespace std;

#include <string>
#include <vector>

class City {
private:
    string name;
    string country;
    vector<string> airports;
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getCountry() const;

    void setCountry(const string &country);

    const vector<string> &getAirports() const;

    void setAirports(const vector<string> &airports);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_CITY_H
