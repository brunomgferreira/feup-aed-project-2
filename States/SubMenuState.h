#ifndef FLIGHT_MANAGEMENT_SYSTEM_SUBMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_SUBMENUSTATE_H


#include "State.h"

class SubMenuState : public State {
public:
    SubMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_SUBMENUSTATE_H
