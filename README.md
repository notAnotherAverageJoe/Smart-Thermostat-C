# Thermostat System

This project simulates a thermostat system in C, allowing the user to adjust the heating and cooling modes, view the current temperature, and update the system settings.

## Features

- **Heating Mode**: Adjusts the temperature to the target temperature using heating.
- **Cooling Mode**: Adjusts the temperature to the target temperature using cooling.
- **System Settings**: Allows the user to modify thermostat settings.
- **User Input Handling**: The program validates user input to ensure proper selection and operation.

## Files

- `main.c`: The main file containing the thermostat system logic.
- `thermostat.h`: Header file containing the structure and function declarations for managing the thermostat.

## Structure

- `Thermostat`: A structure that contains the initial temperature, heating settings, and cooling settings.
- `Heating`: A structure inside `Thermostat` to manage heating parameters like current temperature and target temperature.
- `Cooling`: A structure inside `Thermostat` to manage cooling parameters.

## Functions

- `initializeThermostat()`: Initializes the thermostat with default temperatures for heating, cooling, and the current temperature.
- `updateHeating()`: Updates the heating system based on the target temperature.
- `updateCooling()`: Updates the cooling system based on the target temperature.
- `updateThermostat()`: Allows the user to update the thermostat settings.

## Compilation and Usage

### Requirements

- A C compiler (e.g., GCC).
- This project uses standard C libraries (`stdio.h`, `stdbool.h`).

### Compilation

To compile the project, use the following command:

```bash
gcc main.c -o thermostat -lm
```
