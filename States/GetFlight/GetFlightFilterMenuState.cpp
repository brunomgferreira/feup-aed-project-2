#include <iostream>
#include <iomanip>
#include "GetFlightFilterMenuState.h"
#include "States/MainMenuState.h"
#include "GetFlightDestinationMenuState.h"
#include "States/Utils/GetAirlineSetState.h"
#include "States/Utils/MinimizeAirlinesState.h"

GetFlightFilterMenuState::GetFlightFilterMenuState(const LocationInfo& originInfo, const LocationInfo& destinationInfo)
    : originInfo(originInfo), destinationInfo(destinationInfo) {}

void GetFlightFilterMenuState::display() const {

    cout << "\033[94m";
    cout << "===== FLIGHT FILTERS =====" << endl;
    cout << "\033[0m";
    cout << "\033[93m";
    cout <<  setw(13+originInfo.toString().size()/2)<<  originInfo.toString() << endl;
    cout << setw(15) << "\uEA9A" << endl;
    cout <<  setw(13+destinationInfo.toString().size()/2)<<  destinationInfo.toString() << endl;
    cout << "\033[0m";
    cout << "   1. Set of airlines" << endl;
    cout << "   2. Set of unwanted airlines" << endl;
    cout << "   3. No filter\n" << endl;
    cout << "   b. Go Back" << endl;
    cout << "   q. Main Menu" << endl;
    cout << "\033[94m";
    cout << "-------------------------------" << endl;
    cout << "\033[0m";
    cout << "Enter your choice: ";
}

void GetFlightFilterMenuState::handleInput(App* app) {
    string choice;
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->setState(new GetAirlineSetState(this, [&](App *app,  unordered_set<string> airlineSet){
                    app->setState(new MinimizeAirlinesState([&, airlineSet](App *app, bool minimizeAirlines){
                        app->getData()->getFlights(originInfo, destinationInfo, airlineSet, false, minimizeAirlines);
                        PressEnterToContinue();
                        app->setState(new MainMenuState());
                    }));
                }));
                break;
            case '2':
                app->setState(new GetAirlineSetState(this, [&](App *app,  unordered_set<string> airlineSet){
                    app->setState(new MinimizeAirlinesState([&, airlineSet](App *app, bool minimizeAirlines){
                        app->getData()->getFlights(originInfo, destinationInfo, airlineSet, true, minimizeAirlines);
                        PressEnterToContinue();
                        app->setState(new MainMenuState());
                    }));
                }));
                break;
            case '3':
            {
                app->setState(new MinimizeAirlinesState([&](App *app, bool minimizeAirlines){
                    app->getData()->getFlights(originInfo,destinationInfo, {}, true, minimizeAirlines);
                    PressEnterToContinue();
                    app->setState(new MainMenuState());
                }));
            }
                break;
            case 'b':
                app->setState(new GetFlightDestinationMenuState(originInfo));
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