#include <iostream>
#include "GetCoordinatesState.h"

GetCoordinatesState::GetCoordinatesState(function<void(App*, const string&)> nextStateCallback)
    : nextStateCallback(nextStateCallback) {}

void GetCoordinatesState::display() const {
    cout << "Insert coordinates: ";
}

void GetCoordinatesState::handleInput(App* app) {
    string coordinates;
    std::cin.ignore();
    std::getline(std::cin, coordinates);

    // TODO check coordinates format
    nextStateCallback(app, coordinates);
}