/*
 * ecu_button.c
 *
 * Created: 8/19/2024 11:39:09 PM
 *  Author: Mohamed Tarek
 */ 
#include "ecu_button.h"
Std_ReturnType Button_Init(const button_t *btn){
	Std_ReturnType ret = E_OK;
	
	if(btn == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_direction_initialize(&(btn->pin),GPIO_DIRECTION_INPUT);
	}
	return ret;
}
Std_ReturnType Button_Read_Value(const button_t *btn,button_state *val){
	Std_ReturnType ret = E_NOT_OK;
	logic_t pin_logic = GPIO_LOW;
	if(btn == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_read_logic(&(btn->pin),&pin_logic);
		if(btn->type == ACTIVE_HIGH){
			if(pin_logic == GPIO_HIGH){
				*val = BUTTON_PRESSED;
			}
			else{
				*val = BUTTON_RELEASED;
			}
		}
		else if(btn->type == ACTIVE_LOW){
			if(pin_logic == GPIO_HIGH){
				*val = BUTTON_RELEASED;
			}
			else{
				*val = BUTTON_PRESSED;
			}
		}
		else{/*nothing*/}
		ret = E_OK;
	}
	return ret;
}