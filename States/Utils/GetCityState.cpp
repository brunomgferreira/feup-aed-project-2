#include <iostream>
#include "GetCityState.h"
#include "TryAgainState.h"

GetCityState::GetCityState(function<void(App*, const string&)> nextStateCallback)
    : nextStateCallback(nextStateCallback) {}

void GetCityState::display() const {
    cout << "Insert city name: ";
}

void GetCityState::handleInput(App* app) {
    string cityName;
    std::cin.ignore();
    std::getline(std::cin, cityName);

    bool cityExists = false;

    if (cityExists) {
        nextStateCallback(app, cityName);
    } else {
        cout << "City does not exist." << endl;
        app->setState(new TryAgainState(this));
    }
}