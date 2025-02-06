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
// update heating only
void updateHeating(struct Heating *heating);

#endif 
