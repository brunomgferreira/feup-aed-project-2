#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTSFILTERMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTSFILTERMENUSTATE_H

#include "States/State.h"

class GetFlightsFilterMenuState : public State {
public:
    GetFlightsFilterMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTSFILTERMENUSTATE_H
