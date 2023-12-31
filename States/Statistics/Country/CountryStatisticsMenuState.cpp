#include <iostream>
#include <limits>
#include <iomanip>
#include "CountryStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetStopsState.h"

CountryStatisticsMenuState::CountryStatisticsMenuState(string countryName) {
    this->countryName = countryName;
}

void CountryStatisticsMenuState::display() const {
    cout << "\033[94m";
    cout << "===== COUNTRY STATISTICS =====" << endl;
    cout << "\033[93m";
    cout << setw(15+countryName.size()/2) <<countryName << endl;
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

void CountryStatisticsMenuState::handleInput(App* app) {
    string choice;
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                app->getData()->numberOfAirportsCountry(countryName);
                PressEnterToContinue();
                break;
            case '2':
                app->getData()->numberOfCitiesCountry(countryName);
                PressEnterToContinue();
                break;
            case '3':
                app->getData()->numberOfAirlinesCountry(countryName);
                PressEnterToContinue();
                break;
            case '4':
                app->getData()->numberOfFlightsCountry(countryName);
                PressEnterToContinue();
                break;
            case '5':
                app->getData()->numberOfDestinationsCountry(countryName);
                PressEnterToContinue();
                break;
            case '6':
                app->setState(new GetStopsState(this, [&](App *app, int stops) {
                    app->getData()->numberOfDestinationsXStopsCountry(countryName, stops);
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