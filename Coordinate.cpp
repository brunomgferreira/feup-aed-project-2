#include "Coordinate.h"

Coordinate::Coordinate(double latitude, double longitude)
    : latitude(latitude), longitude(longitude) {}

double Coordinate::getLatitude() const {
    return latitude;
}


double Coordinate::getLongitude() const {
    return longitude;
}


double Coordinate::distanceTo(const Coordinate& coordinate) const {





}