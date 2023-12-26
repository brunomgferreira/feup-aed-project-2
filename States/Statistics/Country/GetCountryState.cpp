#include <iostream>
#include "GetCountryState.h"
#include "States/TryAgainState.h"
#include "CountryStatisticsMenuState.h"

GetCountryState::GetCountryState() {}

void GetCountryState::display() const {
    cout << "Insert country name: ";
}

void GetCountryState::handleInput(App* app) {
    string countryName;
    std::cin.ignore();
    std::getline(std::cin, countryName);

    bool countryExists = true;

    if (countryExists) {
        app->setState(new CountryStatisticsMenuState(countryName));
    } else {
        cout << "Country does not exist." << endl;
        app->setState(new TryAgainState(this));
    }
}