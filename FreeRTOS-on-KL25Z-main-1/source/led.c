/*************************************************
 * @filename : led.c
 * @author   : Dhiraj Bennadi
 * @compiler : GNU Arm
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

#include "MKL25Z4.h"
#include "led.h"
#include "blinkenlights_utils.h"
#include <stdbool.h>

#include "fsl_debug_console.h"

/*
 * Initializes the RGB LEDS
 *
 * Parameters:
 *   None
 *
 * Returns: None.
 */
void LED_Init(void)
{
	/*Enable Clock Gating To Port B and Port D*/
    SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
    SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

    PORTB->PCR[RED_LED] &= ~PORT_PCR_MUX_MASK;
    PORTB->PCR[RED_LED] |= PORT_PCR_MUX(1);

    PORTB->PCR[GREEN_LED] &= ~PORT_PCR_MUX_MASK;
    PORTB->PCR[GREEN_LED] |= PORT_PCR_MUX(1);

    PORTD->PCR[BLUE_LED] &= ~PORT_PCR_MUX_MASK;
    PORTD->PCR[BLUE_LED] |= PORT_PCR_MUX(1);

    /*Testing*/
    GPIOB->PDDR |= (1 << RED_LED);
    GPIOB->PDDR |= (1 << GREEN_LED);
    GPIOD->PDDR |= (1 << BLUE_LED);

    GPIOB->PSOR |= (1 << RED_LED);
    GPIOB->PSOR |= (1 << GREEN_LED);
    GPIOD->PSOR |= (1 << BLUE_LED);
}



void ControlRedLed(bool status)
{
	if(status){
		//Red ON
		GPIOB->PCOR |= (1 << RED_LED);
		GPIOB->PSOR |= (1 << GREEN_LED);
	}
	else{
		//Red OFF
		GPIOB->PSOR |= (1 << RED_LED);
	}

}

void ControlGreenLed(bool status)
{
	if(status){
		//Green ON
		GPIOB->PCOR |= (1 << GREEN_LED);
		GPIOB->PSOR |= (1 << RED_LED);
	}
	else{
		//Green OFF
		GPIOB->PSOR |= (1 << GREEN_LED);
	}
}
