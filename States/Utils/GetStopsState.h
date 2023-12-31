#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETSTOPSSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETSTOPSSTATE_H


#include <functional>
#include "States/State.h"

/**
* @brief Class that represents a state for obtaining the number of stops as user input.
*/

class GetStopsState : public State {
private:
    State* backState;
    function<void(App*, int)> nextStateCallback;
public:

    /**
    * @brief Constructs an instance of GetStopsState with specified back state and callback function.
    *
    * @details This constructor initializes an instance of the GetStopsState class with the given back state and
    * a callback function for transitioning to the next state. The back state represents the state to which the
    * application should return when the user chooses to go back from the current state. The callback function
    * specifies the action to be performed in the next state, usually involving capturing a number of stops from user
    * input and proceeding to the next state with the captured information.
    *
    * @param backState A pointer to the state to which the application should return when the user chooses to go back.
    * @param nextStateCallback A function defining the action to be performed in the next state, usually involving a number of stops.
    */
    GetStopsState(State* backState, function<void(App*, int)> nextStateCallback);

    /**
    * @brief Displays a prompt for inserting the number of stops.
    *
    * @details This method prints a prompt to the console, asking the user to insert the number of stops.
    * The displayed prompt guides the user on the expected format for entering the number of stops. The user is
    * expected to input a valid integer representing the desired number of stops for flight search.
    */
    void display() const override;

    /**
    * @brief Handles user input for obtaining the number of stops.
    *
    * @details This method reads a line of input from the console, representing the desired number of stops for flight search.
    * The method validates the entered input, ensuring it is a valid non-negative integer. If the input is valid,
    * the callback function is invoked with the captured number of stops, and the application transitions to the next
    * state accordingly. If the input is invalid, the user is prompted with an error message, and the state transitions
    * to a "Try Again" state, allowing the user to make another attempt.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETSTOPSSTATE_H