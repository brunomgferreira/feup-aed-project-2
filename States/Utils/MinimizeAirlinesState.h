#ifndef FLIGHT_MANAGEMENT_SYSTEM_MINIMIZEAIRLINESSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_MINIMIZEAIRLINESSTATE_H


#include <functional>
#include "States/State.h"

class MinimizeAirlinesState : public State {
private:
    function<void(App*, bool)> nextStateCallback;
public:
    MinimizeAirlinesState(function<void(App*, bool)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};



#endif //FLIGHT_MANAGEMENT_SYSTEM_MINIMIZEAIRLINESSTATE_H
