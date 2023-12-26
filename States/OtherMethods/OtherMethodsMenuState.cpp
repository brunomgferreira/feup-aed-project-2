#include <iostream>
#include "OtherMethodsMenuState.h"
#include "States/MainMenuState.h"

OtherMethodsMenuState::OtherMethodsMenuState() {}

void OtherMethodsMenuState::display() const {
    cout << "***** Other Methods *****" << endl;
    cout << "1. Reachable airports with X max flights" << endl;
    cout << "2. Reachable cities with X max flights" << endl;
    cout << "3. Reachable countries with X max flights" << endl;
    cout << "4. Maximum trip" << endl;
    cout << "5. Top K airport with the greatest air traffic capacity" << endl;
    cout << "6. Essential airports" << endl;
    cout << "0. Main Menu" << endl;
}

void OtherMethodsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(!isdigit(choice[0])){
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

    switch (choice[0]) {
        case '1':
            cout << "Executing Option 1. Maximum trip" << endl;
            PressEnterToContinue();
            break;
        case '2':
            cout << "Executing Option 2. Top K airport with the greatest air traffic capacity" << endl;
            PressEnterToContinue();
            break;
        case '3':
            cout << "Executing Option 3. Essential airports" << endl;
            PressEnterToContinue();
            break;
        case '0':
            app->setState(new MainMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}