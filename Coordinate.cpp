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
    const double R = 6371.0; // Earth radius in kilometers

    // Convert degrees to radians
    double lat1= latitude * M_PI / 180.0;
    double lon1 = longitude * M_PI / 180.0;
    double lat2 = coordinate.latitude * M_PI / 180.0;
    double lon2 = coordinate.longitude* M_PI / 180.0;

    // Calculate differences in latitude and longitude
    double delta_lat = lat2_rad - lat1_rad;
    double delta_lon = lon2_rad - lon1_rad;

    // Apply Haversine formula
    double a = sin(delta_lat / 2) * sin(delta_lat / 2) +
               cos(lat1_rad) * cos(lat2_rad) *
               sin(delta_lon / 2) * sin(delta_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;

    return distance;
}