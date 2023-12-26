#ifndef FLIGHT_MANAGEMENT_SYSTEM_STATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_STATISTICSMENUSTATE_H


#include "States/State.h"

class StatisticsMenuState : public State {
public:
    StatisticsMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_STATISTICSMENUSTATE_H
