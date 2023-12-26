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

    bool airlineExists = true;

    if (airlineExists) {
        nextStateCallback(app, airlineCode);
    } else {
        cout << "Airline does not exist." << endl;
        app->setState(new TryAgainState(backState, this));
    }
}