#ifndef COOLING_H
#define COOLING_H

#include <stdbool.h>

struct Cooling
{
    int currentTemp;
    int targetTemp;
    bool isCooling;
};

void updateCooling(struct Cooling *cooling);

#endif
