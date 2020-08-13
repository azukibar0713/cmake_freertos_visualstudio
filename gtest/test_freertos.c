#include "test_freertos.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "LedDriver.h"
/* Used as a loop counter to create a very crude delay. */
#define mainDELAY_LOOP_COUNT		( 0xffffff )

/* The task functions. */
void vTaskSample(void* pvParameters);

void drive_freertos(void)
{
    uint16_t adrs = 0;
    LedDriver_Create(&adrs);

    /* Create one of the two tasks. */
    xTaskCreate(vTaskSample,		/* Pointer to the function that implements the task. */
        "Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
        1000,		/* Stack depth - most small microcontrollers will use much less stack than this. */
        NULL,		/* We are not using the task parameter. */
        1,			/* This task will run at priority 1. */
        NULL);		/* We are not using the task handle. */


    /* Start the scheduler to start the tasks executing. */
    vTaskStartScheduler();

    /* The following line should never be reached because vTaskStartScheduler()
    will only return if there was not enough FreeRTOS heap memory available to
    create the Idle and (if configured) Timer tasks.  Heap management, and
    techniques for trapping heap exhaustion, are described in the book text. */
    for (;; );
    //return 0;
}
/*-----------------------------------------------------------*/

void vTaskSample(void* pvParameters)
{
    const char* pcTaskName = "Task 1 is running\r\n";
    volatile uint32_t ul;

    /* As per most tasks, this task is implemented in an infinite loop. */
    for (;; )
    {
        /* Print out the name of this task. */
        printf(pcTaskName);

        /* Delay for a period. */
        for (ul = 0; ul < mainDELAY_LOOP_COUNT; ul++)
        {
            /* This loop is just a very crude delay implementation.  There is
            nothing to do in here.  Later exercises will replace this crude
            loop with a proper delay/sleep function. */
        }
    }
}
