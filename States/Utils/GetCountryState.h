#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETCOUNTRYSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETCOUNTRYSTATE_H


#include <functional>
#include "States/State.h"

class GetCountryState : public State {
private:
    State* backState;
    function<void(App*, const string&)> nextStateCallback;
public:
    GetCountryState(State* backState, function<void(App*, const string&)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETCOUNTRYSTATE_H
