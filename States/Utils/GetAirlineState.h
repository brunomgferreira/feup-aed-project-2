#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESTATE_H


#include <functional>
#include "States/State.h"

class GetAirlineState : public State {
private:
    function<void(App*, const string&)> nextStateCallback;
public:
    GetAirlineState(function<void(App*, const string&)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESTATE_H
