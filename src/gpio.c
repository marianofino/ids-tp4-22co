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

/** @file
 ** @brief Capa de abstracción para gestion de puertos digitales
 **/

/* === Headers files inclusions =============================================================== */

#include "gpio.h"
#include <stddef.h>
#include <stdint.h>

/* === Macros definitions ====================================================================== */

#define USE_DYNAMIC_MEM

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

/* === Private data type declarations ========================================================== */

//! Estructura con los atributos de un puerto
struct gpio_s {
    uint8_t port;
    uint8_t bit;
    bool output;
#ifndef USE_DYNAMIC_MEM
    bool used;
#endif /*USE_DYNAMIC_MEM*/
};

//* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

static gpio_t GpioAllocateInstance(void);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

#ifndef USE_DYNAMIC_MEM
static gpio_t GpioAllocateInstance(void) {

    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};
    gpio_t result = NULL;

    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index];
            result->used = true;
            break;
        }
    }
    return result;
}
#endif /*USE_DYNAMIC_MEM*/

/* === Public function implementation ========================================================== */

gpio_t GpioCreate(uint8_t puerto, uint8_t bit) {

#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpio_t self = GpioAllocateInstance();
#endif

    if (self) {
        self->port = puerto;
        self->bit = bit;
        self->output = false;
    }
    return self;
}

void GpioSetOutput(gpio_t self, bool output) {
    self->output = output;
    HAL_GPIO_SET_OUTPUT(self->port, self->bit);
}

void GpioSetState(gpio_t self, bool state) {
    if (self->output) {
        HAL_GPIO_SET_STATE(self->port, self->bit, state);
    }
}

bool GpioGetState(gpio_t self) {
    return HAL_GPIO_GET_STATE(self->port, self->bit);
}
