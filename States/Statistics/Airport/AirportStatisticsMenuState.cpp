#include <iostream>
#include <iomanip>
#include "AirportStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetStopsState.h"

AirportStatisticsMenuState::AirportStatisticsMenuState(string airportCode) {
    this->airportCode = airportCode;
}

void AirportStatisticsMenuState::display() const {
    cout << "\033[94m";
    cout << "===== AIRPORT STATISTICS =====" << endl;
    cout << "\033[93m";
    cout << setw(14+airportCode.size()/2) <<airportCode << endl;
    cout << "\033[0m";
    cout << " Number of:" << endl;
    cout << "   1. Countries airport flies to" << endl;
    cout << "   2. Airlines out of the airport" << endl;
    cout << "   3. Flights" << endl;
    cout << "   4. Destinations\n" << endl;
    cout << "   5. Reachable Destinations with max X stops\n" << endl;
    cout << "   b. Statistics Menu" << endl;
    cout << "   q. Main Menu" << endl;
    cout << "\033[94m";
    cout << "-------------------------------" << endl;
    cout << "\033[0m";
    cout << "Enter your choice: ";
}

void AirportStatisticsMenuState::handleInput(App* app) {
    string choice;
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->getData()->numberOfCountriesAirport(airportCode);
                PressEnterToContinue();
                break;
            case '2':
                app->getData()->numberOfAirlinesAirport(airportCode);
                PressEnterToContinue();
                break;
            case '3':
                app->getData()->numberOfFlightsAirport(airportCode);
                PressEnterToContinue();
                break;
            case '4':
                app->getData()->numberOfDestinationsAirport(airportCode);
                PressEnterToContinue();
                break;
            case '5':
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