#ifndef FLIGHT_MANAGEMENT_SYSTEM_APP_H
#define FLIGHT_MANAGEMENT_SYSTEM_APP_H

#include "Data.h"

using namespace std;

class State;

/**
* @brief Singleton class representing the main application controller for the flight management system.
*/

class App {
private:
    static App* instance;
    State* currentState;
    Data* data;

    /**
    * @brief Constructor for the App class.
    *
    * @details Initializes an App object with the main menu state and a new Data object.
    */
    App();
public:
    /**
    * @brief Destructor for the App class.
    *
    * @details Deallocates the memory occupied by the App instance.
    */
    ~App();

    /**
    * @brief Gets the singleton instance of the App class.
    *
    * @details If the instance is not yet created, it creates a new App instance.
    *
    * @return A pointer to the singleton instance of the App class.
    */
    static App* getInstance();

    /**
    * @brief Gets the current state of the application.
    *
    * @return A pointer to the current state of the application.
    */
    State *getState();

    /**
    * @brief Sets the state of the application.
    *
    * @details This method sets the current state of the application to the specified state.
    *
    * @param state A pointer to the new state of the application.
    */
    void setState(State* state);

    /**
    * @brief Gets the data object associated with the application.
    *
    * @return A pointer to the Data object used by the application.
    */
    Data *getData();

    /**
    * @brief Displays the current state of the application.
    */
    void display() const;

    /**
    * @brief Handles the user input for the current state of the application.
    */
    void handleInput();
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_APP_H


