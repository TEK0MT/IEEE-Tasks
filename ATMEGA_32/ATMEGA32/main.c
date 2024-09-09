/*
 * ATMEGA32.c
 *
 * Created: 9/8/2024 10:52:29 PM
 * Author : Mohamed Tarek
 */ 
#include "MCAL_LAYER/INTERRUPTS/external_interrupt.h"

volatile uint8 num = 0;

void isr(void);  // ISR function prototype

INTx in0 = {
    .intt = INT0_t, 
    .mode = on_change, 
    .EXT_HANDLER = isr
};

pin_config_t pin_j = {
    .direction = GPIO_DIRECTION_OUTPUT,
    .pin = Pin0,
    .port = PORTD_INDEX,
    .logic = GPIO_LOW
};

int main(void)
{
    /* Initialize pin PD0 as output */
    gpio_pin_initialize(&pin_j);
    
    /* Initialize INT0 interrupt */
    Intx_Init(&in0);
    
    /* Enable global interrupts */
    

    while (1) 
    {
        // Your main loop
    }
}

/* ISR to toggle the pin */
void isr(void){
    gpio_pin_write_logic(&pin_j,GPIO_HIGH);
	_delay_ms(500);
	gpio_pin_write_logic(&pin_j,GPIO_LOW);
}
