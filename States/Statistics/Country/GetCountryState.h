#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETCOUNTRYSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETCOUNTRYSTATE_H


#include "States/State.h"

class GetCountryState : public State {
public:
    GetCountryState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETCOUNTRYSTATE_H
