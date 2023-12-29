#ifndef FLIGHT_MANAGEMENT_SYSTEM_COORDINATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_COORDINATE_H


class Coordinate {
private:
    double latitude;
    double longitude;
public:
    Coordinate();
    Coordinate(double latitude, double longitude);

public:
    double getLatitude() const;
    double getLongitude() const;

    double distanceTo(const Coordinate& coordinate) const;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_COORDINATE_H
