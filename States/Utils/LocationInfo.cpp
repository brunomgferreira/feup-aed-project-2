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