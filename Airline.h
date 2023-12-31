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

    /**
    * @brief Gets the unique code of the airline.
    *
    * @details This method returns the unique code assigned to the airline.
    *
    * @return A constant reference to the string representing the unique code of the airline.
    */
    const string &getCode() const;

    /**
    * @brief Sets the unique code of the airline.
    *
    * @details This method sets the unique code of the airline to the specified value.
    *
    * @param code A constant reference to the string representing the new code for the airline.
    */
    void setCode(const string &code);

    /**
    * @brief Gets the name of the airline.
    *
    * @details This method returns a constant reference to the string representing the name of the airline.
    *
    * @return A constant reference to the string representing the name of the airline.
    */
    const string &getName() const;

    /**
    * @brief Sets the name of the airline.
    *
    * @details This method sets the name of the airline to the specified value.
    *
    * @param name A constant reference to the string representing the new name for the airline.
    */
    void setName(const string &name);

    /**
    * @brief Gets the callsign of the airline.
    *
    * @details This method returns a constant reference to the string representing the callsign of the airline.
    *
    * @return A constant reference to the string representing the callsign of the airline.
    */
    const string &getCallsign() const;

    /**
    * @brief Sets the callsign of the airline.
    *
    * @details This method sets the callsign of the airline to the specified value.
    *
    * @param callsign A constant reference to the string representing the new callsign for the airline.
    */
    void setCallsign(const string &callsign);

    /**
    * @brief Gets the country of the airline.
    *
    * @details This method returns a constant reference to the string representing the country of the airline.
    *
    * @return A constant reference to the string representing the country of the airline.
    */
    const string &getCountry() const;

    /**
    * @brief Sets the country of the airline.
    *
    * @details This method sets the country of the airline to the specified value.
    *
    * @param country A constant reference to the string representing the new country for the airline.
    */
    void setCountry(const string &country);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H
