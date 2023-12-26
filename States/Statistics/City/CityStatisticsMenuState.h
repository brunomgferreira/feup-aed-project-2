#ifndef FLIGHT_MANAGEMENT_SYSTEM_CITYSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_CITYSTATISTICSMENUSTATE_H


#include "States/State.h"

class CityStatisticsMenuState : public State {
public:
    CityStatisticsMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_CITYSTATISTICSMENUSTATE_H
