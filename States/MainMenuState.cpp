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
cout << "q. Exit" << endl;
}

void MainMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
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
            case 'q':
                cout << "Exiting the program." << endl;
                app->setState(nullptr);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;
}