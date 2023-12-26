#ifndef FLIGHT_MANAGEMENT_SYSTEM_BESTFLIGHTMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_BESTFLIGHTMENUSTATE_H

#include "State.h"

class BestFlightMenuState : public State {
public:
    BestFlightMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_BESTFLIGHTMENUSTATE_H
