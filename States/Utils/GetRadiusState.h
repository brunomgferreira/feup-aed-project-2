#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETRADIUSSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETRADIUSSTATE_H


#include <functional>
#include "States/State.h"

/**
* @brief Class that represents a state for obtaining a radius as user input.
*/

class GetRadiusState : public State {
private:
    State* backState;
    function<void(App*, double)> nextStateCallback;
public:

    /**
    * @brief Constructs an instance of GetRadiusState with specified back state and callback function.
    *
    * @details This constructor initializes an instance of the GetRadiusState class with the given back state and
    * a callback function for transitioning to the next state. The back state represents the state to which the
    * application should return when the user chooses to go back from the current state. The callback function
    * specifies the action to be performed in the next state, usually involving capturing a radius value from user
    * input and proceeding to the next state with the captured information.
    *
    * @param backState A pointer to the state to which the application should return when the user chooses to go back.
    * @param nextStateCallback A function defining the action to be performed in the next state, usually involving a radius value.
    */
    GetRadiusState(State* backState, function<void(App*, double)> nextStateCallback);

    /**
    * @brief Displays a prompt for inserting a radius value in kilometers.
    *
    * @details This method prints a prompt to the console, asking the user to insert a radius value in kilometers.
    * The displayed prompt guides the user on the expected format for entering the radius. The user is expected to
    * input a valid numerical value representing the radius in kilometers.
    */
    void display() const override;

    /**
    * @brief Handles user input for obtaining a radius value.
    *
    * @details This method reads a line of input from the console, representing a radius value in kilometers.
    * The method validates the entered input, ensuring it is a valid non-negative double. If the input is valid,
    * the callback function is invoked with the captured radius value, and the application transitions to the next
    * state accordingly. If the input is invalid, the user is prompted with an error message, and the state transitions
    * to a "Try Again" state, allowing the user to make another attempt.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETRADIUSSTATE_H
