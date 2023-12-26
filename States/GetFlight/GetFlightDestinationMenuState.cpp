#include <iostream>
#include "GetFlightDestinationMenuState.h"
#include "States/MainMenuState.h"

GetFlightDestinationMenuState::GetFlightDestinationMenuState() {}

void GetFlightDestinationMenuState::display() const {
    cout << "***** Type of Destination *****" << endl;
    cout << "1. Airport" << endl;
    cout << "2. City" << endl;
    cout << "3. Country" << endl;
    cout << "4. Coordinates" << endl;
    cout << "5. Coordinates & Radius" << endl;
    cout << "0. Main Menu" << endl;
}

void GetFlightDestinationMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(!isdigit(choice[0])){
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

    switch (choice[0]) {
        case '1':
            cout << "Executing Option 1. Airport" << endl;
            break;
        case '2':
            cout << "Executing Option 2. City" << endl;
            break;
        case '3':
            cout << "Executing Option 3. Country" << endl;
            break;
        case '4':
            cout << "Executing Option 4. Coordinates" << endl;
            break;
        case '5':
            cout << "Executing Option 5. Coordinates & Radius" << endl;
            break;
        case '0':
            app->setState(new MainMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}