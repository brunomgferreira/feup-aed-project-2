#ifndef FLIGHT_MANAGEMENT_SYSTEM_MAINMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_MAINMENUSTATE_H


#include "State.h"

class MainMenuState : public State {
public:
    MainMenuState();
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_MAINMENUSTATE_H
