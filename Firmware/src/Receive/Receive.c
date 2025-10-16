/**
 * @file Receive.c
 * @author Seb Madgwick
 * @brief Message reception.
 */

//------------------------------------------------------------------------------
// Includes

#include "FirmwareVersion.h"
#include "Haptic/Haptic.h"
#include <stdio.h>
#include "Uart/Uart1.h"

//------------------------------------------------------------------------------
// Function prototypes

static void ProcessCommand(const char * const string);

//------------------------------------------------------------------------------
// Functions

/**
 * @brief Module tasks. This function should be called repeatedly within the
 * main program loop.
 */
void ReceiveTasks(void) {
    while (Uart1AvailableRead() > 0) {

        // Add to buffer
        static char buffer[64];
        static int index;
        buffer[index] = Uart1ReadByte();

        // Process message
        if (buffer[index] == '\n') {

            // Terminate string
            buffer[index] = '\0';

            // Parse command
            ProcessCommand(buffer);
            index = 0;
            continue;
        }

        // Increment index
        if (++index >= sizeof (buffer)) {
            printf("Receive buffer overrun\n");
            index = 0;
            continue;
        }
    }
}

/**
 * @brief Process command.
 * @param command Command.
 */
static void ProcessCommand(const char * const command) {

    // Haptic
    int effect;
    if (sscanf(command, "%i", &effect) == 1) {
        if (HapticPlay(effect) != HapticResultOk) {
            printf("Invalid haptic effect\n");
        }
        return;
    }

    // Test
    if (strcmp(command, "test") == 0) {
        printf("%s\n", HapticTestResultToString(HapticTest()));
        return;
    }

    // Version
    if (strcmp(command, "version") == 0) {
        printf("%s\n", FIRMWARE_VERSION);
        return;
    }

    // Invalid command
    printf("Invalid command %s\n", command);
}

//------------------------------------------------------------------------------
// End of file
