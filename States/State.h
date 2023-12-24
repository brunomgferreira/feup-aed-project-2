#ifndef FLIGHT_MANAGEMENT_SYSTEM_STATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_STATE_H

#include "App.h"

class State {
public:
    virtual void display() const = 0;
    virtual void handleInput(App* app) = 0;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_STATE_H
