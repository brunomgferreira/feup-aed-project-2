#ifndef FLIGHT_MANAGEMENT_SYSTEM_CITY_H
#define FLIGHT_MANAGEMENT_SYSTEM_CITY_H


using namespace std;

#include <string>
#include <vector>
#include <unordered_set>

/**
* @brief Class representing a city entity in the flight management system.
*/

class City {
private:
    string name;
    string countryName;
    unordered_set<string> airports;
public:

    /**
    * @brief Constructor for the City class.
    *
    * @details Initializes a City object with the given name, country name, and an initial airport code.
    *
    * @param name The name of the city.
    * @param countryName The name of the country to which the city belongs.
    * @param airportCode The code of an initial airport associated with the city.
    */
    City(const string &name, const string &countryName, const string &airportCode);

    /**
    * @brief Gets the name of the city.
    *
    * @return A reference to the name of the city.
    */
    const string &getName() const;

    /**
    * @brief Sets the name of the city.
    *
    * @param name The new name of the city.
    */
    void setName(const string &name);

    /**
    * @brief Gets the name of the country to which the city belongs.
    *
    * @return A reference to the name of the country.
    */
    const string &getCountryName() const;

    /**
    * @brief Sets the name of the country to which the city belongs.
    *
    * @param countryName The new name of the country.
    */
    void setCountryName(const string &countryName);

    /**
    * @brief Gets the set of airport codes associated with the city.
    *
    * @return A reference to the set of airport codes.
    */
    const unordered_set<string> &getAirports() const;

    /**
    * @brief Adds an airport code to the set of airports associated with the city.
    *
    * @param airportCode The code of the airport to add.
    */
    void addAirport(const string &airportCode);

    /**
    * @brief Sets the set of airport codes associated with the city.
    *
    * @param airports The new set of airport codes.
    */
    void setAirports(const unordered_set<string> &airports);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_CITY_H
