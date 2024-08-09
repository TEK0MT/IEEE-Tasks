/*
 * File:   main.c
 * Author: Mohamed Tarek
 *
 * Created on August 7, 2024, 3:29 AM
 */
#include "MCAL_LAYER/GPIO/gpio.h"

/*pin_config_t pin_1 = {.port = PORTC_INDEX,.pin = Pin0,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin_2 = {.port = PORTC_INDEX,.pin = Pin1,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin_3 = {.port = PORTC_INDEX,.pin = Pin2,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin_4 = {.port = PORTC_INDEX,.pin = Pin3,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin_5 = {.port = PORTC_INDEX,.pin = Pin4,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin_6 = {.port = PORTC_INDEX,.pin = Pin5,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin_7 = {.port = PORTC_INDEX,.pin = Pin6,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin_8 = {.port = PORTC_INDEX,.pin = Pin7,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};*/
uint8 counter = 0;
int main(void) {
    /*gpio_pin_initialize(&pin_1);
    gpio_pin_initialize(&pin_2);
    gpio_pin_initialize(&pin_3);
	gpio_pin_initialize(&pin_4);
	gpio_pin_initialize(&pin_5);
	gpio_pin_initialize(&pin_6);
	gpio_pin_initialize(&pin_7);
	gpio_pin_initialize(&pin_8);*/
    gpio_port_direction_initialize(PORTC_INDEX, GPIO_DIRECTION_OUTPUT);
    while (1) {
       gpio_port_write_logic(PORTC_INDEX,counter);
	   _delay_ms(1000);
	   counter++;
    }
}
