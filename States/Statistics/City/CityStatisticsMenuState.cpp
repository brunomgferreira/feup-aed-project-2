#include <iostream>
#include "CityStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"


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
    cout << "0. Statistics Menu" << endl;
}

void CityStatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (!isdigit(choice[0])) {
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

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
        case '0':
            app->setState(new StatisticsMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}