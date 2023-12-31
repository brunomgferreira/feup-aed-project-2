#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H


using namespace std;
#include <string>
#include "Coordinate.h"

/**
* @brief Class representing an airport entity in the flight management system.
*/

class Airport {
private:
    string code;
    string name;
    string city;
    string country;
    Coordinate* coordinate;
public:

    /**
    * @brief Constructor for the Airport class.
    *
    * @details Initializes an Airport object with the specified code, name, city, country, and coordinates.
    *
    * @param code A constant reference to the string representing the airport code.
    * @param name A constant reference to the string representing the airport name.
    * @param city A constant reference to the string representing the city where the airport is located.
    * @param country A constant reference to the string representing the country where the airport is located.
    * @param coordinate A pointer to a Coordinate object representing the geographic coordinates of the airport.
    */
    Airport(string code, string name, string city, string country, Coordinate* coordinate);

    /**
    * @brief Gets the country of the airport.
    *
    * @details This method returns a constant reference to the string representing the country where the airport is located.
    *
    * @return A constant reference to the string representing the country of the airport.
    */
    const string &getCountry() const;

    /**
    * @brief Gets the code of the airport.
    *
    * @details This method returns a constant reference to the string representing the airport code.
    *
    * @return A constant reference to the string representing the airport code.
    */
    const string &getCode() const;

    /**
    * @brief Gets the city of the airport.
    *
    * @details This method returns a constant reference to the string representing the city where the airport is located.
    *
    * @return A constant reference to the string representing the city of the airport.
    */
    const string &getCity() const;

    /**
    * @brief Gets the coordinates of the airport.
    *
    * @details This method returns a pointer to a Coordinate object representing the geographic coordinates of the airport.
    *
    * @return A pointer to a Coordinate object representing the coordinates of the airport.
    */
    const Coordinate *getCoordinate() const;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H
