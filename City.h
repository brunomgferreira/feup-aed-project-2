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
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_CITY_H
