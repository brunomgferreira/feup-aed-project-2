#include <iostream>
#include "MainMenuState.h"
#include "SubMenuState.h"

MainMenuState::MainMenuState() {}

void MainMenuState::display() const {
cout << "***** Main Menu *****" << endl;
cout << "1. Sub Menu" << endl;
cout << "2. Option 2" << endl;
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
            app->setState(new SubMenuState());
            break;
        case '2':
            cout << "Executing Option 2 from Main Menu." << endl;
            break;
        case '0':
            cout << "Exiting the program." << endl;
            app->setState(nullptr);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}