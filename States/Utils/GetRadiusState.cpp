#include <iostream>
#include "GetRadiusState.h"

GetRadiusState::GetRadiusState(function<void(App*, double)> nextStateCallback)
    : nextStateCallback(nextStateCallback) {}

void GetRadiusState::display() const {
    cout << "Insert radius in Km: ";
}

void GetRadiusState::handleInput(App* app) {
    string inputRadius;
    std::cin.ignore();
    std::getline(std::cin, inputRadius);

    double radius = 0;
    try {
         radius = std::stod(inputRadius);
    } catch (...) {
        cout << "Invalid radius, please try again.\n";
    }

    nextStateCallback(app, radius);
}