#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTFILTERMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTFILTERMENUSTATE_H

#include "States/State.h"
#include "States/Utils/LocationInfo.h"

/**
* @brief Class that represents the menu state for displaying and handling the get flight filter options.
*/

class GetFlightFilterMenuState : public State {
private:
    LocationInfo originInfo;
    LocationInfo destinationInfo;
public:

    /**
    * @brief Constructs an instance of GetFlightFilterMenuState with specified origin and destination information.
    *
    * @details This constructor initializes an instance of the GetFlightFilterMenuState class with the given origin
    * and destination information. The origin information includes details about the selected origin for flight
    * retrieval, such as the type of origin (airport, city, country, coordinates, or coordinates with a radius) and
    * the corresponding data (e.g., airport code, city name). Similarly, the destination information provides
    * details about the selected destination. This instance can be used to navigate the application to the state for
    * selecting additional flight filter options based on the provided origin and destination information.
    *
    * @param originInfo A LocationInfo object containing information about the selected origin for flight retrieval.
    * @param destinationInfo A LocationInfo object containing information about the selected destination for flight retrieval.
    */
    GetFlightFilterMenuState(const LocationInfo& originInfo, const LocationInfo& destinationInfo);

    /**
    * @brief Displays the menu for selecting flight filter options.
    *
    * @details This method prints the menu to the console, allowing users to choose from various flight filter
    * options. The displayed menu includes options such as selecting a set of airlines, a set of unwanted airlines,
    * or no filter at all. Users can input a corresponding numeric option, and the method visually enhances the menu
    * for clarity. The menu also provides options to go back to the previous state or return to the main menu.
    */
    void display() const override;

    /**
    * @brief Handles user input for selecting flight filter options.
    *
    * @details This method reads a user's input from the console and processes it based on the chosen option.
    * Users can input a single character corresponding to the desired option (1-3, 'b' for Destination Menu, or 'q'
    * for Main Menu). The method then transitions to the appropriate state based on the user's choice, capturing
    * relevant information such as a set of airlines, a set of unwanted airlines, or no filter at all. The captured
    * information is used to set up the next state for retrieving flights based on the selected filters. Error
    * messages are displayed for invalid inputs, and the state may transition accordingly.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTFILTERMENUSTATE_H
