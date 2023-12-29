#include <cmath>
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
    const double R = 6371.0;

    double lat1= latitude * M_PI / 180.0;
    double lon1 = longitude * M_PI / 180.0;
    double lat2 = coordinate.latitude * M_PI / 180.0;
    double lon2 = coordinate.longitude* M_PI / 180.0;

    double latDiff = lat2- lat1;
    double lonDiff = lon2 - lon1;

    double a = sin(latDiff/ 2) * sin(latDiff / 2) +
               cos(lat1) * cos(lat2) *
               sin(lonDiff/ 2) * sin(lonDiff / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;

    return distance;
}