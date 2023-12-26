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

    bool countryExists = true;

    if (countryExists) {
        nextStateCallback(app, countryName);
    } else {
        cout << "Country does not exist." << endl;
        app->setState(new TryAgainState(backState, this));
    }
}