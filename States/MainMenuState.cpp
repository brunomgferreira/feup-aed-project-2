#include <iostream>
#include "MainMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/GetFlight/GetFlightOriginMenuState.h"
#include "States/OtherMethods/OtherMethodsMenuState.h"

MainMenuState::MainMenuState() {}

void MainMenuState::display() const {
cout <<"\033[94m" << "===== MAIN MENU =====" << "\033[0;0m" << endl;
cout << "   1. Statistics     " << endl;
cout << "   2. Get Flight     " << endl;
cout << "   3. Other Methods  " << endl;
cout << "   q. Exit           " << endl;
cout << "\033[94m" <<"---------------------"<< "\033[0m" << endl;
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
                cout << "\033[1;31m" << "Invalid choice. Please try again." << "\033[0m"  << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;
}