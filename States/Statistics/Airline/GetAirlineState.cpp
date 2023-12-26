#include <iostream>
#include "GetAirlineState.h"
#include "States/TryAgainState.h"
#include "AirlineStatisticsMenuState.h"

GetAirlineState::GetAirlineState() {}

void GetAirlineState::display() const {
    cout << "Insert airline code: ";
}

void GetAirlineState::handleInput(App* app) {
    string airlineCode;
    std::cin.ignore();
    std::getline(std::cin, airlineCode);

    bool airlineExists = true;

    if (airlineExists) {
        app->setState(new AirlineStatisticsMenuState(airlineCode));
    } else {
        cout << "Airline does not exist." << endl;
        app->setState(new TryAgainState(this));
    }
}