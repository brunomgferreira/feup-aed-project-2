#ifndef FLIGHT_MANAGEMENT_SYSTEM_STATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_STATISTICSMENUSTATE_H


#include "States/State.h"


/**
* @brief Class that represents the menu state for displaying and handling the statistics options.
*/

class StatisticsMenuState : public State {
public:

    /**
    * @brief Default constructor for the Statistics Menu state.
    *
    * @details This constructor initializes an instance of the StatisticsMenuState class.
    */
    StatisticsMenuState();

    /**
    * @brief Displays the menu for statistics options.
    *
    * @details This method prints the statistics menu to the console, allowing users to choose between global,
    * country-specific, city-specific, airline-specific, and airport-specific statistics. The displayed menu
    * includes corresponding numeric options, and users can enter their choice.
    */
    void display() const override;

    /**
    * @brief Handles user input for the Statistics Menu state.
    *
    * @details This method reads a user's input from the console and processes it based on the chosen option.
    * Users can input a single character corresponding to the desired option (1-5 or 'q' for Main Menu). The
    * method then transitions the application state accordingly, creating new instances of specific statistics
    * menu states or returning to the main menu. It provides error messages for invalid inputs.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_STATISTICSMENUSTATE_H
