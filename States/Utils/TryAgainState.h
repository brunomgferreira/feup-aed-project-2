#ifndef FLIGHT_MANAGEMENT_SYSTEM_TRYAGAINSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_TRYAGAINSTATE_H


#include "States/State.h"

class TryAgainState : public State {
private:
    State* currentState;
public:
    TryAgainState(State* currentState);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_TRYAGAINSTATE_H
