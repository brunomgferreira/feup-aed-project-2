#include <iostream>
#include "GetAirportState.h"
#include "States/TryAgainState.h"
#include "AirportStatisticsMenuState.h"

GetAirportState::GetAirportState() {}

void GetAirportState::display() const {
    cout << "Insert airport code: ";
}

void GetAirportState::handleInput(App* app) {
    string airportCode;
    std::cin.ignore();
    std::getline(std::cin, airportCode);

    bool airportExists = true;

    if (airportExists) {
        app->setState(new AirportStatisticsMenuState(airportCode));
    } else {
        cout << "Airport does not exist." << endl;
        app->setState(new TryAgainState(this));
    }
}