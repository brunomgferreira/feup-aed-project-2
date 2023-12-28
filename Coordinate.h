#ifndef FLIGHT_MANAGEMENT_SYSTEM_COORDINATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_COORDINATE_H


class Coordinate {
private:
    double latitude;
    double longitude;
public:
    Coordinate(double latitude, double longitude);

public:
    double getLatitude() const;

    void setLatitude(double latitude);

    double getLongitude() const;

    void setLongitude(double longitude);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_COORDINATE_H
