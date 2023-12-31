#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTORIGINMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTORIGINMENUSTATE_H

#include "States/State.h"

/**
* @brief Class that represents the menu state for displaying and handling the get flight origin options.
*/

class GetFlightOriginMenuState : public State {
public:

    /**
    * @brief Default constructor for the Get Flight Origin Menu state.
    *
    * @details This constructor initializes an instance of the GetFlightOriginMenuState class.
    */
    GetFlightOriginMenuState();

    /**
    * @brief Displays the menu for selecting the type of origin for flight retrieval.
    *
    * @details This method prints the menu to the console, allowing users to choose the type of origin when
    * retrieving flight information. The displayed menu includes options such as selecting an airport, city,
    * country, coordinates, or coordinates with a radius. Users can input a corresponding numeric option, and
    * the method visually enhances the menu with color formatting. The menu also provides an option to return to
    * the main menu.
    */
    void display() const override;

    /**
    * @brief Handles user input for selecting the type of origin for flight retrieval.
    *
    * @details This method reads a user's input from the console and processes it based on the chosen option.
    * Users can input a single character corresponding to the desired option (1-5 or 'q' for Main Menu). The method
    * then transitions to the appropriate state based on the user's choice, capturing relevant information such as
    * airport code, city name, country name, coordinates, or coordinates with a radius. The captured information is
    * used to set up the next state for flight destination selection. Error messages are displayed for invalid
    * inputs, and the state may transition accordingly.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTORIGINMENUSTATE_H
