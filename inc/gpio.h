#include <stdint.h>
#include <stdbool.h>

/**
 * @brief declaro un puntero a struct anonima porque no declaro los mienbros
 * 
 */
typedef struct gpio_s * gpio_t; 

/**
 * @brief funcion para crear el objeto
 * 
 * @param puerto 
 * @param bit 
 * @return gpio_t 
 */

gpio_t gpioCreate(uint8_t puerto, uint8_t bit); 

/**
 * @brief funcion para setear si es salida o entrada
 * 
 * @param gpio 
 * @param output 
 */

void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Funcion para saber el estado
 * 
 * @param gpio 
 * @param state 
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Funcion para setear el estado ON/OFF
 * 
 * @param gpio 
 * @return true 
 * @return false 
 */

bool gpioGetState(gpio_t gpio);
