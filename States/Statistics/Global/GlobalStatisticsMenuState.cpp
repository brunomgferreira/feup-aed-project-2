#include <iostream>
#include "GlobalStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"

GlobalStatisticsMenuState::GlobalStatisticsMenuState() {}

void GlobalStatisticsMenuState::display() const {
    cout << "***** Global Statistics *****" << endl;
    cout << "1. Number of Airports" << endl;
    cout << "2. Number of Cities" << endl;
    cout << "3. Number of Countries" << endl;
    cout << "4. Number of Airlines" << endl;
    cout << "5. Number of GetFlight" << endl;
    cout << "0. Statistics Menu" << endl;
}

void GlobalStatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(!isdigit(choice[0])){
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

    switch (choice[0]) {
        case '1':
            cout << "Executing Option 1 - Number of Airports." << endl;
            break;
        case '2':
            cout << "Executing Option 2 - Number of Cities." << endl;
            break;
        case '3':
            cout << "Executing Option 3 - Number of Countries." << endl;
            break;
        case '4':
            cout << "Executing Option 4 - Number of Airlines" << endl;
            break;
        case '5':
            cout << "Executing Option 5 - Number of GetFlight" << endl;
            break;
        case '0':
            app->setState(new StatisticsMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}