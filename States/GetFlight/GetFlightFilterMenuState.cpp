#include <iostream>
#include "GetFlightFilterMenuState.h"
#include "States/MainMenuState.h"

GetFlightFilterMenuState::GetFlightFilterMenuState(LocationInfo *originInfo, LocationInfo *destinationInfo)
    : originInfo(originInfo), destinationInfo(destinationInfo) {}

void GetFlightFilterMenuState::display() const {
    cout << "***** Filters *****" << endl;
    cout << "1. Only one airline" << endl;
    cout << "2. Set of airlines" << endl;
    cout << "3. Set of unwanted airlines" << endl;
    cout << "4. Minimize number of airlines" << endl;
    cout << "5. No filter" << endl;
    cout << "0. Main Menu" << endl;
}

void GetFlightFilterMenuState::handleInput(App* app) {
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
            // getAirline()
            break;
        case '2':
            cout << "Executing Option 2. Set of airlines" << endl;
            // getAirlines()
            break;
        case '3':
            cout << "Executing Option 3. Set of unwanted airlines" << endl;
            // getUnwantedAirlines()
            break;
        case '4':
            cout << "Executing Option 4. Minimize number of airlines" << endl;
            // ?
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