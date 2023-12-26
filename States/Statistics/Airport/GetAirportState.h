#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETAIRPORTSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETAIRPORTSTATE_H


#include "States/State.h"

class GetAirportState : public State {
public:
    GetAirportState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETAIRPORTSTATE_H
