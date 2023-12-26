#ifndef FLIGHT_MANAGEMENT_SYSTEM_COUNTRYSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_COUNTRYSTATISTICSMENUSTATE_H


#include "States/State.h"

class CountryStatisticsMenuState : public State {
private:
    string countryName;
public:
    // TODO Passar o nome ou o objeto country ??
    CountryStatisticsMenuState(string countryName);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_COUNTRYSTATISTICSMENUSTATE_H
