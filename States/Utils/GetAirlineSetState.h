#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESETSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESETSTATE_H

#include <functional>
#include "States/State.h"

/**
* @brief Class that represents a state for obtaining a set of airlines as user input.
*/

class GetAirlineSetState : public State {
private:
    State* backState;
    function<void(App*,  unordered_set<string>)> nextStateCallback;
public:

    /**
    * @brief Constructs an instance of GetAirlineSetState with specified back state and callback function.
    *
    * @details This constructor initializes an instance of the GetAirlineSetState class with the given back state
    * and a callback function for transitioning to the next state. The back state represents the state to which
    * the application should return when the user chooses to go back from the current state. The callback function
    * specifies the action to be performed in the next state, which typically involves receiving a set of airlines
    * from user input and proceeding to the next state with the captured information.
    *
    * @param backState A pointer to the state to which the application should return when the user chooses to go back.
    * @param nextStateCallback A function defining the action to be performed in the next state, usually involving a set of airlines.
    */
    GetAirlineSetState(State* backState, function<void(App*,  unordered_set<string>)> nextStateCallback);

    /**
    * @brief Displays a prompt for inserting a set of airlines.
    *
    * @details This method prints a prompt to the console, asking the user to insert a set of airlines. The displayed
    * prompt guides the user on the expected format for entering the set of airlines, for example, [CDG-EGD-ONF]. The
    * user is expected to enter a valid set of airline codes based on the specified format.
    */
    void display() const override;

    /**
    * @brief Handles user input for obtaining a set of airlines.
    *
    * @details This method reads a line of input from the console, representing a set of airlines in the format
    * [CDG-EGD-ONF]. The method validates each airline code in the set, ensuring its existence in the application's
    * data. If an invalid airline code is detected, the user is prompted with an error message, and the state
    * transitions to a "Try Again" state. If all airline codes are valid, the callback function is invoked with the
    * captured set of airlines, and the application transitions to the next state accordingly.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};

#endif //FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESETSTATE_H
