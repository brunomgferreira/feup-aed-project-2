#include <iostream>
#include "SubMenuState.h"
#include "MainMenuState.h"

SubMenuState::SubMenuState() {}

void SubMenuState::display() const {
    cout << "***** Sub Menu *****" << endl;
    cout << "1. Option 1" << endl;
    cout << "2. Option 2" << endl;
    cout << "0. Main Menu" << endl;
}

void SubMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(!isdigit(choice[0])){
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

    switch (choice[0]) {
        case '1':
            cout << "Executing Option 1 from Sub Menu." << endl;
            break;
        case '2':
            cout << "Executing Option 2 from Sub Menu." << endl;
            break;
        case '0':
            app->setState(new MainMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}