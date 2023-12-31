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


    cout <<"\033[94m" << "===== TYPE OF ORIGIN =====" << "\033[0;0m" << endl;
    cout << "   1. Airport    " << endl;
    cout << "   2. City     " << endl;
    cout << "   3. Country  " << endl;
    cout << "   4. Coordinates" << endl;
    cout << "   5. Coordinates & Radius\n" << endl;
    cout << "   q. Main Menu           " << endl;
    cout << "\033[94m" <<"--------------------------"<< "\033[0m" << endl;
    cout << "Enter your choice: ";

}

void GetFlightOriginMenuState::handleInput(App* app) {
    string choice;
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
                    app->setState(new GetRadiusState([&](App *app, double radius) {
                        LocationInfo originInfo = LocationInfo(5, coordinate, radius);
                        app->setState(new GetFlightDestinationMenuState(originInfo));
                    }));
                }));
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