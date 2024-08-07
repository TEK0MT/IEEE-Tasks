/* 
 * File:   gpio.h
 * Author: Mohamed Tarek
 *
 * Created on August 7, 2024, 3:45 AM
 */

#ifndef GPIO_H
#define	GPIO_H
/*******************Include Section*****************/
#include "gpio_cfg.h"
#include "../Std_Types.h"

/*******************Micro Declarations***************/
#define DDRA_ *(volatile uint8 *)0x3A
#define DDRB_ *(volatile uint8 *)0x3B
#define DDRC_ *(volatile uint8 *)0x35
#define DDRD_ *(volatile uint8 *)0x31

#define PORTA_ *(volatile uint8 *)0x3B
#define PORTB_ *(volatile uint8 *)0x38
#define PORTC_ *(volatile uint8 *)0x35
#define PORTD_ *(volatile uint8 *)0x32

#define PINA_ *(volatile uint8 *)0x39
#define PINB_ *(volatile uint8 *)0x36
#define PINC_ *(volatile uint8 *)0x33
#define PIND_ *(volatile uint8 *)0x30

/*******************Micro Functions Declarations*******/

/*******************Data Type Declaration***************/
typedef enum {
    GPIO_LOW = 0,
            GPIO_HIGH
}logic_t;

typedef enum {
    GPIO_DIRECTION_INPUT,
            GPIO_DIRECTION_OUTPUT
}direction_t;

typedef enum {
    Pin0,
            Pin1,
            Pin2,
            Pin3,
            Pin4,
            Pin5,
            Pin6,
            Pin7
}pin_t;

typedef enum {
    PORTA_INDEX,
            PORTB_INDEX,
            PORTC_INDEX,
            PORTD_INDEX
}port_t;

/*******************Functins Declaration***************/
#endif	/* GPIO_H */

