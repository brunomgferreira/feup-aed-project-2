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
    latitude = longitude = -1000;
    ss >> latitude;
    ss.ignore(10, ',');
    ss >> longitude;
    if (latitude <= 90 && latitude >= -90 && longitude <=180 && longitude >=-180){
        Coordinate coordinate(latitude, longitude);
        nextStateCallback(app, coordinate);
    } else {
        cout << "\033[31m";
        cout << "Not a valid coordinate.\n"
                "  -90 <= latitude <= 90\n"
                " -180 <= longitude <= 180" << endl;
        cout << "\033[0m";
        app->setState(new TryAgainState(backState, this));
    }
}