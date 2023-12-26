#include <iostream>
#include "GetFlightDestinationMenuState.h"
#include "GetFlightFilterMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetAirportState.h"
#include "States/Utils/GetCityState.h"
#include "States/Utils/GetCountryState.h"
#include "States/Utils/GetCoordinatesState.h"
#include "States/Utils/GetRadiusState.h"

GetFlightDestinationMenuState::GetFlightDestinationMenuState(LocationInfo *originInfo)
    : originInfo(originInfo) {}

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
            app->setState(new GetAirportState(this, [&](App* app, const string& airportCode) {
                LocationInfo *destinationInfo = new LocationInfo(1, airportCode);
                app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
            }));
            break;
        case '2':
            app->setState(new GetCityState(this, [&](App* app, const string& cityName) {
                LocationInfo *destinationInfo = new LocationInfo(2, cityName);
                app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
            }));
            break;
        case '3':
            app->setState(new GetCountryState(this, [&](App* app, const string& countryName) {
                LocationInfo *destinationInfo = new LocationInfo(3, countryName);
                app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
            }));
            break;
        case '4':
            app->setState(new GetCoordinatesState([&](App* app, const string& coordinates) {
                // TODO radius[0]->latitude, radius[1]->longitude ou algo do género
                LocationInfo *destinationInfo = new LocationInfo(4, 0, 0);
                app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
            }));
            break;
        case '5':
            app->setState(new GetCoordinatesState([&](App* app, const string& coordinates) {
                app->setState(new GetRadiusState([&](App* app, const int radius) {
                    // TODO radius[0]->latitude, radius[1]->longitude ou algo do género
                    LocationInfo *destinationInfo = new LocationInfo(5, 0, 0, radius);
                    app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
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