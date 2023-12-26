#include <iostream>
#include "AirportStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"

AirportStatisticsMenuState::AirportStatisticsMenuState(string airportCode) {
    this->airportCode = airportCode;
}

void AirportStatisticsMenuState::display() const {
    cout << "***** Airport Statistics *****" << endl;
    cout << "1. Number of Flights" << endl;
    cout << "2. Number of Airlines" << endl;
    cout << "3. Number of Destinations" << endl;
    cout << "4. Reachable Destinations with max X stops" << endl;
    cout << "b. Statistics Menu" << endl;
    cout << "q. Main Menu" << endl;
}

void AirportStatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                cout << "Executing Option 1 - Number of Flight" << endl;
                PressEnterToContinue();
                break;
            case '2':
                cout << "Executing Option 2 - Number of Airlines" << endl;
                PressEnterToContinue();
                break;
            case '3':
                cout << "Executing Option 3 - Number of Destinations." << endl;
                PressEnterToContinue();
                break;
            case '4':
                cout << "Executing Option 4. - Reachable Destinations with max X stops" << endl;
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