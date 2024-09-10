/* 
 * File:   Keypad.c
 * Author: Mohamed Tarek
 *
 * Created on SEPTEMPER 10, 2024, 2:09 AM
 */
#include "ecu_keypad.h"

uint8 keypad_values[KEYPAD_ROWS][KEYPAD_COLOUMNS] = {
                                                    {'7','8','9','/'},
                                                    {'4','5','6','*'},
                                                    {'1','2','3','-'},
                                                    {'#','0','=','+'}
    
                                                    };





/**
 * 
 * @param _keypad_obj
 * @return std return type variable
 */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj){
    Std_ReturnType ret = E_OK;
    uint8 row_counter = 0,coloumns_conter = 0;
    if(_keypad_obj == NULL){
        ret = E_NOT_OK;
    }
    else{
        for(row_counter = 0;row_counter < KEYPAD_ROWS;row_counter++){
            ret = gpio_pin_initialize(&(_keypad_obj->rows[row_counter]));
        }
        for(coloumns_conter = 0;row_counter < KEYPAD_COLOUMNS;coloumns_conter++){
            ret = gpio_pin_initialize(&(_keypad_obj->coloumns[coloumns_conter]));
        }
    }
    return ret;
}

/**
 * 
 * @param _keypad_obj
 * @param value
 * @return 
 */
Std_ReturnType keypad_read_value(const keypad_t *_keypad_obj, uint8 *value) {
    Std_ReturnType ret = E_OK;
    uint8 row_counter = 0, coloumns_conter = 0, l_counter = 0;
    uint8 value_l = 0;
    if (_keypad_obj == NULL || value == NULL) {
        ret = E_NOT_OK;
    } else {
        for (row_counter = 0; row_counter < KEYPAD_ROWS; row_counter++) {
            for (l_counter = 0; l_counter < KEYPAD_ROWS; l_counter++) {
                ret = gpio_pin_write_logic(&(_keypad_obj->rows[l_counter]), GPIO_LOW);
            }
            ret = gpio_pin_write_logic(&(_keypad_obj->rows[row_counter]), GPIO_HIGH);
            _delay_ms(10);

            for (coloumns_conter = 0; coloumns_conter < KEYPAD_COLOUMNS; coloumns_conter++) {
                ret = gpio_pin_read_logic(&(_keypad_obj->coloumns[coloumns_conter]), &value_l);
                if (value_l == GPIO_HIGH) {
                    *value = keypad_values[row_counter][coloumns_conter];
                }
            }
        }
        return ret;
    }
}