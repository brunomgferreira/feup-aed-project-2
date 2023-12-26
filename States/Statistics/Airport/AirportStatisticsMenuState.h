#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRPORTSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRPORTSTATISTICSMENUSTATE_H


#include "States/State.h"

class AirportStatisticsMenuState : public State {
public:
    AirportStatisticsMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRPORTSTATISTICSMENUSTATE_H
