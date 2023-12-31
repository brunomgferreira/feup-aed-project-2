#include <iostream>
#include "MainMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/GetFlight/GetFlightOriginMenuState.h"
#include "States/OtherMethods/OtherMethodsMenuState.h"

MainMenuState::MainMenuState() {}

void MainMenuState::display() const {
    cout << "\033[94m";
    cout << "===== MAIN MENU =====" << endl;
    cout << "\033[0m";
    cout << "   1. Statistics     " << endl;
    cout << "   2. Get Flight     " << endl;
    cout << "   3. Other Methods  \n" << endl;
    cout << "   q. Exit           " << endl;
    cout << "\033[94m";
    cout << "---------------------" << endl;
    cout << "\033[0m";
    cout << "Enter your choice: ";
}

void MainMenuState::handleInput(App* app) {
    string choice;
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
                cout << "Exiting the program..." << endl;
                app->setState(nullptr);
                break;
            default:
                cout << "\033[31m" << "Invalid choice. Please try again." << "\033[0m"  << endl;
        }
    } else  {
        cout << "\033[31m";
        cout << "Invalid input. Please enter a single character." << endl;
        cout << "\033[0m";
    }
}