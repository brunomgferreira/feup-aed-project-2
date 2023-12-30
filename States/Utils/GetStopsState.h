#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETSTOPSSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETSTOPSSTATE_H


#include <functional>
#include "States/State.h"

class GetStopsState : public State {
private:
    State* backState;
    function<void(App*, int)> nextStateCallback;
public:
    GetStopsState(State* backState, function<void(App*, int)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETSTOPSSTATE_H