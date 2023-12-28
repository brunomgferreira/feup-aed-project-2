#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H


using namespace std;
#include <string>
#include "Coordinate.h"

class Airport {
private:
    string code;
    string name;
    string city;
    string country;
    Coordinate* coordinate;
public:

    Airport(string code, string name, string city, string country, Coordinate* coordinate);

    const string &getCountry() const;

    void setCountry(const string &country);

    const string &getCode() const;

    void setCode(const string &code);

    const string &getName() const;

    void setName(const string &name);

    const string &getCity() const;

    void setCity(const string &city);

    const Coordinate *getCoordinate() const;

    void setCoordinate(Coordinate *coordinate);

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H
