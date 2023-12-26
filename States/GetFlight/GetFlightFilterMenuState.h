#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTFILTERMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTFILTERMENUSTATE_H

#include "States/State.h"
#include "States/Utils/LocationInfo.h"

class GetFlightFilterMenuState : public State {
private:
    LocationInfo *originInfo;
    LocationInfo *destinationInfo;
public:
    GetFlightFilterMenuState(LocationInfo *originInfo, LocationInfo *destinationInfo);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTFILTERMENUSTATE_H
