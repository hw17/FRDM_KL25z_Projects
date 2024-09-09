/*
 * Copyright 2016-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    MKL25Z4_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
#include <stdbool.h>
#include "fsl_uart.h"
#include "i2c.h"
/* TODO: insert other definitions and declarations here. */

#define SYSTEM_CLOCK_FREQ      48000000UL  // 48 Mhz
#define SYTICK_TIME_INTERVAL   1           // 1 msec
#define SYTICK_TIME_FREQ       (SYTICK_TIME_INTERVAL * 1000) // 1000 Khz
#define SYSTICK_TMR_RELOAD_VAL ((SYSTEM_CLOCK_FREQ / SYTICK_TIME_FREQ) - 1UL) // 48000 - 1

void config_uart(void){
	/** Uart2 CONFIG **/
	uart_config_t uart2_Config;
	uart2_Config.baudRate_Bps = 115200U;
	uart2_Config.parityMode = kUART_ParityDisabled;
	uart2_Config.stopBitCount = kUART_OneStopBit;
	uart2_Config.enableTx = true;
	uart2_Config.enableRx = true;

	UART_Init(UART2, &uart2_Config, BOARD_BOOTCLOCKRUN_CORE_CLOCK);
	// enables UART2 interrupts
	UART_EnableInterrupts(UART2, kUART_RxDataRegFullInterruptEnable);
	EnableIRQ(UART2_IRQn);
}

void config_spi(void){

}
void config_adc(void){

}
/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("Hello World\r\n");
    MCU_Init();
    Accelerometer_Init();
    Calibrate();
    /** Clock SYS Tick CONFIG **/
    //SysTick_Config(); //done in bootclocks

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
        RunMMA8451Q();
    }
    return 0 ;
}
