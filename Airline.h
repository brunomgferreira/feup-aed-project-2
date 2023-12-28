#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H


#include <string>
using namespace std;

class Airline {
private :
    string code;
    string name;
    string callsign;
    string country;

public:

    Airline(string code, string name, string callsign, string country);


    const string &getCode() const;

    void setCode(const string &code);

    const string &getName() const;

    void setName(const string &name);

    const string &getCallsign() const;

    void setCallsign(const string &callsign);

    const string &getCountry() const;

    void setCountry(const string &country);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H
