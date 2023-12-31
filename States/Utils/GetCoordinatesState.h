#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETCOORDINATESSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETCOORDINATESSTATE_H


#include <functional>
#include "States/State.h"

/**
* @brief Class that represents a state for obtaining a coordinate as user input.
*/

class GetCoordinatesState : public State {
private:
    State* backState;
    function<void(App*, const Coordinate&)> nextStateCallback;
public:

    /**
    * @brief Constructs an instance of GetCoordinatesState with specified back state and callback function.
    *
    * @details This constructor initializes an instance of the GetCoordinatesState class with the given back state
    * and a callback function for transitioning to the next state. The back state represents the state to which
    * the application should return when the user chooses to go back from the current state. The callback function
    * specifies the action to be performed in the next state, usually involving capturing geographical coordinates
    * from user input and proceeding to the next state with the captured information.
    *
    * @param backState A pointer to the state to which the application should return when the user chooses to go back.
    * @param nextStateCallback A function defining the action to be performed in the next state, usually involving
    * geographical coordinates.
    */
    GetCoordinatesState(State* backState, function<void(App*, const Coordinate&)> nextStateCallback);

    /**
    * @brief Displays a prompt for inserting geographical coordinates.
    *
    * @details This method prints a prompt to the console, asking the user to insert geographical coordinates.
    * The displayed prompt guides the user on the expected format for entering coordinates, such as "13.24,65.13".
    * The user is expected to input valid geographical coordinates based on the specified format.
    */
    void display() const override;

    /**
    * @brief Handles user input for obtaining geographical coordinates.
    *
    * @details This method reads a line of input from the console, representing geographical coordinates in the format
    * "latitude, longitude." The method validates the entered coordinates, ensuring they fall within valid ranges
    * (-90 <= latitude <= 90 and -180 <= longitude <= 180). If the coordinates are valid, the callback function is
    * invoked with the captured coordinates, and the application transitions to the next state accordingly. If the
    * coordinates are invalid, the user is prompted with an error message, and the state transitions to a "Try Again"
    * state, allowing the user to make another attempt.
    *
    * @param app A pointer to the application instance.
    */
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETCOORDINATESSTATE_H
