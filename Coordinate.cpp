#include "Coordinate.h"

Coordinate::Coordinate(double latitude, double longitude)
    : latitude(latitude), longitude(longitude) {}

double Coordinate::getLatitude() const {
    return latitude;
}

void Coordinate::setLatitude(double latitude) {
    Coordinate::latitude = latitude;
}

double Coordinate::getLongitude() const {
    return longitude;
}

void Coordinate::setLongitude(double longitude) {
    Coordinate::longitude = longitude;
}