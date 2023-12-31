#include <iostream>
#include <iomanip>
#include "CityStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetStopsState.h"


CityStatisticsMenuState::CityStatisticsMenuState(string cityName) {
    this->cityName = cityName;
}

void CityStatisticsMenuState::display() const {
    cout << "\033[94m";
    cout << "===== CITY STATISTICS =====" << endl;
    cout << "\033[93m";
    cout << setw(14+cityName.size()/2) <<cityName << endl;
    cout << "\033[0m";
    cout << " Number of:" << endl;
    cout << "   1. Airports" << endl;
    cout << "   2. Cities" << endl;
    cout << "   3. Airlines" << endl;
    cout << "   4. Flights" << endl;
    cout << "   5. Destinations\n" << endl;
    cout << "   6. Reachable Destinations with max X stops\n" << endl;
    cout << "   b. Statistics Menu" << endl;
    cout << "   q. Main Menu" << endl;
    cout << "\033[94m";
    cout << "-------------------------------" << endl;
    cout << "\033[0m";
    cout << "Enter your choice: ";
}

void CityStatisticsMenuState::handleInput(App* app) {
    string choice;
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->getData()->numberOfAirportsCity(cityName);
                PressEnterToContinue();
                break;
            case '2':
                app->getData()->numberOfCountriesCity(cityName);
                PressEnterToContinue();
                break;
            case '3':
                app->getData()->numberOfAirlinesCity(cityName);
                PressEnterToContinue();
                break;
            case '4':
                app->getData()->numberOfFlightsCity(cityName);
                PressEnterToContinue();
                break;
            case '5':
                app->getData()->numberOfDestinationsCity(cityName);
                PressEnterToContinue();
                break;
            case '6':
                app->setState(new GetStopsState(this, [&](App *app, int stops) {
                    app->getData()->numberOfDestinationsXStopsCity(cityName, stops);
                    PressEnterToContinue();
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