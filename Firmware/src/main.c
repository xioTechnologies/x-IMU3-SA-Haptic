/**
 * @file main.c
 * @author Seb Madgwick
 * @brief Main file.
 *
 * Device:
 * PIC32MM0064GPL020
 *
 * Compiler:
 * XC32 v4.60, MPLAB Harmony 3
 */

//------------------------------------------------------------------------------
// Includes

#include "definitions.h"
#include "FirmwareVersion.h"
#include "Haptic/Haptic.h"
#include "Receive/Receive.h"
#include "ResetCause/ResetCause.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "Timer/Timer.h"
#include "Uart/Uart1.h"

//------------------------------------------------------------------------------
// Functions

int main(void) {
    SYS_Initialize(NULL);

    // Initialise modules
    TimerInitialise();
    Uart1Initialise(&uartSettingsDefault);
    HapticInitialise();

    // Print start up message
    ResetCausePrint(ResetCauseGet());
    printf("x-IMU3-SA-Haptic " FIRMWARE_VERSION "\n");

    // Main program loop
    while (true) {
        SYS_Tasks();
        ReceiveTasks();
    }
    return (EXIT_FAILURE);
}

//------------------------------------------------------------------------------
// End of file
