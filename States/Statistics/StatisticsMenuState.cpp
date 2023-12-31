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

    cout <<"\033[94m" << "===== STATISTICS =====" << "\033[0m" << endl;
    cout << "    1. Global    " << endl;
    cout << "    2. Country     " << endl;
    cout << "    3. City  " << endl;
    cout << "    4. Airline" << endl;
    cout << "    5. Airport\n" << endl;
    cout << "    q. Main Menu           " << endl;
    cout << "\033[1;94m" <<"----------------------"<< "\033[0m" << endl;
    cout << "Enter your choice: ";
}

void StatisticsMenuState::handleInput(App* app) {
    string choice;
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