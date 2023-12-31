#include <iostream>
#include "GetCountryState.h"
#include "TryAgainState.h"

GetCountryState::GetCountryState(State* backState, function<void(App*, const string&)> nextStateCallback)
    : backState(backState), nextStateCallback( nextStateCallback) {}

void GetCountryState::display() const {
    cout << "Insert country name: ";
}

void GetCountryState::handleInput(App* app) {
    string countryName;
    std::cin.ignore();
    std::getline(std::cin, countryName);

    bool countryExists = app->getData()->countryExists(countryName);
    if (countryExists) {
        nextStateCallback(app, countryName);
    } else {
        cout << "\033[31m";
        cout << "Country does not exist." << endl;
        cout << "\033[0m";
        app->setState(new TryAgainState(backState, this));
    }
}