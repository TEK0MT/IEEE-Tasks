/*
 * Interrupt_config.h
 *
 * Created: 9/8/2024 11:27:42 PM
 *  Author: Mohamed Tarek
 */ 


#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_

#include "../GPIO/gpio.h"
#include "../Std_libraries.h"
#define INTERRUPT_DISABLE 0x00
#define INTERRUPT_ENABLE  0x01
#define INTERRUPT  INTERRUPT_ENABLE

#if INTERRUPT == INTERRUPT_ENABLE
#define INT0_ENABLE INTERRUPT_ENABLE
#define INT1_ENABLE INTERRUPT_ENABLE
#define INT2_ENABLE INTERRUPT_ENABLE
#endif



#endif /* INTERRUPT_CONFIG_H_ */