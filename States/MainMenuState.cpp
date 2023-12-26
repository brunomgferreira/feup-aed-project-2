#include <iostream>
#include "MainMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "BestFlightMenuState.h"

MainMenuState::MainMenuState() {}

void MainMenuState::display() const {
cout << "***** Main Menu *****" << endl;
cout << "1. Statistics" << endl;
cout << "2. Search best flight" << endl;
cout << "0. Exit" << endl;
}

void MainMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(!isdigit(choice[0])){
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

    switch (choice[0]) {
        case '1':
            app->setState(new StatisticsMenuState());
            break;
        case '2':
            app->setState(new BestFlightMenuState());
            break;
        case '0':
            cout << "Exiting the program." << endl;
            app->setState(nullptr);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}