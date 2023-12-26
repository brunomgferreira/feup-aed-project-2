#include <iostream>
#include "GetAirportState.h"
#include "TryAgainState.h"

GetAirportState::GetAirportState(function<void(App*, const string&)> nextStateCallback)
    : nextStateCallback(nextStateCallback) {}

void GetAirportState::display() const {
    cout << "Insert airport code: ";
}

void GetAirportState::handleInput(App* app) {
    string airportCode;
    std::cin.ignore();
    std::getline(std::cin, airportCode);

    bool airportExists = true;

    if (airportExists) {
        nextStateCallback(app, airportCode);
    } else {
        cout << "Airport does not exist." << endl;
        app->setState(new TryAgainState(this));
    }
}