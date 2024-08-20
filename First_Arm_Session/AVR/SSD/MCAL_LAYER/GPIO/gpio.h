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
#define SET_BIT(REG,POS)    (REG |= (1 << POS))
#define CLEAR_BIT(REG,POS)    (REG &= ~(1 << POS))
#define TOGGLE_BIT(REG,POS)    (REG ^= (1 << POS))
#define READ_BIT(REG,POS)    ((REG >> POS) & 0x01)

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

typedef struct{
  port_t port;
  pin_t pin;
  direction_t direction;
  logic_t logic;
}pin_config_t;

/*******************Functions Declaration***************/
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *obj_pin, direction_t direction);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *obj_pin,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *obj_pin,uint8 *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *obj_pin);
Std_ReturnType gpio_pin_initialize(const pin_config_t *obj_pin);


Std_ReturnType gpio_port_direction_initialize(const port_t port, direction_t direction);
Std_ReturnType gpio_port_write_logic(const port_t port,uint8 logic);
Std_ReturnType gpio_port_read_logic(const port_t port,uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(const port_t port);



#endif	/* GPIO_H */

