#include <iostream>
#include <limits>
#include "CountryStatisticsMenuState.h"
#include "States/Statistics/StatisticsMenuState.h"
#include "States/MainMenuState.h"
#include "States/Utils/GetStopsState.h"

CountryStatisticsMenuState::CountryStatisticsMenuState(string countryName) {
    this->countryName = countryName;
}

void CountryStatisticsMenuState::display() const {
    cout << "***** Country Statistics *****" << endl;
    cout << "1. Number of Airports" << endl;
    cout << "2. Number of Cities" << endl;
    cout << "3. Number of Airlines" << endl;
    cout << "4. Number of Flights" << endl;
    cout << "5. Number of Destinations" << endl;
    cout << "6. Reachable Destinations with max X stops" << endl;
    cout << "b. Statistics Menu" << endl;
    cout << "q. Main Menu" << endl;
}

void CountryStatisticsMenuState::handleInput(App* app) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case '1':
                cout << "Executing Option 1 - Number of Airports" << endl;
                app->getData()->numberOfAirportsCountry(countryName);
                PressEnterToContinue();
                break;
            case '2':
                cout << "Executing Option 2 - Number of Cities" << endl;
                app->getData()->numberOfCitiesCountry(countryName);
                PressEnterToContinue();
                break;
            case '3':
                cout << "Executing Option 3 - Number of Airlines" << endl;
                app->getData()->numberOfAirlinesCountry(countryName);
                PressEnterToContinue();
                break;
            case '4':
                cout << "Executing Option 4 - Number of Flights" << endl;
                app->getData()->numberOfFlightsCountry(countryName);
                PressEnterToContinue();
                break;
            case '5':
                cout << "Executing Option 5 - Number of Destinations" << endl;
                app->getData()->numberOfDestinationsCountry(countryName);
                PressEnterToContinue();
                break;
            case '6':
                cout << "Executing Option 6 - Reachable Destinations with max X stops" << endl;
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
                cout << "Invalid choice. Please try again." << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;
}