#ifndef FLIGHT_MANAGEMENT_SYSTEM_TRYAGAINSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_TRYAGAINSTATE_H


#include <functional>
#include "States/State.h"

class TryAgainState : public State {
private:
private:
    State *backState;
    State *currentState;
public:
    TryAgainState(State *backState, State *currentState);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_TRYAGAINSTATE_H
