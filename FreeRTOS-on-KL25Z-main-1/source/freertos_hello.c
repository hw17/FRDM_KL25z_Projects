/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"

#include "semphr.h"

#include "led.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Task priorities. */
#define hello_task_PRIORITY (configMAX_PRIORITIES - 1)

#define DELAY_LOOP 65535
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
//static void hello_task(void *pvParameters);
//static void hello_task2(void *pvParameters);
SemaphoreHandle_t xSemaphoreMutex;
QueueHandle_t msgQueue1;

static void createSemaphore(void);

static void task1(void *pvParameters);
static void task2(void *pvParameters);

static void senderTask(void *pvParameters);
static void receiverTask(void *pvParameters);

typedef struct{
	TaskFunction_t pxTaskCode;
	const char * const pcName;
	const uint16_t usStackDepth;
	void * const pvParameters;
	UBaseType_t uxPriority;
	TaskHandle_t * const pxCreatedTask;
}tasks_t;

tasks_t Tasks_List[] = {
		{task1, "Task1", configMINIMAL_STACK_SIZE + 10, "Task 1 executing", hello_task_PRIORITY, NULL},
		{task2, "Task2", configMINIMAL_STACK_SIZE + 10, "Task 2 Executing", hello_task_PRIORITY, NULL},
		{senderTask, "senderTask", configMINIMAL_STACK_SIZE + 50, "senderTask executing", hello_task_PRIORITY, NULL},
		{receiverTask, "receiverTask", configMINIMAL_STACK_SIZE + 50, "receiverTask executing", hello_task_PRIORITY - 1, NULL},
};
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */
int main(void)
{
    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    LED_Init();

    createSemaphore();

    for(uint8_t i=0; i <4; i++){
    	xTaskCreate(Tasks_List[i].pxTaskCode,
    				Tasks_List[i].pcName,
					Tasks_List[i].usStackDepth,
					Tasks_List[i].pvParameters,
					Tasks_List[i].uxPriority,
					Tasks_List[i].pxCreatedTask);
    }

    vTaskStartScheduler();
    for (;;)
        ;
}

static void createSemaphore(void){
    xSemaphoreMutex = xSemaphoreCreateMutex();

    if(xSemaphoreMutex != NULL)
    {
    	PRINTF("Mutex was successfully created\n\r");
    }
    else
    {
    	PRINTF("Mutex creation failed\n\r");
    }

    msgQueue1 = xQueueCreate(5 , sizeof(int));

    if(msgQueue1 == NULL)
    {
    	PRINTF("Message queue created failed\n\r");
    }
}

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void task1(void *pvParameters)
{
	uint8_t *str = pvParameters;


    for (;;)
    {
    	if( xSemaphoreTake( xSemaphoreMutex, ( TickType_t ) 10000 ) == pdTRUE )
    	{
    		PRINTF("%s.\n\r", str);
    		ControlRedLed(1);
    		vTaskDelay(1000);
    		PRINTF("Task 1 Ended\n\r");
    		xSemaphoreGive(xSemaphoreMutex);
    		vTaskDelay(1000);
    	}
    	else
    	{
    		PRINTF("Mutex could not be acquired by Task 1\n\r");
    	}

    }
}

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void task2(void *pvParameters)
{
	uint8_t *str = pvParameters;

    for (;;)
    {
    	if( xSemaphoreTake( xSemaphoreMutex, ( TickType_t ) 10000 ) == pdTRUE )
    	{
    		PRINTF("%s.\n\r", str);
    		ControlGreenLed(1);
    		vTaskDelay(1000);
    		PRINTF("Task 2 Ended\n\r");
    		xSemaphoreGive(xSemaphoreMutex);
    		vTaskDelay(1000);
    	}
    	else
    	{
    		PRINTF("Mutex could not be acquired by Task 2\n\r");
    	}
    }
}

static void senderTask(void *pvParameters)
{
	static int value = 0;

	while(1)
	{
		if(xQueueSend( /* The handle of the queue. */
						msgQueue1,
		               /* The address of the xMessage variable.  sizeof( struct AMessage )
		               bytes are copied from here into the queue. */
		               ( void * ) &value,
		               /* Block time of 0 says don't block if the queue is already full.
		               Check the value returned by xQueueSend() to know if the message
		               was sent to the queue successfully. */
		               ( TickType_t ) 1000 ) == pdPASS)
		{
			PRINTF("Message Sent Sucessfully\n\r");
		}

		else{
			PRINTF("Message Sending Failed\n\r");
		}

		vTaskDelay(1000);
		value++;

		if(value == 100){
			value = 0;
		}
	}
}
static void receiverTask(void *pvParameters)
{
	int value = 0;

	vTaskDelay(100);
	while(1)
	{
	    if( xQueueReceive( msgQueue1,
	                       (void*)&( value),
	                       ( TickType_t ) 1000 ) == pdPASS )
	    {
	    	PRINTF("Message Received = %d\n\r", value);

	    }
	    else
	    {
	    	PRINTF("Failed to receive a message\n\r");
	    }

	    vTaskDelay(1000);
	}

}
