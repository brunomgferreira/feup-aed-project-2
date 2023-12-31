#include <iostream>
#include <iomanip>
#include "AirlineStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"

AirlineStatisticsMenuState::AirlineStatisticsMenuState(string airlineCode) {
    this->airlineCode = airlineCode;
}

void AirlineStatisticsMenuState::display() const {
    cout << "\033[94m";
    cout << "===== AIRLINE STATISTICS =====" << endl;
    cout << "\033[93m";
    cout << setw(15+airlineCode.size()/2) <<airlineCode << endl;
    cout << "\033[0m";
    cout << " Number of:" << endl;
    cout << "   1. Flights" << endl;
    cout << "   2. Destinations\n" << endl;
    cout << "   b. Statistics Menu" << endl;
    cout << "   q. Main Menu" << endl;
    cout << "\033[94m";
    cout << "-------------------------------" << endl;
    cout << "\033[0m";
    cout << "Enter your choice: ";
}

void AirlineStatisticsMenuState::handleInput(App* app) {
    string choice;
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->getData()->numberOfFlightsAirline(airlineCode);
                PressEnterToContinue();
                break;
            case '2':
                app->getData()->numberOfDestinationsAirline(airlineCode);
                PressEnterToContinue();
                break;
            case 'b':
                app->setState(new StatisticsMenuState());
                break;
            case 'q':
                app->setState(new MainMenuState());
                break;
            default:
                cout << "\033[31m";
                cout << "Invalid choice. Please try again." << endl;
                cout << "\033[0m";
        }
    } else {
        cout << "\033[31m";
        cout << "Invalid input. Please enter a single character." << endl;
        cout << "\033[0m";
    }
}