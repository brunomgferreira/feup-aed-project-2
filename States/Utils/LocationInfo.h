#ifndef FLIGHT_MANAGEMENT_SYSTEM_LOCATIONINFO_H
#define FLIGHT_MANAGEMENT_SYSTEM_LOCATIONINFO_H

#include <string>

using namespace std;

class LocationInfo {
private:
    int type; // 1. Airport, 2. City, 3. Country, 4. Coordinates, 5. Coordinates & Radius
    std::string info;
    double latitude;  // For Coordinates
    double longitude; // For Coordinates
    double radius;    // For Coordinates & Radius

public:
    // Constructor for types 1-3
    LocationInfo(int type, const std::string& info);
    // Constructor for type 4 (Coordinates)
    LocationInfo(int type, double latitude, double longitude);
    // Constructor for type 5 (Coordinates & Radius)
    LocationInfo(int type, double latitude, double longitude, double radius);

    int getType();
    string getInfo();
    double getLatitude();
    double getLongitude();
    double getRadius();
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_LOCATIONINFO_H
