#ifndef FLIGHT_MANAGEMENT_SYSTEM_COUNTRY_H
#define FLIGHT_MANAGEMENT_SYSTEM_COUNTRY_H


using namespace std;

#include <string>
#include <unordered_set>
#include "City.h"

/**
* @brief Class representing a country entity in the flight management system.
*/

class Country {
private:
    string name;
    unordered_set<string> cities;
public:

    /**
    * @brief Constructor for the Country class.
    *
    * @details Initializes a Country object with the given name and city.
    *
    * @param name The name of the country.
    * @param cityName The name of the initial city to be added to the country.
    */
    Country(const string &name, const string &cityName);

    /**
    * @brief Gets the name of the country.
    *
    * @return The name of the country.
    */
    const string &getName() const;

    /**
    * @brief Sets the name of the country.
    *
    * @param name The new name of the country.
    */
    void setName(const string &name);

    /**
    * @brief Gets the set of cities in the country.
    *
    * @return The set of city names in the country.
    */
    const unordered_set<string> &getCities() const;

    /**
    * @brief Adds a new city to the country.
    *
    * @param cityName The name of the city to be added.
    */
    void addCity(const string &cityName);

    /**
    * @brief Sets the set of cities in the country.
    *
    * @param cities The set of city names to be set for the country.
    */
    void setCities(const unordered_set<string> &cities);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_COUNTRY_H
