#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRLINESTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRLINESTATISTICSMENUSTATE_H


#include "States/State.h"

/**
* @brief Class that represents the menu state for displaying and handling the airline statistics options.
*/

class AirlineStatisticsMenuState : public State {
private:
    string airlineCode;
public:

    /**
    * @brief Default constructor for the Airline Statistics Menu state.
    *
    * @details This constructor initializes the AirlineStatisticsMenuState with the specified airline code.
    *
    * @param airlineCode The code of the airline for which statistics will be displayed.
    */
    AirlineStatisticsMenuState(string airlineCode);

    /**
    * @brief Displays the menu for airline-specific statistics options.
    *
    * @details This method prints the airline statistics menu to the console, allowing users to choose between
    * different statistical options related to a specific airline. The displayed menu includes corresponding
    * numeric options, and users can enter their choice. The menu covers information such as the number of
    * flights operated by the airline, the number of destinations served, and options to return to the statistics
    * menu or the main menu.
    */
    void display() const override;

    /**
     * @brief Handles user input for the Airline Statistics Menu state.
     *
     * @details This method reads a user's input from the console and processes it based on the chosen option.
     * Users can input a single character corresponding to the desired option (1-2, 'b' for Statistics Menu, or
     * 'q' for Main Menu). The method then executes the selected option, calling specific methods from the
     * application's data module to retrieve and display relevant airline statistics. Error messages are displayed
     * for invalid inputs, and the state may transition accordingly.
     *
     * @param app A pointer to the application instance.
     */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRLINESTATISTICSMENUSTATE_H
