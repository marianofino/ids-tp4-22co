/************************************************************************************************
Copyright (c) 2024, Federico Leonardo Alderisi <federicoalderisi@gmail.com>

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

#ifndef GPIO_H
#define GPIO_H

/** @file gpio.h
 ** @brief Definición de la clase gpio
 **/

/* === Headers files inclusions ================================================================ */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

typedef struct gpio_s * gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Función que crea objeto y lo retorna. Utilizando #define USE_DYNAMIC_MEM, se crea
 * dinámicamente, sino, GPIO_MAX_INSTANCES define la cantidad maxima de instancias que se pueden
 * crear.
 *
 * @param puerto
 * @param pin
 * @return gpio_t
 */
gpio_t GpioCreate(uint8_t puerto, uint8_t pin);

/**
 * @brief Define un gpio como salida
 *
 * @param self
 * @param output
 */
void GpioSetOutput(gpio_t self, bool output);

/**
 * @brief Configura el estado de la salida como 1 o 0 según el valor de state
 *
 * @param self
 * @param state
 */
void GpioSetState(gpio_t self, bool state);

/**
 * @brief Devuelve el estado del gpio
 *
 * @param self
 * @return true
 * @return false
 */
bool GpioGetState(gpio_t self);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
