#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTDESTINATIONMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTDESTINATIONMENUSTATE_H

#include "States/State.h"

class GetFlightDestinationMenuState : public State {
public:
    GetFlightDestinationMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTDESTINATIONMENUSTATE_H
