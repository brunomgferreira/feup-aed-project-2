#ifndef FLIGHT_MANAGEMENT_SYSTEM_GLOBALSTATISTICSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GLOBALSTATISTICSMENUSTATE_H


#include "States/State.h"

class GlobalStatisticsMenuState : public State {
public:
    GlobalStatisticsMenuState();
    void display() const override;
    void handleInput(App* app) override;
};

#endif //FLIGHT_MANAGEMENT_SYSTEM_GLOBALSTATISTICSMENUSTATE_H
