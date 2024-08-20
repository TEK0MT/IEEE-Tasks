/*
 * ecu_seven_segment.h
 *
 * Created: 8/19/2024 11:09:14 AM
 *  Author: Mohamed Tarek
 */ 


#ifndef ECU_SEVEN_SEGMENT_H_
#define ECU_SEVEN_SEGMENT_H_
/*******************Include Section*****************/
#include "../../MCAL_LAYER/GPIO/gpio.h"
/*******************Micro Declarations***************/

/*******************Micro Functions Declarations*******/

/*******************Data Type Declaration***************/
typedef enum{
	ANODE,
	CATHODE
}seven_segment_connection_type;

typedef struct{
	pin_config_t pins[4];
	seven_segment_connection_type connection;
}seven_segment_t;

/*******************Data Type Declaration***************/
Std_ReturnType Seven_Segment_Init(const seven_segment_t *ssd);
Std_ReturnType Seven_Segment_Write_Value(const seven_segment_t *ssd,uint8 value);

#endif /* ECU_SEVEN_SEGMENT_H_ */