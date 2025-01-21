#include "thermostat.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int getKeyPress()
{
    struct termios oldt, newt;
    int ch;

    // Save the old terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable canonical mode and echo
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read a single character
    ch = getchar();

    // Restore the old attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

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
    int userChoice;
    while (true)
    {
        printf("What settings would you like to change?\n");
        printf("1. Heating Target\n");
        printf("2. Cooling Target\n");
        printf("3. Exit\n");
        scanf("%d", &userChoice);

        if (userChoice == 3)
        {
            printf("Exiting thermostat settings.\n");
            break;
        }

        switch (userChoice)
        {
        case 1: // Adjust Heating Target
            printf("Heating Target Selected.\n");
            while (true)
            {
                printf("Current Heating Target: %d\n", thermostat->heating.targetTemp);
                printf("Use Up/Down arrows to adjust the heating target. Press 'q' to quit.\n");

                int key = getKeyPress();

                if (key == 'q') // Quit on 'q'
                {
                    printf("Exiting Heating Target adjustment.\n");
                    break;
                }
                else if (key == 65) // Up arrow (ASCII code for up)
                {
                    thermostat->heating.targetTemp++;
                }
                else if (key == 66) // Down arrow (ASCII code for down)
                {
                    thermostat->heating.targetTemp--;
                }
            }
            break;

        case 2: // Adjust Cooling Target
            printf("Cooling Target Selected.\n");
            while (true)
            {
                printf("Current Cooling Target: %d\n", thermostat->cooling.targetTemp);
                printf("Use Up/Down arrows to adjust the cooling target. Press 'q' to quit.\n");

                int key = getKeyPress();

                if (key == 'q') // Quit on 'q'
                {
                    printf("Exiting Cooling Target adjustment.\n");
                    break;
                }
                else if (key == 65) // Up arrow
                {
                    thermostat->cooling.targetTemp++;
                }
                else if (key == 66) // Down arrow
                {
                    thermostat->cooling.targetTemp--;
                }
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}
