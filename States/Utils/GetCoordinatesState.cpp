#include <iostream>
#include "GetCoordinatesState.h"
#include "TryAgainState.h"

GetCoordinatesState::GetCoordinatesState(State* backState, function<void(App*, const Coordinate&)> nextStateCallback)
    : nextStateCallback(nextStateCallback), backState(backState){}

void GetCoordinatesState::display() const {
    cout << "Insert coordinates [e.g 13.24,65.13] : ";
}

void GetCoordinatesState::handleInput(App* app) {
    string inputCoordinates;
    std::cin.ignore();
    std::getline(std::cin, inputCoordinates);

    stringstream ss(inputCoordinates);
    double latitude, longitude;
    latitude = longitude = 0;
    ss >> latitude;
    ss.ignore(10, ',');
    ss >> longitude;
    cout << latitude << "," << longitude << '\n';
    if (latitude <= 90 && latitude >= -90 && longitude <=180 && longitude >=-180){
        Coordinate coordinate(latitude, longitude);
        nextStateCallback(app, coordinate);
    } else {
        cout << "Not a valid coordinate. "
                " -90 <= latitude <= 90 |"
                " -180 <= longitude <= 180" << endl;
        app->setState(new TryAgainState(backState, this));
    }
}