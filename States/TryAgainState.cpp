#include <iostream>
#include "TryAgainState.h"
#include "MainMenuState.h"

TryAgainState::TryAgainState(State* currentState) {
    this->currentState = currentState;
}

void TryAgainState::display() const {
    cout << "1. Try Again" << endl;
    cout << "0. Main Menu" << endl;
}

void TryAgainState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(!isdigit(choice[0])){
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

    switch (choice[0]) {
        case '1':
            app->setState(currentState);
            break;
        case '0':
            app->setState(new MainMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}