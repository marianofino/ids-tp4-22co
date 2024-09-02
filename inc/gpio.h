/************************************************************************************************
Copyright (c) 2024, Iván Podoroska <ivanpodoroska@gmail.com>

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

/** @file gpio.h
 ** @brief GPIO control module header file
 **/

#ifndef GPIO_H_
#define GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

/* === Headers files inclusions =============================================================== */

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/**
 * @brief A handle for managing a GPIO pin.
 *
 * This type represents a pointer to a structure that encapsulates
 * the details of a GPIO pin.
 * It is used to abstract and simplify the manipulation of GPIO pins
 * within the application.
 */
typedef struct gpio_s * gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Creates a GPIO handle for a specific pin.
 *
 * @param port The port number of the GPIO pin.
 * @param bit The bit number of the GPIO pin.
 * @return A handle for the GPIO pin.
 */
gpio_t gpio_Create(uint8_t port, uint8_t bit);

/**
 * @brief Configures the GPIO pin as an output.
 *
 * @param gpio The GPIO handle.
 * @param enable Set to true to enable output mode, false to disable.
 */
void gpio_SetOutput(gpio_t gpio, bool enable);

/**
 * @brief Sets the state of the GPIO pin.
 *
 * @param gpio The GPIO handle.
 * @param state Set to true to turn the pin high, false to turn it low.
 */
void gpio_SetState(gpio_t gpio, bool state);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H_ */

/* === End of file ============================================================================ */
