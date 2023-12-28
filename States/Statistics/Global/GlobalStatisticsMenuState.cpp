#include <iostream>
#include "GlobalStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"

GlobalStatisticsMenuState::GlobalStatisticsMenuState() {}

void GlobalStatisticsMenuState::display() const {
    cout << "***** Global Statistics *****" << endl;
    cout << "1. Number of Airports" << endl;
    cout << "2. Number of Cities" << endl;
    cout << "3. Number of Countries" << endl;
    cout << "4. Number of Airlines" << endl;
    cout << "5. Number of Flights" << endl;
    cout << "b. Statistics Menu" << endl;
    cout << "q. Main Menu" << endl;
}

void GlobalStatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                cout << "Executing Option 1 - Number of Airports." << endl;
                app->getData()->numberOfAirports();
                PressEnterToContinue();
                break;
            case '2':
                cout << "Executing Option 2 - Number of Cities." << endl;
                app->getData()->numberOfCities();
                PressEnterToContinue();
                break;
            case '3':
                cout << "Executing Option 3 - Number of Countries." << endl;
                app->getData()->numberOfCountries();
                PressEnterToContinue();
                break;
            case '4':
                cout << "Executing Option 4 - Number of Airlines" << endl;
                app->getData()->numberOfAirlines();
                PressEnterToContinue();
                break;
            case '5':
                cout << "Executing Option 5 - Number of Flights" << endl;
                app->getData()->numberOfFlights();
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