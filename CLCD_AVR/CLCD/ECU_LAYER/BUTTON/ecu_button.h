/*
 * ecu_button.h
 *
 * Created: 8/19/2024 11:33:40 PM
 *  Author: Mohamed Tarek
 */ 


#ifndef ECU_BUTTON_H_
#define ECU_BUTTON_H_
/*******************Include Section*****************/
#include "../../MCAL_LAYER/GPIO/gpio.h"

/*******************Micro Functions Declarations*******/




/*******************Micro Declarations***************/



/*******************Data Type Declaration***************/
typedef enum{
	ACTIVE_HIGH,
	ACTIVE_LOW
	}button_typed;
	
typedef enum{
	BUTTON_RELEASED,
	BUTTON_PRESSED
	}button_state;

typedef struct{
	pin_config_t pin;
	button_typed type;
	}button_t;
	
/*******************Functions Declaration***************/
Std_ReturnType Button_Init(const button_t *btn);
Std_ReturnType Button_Read_Value(const button_t *btn,button_state *val);

#endif /* ECU_BUTTON_H_ */