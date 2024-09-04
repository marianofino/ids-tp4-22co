#ifndef GPIO_H
#define GPIO_H

/**
 * @file gpio.h
 * @author Edilberto Carvajal (edicarvajalp@gmail.com)
 * @brief Archivo de cabecera para gestión de GPIOs.
 * @version 0.1
 * @date 2024-09-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/* === Headers files inclusions ================================================================ */
#include <stdint.h>
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
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);
void gpioSetOutput(gpio_t gpio, bool output);
void gpioSetState(gpio_t gpip, bool state);
void gpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
