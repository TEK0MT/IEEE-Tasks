/*
 * external_interrupt.c
 *
 * Created: 9/9/2024 2:34:44 AM
 *  Author: Mohamed Tarek
 */ 
#include "external_interrupt.h"
static void(*INT0_HANDLER)(void) = NULL;
static void(*INT1_HANDLER)(void);
static void(*INT2_HANDLER)(void);

static void mode_select_int0(const INTx *intx);
static void mode_select_int1(const INTx *intx);

Std_ReturnType Intx_Init(const INTx *intx){
	Std_ReturnType ret = E_OK;
	if (intx == NULL)
	{
		ret = E_NOT_OK;
	}
	else{
		SET_BIT(SREG,7);
		if (intx->intt == INT0_t)
		{
			SET_BIT(GICR,6);
			SET_BIT(GIFR,6);
			DDRD &= ~(1 << PD2);
			INT0_HANDLER = intx->EXT_HANDLER;
			mode_select_int0(intx);
		}
		else if(intx->intt == INT1_t){
			SET_BIT(GICR,7);
			SET_BIT(GIFR,7);
			DDRD &= ~(1 << PD3);
			INT1_HANDLER = intx->EXT_HANDLER;
			mode_select_int1(intx);
		}
		else if(intx->intt == INT2){
			SET_BIT(GICR,5);
			SET_BIT(GIFR,5);
			INT2_HANDLER = intx->EXT_HANDLER;
		}
	}
	return ret;
}



Std_ReturnType DISABLE_Init(const INTx *intx){
	Std_ReturnType ret = E_OK;
	if (intx == NULL)
	{
		ret = E_NOT_OK;
	}
	else{
		
		if (intx->intt == INT0_t)
		{
			CLEAR_BITR(GICR,6);
			
		}
		else if(intx->intt == INT1_t){
			CLEAR_BIT(GICR,7);
			
		}
		else if(intx->intt == INT2_t){
			CLEAR_BIT(GICR,5);
			
		}
	}
	return ret;
}







static void mode_select_int0(const INTx *intx){
	if(intx->mode == low_level){
		CLEAR_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);
	}
	else if(intx->mode == on_change){
		SET_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);
	}
	else if(intx->mode == failing_edge){
		SET_BIT(MCUCR,1);
		CLEAR_BIT(MCUCR,0);
	}
	else if(intx->mode == rising_edge){
		SET_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);
	}
	else{}
}


static void mode_select_int1(const INTx *intx){
	if(intx->mode == low_level){
		CLEAR_BIT(MCUCR,2);
		CLEAR_BIT(MCUCR,3);
	}
	else if(intx->mode == on_change){
		SET_BIT(MCUCR,2);
		CLEAR_BIT(MCUCR,3);
	}
	else if(intx->mode == failing_edge){
		SET_BIT(MCUCR,3);
		CLEAR_BIT(MCUCR,2);
	}
	else if(intx->mode == rising_edge){
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	}
	else{}
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(INT0_HANDLER != NULL){
		INT0_HANDLER();
	}
	SET_BIT(GIFR,6);
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(INT1_HANDLER){
		INT1_HANDLER();
	}
	SET_BIT(GIFR,7);
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(INT2_HANDLER){
		INT2_HANDLER();
	}
	SET_BIT(GIFR,5);
}
