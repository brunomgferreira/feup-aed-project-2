#include <iostream>
#include "GetCityState.h"
#include "States/TryAgainState.h"
#include "CityStatisticsMenuState.h"

GetCityState::GetCityState() {}

void GetCityState::display() const {
    cout << "Insert city name: ";
}

void GetCityState::handleInput(App* app) {
    string cityName;
    std::cin.ignore();
    std::getline(std::cin, cityName);

    bool cityExists = false;

    if (cityExists) {
        app->setState(new CityStatisticsMenuState(cityName));
    } else {
        cout << "City does not exist." << endl;
        app->setState(new TryAgainState(this));
    }
}