#include <iostream>
#include "AirlineStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"

AirlineStatisticsMenuState::AirlineStatisticsMenuState() {}

void AirlineStatisticsMenuState::display() const {
    cout << "***** Airline Statistics *****" << endl;
    cout << "1. Number of Destinations" << endl;
    cout << "2. Number of GetFlight" << endl;
    cout << "0. Statistics Menu" << endl;
}

void AirlineStatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(!isdigit(choice[0])){
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

    switch (choice[0]) {
        case '1':
            cout << "Executing Option 2 - Number of GetFlight." << endl;
            break;
        case '2':
            cout << "Executing Option 3 - Number of Destinations." << endl;
            break;
        case '0':
            app->setState(new StatisticsMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}