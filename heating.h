#ifndef HEATING_H
#define HEATING_H

#include <stdbool.h>
// heating struct
struct Heating
{
    int currentTemp;
    int targetTemp;
    bool isHeating;
};

void updateHeating(struct Heating *heating);

#endif // HEATING_H
