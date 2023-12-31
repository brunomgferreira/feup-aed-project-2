#ifndef FLIGHT_MANAGEMENT_SYSTEM_GLOBALSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GLOBALSTATISTICSMENUSTATE_H


#include "States/State.h"

/**
* @brief Class that represents the global statistics state for displaying and handling the global statistics options.
*/

class GlobalStatisticsMenuState : public State {
public:

    /**
    * @brief Default constructor for the Global Statistics Menu state.
    *
    * @details This constructor initializes an instance of the GlobalStatisticsMenuState class.
    */
    GlobalStatisticsMenuState();

    /**
    * @brief Displays the Global Statistics Menu.
    *
    * @details This method is responsible for displaying the Global Statistics Menu. It prints options for various
    * global statistics, including the number of airports, cities, countries, airlines, and flights. Additionally,
    * it provides options to navigate back to the Statistics Menu or return to the Main Menu. The user is prompted
    * to enter a choice.
    */
    void display() const override;

    /**
    * @brief Handles user input for the Global Statistics Menu.
    *
    * @details This method reads the user's input and performs corresponding actions based on the selected option.
    * The user can choose to view the number of airports, cities, countries, airlines, or flights globally. Additionally,
    * the user can navigate back to the Statistics Menu or return to the Main Menu. After processing the choice, the user
    * is prompted to press Enter to continue.
    *
    * @param app Pointer to the application instance.
    */
    void handleInput(App* app) override;
};

#endif //FLIGHT_MANAGEMENT_SYSTEM_GLOBALSTATISTICSMENUSTATE_H
