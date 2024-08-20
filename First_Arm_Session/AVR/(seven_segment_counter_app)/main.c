/*
 * SSD.c
 *
 * Created: 8/19/2024 11:00:55 AM
 * Author : Mohamed Tarek
 */ 

#include "ECU_LAYER/Seven_Segment/ecu_seven_segment.h"

seven_segment_t ssd = {.pins[0].port = PORTA_INDEX , .pins[0].pin = Pin0,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
	.pins[1].port = PORTA_INDEX , .pins[1].pin = Pin1,.pins[1].logic = GPIO_LOW,.pins[1].direction = GPIO_DIRECTION_OUTPUT,
	.pins[2].port = PORTA_INDEX , .pins[2].pin = Pin2,.pins[2].logic = GPIO_LOW,.pins[2].direction = GPIO_DIRECTION_OUTPUT,
	.pins[3].port = PORTA_INDEX , .pins[3].pin = Pin3,.pins[3].logic = GPIO_LOW,.pins[3].direction = GPIO_DIRECTION_OUTPUT,
	.connection = CATHODE};
	
	pin_config_t pin1 = {.port = PORTD_INDEX,.pin = Pin0,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
		pin_config_t pin2 = {.port = PORTD_INDEX,.pin = Pin1,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
			
			volatile uint8 num = 0;
			uint8 counter = 0;
int main(void)
{
	Seven_Segment_Init(&ssd);
	gpio_pin_initialize(&pin1);
	gpio_pin_initialize(&pin2);
    /* Replace with your application code */
    while (1) 
    {
		for(counter = 0;counter < 50;counter++){
		Seven_Segment_Write_Value(&ssd,num %10);
		gpio_pin_write_logic(&pin2,GPIO_HIGH);
		_delay_ms(10);
		gpio_pin_write_logic(&pin2,GPIO_LOW);
		
		Seven_Segment_Write_Value(&ssd,num /10);
		gpio_pin_write_logic(&pin1,GPIO_HIGH);
		_delay_ms(10);
		gpio_pin_write_logic(&pin1,GPIO_LOW);}
		
		
		num++;
}
}
