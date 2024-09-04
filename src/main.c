
/**
 * @file main.c
 * @author Edilberto Carvajal (edicarvajalp@gmail.com)
 * @brief Definición de la función principal del programa
 * @version 0.1
 * @date 2024-09-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/* === Headers files inclusions =============================================================== */
#include "gpio.h"
#include "main.h"

/* === Macros definitions ====================================================================== */
#define LED_ROJO_PUERTO 0
#define LED_ROJO_BIT    1
#define LED_AZUL_PUERTO 3
#define LED_AZUL_BIT    1

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/**
 * @brief Función principal
 * 
 * @return int 
 */
int main(void) {

    gpio_t p_led_rojo = gpioCreate(LED_ROJO_PUERTO, LED_ROJO_BIT);
    gpioSetOutput(p_led_rojo, true);

    gpio_t p_led_azul = gpioCreate(LED_AZUL_PUERTO, LED_AZUL_BIT);
    gpioSetOutput(p_led_azul, true);

    return 0;
}

/* === End of documentation ==================================================================== */
