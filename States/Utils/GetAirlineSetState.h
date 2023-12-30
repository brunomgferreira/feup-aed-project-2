//
// Created by soestilooo on 30-12-2023.
//

#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESETSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESETSTATE_H

#include <functional>
#include "States/State.h"

class GetAirlineSetState : public State {
private:
    State* backState;
    function<void(App*,  unordered_set<string>)> nextStateCallback;
public:
    GetAirlineSetState(State* backState, function<void(App*,  unordered_set<string>)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};

#endif //FLIGHT_MANAGEMENT_SYSTEM_GETAIRLINESETSTATE_H
