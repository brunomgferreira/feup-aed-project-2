#include "GetTopState.h"
#include <iostream>
#include "TryAgainState.h"

GetTopState::GetTopState(State* backState, function<void(App*, int)> nextStateCallback)
        : backState(backState), nextStateCallback( nextStateCallback) {}

void GetTopState::display() const {
    cout << "Insert number of Stops: ";
}

void GetTopState::handleInput(App* app) {
    string top;
    cin.ignore();
    getline(std::cin, top);

    try {
        int topValue = stoi(top);
        if ((topValue > 0) && (topValue <= 3019)){
            nextStateCallback(app, topValue);
        } else {
            cout << "Invalid input. Please enter a valid positive integer not greater than 3019 (number of airports)." << endl;
            app->setState(new TryAgainState(backState, this));
        }
    } catch (const std::invalid_argument& e) {
        cout << "Invalid input. Please enter a valid integer." << endl;
        app->setState(new TryAgainState(backState, this));
    }
}