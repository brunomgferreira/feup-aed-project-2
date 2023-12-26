#include <iostream>
#include <limits>
#include "State.h"

void State::PressEnterToContinue() const {
    cout << "Press ENTER to continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}