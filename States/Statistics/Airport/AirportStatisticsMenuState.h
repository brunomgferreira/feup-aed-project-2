#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRPORTSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRPORTSTATISTICSMENUSTATE_H


#include "States/State.h"

class AirportStatisticsMenuState : public State {
private:
    string airportCode;
public:
    AirportStatisticsMenuState(string airportCode);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRPORTSTATISTICSMENUSTATE_H
