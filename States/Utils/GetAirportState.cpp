#include <iostream>
#include "GetAirportState.h"
#include "TryAgainState.h"

GetAirportState::GetAirportState(State* backState, function<void(App*, const string&)> nextStateCallback)
    : backState(backState), nextStateCallback(nextStateCallback) {}

void GetAirportState::display() const {
    cout << "Insert airport code: ";
}

void GetAirportState::handleInput(App* app) {
    string airportCode;
    std::cin.ignore();
    std::getline(std::cin, airportCode);

    bool airportExists = app->getData()->airportExists(airportCode);

    if (airportExists) {
        nextStateCallback(app, airportCode);
    } else {
        cout << "Airport does not exist." << endl;
        app->setState(new TryAgainState(backState, this));
    }
}