#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETRADIUSSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETRADIUSSTATE_H


#include <functional>
#include "States/State.h"

class GetRadiusState : public State {
private:
    State* backState;
    function<void(App*, double)> nextStateCallback;
public:
    GetRadiusState(State* backState, function<void(App*, double)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETRADIUSSTATE_H
