#ifndef FLIGHT_MANAGEMENT_SYSTEM_LOCATIONINFO_H
#define FLIGHT_MANAGEMENT_SYSTEM_LOCATIONINFO_H

#include <string>
#include "Coordinate.h"

using namespace std;

class LocationInfo {
private:
    int type; // 1. Airport, 2. City, 3. Country, 4. Coordinates, 5. Coordinates & Radius
    std::string info;
    Coordinate coordinate;
    double radius;    // For Coordinates & Radius

public:
    // Constructor for types 1-3
    LocationInfo(int type, const std::string& info);
    // Constructor for type 4 (Coordinates)
    LocationInfo(int type, Coordinate coordinate);
    // Constructor for type 5 (Coordinates & Radius)
    LocationInfo(int type, Coordinate coordinate, double radius);

    int getType() const;
    string getInfo() const;
    Coordinate getCoordinate() const;
    double getRadius() const;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_LOCATIONINFO_H
