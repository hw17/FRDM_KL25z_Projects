/*************************************************
 * @filename : blinkenlights_utils.h
 * @author   : Dhiraj Bennadi
 * @compiler : GNU Arm
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

#ifndef BLINKENLIGHTS_UTILS_H_
#define BLINKENLIGHTS_UTILS_H_

 /*Standard Library Inclusion*/
#include <stdint.h>

/*Macro to Switch Between Debug and Release mode*/
/* To switch to release mode, comment the below line*/
#define DEBUG_BUILD 	    (1U)
#define DELAY_UNITS         (100U)
#define DELAY_UNITS_500MS   (5*DELAY_UNITS)

/*
 * Creates a delay specified the parameter msecs
 *
 * Parameters:
 *   duration of delay in msecs
 *
 * Returns: None.
 */
void delay(uint32_t msecs);


#endif /* BLINKENLIGHTS_UTILS_H_ */
