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

/** @file gpio.c
 ** @brief GPIO control module source file
 **/

/* === Headers files inclusions =============================================================== */

#include "gpio.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/**
 * @brief Internal representation of a GPIO pin.
 *
 * This structure holds the necessary information to represent
 * a GPIO pin, including its port number, bit number, and
 * whether it is configured as an output.
 */
struct gpio_s {
    uint8_t port;   /**< Port number where the GPIO pin is located. */
    uint8_t bit;    /**< Bit number representing the specific pin in the port. */
    bool output;    /**< Flag indicating if the pin is configured as an output. */
};


/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

gpio_t gpio_Create(uint8_t port, uint8_t bit) {
    gpio_t gpio = malloc(sizeof(struct gpio_s));
    if (NULL != gpio) {
        gpio->port = port;
        gpio->bit = bit;
        gpio->output = false;
    }
    return gpio;
}

void gpio_SetOutput(gpio_t gpio, bool enable) {
    if (NULL != gpio) {
        gpio->output = output;
        HAL_GPIO_SetOutput(gpio->port, gpio->bit, enable);
    }
    else{
        /**  @todo: handle error */
    }    
}

void gpio_SetState(gpio_t gpio, bool state) {
    if (NULL != gpio) {
        HAL_GPIO_SetState(gpio->port, gpio->bit, state);
    }
    else{
        /**  @todo: handle error */
    }
}

/* === End of file ============================================================================== */