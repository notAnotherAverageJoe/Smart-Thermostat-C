#include "thermostat.h"

void initializeThermostat(struct Thermostat *thermostat, int initialTemp, int heatingTarget, int coolingTarget)
{
    thermostat->initialTemp = initialTemp;
    thermostat->heating.currentTemp = initialTemp;
    thermostat->heating.targetTemp = heatingTarget;
    thermostat->heating.isHeating = false;

    thermostat->cooling.currentTemp = initialTemp;
    thermostat->cooling.targetTemp = coolingTarget;
    thermostat->cooling.isCooling = false;
}

void updateThermostat(struct Thermostat *thermostat)
{
    if (thermostat->cooling.currentTemp > thermostat->cooling.targetTemp)
    {
        updateCooling(&thermostat->cooling);
    }
}