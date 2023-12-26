#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESTATE_H


#include "States/State.h"

class GetAirlineState : public State {
public:
    GetAirlineState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESTATE_H
