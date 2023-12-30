#include <iostream>
#include "OtherMethodsMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetTopState.h"

OtherMethodsMenuState::OtherMethodsMenuState() {}

void OtherMethodsMenuState::display() const {
    cout << "***** Other Methods *****" << endl;
    cout << "1. Maximum trip" << endl;
    cout << "2. Top K airport with the greatest air traffic capacity" << endl; //input problem
    cout << "3. Essential airports" << endl;
    cout << "q. Main Menu" << endl;
}

void OtherMethodsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                cout << "Executing Option 1. Maximum trip" << endl;
                app->getData()->maximumTrip();
                PressEnterToContinue();
                break;
            case '2':
                cout << "Executing Option 2. Top K airport with the greatest air traffic capacity" << endl;
                app->setState(new GetTopState(this, [&](App *app, int top) {
                    app->getData()->topKAirports(top);
                    PressEnterToContinue();
                    app->setState(this);
                }));
                break;
            case '3':
                cout << "Executing Option 3. Essential airports" << endl;
                PressEnterToContinue();
                break;
            case 'q':
                app->setState(new MainMenuState());
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;
}