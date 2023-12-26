#include <iostream>
#include "StatisticsMenuState.h"
#include "States/MainMenuState.h"
#include "States/Statistics/Global/GlobalStatisticsMenuState.h"
#include "States/Statistics/Airline/AirlineStatisticsMenuState.h"
#include "States/Utils/GetCountryState.h"
#include "States/Utils/GetCityState.h"
#include "States/Utils/GetAirportState.h"
#include "States/Utils/GetAirlineState.h"
#include "States/Statistics/Airport/AirportStatisticsMenuState.h"
#include "States/Statistics/Country/CountryStatisticsMenuState.h"
#include "States/Statistics/City/CityStatisticsMenuState.h"

StatisticsMenuState::StatisticsMenuState() {}

void StatisticsMenuState::display() const {
    cout << "***** Statistics *****" << endl;
    cout << "1. Global" << endl;
    cout << "2. Country" << endl;
    cout << "3. City" << endl;
    cout << "4. Airline" << endl;
    cout << "5. Airport" << endl;
    cout << "q. Main Menu" << endl;
}

void StatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->setState(new GlobalStatisticsMenuState());
                break;
            case '2':
                app->setState(new GetCountryState(this, [&](App *app, const string &countryName) {
                    app->setState(new CountryStatisticsMenuState(countryName));
                }));
                break;
            case '3':
                app->setState(new GetCityState(this, [&](App *app, const string &cityName) {
                    app->setState(new CityStatisticsMenuState(cityName));
                }));
                break;
            case '4':
                app->setState(new GetAirlineState(this, [&](App *app, const string &airlineCode) {
                    app->setState(new AirlineStatisticsMenuState(airlineCode));
                }));
                break;
            case '5':
                app->setState(new GetAirportState(this, [&](App *app, const string &airportCode) {
                    app->setState(new AirportStatisticsMenuState(airportCode));
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