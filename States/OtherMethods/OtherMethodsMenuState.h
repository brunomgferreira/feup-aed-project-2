#ifndef FLIGHT_MANAGEMENT_SYSTEM_OTHERMETHODSMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_OTHERMETHODSMENUSTATE_H


#include "States/State.h"

class OtherMethodsMenuState : public State {
public:
    OtherMethodsMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_OTHERMETHODSMENUSTATE_H
