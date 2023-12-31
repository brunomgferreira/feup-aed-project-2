#include <iostream>
#include "GetRadiusState.h"
#include "TryAgainState.h"

GetRadiusState::GetRadiusState(State* backState, function<void(App*, double)> nextStateCallback)
    : nextStateCallback(nextStateCallback), backState(backState) {}

void GetRadiusState::display() const {
    cout << "Insert radius in Km: ";
}

void GetRadiusState::handleInput(App* app) {
    string inputRadius;
    std::cin.ignore();
    std::getline(std::cin, inputRadius);

    double radius;
    try {
        radius = stod(inputRadius);
        if (radius >= 0) {
            nextStateCallback(app, radius);
        } else {
            cout << "Invalid input. Please enter a valid non-negative double." << endl;
            app->setState(new TryAgainState(backState, this));
        }
    } catch (const invalid_argument& e) {
        cout << "Invalid input. Please enter a valid double." << endl;
        app->setState(new TryAgainState(backState, this));
    }
}