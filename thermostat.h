#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include "heating.h"
#include "cooling.h"
#include <stdbool.h>
struct Thermostat
{
    int initialTemp;
    struct Heating heating;
    struct Cooling cooling;
};

void initializeThermostat(struct Thermostat *thermostat, int initialTemp, int heatingTarget, int coolingTarget);
void updateThermostat(struct Thermostat *thermostat);
#endif