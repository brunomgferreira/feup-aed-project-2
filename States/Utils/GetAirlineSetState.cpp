
#include "GetAirlineSetState.h"
#include "TryAgainState.h"


GetAirlineSetState::GetAirlineSetState(State* backState, function<void(App*, unordered_set<string>)> nextStateCallback)
: backState(backState), nextStateCallback(nextStateCallback) {}

void GetAirlineSetState::display() const {
    cout << "Insert set of airlines [CDG-EGD-ONF]: ";
}

void GetAirlineSetState::handleInput(App* app) {
    string inputAirlineSet;
    std::cin.ignore();
    std::getline(std::cin, inputAirlineSet);

    unordered_set<string> airlineSet;

    stringstream ss(inputAirlineSet);
    string airlineCode;

    bool error=false;
    while (getline(ss, airlineCode, '-')){
        if (!app->getData()->airlineExists(airlineCode)){
            cout << "Invalid Airline Set. " << airlineCode << " does not exist.\n";
            app->setState(new TryAgainState(backState, this));
            error=true;
            break;
        }else{
            airlineSet.insert(airlineCode);
        }
    }
    if (!error){
        nextStateCallback(app, airlineSet);
    }
}
