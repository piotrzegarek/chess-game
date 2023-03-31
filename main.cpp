#include "Application.h"

int main()
{
    Application application;

    // Main app loop
    while (application.isRunning()) {
        application.update();
        application.render();
    }

    return 0;
}