#ifndef FLIGHT_MANAGEMENT_SYSTEM_LOCATIONINFO_H
#define FLIGHT_MANAGEMENT_SYSTEM_LOCATIONINFO_H

#include <string>
#include "Coordinate.h"

using namespace std;

/**
* @brief Class representing information about a location, including its type, details, coordinates, and radius.
*/

class LocationInfo {
private:
    int type; // 1. Airport, 2. City, 3. Country, 4. Coordinates, 5. Coordinates & Radius
    std::string info;
    Coordinate coordinate;
    double radius;    // For Coordinates & Radius

public:

    /**
    * @brief Constructs an instance of LocationInfo for types 1-3.
    *
    * @details This constructor initializes an instance of the LocationInfo class with the specified type and information.
    * For types 1-3, the constructor takes an integer type (representing the location type) and a string info (representing
    * the specific information about the location, such as airport code, city name, or country name). This constructor is
    * designed to create LocationInfo objects for different types of locations, allowing flexibility in capturing location details.
    *
    * @param type An integer representing the type of location (1 for airport, 2 for city, 3 for country).
    * @param info A string containing specific information about the location (e.g., airport code, city name, country name).
    */
    LocationInfo(int type, const std::string& info);

    /**
    * @brief Constructs an instance of LocationInfo for type 4 (Coordinates).
    *
    * @details This constructor initializes an instance of the LocationInfo class with the specified type and coordinates.
    * For type 4 (Coordinates), the constructor takes an integer type (representing the location type) and a Coordinate object
    * containing latitude and longitude information. This constructor is designed to create LocationInfo objects for locations
    * specified by coordinates, providing a way to capture geographic information for certain operations.
    *
    * @param type An integer representing the type of location (4 for coordinates).
    * @param coordinate A Coordinate object containing latitude and longitude information for the location.
    */
    LocationInfo(int type, Coordinate coordinate);

    /**
    * @brief Constructs an instance of LocationInfo for type 5 (Coordinates & Radius).
    *
    * @details This constructor initializes an instance of the LocationInfo class with the specified type, coordinates, and radius.
    * For type 5 (Coordinates & Radius), the constructor takes an integer type (representing the location type), a Coordinate object
    * containing latitude and longitude information, and a double radius. This constructor is designed to create LocationInfo objects
    * for locations specified by coordinates with an associated search radius, enabling operations that involve a geographical area.
    *
    * @param type An integer representing the type of location (5 for coordinates & radius).
    * @param coordinate A Coordinate object containing latitude and longitude information for the location.
    * @param radius A double representing the search radius associated with the location.
    */
    LocationInfo(int type, Coordinate coordinate, double radius);

    /**
    * @brief Retrieves the type of the LocationInfo object.
    *
    * @details This method returns the type of the LocationInfo object. The type represents the category or format
    * of the location information stored in the object. It allows the program to distinguish between different types
    * of locations, such as airports, cities, countries, or coordinates with or without a radius.
    *
    * @return An integer representing the type of the LocationInfo object.
    */
    int getType() const;

    /**
    * @brief Retrieves the information stored in the LocationInfo object.
    *
    * @details This method returns the information associated with the LocationInfo object. The nature of the information
    * depends on the type of the location. For types 1-3, it represents the airport code, city name, or country name. For
    * types 4-5, it may be an empty string as the actual information is stored in the Coordinate object.
    *
    * @return A string containing the information associated with the LocationInfo object.
    */
    string getInfo() const;

    /**
    * @brief Retrieves the Coordinate object associated with the LocationInfo object.
    *
    * @details This method returns the Coordinate object stored in the LocationInfo object. The Coordinate object contains
    * latitude and longitude information for locations represented by coordinates (types 4 and 5). For other location types,
    * this method may return a default or undefined Coordinate object.
    *
    * @return A Coordinate object containing latitude and longitude information for the location (or a default object if not applicable).
    */
    Coordinate getCoordinate() const;

    /**
    * @brief Retrieves the radius associated with the LocationInfo object.
    *
    * @details This method returns the radius stored in the LocationInfo object. The radius is relevant for locations
    * represented by coordinates with a specified radius (type 5). For other location types, this method may return
    * a default or undefined radius value.
    *
    * @return A double representing the radius associated with the location (or a default value if not applicable).
    */
    double getRadius() const;

    /**
    * @brief Retrieves the location in a string format.
    *
    * @details This method returns the string format of the location considering of what type it is.
    *
    * @return A string representing the location.
    */
    string toString() const;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_LOCATIONINFO_H
