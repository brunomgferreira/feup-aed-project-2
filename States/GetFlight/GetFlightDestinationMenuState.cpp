#include <iostream>
#include "GetFlightDestinationMenuState.h"
#include "GetFlightFilterMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetAirportState.h"
#include "States/Utils/GetCityState.h"
#include "States/Utils/GetCountryState.h"
#include "States/Utils/GetCoordinatesState.h"
#include "States/Utils/GetRadiusState.h"
#include "GetFlightOriginMenuState.h"

GetFlightDestinationMenuState::GetFlightDestinationMenuState(const LocationInfo& originInfo)
    : originInfo(originInfo) {}

void GetFlightDestinationMenuState::display() const {
    cout << "***** Type of Destination *****" << endl;
    cout << "1. Airport" << endl;
    cout << "2. City" << endl;
    cout << "3. Country" << endl;
    cout << "4. Coordinates" << endl;
    cout << "5. Coordinates & Radius" << endl;
    cout << "b. Go Back" << endl;
    cout << "q. Main Menu" << endl;
}

void GetFlightDestinationMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->setState(new GetAirportState(this, [&](App *app, const string &airportCode) {
                    LocationInfo destinationInfo(1, airportCode);
                    app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
                }));
                break;
            case '2':
                app->setState(new GetCityState(this, [&](App *app, const string &cityName) {
                    LocationInfo destinationInfo(2, cityName);
                    app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
                }));
                break;
            case '3':
                app->setState(new GetCountryState(this, [&](App *app, const string &countryName) {
                    LocationInfo destinationInfo(3, countryName);
                    app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
                }));
                break;
            case '4':
                app->setState(new GetCoordinatesState(this, [&](App *app, const Coordinate &coordinates) {
                    LocationInfo destinationInfo(4, coordinates);
                    app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
                }));
                break;
            case '5':
                app->setState(new GetCoordinatesState(this, [&](App *app, const Coordinate &coordinates) {
                    app->setState(new GetRadiusState([&](App *app, const int radius) {
                        // TODO radius[0]->latitude, radius[1]->longitude ou algo do género
                       // LocationInfo *destinationInfo = new LocationInfo(5, 0, 0, radius);
                       // app->setState(new GetFlightFilterMenuState(originInfo, destinationInfo));
                    }));
                }));
                break;
            case 'b':
                app->setState(new GetFlightOriginMenuState());
                break;
            case 'q':
                app->setState(new MainMenuState());
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;
}