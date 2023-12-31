#include <iomanip>
#include "LocationInfo.h"

// Constructor for types 1-3
LocationInfo::LocationInfo(int type, const std::string& info)
    : type(type), info(info) {}

// Constructor for type 4 (Coordinates)
LocationInfo::LocationInfo(int type, Coordinate coordinate)
    : type(type), coordinate(coordinate) {}

// Constructor for type 5 (Coordinates & Radius)
LocationInfo::LocationInfo(int type, Coordinate coordinate, double radius)
    : type(type), coordinate(coordinate), radius(radius) {}

int LocationInfo::getType() const{
    return type;
}

string LocationInfo::getInfo() const {
    return info;
}

Coordinate LocationInfo::getCoordinate() const {return coordinate;}

double LocationInfo::getRadius() const{
    return radius;
}

string LocationInfo::toString() const {

    switch (type) {
        case 1:
            return info;
            break;
        case 2:
            return  info;
            break;
        case 3:
            return info;
            break;
        case 4:
            return coordinate.toString();
            break;
        case 5:
            stringstream result;
            result << coordinate.toString() << " - " << fixed << setprecision(1) << radius << "Km";
            return result.str();
    }



}