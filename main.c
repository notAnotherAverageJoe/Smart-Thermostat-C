#include <stdio.h>
#include <stdbool.h>
#include "thermostat.h"

int main()
{
    struct Thermostat thermostat;
    initializeThermostat(&thermostat, 50, 78, 68);

    bool hasPower = true;
    int userChoice;

    printf("Thermostat System\n");
    printf("1. Adjust Heating\n");
    printf("2. Adjust Cooling\n");
    printf("3. Exit\n");

    while (hasPower)
    {
        // current temp
        printf("\nCurrent Temp -> %d", thermostat.initialTemp);

        printf("\n\nEnter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:
            printf("\nHeating Mode Activated.\n");
            updateHeating(&thermostat.heating);
            printf("Heating - Current Temp: %d, Target Temp: %d, Is Heating: %s\n",
                   thermostat.heating.currentTemp, thermostat.heating.targetTemp,
                   thermostat.heating.isHeating ? "Yes" : "No");
            thermostat.initialTemp = thermostat.heating.currentTemp;
            break;

        case 2:
            printf("\nCooling Mode Activated.\n");
            updateCooling(&thermostat.cooling);
            printf("Cooling - Current Temp: %d, Target Temp: %d, Is Cooling: %s\n",
                   thermostat.cooling.currentTemp, thermostat.cooling.targetTemp,
                   thermostat.cooling.isCooling ? "Yes" : "No");
            break;

        case 3:
            printf("\nExiting Thermostat System. Goodbye!\n");
            hasPower = false;
            break;

        default:
            printf("\nInvalid choice. Please select 1, 2, or 3.\n");
            break;
        }
    }

    return 0;
}
