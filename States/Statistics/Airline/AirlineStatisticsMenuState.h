#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRLINESTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRLINESTATISTICSMENUSTATE_H


#include "States/State.h"

class AirlineStatisticsMenuState : public State {
public:
    AirlineStatisticsMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRLINESTATISTICSMENUSTATE_H
