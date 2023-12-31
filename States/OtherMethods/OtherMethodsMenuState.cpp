#include <iostream>
#include "OtherMethodsMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetTopState.h"

OtherMethodsMenuState::OtherMethodsMenuState() {}

void OtherMethodsMenuState::display() const {
    cout << "\033[94m";
    cout << "===== OTHER METHODS =====" << endl;
    cout << "\033[0m";
    cout << "   1. Maximum trip" << endl;
    cout << "   2. Top K airport with the greatest air traffic capacity" << endl; //input problem
    cout << "   3. Essential airports\n" << endl;
    cout << "   q. Main Menu" << endl;
    cout << "\033[94m";
    cout << "-------------------------" << endl;
    cout << "\033[0m";
    cout << "Enter your choice: ";
}

void OtherMethodsMenuState::handleInput(App* app) {
    string choice;
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->getData()->maximumTrip();
                PressEnterToContinue();
                break;
            case '2':
                app->setState(new GetTopState(this, [&](App *app, int top) {
                    app->getData()->topKAirports(top);
                    PressEnterToContinue(1);
                    app->setState(this);
                }));
                break;
            case '3':
                app->getData()->essentialAirports();
                PressEnterToContinue();
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