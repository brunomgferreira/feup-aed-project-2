#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETCITYSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETCITYSTATE_H


#include <functional>
#include "States/State.h"

class GetCityState : public State {
private:
    State* backState;
    function<void(App*, const string&)> nextStateCallback;
public:
    GetCityState(State* backState, function<void(App*, const string&)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETCITYSTATE_H
