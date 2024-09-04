/**
 * @file gpio.c
 * @author Edilberto Carvajal (edicarvajalp@gmail.com)
 * @brief Definición de funciones para gestión de GPIOs
 * @version 0.1
 * @date 2024-09-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* === Headers files inclusions =============================================================== */
#include <stdio.h>
#include "gpio.h"

/* === Macros definitions ====================================================================== */
#define USE_DYNAMIC_MEM

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */
struct gpio_s {
    uint8_t port;
    uint8_t bit;
    bool output;
    bool state;
    bool used;
};

static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

/**
 * @brief Asigna una instancia libre de GPIO.
 * 
 * @return gpio_t 
 */
static gpio_t allocateInstance() {

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
 * @brief Crea un objeto GPIO para el puerto y bit especificados.
 * 
 * @param puerto Puerto del GPIO.
 * @param bit Bit del GPIO.
 * @return gpio_t 
 */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit) {
#ifdef USE_SYNAMIC_MEM
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
 * @brief Configura el modo de salida de un GPIO.
 * 
 * @param self Puntero al objeto GPIO.
 * @param output Modo de salida (true para salida, false para entrada).
 */
void gpioSetOutput(gpio_t self, bool output) {
    self->output = output;
    printf("Configuracion \tPuerto: %d Output: %d\n", self->port, self->output);
}

/**
 * @brief Establece el estado de un GPIO.
 * 
 * @param self Puntero al objeto GPIO.
 * @param state Estado del GPIO (true para alto, false para bajo).
 */
void gpioSetState(gpio_t self, bool state) {
    self->state = state;
    printf("Set state OK\n");
}

/**
 * @brief Obtiene y muestra el estado actual de un GPIO.
 * 
 * @param self Puntero al objeto GPIO.
 */
void gpioGetState(gpio_t self) {
    printf("State: %d\n", self->state);
}

/* === End of documentation ==================================================================== */
