#include <iostream>
#include "GetFlightFilterMenuState.h"
#include "States/MainMenuState.h"

GetFlightsFilterMenuState::GetFlightsFilterMenuState() {}

void GetFlightsFilterMenuState::display() const {
    cout << "***** Filters *****" << endl;
    cout << "1. Only one airline" << endl;
    cout << "2. Set of airlines" << endl;
    cout << "3. Set of unwanted airlines" << endl;
    cout << "4. Minimize number of airlines" << endl;
    cout << "5. No filter" << endl;
    cout << "0. Main Menu" << endl;
}

void GetFlightsFilterMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(!isdigit(choice[0])){
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

    switch (choice[0]) {
        case '1':
            cout << "Executing Option 1. Only one airline" << endl;
            break;
        case '2':
            cout << "Executing Option 2. Set of airlines" << endl;
            break;
        case '3':
            cout << "Executing Option 3. Set of unwanted airlines" << endl;
            break;
        case '4':
            cout << "Executing Option 4. Minimize number of airlines" << endl;
            break;
        case '5':
            cout << "Executing Option 5. No filter" << endl;
            break;
        case '0':
            app->setState(new MainMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}