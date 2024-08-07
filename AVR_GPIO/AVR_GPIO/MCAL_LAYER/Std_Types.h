/* 
 * File:   Std_Types.h
 * Author: Mohamed Tarek
 *
 * Created on August 7, 2024, 3:37 AM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H
/*******************Include Section*****************/
#include "Std_libraries.h"

/*******************Micro Functions Declarations*******/

/*******************Data Type Declaration***************/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;


typedef enum{
    E_NOT_OK,
            E_OK
}status_t;

/*******************Micro Declarations***************/


#define Std_ReturnType uint8
#endif	/* STD_TYPES_H */

