#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETCOORDINATESSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETCOORDINATESSTATE_H


#include <functional>
#include "States/State.h"

class GetCoordinatesState : public State {
private:
    function<void(App*, const string&)> nextStateCallback;
public:
    GetCoordinatesState(function<void(App*, const string&)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETCOORDINATESSTATE_H
