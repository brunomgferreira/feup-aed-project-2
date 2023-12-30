#include <iostream>
#include "GetFlightFilterMenuState.h"
#include "States/MainMenuState.h"
#include "GetFlightDestinationMenuState.h"
#include "States/Utils/GetAirlineSetState.h"

GetFlightFilterMenuState::GetFlightFilterMenuState(const LocationInfo& originInfo, const LocationInfo& destinationInfo)
    : originInfo(originInfo), destinationInfo(destinationInfo) {}

void GetFlightFilterMenuState::display() const {
    cout << "***** Filters *****" << endl;
    cout << "1. Set of airlines" << endl;
    cout << "2. Set of unwanted airlines" << endl;
    cout << "3. Minimize number of airlines" << endl;
    cout << "4. No filter" << endl;
    cout << "b. Go Back" << endl;
    cout << "q. Main Menu" << endl;
}

void GetFlightFilterMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                cout << "Executing Option 2. Set of airlines" << endl;
                app->setState(new GetAirlineSetState(this, [&](App *app, const unordered_set<string> &airlineSet){
                    app->getData()->getFlights(originInfo, destinationInfo, airlineSet, false);
                    PressEnterToContinue();
                    app->setState(new MainMenuState());
                }));
                break;
            case '2':
                cout << "Executing Option 3. Set of unwanted airlines" << endl;
                app->setState(new GetAirlineSetState(this, [&](App *app, const unordered_set<string> &airlineSet){
                    app->getData()->getFlights(originInfo, destinationInfo, airlineSet, true);
                    PressEnterToContinue();
                    app->setState(new MainMenuState());
                }));
                break;
            case '3':
                cout << "Executing Option 4. Minimize number of airlines" << endl;
                // ?
                break;
            case '4':
            {
                cout << "Executing Option 5. No filter" << endl;
                unordered_set<string> emptyAirlineSet;
                app->getData()->getFlights(originInfo,destinationInfo, emptyAirlineSet, true);
                PressEnterToContinue();
            }
                break;
            case 'b':
                app->setState(new GetFlightDestinationMenuState(originInfo));
                break;
            case 'q':
                app->setState(new MainMenuState());
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;
}