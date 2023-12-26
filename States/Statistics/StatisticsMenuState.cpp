#include <iostream>
#include "StatisticsMenuState.h"
#include "States/MainMenuState.h"
#include "States/Statistics/Global/GlobalStatisticsMenuState.h"
#include "States/Statistics/Airline/AirlineStatisticsMenuState.h"
#include "States/Statistics/Country/GetCountryState.h"
#include "States/Statistics/City/GetCityState.h"
#include "States/Statistics/Airport/GetAirportState.h"
#include "States/Statistics/Airline/GetAirlineState.h"

StatisticsMenuState::StatisticsMenuState() {}

void StatisticsMenuState::display() const {
    cout << "***** Statistics *****" << endl;
    cout << "1. Global" << endl;
    cout << "2. Country" << endl;
    cout << "3. City" << endl;
    cout << "4. Airline" << endl;
    cout << "5. Airport" << endl;
    cout << "0. Main Menu" << endl;
}

void StatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(!isdigit(choice[0])){
        cout << "Invalid input. Please enter a valid integer choice." << endl;
        return;
    }

    switch (choice[0]) {
        case '1':
            app->setState(new GlobalStatisticsMenuState());
            break;
        case '2':
            app->setState(new GetCountryState());
            break;
        case '3':
            app->setState(new GetCityState());
            break;
        case '4':
            app->setState(new GetAirlineState());
            break;
        case '5':
            app->setState(new GetAirportState());
            break;
        case '0':
            app->setState(new MainMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}