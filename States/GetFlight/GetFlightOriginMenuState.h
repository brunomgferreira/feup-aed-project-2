#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTORIGINMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTORIGINMENUSTATE_H

#include "States/State.h"

class GetFlightOriginMenuState : public State {
public:
    GetFlightOriginMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTORIGINMENUSTATE_H
