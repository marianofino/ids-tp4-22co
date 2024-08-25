#include "gpio.h"
#include <stdlib.h>
#include <stddef.h>

#define USE_DYNAMIC_MEM

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

struct gpio_s {
    uint8_t port;
    uint8_t bit;
    bool output;
    bool used;
};

/**
 * @brief funcion para reservar memoria estatica
 *
 * @return gpio_t
 */
static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index].used;
            result->used = true;
            break;
        }
    }
    
    return result;
}

/**
 * @brief  funcion que crea la struct para los objetos
 * 
 * @param puerto 
 * @param bit 
 * @return gpio_t 
 */

gpio_t gpioCreate(uint8_t puerto, uint8_t bit) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpio_t self = allocateInstance();
#endif
    if (self) {
        self->port = puerto;
        self->bit = bit;
        self->output = false;
    }
    return self;
}

/**
 * @brief funcion para setear si es salida o entrada
 * 
 * @param self 
 * @param output 
 */
void gpioSetOutput(gpio_t self, bool output) {
    //HAL_GPIO_SET_OUTPUT(self->port, self->bit);
}

/**
 * @brief Funcion para setear el estado ON/OFF
 * 
 * @param self 
 * @param state 
 */

void gpioSetState(gpio_t self, bool state) {
    //HAL_GPIO_SET_STATE(self->port, self->bit);
}

/**
 * @brief funcion para saber el estado
 * 
 * @param self 
 * @return true 
 * @return false 
 */
bool gpioGetState(gpio_t self) {
    return 1;//HAL_GPIO_GET_STATE(self->port, self->bit);
}
