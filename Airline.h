#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H


#include <string>
using namespace std;

/**
* @brief Class representing an airline entity in the flight management system.
*/

class Airline {
private :
    string code;
    string name;
    string callsign;
    string country;

public:

    /**
    * @brief Constructs an Airline object with the provided details.
    *
    * @details This constructor initializes an Airline object with the specified airline code, name, callsign, and country.
    * The parameters represent essential information about an airline, including its unique code, full name, callsign, and
    * the country to which it belongs.
    *
    * @param code The unique code assigned to the airline.
    * @param name The full name of the airline.
    * @param callsign The callsign used by the airline for communication.
    * @param country The country to which the airline belongs.
    */
    Airline(string code, string name, string callsign, string country);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H
