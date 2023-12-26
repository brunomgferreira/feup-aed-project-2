#include <iostream>
#include "GetFlightOriginMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetAirportState.h"
#include "GetFlightDestinationMenuState.h"
#include "States/Utils/GetCityState.h"
#include "States/Utils/GetCountryState.h"
#include "States/Utils/GetCoordinatesState.h"
#include "States/Utils/GetRadiusState.h"
#include "States/Utils/LocationInfo.h"

GetFlightOriginMenuState::GetFlightOriginMenuState() {}

void GetFlightOriginMenuState::display() const {
    cout << "***** Type of Origin *****" << endl;
    cout << "1. Airport" << endl;
    cout << "2. City" << endl;
    cout << "3. Country" << endl;
    cout << "4. Coordinates" << endl;
    cout << "5. Coordinates & Radius" << endl;
    cout << "0. Main Menu" << endl;
}

void GetFlightOriginMenuState::handleInput(App* app) {
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
            app->setState(new GetAirportState([&](App* app, const string& airportCode) {
                LocationInfo *originInfo = new LocationInfo(1, airportCode);
                app->setState(new GetFlightDestinationMenuState(originInfo));
            }));
            break;
        case '2':
            cout << "Executing Option 2. City" << endl;
            app->setState(new GetCityState([&](App* app, const string& cityName) {
                LocationInfo *originInfo = new LocationInfo(2, cityName);
                app->setState(new GetFlightDestinationMenuState(originInfo));
            }));
            break;
        case '3':
            cout << "Executing Option 3. Country" << endl;
            app->setState(new GetCountryState([&](App* app, const string& countryName) {
                LocationInfo *originInfo = new LocationInfo(3, countryName);
                app->setState(new GetFlightDestinationMenuState(originInfo));
            }));
            break;
        case '4':
            cout << "Executing Option 4. Coordinates" << endl;
            app->setState(new GetCoordinatesState([&](App* app, const string& coordinates) {
                // TODO radius[0]->latitude, radius[1]->longitude ou algo do género
                LocationInfo *originInfo = new LocationInfo(4, 0, 0);
                app->setState(new GetFlightDestinationMenuState(originInfo));
            }));
            break;
        case '5':
            cout << "Executing Option 5. Coordinates & Radius" << endl;
            app->setState(new GetCoordinatesState([&](App* app, const string& coordinates) {
                app->setState(new GetRadiusState([&](App* app, const int radius) {
                    // TODO radius[0]->latitude, radius[1]->longitude ou algo do género
                    LocationInfo *originInfo = new LocationInfo(5, 0, 0, radius);
                    app->setState(new GetFlightDestinationMenuState(originInfo));
                }));
            }));
            break;
        case '0':
            app->setState(new MainMenuState());
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}