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
    cout << "q. Main Menu" << endl;
}

void GetFlightOriginMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->setState(new GetAirportState(this, [&](App *app, const string &airportCode) {
                    LocationInfo originInfo(1, airportCode);
                    app->setState(new GetFlightDestinationMenuState(originInfo));
                }));
                break;
            case '2':
                app->setState(new GetCityState(this, [&](App *app, const string &cityName) {
                    LocationInfo originInfo(2, cityName);
                    app->setState(new GetFlightDestinationMenuState(originInfo));
                }));
                break;
            case '3':
                app->setState(new GetCountryState(this, [&](App *app, const string &countryName) {
                    LocationInfo originInfo(3, countryName);
                    app->setState(new GetFlightDestinationMenuState(originInfo));
                }));
                break;
            case '4':
                app->setState(new GetCoordinatesState(this, [&](App *app, const Coordinate &coordinate) {
                    LocationInfo originInfo(4, coordinate);
                    app->setState(new GetFlightDestinationMenuState(originInfo));
                }));
                break;
            case '5':
                app->setState(new GetCoordinatesState(this, [&](App *app, const Coordinate &coordinate) {
                    app->setState(new GetRadiusState([&](App *app, const int radius) {
                        // TODO radius[0]->latitude, radius[1]->longitude ou algo do género
                        // LocationInfo *originInfo = new LocationInfo(5, 0, 0, radius);
                        // app->setState(new GetFlightDestinationMenuState(originInfo));
                    }));
                }));
                break;
            case 'q':
                app->setState(new MainMenuState());
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;
}