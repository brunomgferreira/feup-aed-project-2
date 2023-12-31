#ifndef FLIGHT_MANAGEMENT_SYSTEM_MINIMIZEAIRLINESSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_MINIMIZEAIRLINESSTATE_H


#include <functional>
#include "States/State.h"

/**
* @brief Class representing the state for minimizing airlines in the flight management system.
*/

class MinimizeAirlinesState : public State {
private:
    function<void(App*, bool)> nextStateCallback;
public:

    /**
    * @brief Constructs a MinimizeAirlinesState object with a callback for the next state.
    *
    * @details This constructor initializes a MinimizeAirlinesState object with a callback function that will be executed
    * in the next state. The callback function takes a pointer to the application instance and a boolean parameter
    * indicating whether to minimize airlines or not. This state is typically used to prompt the user for minimizing or
    * not minimizing airlines in the context of flight-related queries.
    *
    * @param nextStateCallback A function that takes an App pointer and a boolean parameter, representing the callback to
    * be executed in the next state.
    */
    MinimizeAirlinesState(function<void(App*, bool)> nextStateCallback);

    /**
    * @brief Displays a prompt for user input regarding airline minimization.
    *
    * @details This method prints a prompt to the console, asking the user whether they want to show only flights with the
    * minimum number of different airlines. The user is expected to respond with 's' for yes or 'n' for no.
    */
    void display() const override;

    /**
    * @brief Handles user input for airline minimization prompt.
    *
    * @details This method reads a user's input from the console and processes it based on the chosen option. Users can
    * input a single character ('s' for yes or 'n' for no). The method then calls the callback function with the
    * appropriate boolean parameter to indicate the user's choice. It provides error messages for invalid inputs.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};



#endif //FLIGHT_MANAGEMENT_SYSTEM_MINIMIZEAIRLINESSTATE_H
