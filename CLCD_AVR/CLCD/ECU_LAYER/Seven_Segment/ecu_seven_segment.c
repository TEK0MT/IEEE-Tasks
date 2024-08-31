/*
 * ecu_seven_segment.c
 *
 * Created: 8/19/2024 11:17:16 AM
 *  Author: Mohamed Tarek
 */ 
#include "ecu_seven_segment.h"

Std_ReturnType Seven_Segment_Init(const seven_segment_t *ssd){
	Std_ReturnType ret = E_OK;
	if(ssd == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_initialize(&(ssd->pins[0]));
		gpio_pin_initialize(&(ssd->pins[1]));
		gpio_pin_initialize(&(ssd->pins[2]));
		gpio_pin_initialize(&(ssd->pins[3]));
	}
	return ret;
}
Std_ReturnType Seven_Segment_Write_Value(const seven_segment_t *ssd,uint8 value){
	Std_ReturnType ret = E_OK;
	if(ssd == NULL){
		ret = E_NOT_OK;
	}
	else{
		
			
		
			gpio_pin_write_logic(&(ssd->pins[0]),(value & 0x01));
			gpio_pin_write_logic(&(ssd->pins[1]),((value >> 1) & 0x01));
			gpio_pin_write_logic(&(ssd->pins[2]),((value >> 2) & 0x01));
			gpio_pin_write_logic(&(ssd->pins[3]),((value >> 3) & 0x01));
		
	}
	return ret;
}