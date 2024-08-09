/*
 * File:   main.c
 * Author: Mohamed Tarek
 *
 * Created on August 7, 2024, 3:29 AM
 */
#include "MCAL_LAYER/GPIO/gpio.h"

pin_config_t pin_red = {.port = PORTC_INDEX,.pin = Pin0,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin_yellow = {.port = PORTC_INDEX,.pin = Pin1,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin_green = {.port = PORTC_INDEX,.pin = Pin2,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
uint8 counter;
int main(void) {
    gpio_pin_initialize(&pin_red);
    gpio_pin_initialize(&pin_yellow);
    gpio_pin_initialize(&pin_green);
    
    while (1) {
        gpio_pin_write_logic(&pin_red,GPIO_LOW);
        gpio_pin_write_logic(&pin_yellow,GPIO_LOW);
        gpio_pin_write_logic(&pin_green,GPIO_LOW);
        if(counter == 0){
            gpio_pin_write_logic(&pin_red,GPIO_HIGH);
            counter++;
        }
        else if(counter == 1){
            gpio_pin_write_logic(&pin_yellow,GPIO_HIGH);
            counter++;
        }
        else if(counter == 2){
            gpio_pin_write_logic(&pin_green,GPIO_HIGH);
            counter = 0;
        }
        else{}
        _delay_ms(3000);
    }
}
