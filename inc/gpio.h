#include <stdint.h>
#include <stdbool.h>


typedef struct gpio_s * gpio_t; // declaro un puntero astruct anonima porque no declaro los mienbros

gpio_t gpioCreate(uint8_t puerto, uint8_t bit); //para crear el objeto y recibe las elementar para que funcione o no recibir nada y me devuelve el puntero gpio_t

void gpioSetOutput(gpio_t gpio, bool output);

void gpioSetState(gpio_t gpio, bool state);

bool gpioGetState(gpio_t gpio);
