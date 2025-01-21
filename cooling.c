#include "cooling.h"
#include <stdio.h>

void updateCooling(struct Cooling *cooling)
{
    while (cooling->currentTemp > cooling->targetTemp)
    {
        cooling->isCooling = true;
        cooling->currentTemp--;
        printf("Cooling in process -> Current Temp: %d\n", cooling->currentTemp);
    }

    cooling->isCooling = false;
    printf("Target temperature reached: %d\n", cooling->currentTemp);
}
