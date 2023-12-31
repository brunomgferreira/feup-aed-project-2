#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRPORTSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRPORTSTATISTICSMENUSTATE_H


#include "States/State.h"

/**
* @brief Class that represents the menu state for displaying and handling the airport statistics options.
*/

class AirportStatisticsMenuState : public State {
private:
    string airportCode;
public:

    /**
    * @brief Default constructor for the Airport Statistics Menu state.
    *
    * @details This constructor initializes the AirportStatisticsMenuState object with the specified airport code. The
    * airport code is used to display statistics related to the selected airport in the menu options.
    *
    * @param airportCode The code of the airport for which statistics will be displayed.
    */
    AirportStatisticsMenuState(string airportCode);

    /**
    * @brief Displays the menu for airline-specific statistics options.
    *
    * @details This method prints the airline statistics menu to the console, allowing users to choose between
    * different statistical options related to a specific airline. The displayed menu includes corresponding
    * numeric options, and users can enter their choice. The menu covers information such as the number of
    * countries served, number of airports served, total number of flights operated, average flight distance,
    * and percentage of on-time arrivals.
    */
    void display() const override;

    /**
    * @brief Handles user input for the Airport Statistics Menu state.
    *
    * @details This method reads a user's input from the console and processes it based on the chosen option.
    * Users can input a single character corresponding to the desired option (1-5, 'b' for Statistics Menu, or
    * 'q' for Main Menu). The method then executes the selected option, calling specific methods from the
    * application's data module to retrieve and display relevant airport statistics. In some cases, the method
    * prompts the user for additional input, such as the maximum number of stops for reachable destinations.
    * Error messages are displayed for invalid inputs, and the state may transition accordingly.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRPORTSTATISTICSMENUSTATE_H
