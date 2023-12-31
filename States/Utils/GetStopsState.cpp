#include <iostream>
#include "GetStopsState.h"
#include "TryAgainState.h"

GetStopsState::GetStopsState(State* backState, function<void(App*, int)> nextStateCallback)
        : backState(backState), nextStateCallback( nextStateCallback) {}

void GetStopsState::display() const {
    cout << "Insert number of Stops: ";
}

void GetStopsState::handleInput(App* app) {
    string stops;
    cin.ignore();
    getline(std::cin, stops);

    try {
        int stopsValue = stoi(stops);
        if (stopsValue >= 0) {
            nextStateCallback(app, stopsValue);
        } else {
            cout << "\033[31m";
            cout << "Invalid input. Please enter a valid positive integer." << endl;
            cout << "\033[0m";
            app->setState(new TryAgainState(backState, this));
        }
    } catch (const std::invalid_argument& e) {
        cout << "\033[31m";
        cout << "Invalid input. Please enter a valid integer." << endl;
        cout << "\033[0m";
        app->setState(new TryAgainState(backState, this));
    }
}