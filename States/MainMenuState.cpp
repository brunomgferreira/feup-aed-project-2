#include <iostream>
#include "MainMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/GetFlight/GetFlightOriginMenuState.h"
#include "States/OtherMethods/OtherMethodsMenuState.h"

MainMenuState::MainMenuState() {}

void MainMenuState::display() const {
cout << "***** Main Menu *****" << endl;
cout << "1. Statistics" << endl;
cout << "2. Get Flight" << endl;
cout << "3. Other Methods" << endl;
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
            app->setState(new GetFlightOriginMenuState());
            break;
        case '3':
            app->setState(new OtherMethodsMenuState());
            break;
        case '0':
            cout << "Exiting the program." << endl;
            app->setState(nullptr);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}