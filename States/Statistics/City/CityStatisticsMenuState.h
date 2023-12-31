#ifndef FLIGHT_MANAGEMENT_SYSTEM_CITYSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_CITYSTATISTICSMENUSTATE_H


#include "States/State.h"

/**
* @brief Class that represents the menu state for displaying and handling the city statistics options.
*/

class CityStatisticsMenuState : public State {
private:
    string cityName;
public:

    /**
    * @brief Default constructor for the City Statistics Menu state.
    *
    * @details This constructor initializes a CityStatisticsMenuState with the specified city name. The city name is used to
    * provide city-specific statistics options in the menu.
    *
    * @param cityName The name of the city for which statistics will be displayed.
    */
    CityStatisticsMenuState(string cityName);

    /**
    * @brief Displays the menu for city-specific statistics.
    *
    * @details This method outputs a formatted menu to the console, presenting various statistical options related to the
    * specified city. Users can choose from options such as the number of airports, cities, airlines, flights, destinations,
    * and reachable destinations with a maximum number of stops.
    */
    void display() const override;

    /**
    * @brief Handles user input for city-specific statistics menu.
    *
    * @details This method prompts the user for input and processes the chosen option for city-specific statistics. Users
    * can choose from options such as the number of airports, countries, airlines, flights, destinations, and reachable
    * destinations with a maximum number of stops. Additionally, users can navigate back to the statistics menu or return to
    * the main menu.
    *
    * @param app A pointer to the application object.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_CITYSTATISTICSMENUSTATE_H
