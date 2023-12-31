#include <iostream>
#include "AirportStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetStopsState.h"

AirportStatisticsMenuState::AirportStatisticsMenuState(string airportCode) {
    this->airportCode = airportCode;
}

void AirportStatisticsMenuState::display() const {
    cout << "***** Airport Statistics *****" << endl;
    cout << "1. Number of different Countries that airport flies to" << endl;
    cout << "2. Number of different Airlines out of this airport" << endl;
    cout << "3. Number of Flights" << endl;
    cout << "4. Number of Destinations" << endl;
    cout << "5. Reachable Destinations with max X stops" << endl;
    cout << "b. Statistics Menu" << endl;
    cout << "q. Main Menu" << endl;
}

void AirportStatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                cout << "Executing Option 1 - Number of different Countries that airport flies to" << endl;
                app->getData()->numberOfCountriesAirport(airportCode);
                PressEnterToContinue();
                break;
            case '2':
                cout << "Executing Option 2 - Number of different Airlines out of this airport" << endl;
                app->getData()->numberOfAirlinesAirport(airportCode);
                PressEnterToContinue();
                break;
            case '3':
                cout << "Executing Option 3 - Number of Flights" << endl;
                app->getData()->numberOfFlightsAirport(airportCode);
                PressEnterToContinue();
                break;
            case '4':
                cout << "Executing Option 4 - Number of Destinations" << endl;
                app->getData()->numberOfDestinationsAirport(airportCode);
                PressEnterToContinue();
                break;
            case '5':
                cout << "Executing Option 5. - Reachable Destinations with max X stops" << endl;
                app->setState(new GetStopsState(this, [&](App *app, int stops) {
                    app->getData()->numberOfDestinationsXStopsAirport(airportCode, stops);
                    PressEnterToContinue(1);
                    app->setState(this);
                }));
                break;
            case 'b':
                app->setState(new StatisticsMenuState());
                break;
            case 'q':
                app->setState(new MainMenuState());
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;
}