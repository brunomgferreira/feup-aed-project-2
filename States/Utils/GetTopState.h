#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETTOPSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETTOPSTATE_H

#include <functional>
#include "States/State.h"

class GetTopState : public State {
private:
    State* backState;
    function<void(App*, int)> nextStateCallback;
public:
    GetTopState(State* backState, function<void(App*, int)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETTOPSTATE_H
