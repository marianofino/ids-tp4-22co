/************************************************************************************************
Copyright (c) 2024, Marco Rolon Radcenco <rolma271@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file main.c
 ** @brief Main application source file for LED control
 **
 ** This application demonstrates basic GPIO manipulation by controlling
 ** two LEDs (Red and Blue) connected to specific GPIO pins. The LEDs are 
 ** turned on when the application starts.
 **/

/* === Header files inclusions ================================================================ */

#include "main.h"
#include "gpio.h"

/* === Macros definitions ===================================================================== */

/**
 * @brief GPIO configuration for the Red LED.
 *
 * Defines the port and pin number where the Red LED is connected.
 */
#define LED_RED_PORT  1  /**< Port number for Red LED */
#define LED_RED_BIT   2  /**< Pin number for Red LED */

/**
 * @brief GPIO configuration for the Blue LED.
 *
 * Defines the port and pin number where the Blue LED is connected.
 */
#define LED_BLUE_PORT  1  /**< Port number for Blue LED */
#define LED_BLUE_BIT   3  /**< Pin number for Blue LED */

/* === Private data type declarations ========================================================= */

/* === Private variable declarations ========================================================== */

/* === Private function declarations ========================================================== */

/* === Public variable definitions ============================================================ */

/* === Private variable definitions =========================================================== */

/* === Private function implementation ======================================================== */

/* === Public function implementation ========================================================= */

/**
 * @brief Main function for the LED control application.
 *
 * This function initializes two GPIO pins for the Red and Blue LEDs,
 * sets them as outputs, and turns them on.
 *
 * @return The function returns 0 upon successful execution.
 */
int main(void) {

    // Initialize the Red LED GPIO pin and turn it on
    gpio_t led_red = gpio_Create(LED_RED_PORT, LED_RED_BIT);
    gpio_SetOutput(led_red, true);
    gpio_SetState(led_red, true);

    // Initialize the Blue LED GPIO pin and turn it on
    gpio_t led_blue = gpio_Create(LED_BLUE_PORT, LED_BLUE_BIT);
    gpio_SetOutput(led_blue, true);
    gpio_SetState(led_blue, true);

    return 0;  /**< Return 0 to indicate successful execution */
}

/* === End of file ============================================================================ */