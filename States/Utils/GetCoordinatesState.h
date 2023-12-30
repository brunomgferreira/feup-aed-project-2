#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETCOORDINATESSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETCOORDINATESSTATE_H


#include <functional>
#include "States/State.h"

class GetCoordinatesState : public State {
private:
    State* backState;
    function<void(App*, const Coordinate&)> nextStateCallback;
public:
    GetCoordinatesState(State* backState, function<void(App*, const Coordinate&)> nextStateCallback);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETCOORDINATESSTATE_H
