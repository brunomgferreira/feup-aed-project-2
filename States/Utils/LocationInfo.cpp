#include "LocationInfo.h"

// Constructor for types 1-3
LocationInfo::LocationInfo(int type, const std::string& info)
    : type(type), info(info) {}

// Constructor for type 4 (Coordinates)
LocationInfo::LocationInfo(int type, double latitude, double longitude)
    : type(type), latitude(latitude), longitude(longitude) {}

// Constructor for type 5 (Coordinates & Radius)
LocationInfo::LocationInfo(int type, double latitude, double longitude, double radius)
    : type(type), latitude(latitude), longitude(longitude), radius(radius) {}

int LocationInfo::getType() {
    return type;
}

string LocationInfo::getInfo() {
    return info;
}

double LocationInfo::getLatitude() {
    return latitude;
}

double LocationInfo::getLongitude() {
    return longitude;
}

double LocationInfo::getRadius() {
    return radius;
}