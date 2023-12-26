#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRLINESTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRLINESTATISTICSMENUSTATE_H


#include "States/State.h"

class AirlineStatisticsMenuState : public State {
private:
    string airlineCode;
public:
    AirlineStatisticsMenuState(string airlineCode);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRLINESTATISTICSMENUSTATE_H
