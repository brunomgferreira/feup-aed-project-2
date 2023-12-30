#ifndef FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTDESTINATIONMENUSTATE_H
#define FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTDESTINATIONMENUSTATE_H

#include "States/State.h"
#include "States/Utils/LocationInfo.h"

class GetFlightDestinationMenuState : public State {
private:
    LocationInfo originInfo;
public:
    GetFlightDestinationMenuState(const LocationInfo& originInfo);
    void display() const override;
    void handleInput(App* app) override;
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_GETFLIGHTDESTINATIONMENUSTATE_H
