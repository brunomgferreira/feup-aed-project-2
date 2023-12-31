#ifndef FLIGHT_MANAGEMENT_SYSTEM_COUNTRYSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_COUNTRYSTATISTICSMENUSTATE_H


#include "States/State.h"

/**
* @brief Class that represents the menu state for displaying and handling the country statistics options.
*/

class CountryStatisticsMenuState : public State {
private:
    string countryName;
public:

    /**
    * @brief Default constructor for the Country Statistics Menu state.
    *
    * @details This constructor initializes a CountryStatisticsMenuState with the specified country name.
    *
    * @param countryName The name of the country for which statistics will be displayed.
    */
    CountryStatisticsMenuState(string countryName);

    /**
    * @brief Displays the menu for country-specific statistics.
    *
    * @details This method prints the menu for country-specific statistics to the console. It includes options
    * for displaying the number of airports, cities, airlines, flights, and destinations for the specified country.
    * Additionally, it provides options for finding reachable destinations with a maximum number of stops, returning
    * to the statistics menu, or going back to the main menu.
    */
    void display() const override;

    /**
    * @brief Handles user input for country-specific statistics menu.
    *
    * @details This method reads a user's choice from the console and performs the corresponding action based on the
    * selected option. It allows the user to view the number of airports, cities, airlines, flights, and destinations
    * for the specified country. Additionally, it provides an option to find reachable destinations with a maximum
    * number of stops, return to the statistics menu, or go back to the main menu.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_COUNTRYSTATISTICSMENUSTATE_H
