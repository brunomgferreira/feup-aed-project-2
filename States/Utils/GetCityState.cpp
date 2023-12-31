#include <iostream>
#include "GetCityState.h"
#include "TryAgainState.h"

GetCityState::GetCityState(State* backState, function<void(App*, const string&)> nextStateCallback)
    : backState(backState), nextStateCallback(nextStateCallback) {}

void GetCityState::display() const {
    cout << "Insert city [city,country]: ";
}

void GetCityState::handleInput(App* app) {
    string cityName;
    std::cin.ignore();
    std::getline(std::cin, cityName);

    bool cityExists = app->getData()->cityExists(cityName);

    if (cityExists) {
        nextStateCallback(app, cityName);
    } else {
        cout << "\033[31m";
        cout << "City does not exist." << endl;
        cout << "\033[0m";
        app->setState(new TryAgainState(backState, this));
    }
}