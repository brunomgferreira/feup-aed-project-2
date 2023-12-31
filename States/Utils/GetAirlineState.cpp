#include <iostream>
#include "GetAirlineState.h"
#include "TryAgainState.h"

GetAirlineState::GetAirlineState(State* backState, function<void(App*, const string&)> nextStateCallback)
    : backState(backState), nextStateCallback(nextStateCallback) {}

void GetAirlineState::display() const {
    cout << "Insert airline code: ";
}

void GetAirlineState::handleInput(App* app) {
    string airlineCode;
    std::cin.ignore();
    std::getline(std::cin, airlineCode);

    bool airlineExists = app->getData()->airlineExists(airlineCode);

    if (airlineExists) {
        nextStateCallback(app, airlineCode);
    } else {
        cout << "\033[31m";
        cout << "Airline does not exist." << endl;
        cout << "\033[0m";
        app->setState(new TryAgainState(backState, this));
    }
}