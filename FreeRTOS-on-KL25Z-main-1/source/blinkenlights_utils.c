/*************************************************
 * @filename : blinkenlights_utils.c
 * @author   : Dhiraj Bennadi
 * @compiler : GNU Arm
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

#include "blinkenlights_utils.h"

/*
 * Creates a delay specified the parameter msecs
 *
 * Parameters:
 *   duration of delay in msecs
 *
 * Returns: None.
 */
void delay(uint32_t msecs)
{
#ifdef DEBUG_BUILD
	uint32_t loop_counter = 0;

	loop_counter = msecs / 100;

	loop_counter *= 550000;
	while(loop_counter--)
	{
		;
	}
#else
	uint64_t loop_counter = 0;

	loop_counter = msecs / 100;

	loop_counter *= 550000;

	while(loop_counter--)
	{
		__asm("nop");
	}
#endif
}


