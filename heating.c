#include "heating.h"
#include <stdio.h>

void updateHeating(struct Heating *heating)
{
    while (heating->currentTemp < heating->targetTemp)
    {
        heating->isHeating = true;
        heating->currentTemp++;
        printf("Heating in process -> Current Temp: %d\n", heating->currentTemp);
    }

    heating->isHeating = false;
    printf("Target temperature reached: %d\n", heating->currentTemp);
}
