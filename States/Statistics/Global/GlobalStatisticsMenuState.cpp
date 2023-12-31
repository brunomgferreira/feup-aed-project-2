#include <iostream>
#include "GlobalStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"

GlobalStatisticsMenuState::GlobalStatisticsMenuState() {}

void GlobalStatisticsMenuState::display() const {
    cout << "\033[94m";
    cout << "===== GLOBAL STATISTICS ===== " << endl;
    cout << "\033[0m";
    cout << " Number of:     " << endl;
    cout << "   1. Airports" << endl;
    cout << "   2. Cities" << endl;
    cout << "   3. Countries" << endl;
    cout << "   4. Airlines" << endl;
    cout << "   5. Flights\n" << endl;
    cout << "   b. Statistics Menu" << endl;
    cout << "   q. Main Menu" << endl;
    cout << "\033[94m";
    cout << "------------------------------" << endl;
    cout << "\033[0m";
    cout << "Enter your choice: ";
}

void GlobalStatisticsMenuState::handleInput(App* app) {
    string choice;
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->getData()->numberOfAirports();
                PressEnterToContinue();
                break;
            case '2':
                app->getData()->numberOfCities();
                PressEnterToContinue();
                break;
            case '3':
                app->getData()->numberOfCountries();
                PressEnterToContinue();
                break;
            case '4':
                app->getData()->numberOfAirlines();
                PressEnterToContinue();
                break;
            case '5':
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