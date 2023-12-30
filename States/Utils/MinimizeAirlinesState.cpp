
#include "MinimizeAirlinesState.h"


MinimizeAirlinesState::MinimizeAirlinesState(function<void(App *, bool)> nextStateCallback) : nextStateCallback(nextStateCallback){}

void MinimizeAirlinesState::display() const {
    cout << "Show only flights with the minimum number of different airlines? [s/n]: ";
}

void MinimizeAirlinesState::handleInput(App* app) {

    string choice;
    cin >> choice;

    if (choice.size() == 1) {
        switch (choice[0]) {
            case 's':
                nextStateCallback(app, true);
                break;
            case 'n':
                nextStateCallback(app, false);
                break;
            default:
                cout << "Not a valid option. Try again." << endl;
        }
    } else cout << "Invalid input. Please enter a single character." << endl;



}
