#include <iostream>
#include "CityStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"


CityStatisticsMenuState::CityStatisticsMenuState(string cityName) {
    this->cityName = cityName;
}

void CityStatisticsMenuState::display() const {
    cout << "***** City Statistics *****" << endl;
    cout << "1. Number of Airports" << endl;
    cout << "2. Number of Destinations" << endl;
    cout << "3. Number of Airlines" << endl;
    cout << "4. Number of Flights" << endl;
    cout << "5. Reachable Destinations with max X stops" << endl;
    cout << "b. Statistics Menu" << endl;
    cout << "q. Main Menu" << endl;
}

void CityStatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                cout << "Executing Option 1 - Number of Airports." << endl;
                PressEnterToContinue();
                break;
            case '2':
                cout << "Executing Option 2 - Number of Destinations." << endl;
                PressEnterToContinue();
                break;
            case '3':
                cout << "Executing Option 3 - Number of Airlines" << endl;
                PressEnterToContinue();
                break;
            case '4':
                cout << "Executing Option 4 - Number of Flights" << endl;
                PressEnterToContinue();
                break;
            case '5':
                cout << "Executing Option 5. - Reachable Destinations with max X stops" << endl;
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