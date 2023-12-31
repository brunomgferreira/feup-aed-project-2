#include <iostream>
#include <limits>
#include "GetRadiusState.h"
#include "TryAgainState.h"

GetRadiusState::GetRadiusState(State* backState, function<void(App*, double)> nextStateCallback)
    : nextStateCallback(nextStateCallback), backState(backState) {}

void GetRadiusState::display() const {
    cout << "Insert radius in Km [e.g 13.74]: ";
}

void GetRadiusState::handleInput(App* app) {
    string inputRadius;
    std::getline(std::cin, inputRadius);

    double radius;
    try {
        radius = stod(inputRadius);
        if (radius >= 0) {
            nextStateCallback(app, radius);
        } else {
            cout << "\033[31m";
            cout << "Invalid input. Please enter a valid non-negative double." << endl;
            cout << "\033[0m";
            app->setState(new TryAgainState(backState, this));
        }
    } catch (const invalid_argument& e) {
        cout << "\033[31m";
        cout << "Invalid input. Please enter a valid double." << endl;
        cout << "\033[0m";
        app->setState(new TryAgainState(backState, this));
    }
}