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
    * @brief Sets the country of the airport.
    *
    * @details This method sets the country of the airport to the specified value.
    *
    * @param country A constant reference to the string representing the new country for the airport.
    */
    void setCountry(const string &country);

    /**
    * @brief Gets the code of the airport.
    *
    * @details This method returns a constant reference to the string representing the airport code.
    *
    * @return A constant reference to the string representing the airport code.
    */
    const string &getCode() const;

    /**
    * @brief Sets the code of the airport.
    *
    * @details This method sets the code of the airport to the specified value.
    *
    * @param code A constant reference to the string representing the new code for the airport.
    */
    void setCode(const string &code);

    /**
    * @brief Gets the name of the airport.
    *
    * @details This method returns a constant reference to the string representing the airport name.
    *
    * @return A constant reference to the string representing the airport name.
    */
    const string &getName() const;

    /**
    * @brief Sets the name of the airport.
    *
    * @details This method sets the name of the airport to the specified value.
    *
    * @param name A constant reference to the string representing the new name for the airport.
    */
    void setName(const string &name);

    /**
    * @brief Gets the city of the airport.
    *
    * @details This method returns a constant reference to the string representing the city where the airport is located.
    *
    * @return A constant reference to the string representing the city of the airport.
    */
    const string &getCity() const;

    /**
    * @brief Sets the city of the airport.
    *
    * @details This method sets the city of the airport to the specified value.
    *
    * @param city A constant reference to the string representing the new city for the airport.
    */
    void setCity(const string &city);

    /**
    * @brief Gets the coordinates of the airport.
    *
    * @details This method returns a pointer to a Coordinate object representing the geographic coordinates of the airport.
    *
    * @return A pointer to a Coordinate object representing the coordinates of the airport.
    */
    const Coordinate *getCoordinate() const;

    /**
    * @brief Sets the coordinates of the airport.
    *
    * @details This method sets the coordinates of the airport to the specified value.
    *
    * @param coordinate A pointer to a Coordinate object representing the new coordinates for the airport.
    */
    void setCoordinate(Coordinate *coordinate);

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H
