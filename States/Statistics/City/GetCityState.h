#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETCITYSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETCITYSTATE_H


#include "States/State.h"

class GetCityState : public State {
public:
    GetCityState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETCITYSTATE_H
