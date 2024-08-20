/*
 * SSD.c
 *
 * Created: 8/19/2024 11:00:55 AM
 * Author : Mohamed Tarek
 */ 
#include <string.h>
#include "ECU_LAYER/Seven_Segment/ecu_seven_segment.h"
#include "ECU_LAYER/BUTTON/ecu_button.h"

seven_segment_t ssd = {.pins[0].port = PORTA_INDEX , .pins[0].pin = Pin0,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
	.pins[1].port = PORTA_INDEX , .pins[1].pin = Pin1,.pins[1].logic = GPIO_LOW,.pins[1].direction = GPIO_DIRECTION_OUTPUT,
	.pins[2].port = PORTA_INDEX , .pins[2].pin = Pin2,.pins[2].logic = GPIO_LOW,.pins[2].direction = GPIO_DIRECTION_OUTPUT,
	.pins[3].port = PORTA_INDEX , .pins[3].pin = Pin3,.pins[3].logic = GPIO_LOW,.pins[3].direction = GPIO_DIRECTION_OUTPUT,
	.connection = CATHODE};
	
	pin_config_t pin_false = {.port = PORTD_INDEX,.pin = Pin6,.logic=GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
		pin_config_t pin_true = {.port = PORTD_INDEX,.pin = Pin7,.logic=GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
			pin_config_t pin_TEST = {.port = PORTC_INDEX,.pin = Pin7,.logic=GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
			
			button_t btn1= {.pin.port = PORTD_INDEX,.pin.pin = Pin0,.pin.direction = GPIO_DIRECTION_INPUT,.pin.logic = GPIO_LOW,.type = ACTIVE_HIGH};
				button_t btn2= {.pin.port = PORTD_INDEX,.pin.pin = Pin1,.pin.direction = GPIO_DIRECTION_INPUT,.pin.logic = GPIO_LOW,.type = ACTIVE_HIGH};
					button_t btn3= {.pin.port = PORTD_INDEX,.pin.pin = Pin2,.pin.direction = GPIO_DIRECTION_INPUT,.pin.logic = GPIO_LOW,.type = ACTIVE_HIGH};
						button_t btn4= {.pin.port = PORTD_INDEX,.pin.pin = Pin3,.pin.direction = GPIO_DIRECTION_INPUT,.pin.logic = GPIO_LOW,.type = ACTIVE_HIGH};
							button_t btn5 = {.pin.port = PORTD_INDEX,.pin.pin = Pin4,.pin.direction = GPIO_DIRECTION_INPUT,.pin.logic = GPIO_LOW,.type = ACTIVE_HIGH};
			
button_state btns1 = BUTTON_RELEASED;
button_state btns2 = BUTTON_RELEASED;
button_state btns3 = BUTTON_RELEASED;
button_state btns4 = BUTTON_RELEASED;
button_state btns5 = BUTTON_RELEASED;
const uint8 right[4] = "1234";
uint8 counter = 0;
uint8 pass[4] = "0000";

uint8 check(uint8 *pas);
int main(void)
{
	Seven_Segment_Init(&ssd);
	gpio_pin_initialize(&pin_false);
	gpio_pin_initialize(&pin_true);
	Button_Init(&btn1);
	Button_Init(&btn2);
	Button_Init(&btn3);
	Button_Init(&btn4);
	Button_Init(&btn5);
    /* Replace with your application code */
    while (1) 
    {
		Button_Read_Value(&btn1,&btns1);
		Button_Read_Value(&btn2,&btns2);
		Button_Read_Value(&btn3,&btns3);
		Button_Read_Value(&btn4,&btns4);
		Button_Read_Value(&btn5,&btns5);
		if(counter < 4){
		if(btns1 == BUTTON_PRESSED){
			pass[counter] = '1';
			Seven_Segment_Write_Value(&ssd,1);
			counter++;
		}
		else if(btns2 == BUTTON_PRESSED){
			pass[counter] = '2';
			Seven_Segment_Write_Value(&ssd,2);
			counter++;
		}
		else if(btns3 == BUTTON_PRESSED){
			pass[counter] = '3';
			Seven_Segment_Write_Value(&ssd,3);
			counter++;
		}
		else if(btns4 == BUTTON_PRESSED){
			pass[counter] = '4';
			Seven_Segment_Write_Value(&ssd,4);
			counter++;
		}
		else if(btns5 == BUTTON_PRESSED){
			pass[counter] = '5';
			Seven_Segment_Write_Value(&ssd,5);
			counter++;
		}
		else{//gpio_pin_write_logic(&pin_false,GPIO_HIGH);gpio_pin_write_logic(&pin_true,GPIO_HIGH);
		}
			
		}
		else{
			if(check(pass)){
				gpio_pin_write_logic(&pin_true,GPIO_HIGH);
			}
			else{
				gpio_pin_write_logic(&pin_false,GPIO_HIGH);
			}
		}
		_delay_ms(200);
	}
}
uint8 check(uint8 *pas){
	uint8 flag = 1;
	for(uint8 i = 0;i < 4;i++){
		if(pas[i] != right[i]){
			flag = 0;
			break;
		}
	}
	return flag;
}