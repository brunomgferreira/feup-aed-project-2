#ifndef FLIGHT_MANAGEMENT_SYSTEM_APP_H
#define FLIGHT_MANAGEMENT_SYSTEM_APP_H

using namespace std;

class State;

class App {
private:
    static App* instance;
    State* currentState;

public:
    App();
    ~App();
    static App* getInstance();
    State *getState();
    void setState(State* state);
    void display() const;
    void handleInput();
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_APP_H


