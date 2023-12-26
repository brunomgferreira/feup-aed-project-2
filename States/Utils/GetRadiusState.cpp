#include <iostream>
#include "GetRadiusState.h"

GetRadiusState::GetRadiusState(function<void(App*, const int)> nextStateCallback)
    : nextStateCallback(nextStateCallback) {}

void GetRadiusState::display() const {
    cout << "Insert radius: ";
}

void GetRadiusState::handleInput(App* app) {
    string radius;
    std::cin.ignore();
    std::getline(std::cin, radius);

    // TODO check radius format
    // TODO erro quando a passar para inteiro quando o input é um digito por exemplo: 1
    nextStateCallback(app, stoi(radius));
}