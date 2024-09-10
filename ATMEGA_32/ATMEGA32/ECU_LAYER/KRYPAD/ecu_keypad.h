/* 
 * File:   Keypad.h
 * Author: Mohamed Tarek
 *
 * Created on SEPTEMPER 10, 2024, 2:09 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H
/*Section : includes */
#include "../../MCAL_LAYER/GPIO/gpio.h"
/* Section : Macro Declarations */
#define KEYPAD_ROWS 4
#define KEYPAD_COLOUMNS 4
/* Section : Macro Functions Declarations */


/* Section : Data Type Declarations */
typedef struct{
    pin_config_t rows[KEYPAD_ROWS];
    pin_config_t coloumns[KEYPAD_COLOUMNS];
}keypad_t;

/* Section : Function Declarations */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_read_value(const keypad_t *_keypad_obj,uint8 *value);

#endif	/* KEYPAD_H */

