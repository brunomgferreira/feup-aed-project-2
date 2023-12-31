#ifndef FLIGHT_MANAGEMENT_SYSTEM_COORDINATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_COORDINATE_H
#include <string>
using namespace  std;
/**
* @brief Class representing geographical coordinates in the flight management system.
*/

class Coordinate {
private:
    double latitude;
    double longitude;
public:

    /**
    * @brief Default constructor for the Coordinate class.
    *
    * @details Initializes a Coordinate object with latitude and longitude set to 0.
    */
    Coordinate();

    /**
    * @brief Parameterized constructor for the Coordinate class.
    *
    * @details Initializes a Coordinate object with the given latitude and longitude values.
    *
    * @param latitude The latitude value in degrees.
    * @param longitude The longitude value in degrees.
    */
    Coordinate(double latitude, double longitude);

    /**
    * @brief Gets the latitude value of the coordinate.
    *
    * @return The latitude value in degrees.
    */
    double getLatitude() const;

    /**
    * @brief Gets the longitude value of the coordinate.
    *
    * @return The longitude value in degrees.
    */
    double getLongitude() const;

    /**
    * @brief Calculates the great-circle distance between two coordinates using the Haversine formula.
    *
    * @param coordinate The target coordinate.
    * @return The distance between the two coordinates in kilometers.
    */
    double distanceTo(const Coordinate& coordinate) const;


    /**
    * @brief Retrieves the coordinate in a string format
    *
    * @return A string that represents the coordinate
    */
    string toString() const;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_COORDINATE_H
