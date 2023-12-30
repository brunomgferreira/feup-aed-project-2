#ifndef FLIGHT_MANAGEMENT_SYSTEM_DATA_H
#define FLIGHT_MANAGEMENT_SYSTEM_DATA_H


using namespace std;

#include <unordered_map>
#include "Airline.h"
#include "Airport.h"
#include "Graph.h"
#include "City.h"
#include "Country.h"
#include "States/Utils/LocationInfo.h"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Class that saves all the program data.
 */

class Data {
private:
    unordered_map<string , Airline* > airlines;
    unordered_map<string , Airport* > airports;
    unordered_map<string , City* > cities;
    unordered_map<string , Country* > countries;
    Graph g;
public:
    /**
    * @brief Default constructor for the Data class.
    *
    * @details This default constructor creates a new instance of the Data class without
    * specifying any initial values. It initializes the Data object with default values.
    * @details Time complexity: O(1)
    */
    Data();

    /**
    * @brief Reads and populates the map of airlines from an external file.
    *
    * @details This method reads data from an external file containing airlines
    * and populates the map of airlines in the database.
    * Each airline has a code, name, callsign and a country.
    * @details Time complexity: O(N), where N is the number airlines read from the file.
    */
    void readFileAirlines();

    /**
    * @brief Reads and populates the map of airports from an external file.
    *
    * @details This method reads data from an external file containing airports
    * and populates the map of airports in the database. Each airport has a code,
    * name, city, country, latitude, and longitude.
    * Additionally, this function updates the graph, and the maps of the cities and countries,
    * creating new entries if necessary.
    *
    * @details Time complexity: O(N), where N is the number of airports read from the file.
    */
    void readFileAirports();

    /**
    * @brief Reads and populates the map of flights from an external file.
    *
    * @details This method reads data from an external file containing flight information
    * and populates the map of flights in the database. Each line in the file represents
    * a flight with the origin airport code, destination airport code, and the airline code.
    * Additionally, this function adds an edge to the graph representing the flight between
    * the origin and destination airports.
    *
    * @details Time complexity: O(N), where N is the number of flights read from the file.
    */
    void readFileFlights();


    //Confirm Existence

    /**
    * @brief Checks the existence of a country in the database.
    *
    * @details This method checks whether a country with the given name exists in the database.
    * It searches the map of countries and returns true if the country is found; otherwise, it
    * returns false. The function is used to determine if a country is already present in the database.
    *
    * @param countryName The name of the country to be checked for existence.
    *
    * @return True if the country exists in the database, false otherwise.
    *
    * @details Time complexity: O(1), as the function performs a constant-time map lookup.
    */
    bool countryExists(string basicString);

    /**
    * @brief Checks the existence of a city in the database.
    *
    * @details This method checks whether a city with the given name exists in the database.
    * It searches the map of cities and returns true if the city is found; otherwise, it
    * returns false. The function is used to determine if a city is already present in the database.
    *
    * @param cityName The name of the city to be checked for existence.
    *
    * @return True if the city exists in the database, false otherwise.
    *
    * @details Time complexity: O(1), as the function performs a constant-time map lookup.
    */
    bool cityExists(string basicString);

    /**
    * @brief Checks the existence of an airport in the database.
    *
    * @details This method checks whether an airport with the given code exists in the database.
    * It searches the map of airports and returns true if the airport is found; otherwise, it
    * returns false. The function is used to determine if an airport is already present in the database.
    *
    * @param airportCode The code of the airport to be checked for existence.
    *
    * @return True if the airport exists in the database, false otherwise.
    *
    * @details Time complexity: O(1), as the function performs a constant-time map lookup.
    */
    bool airportExists(string basicString);

    /**
    * @brief Checks the existence of an airline in the database.
    *
    * @details This method checks whether an airline with the given code exists in the database.
    * It searches the map of airlines and returns true if the airline is found; otherwise, it
    * returns false. The function is used to determine if an airline is already present in the database.
    *
    * @param airlineCode The code of the airline to be checked for existence.
    *
    * @return True if the airline exists in the database, false otherwise.
    *
    * @details Time complexity: O(1), as the function performs a constant-time map lookup.
    */
    bool airlineExists(string basicString);


    //Global

    /**
    * @brief Prints the number of airports in the database.
    *
    * @details This method outputs the count of airports present in the database to the standard output.
    * It utilizes the size of the map containing airports to determine the total number of airports.
    *
    * @details Time complexity: O(1), as the function only involves retrieving the size of the map.
    */
    void numberOfAirports();

    /**
    * @brief Prints the number of cities in the database.
    *
    * @details This method outputs the count of cities present in the database to the standard output.
    * It utilizes the size of the map containing cities to determine the total number of cities.
    *
    * @details Time complexity: O(1), as the function only involves retrieving the size of the map.
    */
    void numberOfCities();

    /**
    * @brief Prints the number of countries in the database.
    *
    * @details This method outputs the count of countries present in the database to the standard output.
    * It utilizes the size of the map containing countries to determine the total number of cities.
    *
    * @details Time complexity: O(1), as the function only involves retrieving the size of the map.
    */
    void numberOfCountries();

    /**
    * @brief Prints the number of airlines in the database.
    *
    * @details This method outputs the count of airlines present in the database to the standard output.
    * It utilizes the size of the map containing airlines to determine the total number of cities.
    *
    * @details Time complexity: O(1), as the function only involves retrieving the size of the map.
    */
    void numberOfAirlines();

    /**
    * @brief Prints the total number of flights in the database.
    *
    * @details This method calculates and outputs the total count of flights present in the database.
    * It iterates through the vertices of the graph, considering each airport and its connections,
    * and accumulates the count of flights from those connections. The final count is then displayed
    * on the standard output.
    *
    * @details Time complexity: O(V + E), where V is the number of vertices (airports) and E is the
    * number of edges (connections/flights) in the graph.
    */
    void numberOfFlights();


    //Country

    /**
    * @brief Prints the number of airports in a specific country.
    *
    * @details This method calculates and outputs the count of airports in the specified country.
    * It retrieves the cities associated with the given country and, for each city, accumulates
    * the count of airports. The final count is then displayed on the standard output.
    *
    * @param countryName The name of the country for which the number of airports is calculated.
    *
    * @details Time complexity: O(C), where C is the number of cities associated with the specified country.
    */
    void numberOfAirportsCountry(string basicString);

    /**
    * @brief Prints the number of cities in a specific country with airports.
    *
    * @details This method calculates and outputs the count of cities in the specified country
    * that have at least one airport. It retrieves the cities associated with the given country
    * and counts the total number of such cities. The final count is then displayed on the standard output.
    *
    * @param countryName The name of the country for which the number of cities is calculated.
    *
    * @details Time complexity: O(1), as the function involves retrieving the size of the set of cities.
    */
    void numberOfCitiesCountry(string basicString);

    /**
    * @brief Retrieves the set of airport codes in a specific country.
    *
    * @details This method returns an unordered set containing the airport codes
    * for all the airports located in the specified country. It achieves this by
    * iterating through the cities associated with the country and, for each city,
    * retrieving the airports and adding their codes to the set.
    *
    * @param countryName The name of the country for which the set of airport codes is retrieved.
    *
    * @return An unordered set of strings representing the airport codes in the specified country.
    *
    * @details Time complexity: O(C + A), where C is the number of cities associated with the specified country,
    * and A is the total number of airports in those cities.
    */
    unordered_set<string> airportsInCountry(const string& countryName) const;

    /**
    * @brief Prints the number of different airlines operating in a specific country.
    *
    * @details This method calculates and outputs the count of unique airline codes for all
    * the flights originating from airports in the specified country. It iterates through the
    * cities associated with the country, retrieves the airports in each city, and collects the
    * unique airline codes from the flights connected to those airports.
    *
    * @param countryName The name of the country for which the number of airlines is calculated.
    *
    * @details Time complexity: O(C + A + F), where C is the number of cities associated with the specified country,
    * A is the total number of airports in those cities, and F is the total number of flights from those airports.
    */
    void numberOfAirlinesCountry(string countryName);

    /**
    * @brief Prints the total number of flights originating from airports in a specific country.
    *
    * @details This method calculates and outputs the count of flights originating from airports
    * in the specified country. It iterates through the cities associated with the country, retrieves
    * the airports in each city, and counts the total number of flights connected to those airports.
    *
    * @param countryName The name of the country for which the number of flights is calculated.
    *
    * @details Time complexity: O(C + A + F), where C is the number of cities associated with the specified country,
    * A is the total number of airports in those cities, and F is the total number of flights from those airports.
    */
    void numberOfFlightsCountry(string countryName);

    /**
    * @brief Prints the number of unique destinations (airports, cities, and countries) reachable
    * from airports in a specific country using breadth-first search (BFS).
    *
    * @details This method performs a BFS starting from each airport in the specified country to
    * identify unique destinations. It counts and outputs the number of unique airports, cities,
    * and countries that can be reached from airports in the given country.
    *
    * @param countryName The name of the country for which the number of destinations is calculated.
    *
    * @details Time complexity: O(C + A + D), where C is the number of cities associated with the specified country,
    * A is the total number of airports in those cities, and D is the total number of unique destinations reached.
    */
    void numberOfDestinationsCountry(string countryName);

    /**
    * @brief Prints the number of unique destinations (airports, cities, and countries) reachable
    * from airports in a specific country within a given number of stops using breadth-first search (BFS).
    *
    * @details This method performs a BFS starting from each airport in the specified country, considering
    * a maximum number of stops, to identify unique destinations. It counts and outputs the number of unique
    * airports, cities, and countries that can be reached within the specified number of stops.
    *
    * @param countryName The name of the country for which the number of destinations is calculated.
    * @param stops The maximum number of stops allowed for each BFS traversal.
    *
    * @details Time complexity: O(C + A + D), where C is the number of cities associated with the specified country,
    * A is the total number of airports in those cities, and D is the total number of unique destinations reached.
    */
    void numberOfDestinationsXStopsCountry(string countryName, int stops);


    //City

    /**
    * @brief Prints the number of airports in a specific city.
    *
    * @details This method calculates and outputs the count of airports in the specified city.
    * It retrieves the set of airports associated with the given city and counts the total number
    * of airports in that set. The final count is then displayed on the standard output.
    *
    * @param cityName The name of the city for which the number of airports is calculated.
    *
    * @details Time complexity: O(1), as the function involves retrieving the size of the set of airports.
    */
    void numberOfAirportsCity(string cityName);

    /**
    * @brief Prints the number of different countries reachable from airports in a specific city.
    *
    * @details This method calculates and outputs the count of unique countries that can be reached
    * from airports in the specified city. It iterates through the airports in the city, retrieves
    * the connections from each airport, and counts the total number of unique destination countries.
    *
    * @param cityName The name of the city for which the number of countries is calculated.
    *
    * @details Time complexity: O(A + C), where A is the total number of airports in the specified city,
    * and C is the total number of unique countries reached from those airports.
    */
    void numberOfCountriesCity(string cityName);

    /**
    * @brief Prints the number of different airlines operating from airports in a specific city.
    *
    * @details This method calculates and outputs the count of unique airline codes for all the flights
    * originating from airports in the specified city. It iterates through the airports in the city,
    * retrieves the connections from each airport, and counts the total number of unique airline codes.
    *
    * @param cityName The name of the city for which the number of airlines is calculated.
    *
    * @details Time complexity: O(A + F), where A is the total number of airports in the specified city,
    * and F is the total number of flights from those airports.
    */
    void numberOfAirlinesCity(string cityName);

    /**
    * @brief Prints the total number of flights originating from airports in a specific city.
    *
    * @details This method calculates and outputs the count of flights originating from airports
    * in the specified city. It iterates through the airports in the city, retrieves the connections
    * from each airport, and counts the total number of flights connected to those airports.
    *
    * @param cityName The name of the city for which the number of flights is calculated.
    *
    * @details Time complexity: O(A + F), where A is the total number of airports in the specified city,
    * and F is the total number of flights from those airports.
    */
    void numberOfFlightsCity(string cityName);

    /**
    * @brief Prints the number of unique destinations (airports, cities, and countries) reachable
    * from airports in a specific city using breadth-first search (BFS).
    *
    * @details This method performs a BFS starting from each airport in the specified city to identify
    * unique destinations. It counts and outputs the number of unique airports, cities, and countries
    * that can be reached from airports in the given city.
    *
    * @param cityName The name of the city for which the number of destinations is calculated.
    *
    * @details Time complexity: O(A + D), where A is the total number of airports in the specified city,
    * and D is the total number of unique destinations reached from those airports.
    */
    void numberOfDestinationsCity(string cityName);

    /**
    * @brief Prints the number of unique destinations (airports, cities, and countries) reachable
    * from airports in a specific city within a given number of stops using breadth-first search (BFS).
    *
    * @details This method performs a BFS starting from each airport in the specified city, considering
    * a maximum number of stops, to identify unique destinations. It counts and outputs the number of unique
    * airports, cities, and countries that can be reached within the specified number of stops.
    *
    * @param cityName The name of the city for which the number of destinations is calculated.
    * @param stops The maximum number of stops allowed for each BFS traversal.
    *
    * @details Time complexity: O(A + D), where A is the total number of airports in the specified city,
    * and D is the total number of unique destinations reached from those airports.
    */
    void numberOfDestinationsXStopsCity(string cityName, int stops);

    /**
    * @brief Retrieves the set of airport codes associated with a specific city.
    *
    * @details This method returns an unordered set containing the airport codes
    * associated with the specified city. It retrieves the set of airports from the
    * city object and returns it.
    *
    * @param cityName The name of the city for which the set of airport codes is retrieved.
    *
    * @return An unordered set of strings representing the airport codes in the specified city.
    *
    * @details Time complexity: O(1), as the function involves a direct retrieval of the set of airport codes.
    */
    unordered_set<string> airportsInCity(const string& cityName) const;

    //Airline

    /**
    * @brief Prints the total number of flights operated by a specific airline.
    *
    * @details This method calculates and outputs the count of flights operated by
    * the specified airline. It iterates through all airports and connections in the
    * graph, checking for the presence of the given airline code in the set of airlines
    * for each connection.
    *
    * @param airlineCode The code of the airline for which the number of flights is calculated.
    *
    * @details Time complexity: O(A + F), where A is the total number of airports in the graph,
    * and F is the total number of flights in the graph.
    */
    void numberOfFlightsAirline(string airlineCode);

    /**
    * @brief Prints the number of unique destinations (airports, cities, and countries) reachable
    * by flights operated by a specific airline.
    *
    * @details This method calculates and outputs the count of unique destinations (airports, cities, and countries)
    * reachable by flights operated by the specified airline. It iterates through all airports and connections in the
    * graph, checking for the presence of the given airline code in the set of airlines for each connection. For each
    * connection with the specified airline, it adds the destination airport's code, city, and country to the respective sets.
    *
    * @param airlineCode The code of the airline for which the number of destinations is calculated.
    *
    * @details Time complexity: O(A + F + D), where A is the total number of airports in the graph, F is the total number
    * of flights in the graph, and D is the total number of unique destinations reached by flights operated by the specified airline.
    */
    void numberOfDestinationsAirline(string airlineCode);


    //Airport
    void numberOfFlightsAirport(string basicString);
    void numberOfAirlinesAirport(string airportCode);
    void numberOfCountriesAirport(string airportCode);
    void numberOfDestinationsAirport(const string& airportCode);
    void numberOfDestinationsXStopsAirport(const string& airportCode, int stops);

    string airportNearCoordinate(Coordinate coordinate) const;
    unordered_set<string> airportsInLocation(Coordinate coordinate, double radius);

    // Flights
    void getFlights(const LocationInfo& originLocation, const LocationInfo& destinyLocation,const unordered_set<string>& airlineSet, bool unwantedAirlines);
    list<list<string>> processFlights(const string& destiny, const unordered_map<string, pair<list<string>, int>>& airportTrack) const;

    // Location
    unordered_set<string> convertLocation(const LocationInfo& location);


    //Othermethods
    void maximumTrip();
    void topKAirports(int k);
    void essentialAirports();


    //Sortmethod
    static bool sortTopAirports(const pair<string, int>& a, const pair<string, int>& b);

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_DATA_H
