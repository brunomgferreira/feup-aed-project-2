#ifndef FLIGHT_MANAGEMENT_SYSTEM_COUNTRYSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_COUNTRYSTATISTICSMENUSTATE_H


#include "States/State.h"

class CountryStatisticsMenuState : public State {
public:
    CountryStatisticsMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_COUNTRYSTATISTICSMENUSTATE_H
