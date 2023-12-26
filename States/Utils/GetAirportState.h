#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETAIRPORTSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETAIRPORTSTATE_H


#include "States/State.h"
#include <functional>

class GetAirportState : public State {
private:
    State* backState;
    function<void(App*, const string&)> nextStateCallback;
public:
    GetAirportState(State* backState, function<void(App*, const string&)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETAIRPORTSTATE_H
