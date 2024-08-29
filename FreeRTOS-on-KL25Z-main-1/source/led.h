/*************************************************
 * @filename : led.h
 * @author   : Dhiraj Bennadi
 * @compiler : GNU Arm
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

#ifndef LED_H_
#define LED_H_

 /*Standard Library Inclusion*/
#include <stdbool.h>

#define LED_ON 		(1U)
#define LED_OFF 	(0U)

#define RED_LED     (18U)
#define GREEN_LED   (19U)
#define BLUE_LED    (1U)

/*
 * Initializes the RGB LEDS
 *
 * Parameters:
 *   None
 *
 * Returns: None.
 */
void LED_Init(void);

void ControlRedLed(bool status);
void ControlGreenLed(bool status);

#endif /* LED_H_ */
