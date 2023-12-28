#include <iostream>
#include "AirlineStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"

AirlineStatisticsMenuState::AirlineStatisticsMenuState(string airlineCode) {
    this->airlineCode = airlineCode;
}

void AirlineStatisticsMenuState::display() const {
    cout << "***** Airline Statistics *****" << endl;
    cout << "1. Number of Flights" << endl;
    cout << "2. Number of Destinations" << endl;
    cout << "b. Statistics Menu" << endl;
    cout << "q. Main Menu" << endl;
}

void AirlineStatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                cout << "Executing Option 1 - Number of Flights." << endl;
                app->getData()->numberOfFlightsAirline(airlineCode);
                PressEnterToContinue();
                break;
            case '2':
                cout << "Executing Option 2 - Number of Destinations." << endl;
                PressEnterToContinue();
                break;
            case 'b':
                app->setState(new StatisticsMenuState());
                break;
            case 'q':
                app->setState(new MainMenuState());
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;
}