#include "App.h"
#include "Data.h"

using namespace std;

int main()
{
    App* app = App::getInstance();
    Data* data = new Data();

    data->readFileAirlines();
    data->readFileAirports();
    data->readFileFlights();

    // Display the main menu
    while(app->getState() != nullptr) {
        app->display();
        app->handleInput();
    }

    // Cleanup
    delete app;

    return 0;
}
