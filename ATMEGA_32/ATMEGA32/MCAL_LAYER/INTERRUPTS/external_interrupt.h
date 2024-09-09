/*
 * external_interrupt.h
 *
 * Created: 9/8/2024 11:30:11 PM
 *  Author: Mohamed Tarek
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
/*******************Include Section*****************/
#include "Interrupt_config.h"
/*******************Micro Declarations***************/

/*******************Micro Functions Declarations*******/


/*******************Data Type Declaration***************/
typedef enum {
	low_level = 0 ,
	on_change ,
	failing_edge,
	rising_edge
	}INTx_MODE;

typedef enum{
	INT0_t = 0,
	INT1_t,
	INT2_t
	}intx;
typedef struct{
	void(*EXT_HANDLER)(void);
	intx intt;
	INTx_MODE mode;
	}INTx;


Std_ReturnType Intx_Init(const INTx *intx);
Std_ReturnType DISABLE_Init(const INTx *intx);
#endif /* EXTERNAL_INTERRUPT_H_ */