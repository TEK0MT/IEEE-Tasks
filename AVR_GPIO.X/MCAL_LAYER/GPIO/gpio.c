/* 
 * File:   gpio.c
 * Author: Mohamed Tarek
 *
 * Created on August 7, 2024, 1:32 PM
 */
#include "gpio.h"

static volatile uint8 *port_registers[4] = {&PORTA_ ,&PORTB_ ,&PORTC_ ,&PORTD_};
static volatile uint8 *DDR_registers[4] = {&DDRA_ ,&DDRB_ ,&DDRC_ ,&DDRD_};
static volatile uint8 *PIN_registers[4] = {&PINA_ ,&PINB_ ,&PINC_ ,&PIND_};

/**
 * 
 * @param obj_pin
 * @param direction
 * @return 
 */
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *obj_pin, direction_t direction){
    Std_ReturnType ret = E_OK;
    if(obj_pin == NULL || obj_pin->port > MAX_PORTS || obj_pin->pin > MAX_PIN){
        ret = E_NOT_OK;
    }
    else{
        switch(direction){
            case GPIO_DIRECTION_INPUT :
                CLEAR_BIT(*DDR_registers[obj_pin->port],obj_pin->pin);
                break;
                case GPIO_DIRECTION_OUTPUT :
                SET_BIT(*DDR_registers[obj_pin->port],obj_pin->pin);
                break;
            default :
                ret = E_NOT_OK;
        }
    }
    return ret;
}
/**
 * 
 * @param obj_pin
 * @param logic
 * @return 
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *obj_pin,logic_t logic){
    Std_ReturnType ret = E_OK;
    if(obj_pin == NULL || obj_pin->port > MAX_PORTS || obj_pin->pin > MAX_PIN){
        ret = E_NOT_OK;
    }
    else{
        switch(logic){
            case GPIO_LOW :
                CLEAR_BIT(*port_registers[obj_pin->port],obj_pin->pin);
                break;
                case GPIO_HIGH :
                SET_BIT(*port_registers[obj_pin->port],obj_pin->pin);
                break;
            default :
                ret = E_NOT_OK;
        }
    }
    return ret;
}
/**
 * 
 * @param obj_pin
 * @param logic
 * @return 
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *obj_pin,logic_t *logic){
    Std_ReturnType ret = E_OK;
    if(obj_pin == NULL || obj_pin->port > MAX_PORTS || obj_pin->pin > MAX_PIN){
        ret = E_NOT_OK;
    }
    else{
        *logic = READ_BIT(*port_registers[obj_pin->port],obj_pin->pin);
    }
    return ret;
}
/**
 * 
 * @param obj_pin
 * @return 
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *obj_pin){
    Std_ReturnType ret = E_OK;
    if(obj_pin == NULL || obj_pin->port > MAX_PORTS || obj_pin->pin > MAX_PIN){
        ret = E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*port_registers[obj_pin->port],obj_pin->pin);
    }
    return ret;
}
Std_ReturnType gpio_pin_initialize(const pin_config_t *obj_pin){
    Std_ReturnType ret = E_OK;
    if(obj_pin == NULL || obj_pin->port > MAX_PORTS || obj_pin->pin > MAX_PIN){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_direction_initialize(obj_pin,obj_pin->direction);
        gpio_pin_write_logic(obj_pin,obj_pin->logic);
    }
    return ret;
}


/**
 * 
 * @param port
 * @param direction
 * @return 
 */
Std_ReturnType gpio_port_direction_initialize(const port_t port, direction_t direction){
    Std_ReturnType ret = E_OK;
    if(port == NULL){
        ret = E_NOT_OK;
    }
    else{
        *DDR_registers[port] = direction;
    }
}
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
Std_ReturnType gpio_port_write_logic(const port_t port,logic_t logic){
    Std_ReturnType ret = E_OK;
    if(port == NULL){
        ret = E_NOT_OK;
    }
    else{
        *port_registers[port] = logic;
    }
}
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
Std_ReturnType gpio_port_read_logic(const port_t port,uint8 *logic){
    Std_ReturnType ret = E_OK;
    if(port == NULL){
        ret = E_NOT_OK;
    }
    else{
       *logic =  *port_registers[port];
    }
}
/**
 * 
 * @param port
 * @return 
 */
Std_ReturnType gpio_port_toggle_logic(const port_t port){
    Std_ReturnType ret = E_OK;
    if(port == NULL){
        ret = E_NOT_OK;
    }
    else{
        *port_registers[port] ^= 0xFF;
    }
}