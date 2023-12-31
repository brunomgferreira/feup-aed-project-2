#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETCOUNTRYSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETCOUNTRYSTATE_H


#include <functional>
#include "States/State.h"

/**
* @brief Class that represents a state for obtaining a country as user input.
*/

class GetCountryState : public State {
private:
    State* backState;
    function<void(App*, const string&)> nextStateCallback;
public:

    /**
    * @brief Constructs an instance of GetCountryState with specified back state and callback function.
    *
    * @details This constructor initializes an instance of the GetCountryState class with the given back state
    * and a callback function for transitioning to the next state. The back state represents the state to which
    * the application should return when the user chooses to go back from the current state. The callback function
    * specifies the action to be performed in the next state, usually involving capturing a country name from user
    * input and proceeding to the next state with the captured information.
    *
    * @param backState A pointer to the state to which the application should return when the user chooses to go back.
    * @param nextStateCallback A function defining the action to be performed in the next state, usually involving a country name.
    */
    GetCountryState(State* backState, function<void(App*, const string&)> nextStateCallback);

    /**
    * @brief Displays a prompt for inserting a country name.
    *
    * @details This method prints a prompt to the console, asking the user to insert a country name. The displayed
    * prompt guides the user on the expected format for entering the country name. The user is expected to input
    * a valid country name based on the specified format.
    */
    void display() const override;

    /**
    * @brief Handles user input for obtaining a country name.
    *
    * @details This method reads a line of input from the console, representing a country name. The method validates
    * the existence of the entered country name in the application's data. If the country name is valid, the callback
    * function is invoked with the captured country name, and the application transitions to the next state accordingly.
    * If the country name is invalid, the user is prompted with an error message, and the state transitions to a "Try Again"
    * state, allowing the user to make another attempt.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETCOUNTRYSTATE_H
