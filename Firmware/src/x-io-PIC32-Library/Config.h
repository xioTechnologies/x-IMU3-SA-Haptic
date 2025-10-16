/**
 * @file Config.h
 * @author Seb Madgwick
 * @brief Library configuration.
 */

#ifndef CONFIG_H
#define CONFIG_H

//------------------------------------------------------------------------------
// Includes

#include "definitions.h"

//------------------------------------------------------------------------------
// Definitions

#define I2CBB1_SCL_PIN                      SCL_PIN
#define I2CBB1_SDA_PIN                      SDA_PIN
#define I2CBB1_HALF_CLOCK_CYCLE             (5)

#define UART1_READ_BUFFER_SIZE              (2048)
#define UART1_WRITE_BUFFER_SIZE             (2048)

#endif

//------------------------------------------------------------------------------
// End of file
