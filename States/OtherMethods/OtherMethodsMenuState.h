#ifndef FLIGHT_MANAGEMENT_SYSTEM_OTHERMETHODSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_OTHERMETHODSMENUSTATE_H


#include "States/State.h"

/**
* @brief Class that represents the menu state for displaying and handling the other methods options.
*/

class OtherMethodsMenuState : public State {
public:
    /**
    * @brief Default constructor for the Other Methods Menu state.
    *
    * @details This constructor initializes an instance of the OtherMethodsMenuState class.
    */
    OtherMethodsMenuState();

    /**
    * @brief Displays the menu for other miscellaneous methods options.
    *
    * @details This method prints the menu for miscellaneous methods to the console, allowing users to choose
    * between different options such as finding the maximum trip, identifying the top K airports with the
    * greatest air traffic capacity, and viewing essential airports. The displayed menu includes corresponding
    * numeric options, and users can enter their choice. The menu also provides an option to return to the main
    * menu. Color formatting is applied to enhance the visual appeal of the menu.
    */
    void display() const override;

    /**
    * @brief Handles user input for the Other Methods Menu state.
    *
    * @details This method reads a user's input from the console and processes it based on the chosen option.
    * Users can input a single character corresponding to the desired option (1-3 or 'q' for Main Menu). The method
    * then executes the selected option, calling specific methods from the application's data module to perform
    * various miscellaneous tasks. In some cases, the method prompts the user for additional input, such as the
    * value of 'K' for the top K airports. Error messages are displayed for invalid inputs, and the state may
    * transition accordingly.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_OTHERMETHODSMENUSTATE_H
