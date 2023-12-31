#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTDESTINATIONMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTDESTINATIONMENUSTATE_H

#include "States/State.h"
#include "States/Utils/LocationInfo.h"

/**
* @brief Class that represents the menu state for displaying and handling the get flight destination options.
*/

class GetFlightDestinationMenuState : public State {
private:
    LocationInfo originInfo;
public:

    /**
    * @brief Constructs an instance of GetFlightDestinationMenuState with a specified origin information.
    *
    * @details This constructor initializes an instance of the GetFlightDestinationMenuState class with the given
    * origin information. The origin information includes details such as the type of origin (airport, city,
    * country, coordinates, or coordinates with a radius) and the corresponding data (e.g., airport code, city
    * name). This instance can then be used to navigate the application to the state for selecting flight
    * destination options based on the provided origin information.
    *
    * @param originInfo A LocationInfo object containing information about the selected origin for flight retrieval.
    */
    GetFlightDestinationMenuState(const LocationInfo& originInfo);

    /**
    * @brief Displays the menu for selecting the type of destination for flight retrieval.
    *
    * @details This method prints the menu to the console, allowing users to choose the type of destination when
    * retrieving flight information based on the previously selected origin. The displayed menu includes options
    * such as selecting an airport, city, country, coordinates, or coordinates with a radius. Users can input a
    * corresponding numeric option, and the method visually enhances the menu with color formatting. The menu also
    * provides an option to return to the main menu.
    */
    void display() const override;

    /**
    * @brief Handles user input for selecting the type of destination for flight retrieval.
    *
    * @details This method reads a user's input from the console and processes it based on the chosen option.
    * Users can input a single character corresponding to the desired option (1-5, 'b' for Origin Menu, or 'q' for
    * Main Menu). The method then transitions to the appropriate state based on the user's choice, capturing
    * relevant information such as airport code, city name, country name, coordinates, or coordinates with a radius.
    * The captured information is used to set up the next state for flight filter options. Error messages are
    * displayed for invalid inputs, and the state may transition accordingly.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTDESTINATIONMENUSTATE_H
