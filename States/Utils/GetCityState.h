#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETCITYSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETCITYSTATE_H


#include <functional>
#include "States/State.h"

/**
* @brief Class that represents a state for obtaining a city as user input.
*/

class GetCityState : public State {
private:
    State* backState;
    function<void(App*, const string&)> nextStateCallback;
public:

    /**
    * @brief Constructs an instance of GetCityState with specified back state and callback function.
    *
    * @details This constructor initializes an instance of the GetCityState class with the given back state
    * and a callback function for transitioning to the next state. The back state represents the state to which
    * the application should return when the user chooses to go back from the current state. The callback function
    * specifies the action to be performed in the next state, usually involving capturing a city name from user
    * input and proceeding to the next state with the captured information.
    *
    * @param backState A pointer to the state to which the application should return when the user chooses to go back.
    * @param nextStateCallback A function defining the action to be performed in the next state, usually involving a city name.
    */
    GetCityState(State* backState, function<void(App*, const string&)> nextStateCallback);

    /**
    * @brief Displays a prompt for inserting a city name.
    *
    * @details This method prints a prompt to the console, asking the user to insert a city name. The displayed
    * prompt guides the user on the expected format for entering the city name, such as "Montevideo, Uruguay".
    * The user is expected to input a valid city name based on the specified format.
    */
    void display() const override;

    /**
    * @brief Handles user input for obtaining a city name.
    *
    * @details This method reads a line of input from the console, representing a city name. The method validates
    * the existence of the entered city name in the application's data. If the city name is valid, the callback
    * function is invoked with the captured city name, and the application transitions to the next state accordingly.
    * If the city name is invalid, the user is prompted with an error message, and the state transitions to a
    * "Try Again" state, allowing the user to make another attempt.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETCITYSTATE_H
