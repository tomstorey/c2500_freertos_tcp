#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "C2500.h"
#include "HD64570.h"
#include "SCN2681.h"
#include "LANCE.h"
#include "FreeRTOS-Kernel/include/FreeRTOS.h"
#include "FreeRTOS-Kernel/include/task.h"
#include "FreeRTOS-Kernel/include/stream_buffer.h"
#include "FreeRTOS-Plus-TCP/include/FreeRTOS_IP.h"
#include "FreeRTOS-Plus-TCP/portable/NetworkInterface/C2500/NetworkInterface.h"

static TaskHandle_t task_handle1 = NULL;
static TaskHandle_t task_handle2 = NULL;
static TaskHandle_t task_handle3 = NULL;
static TaskHandle_t task_handle4 = NULL;
static TaskHandle_t task_handle5 = NULL;
static TaskHandle_t task_handle6 = NULL;
static TaskHandle_t task_handle7 = NULL;
static TaskHandle_t task_handle8 = NULL;
static TaskHandle_t task_handle9 = NULL;
static TaskHandle_t task_handle10 = NULL;

static void task1(void *param);
static void task2(void *param);
static void task3(void *param);
static void task4(void *param);
static void task5(void *param);
static void task6(void *param);
static void task7(void *param);
static void task8(void *param);
static void task9(void *param);
static void task10(void *param);

// void __attribute__((interrupt))
// IRQ4(void)
void
IRQ4_Handler(void)
{
    /*
     * ISR for IRQ4 - HD64570 timers and LANCE ethernet controller
     */ 
    __INTSRCbits_t intsrc;
    __ISR2bits_t isr2;
    intsrc.u16 = INTSRC;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (intsrc.ETH) {
        xHigherPriorityTaskWoken = LANCE_Interrupt_Handler();
    }

    if (intsrc.SER) {
        isr2.u8 = ISR2;

        if (isr2.T0IRQ) {
            /* Clear interrupt from HD64570 timer channel */
            (void)TCSR0;
            (void)TCNT0;

            /* Tick */
            // asm volatile("trap #14");
            if (xTaskIncrementTick() != pdFALSE) {
                xHigherPriorityTaskWoken = pdTRUE;
            }
        }
    }

    if (xHigherPriorityTaskWoken) {
        /* Make way for a higher priority task that has been woken */
        vTaskSwitchContext();
    }
}

void
vApplicationSetupInterrupts( void )
{
    /* The system clock (10MHz) is divided by 8 to derive the timer
     * base clock (BC) of 1.25MHz. */
    TCONR0 = (1250000 / configTICK_RATE_HZ);
    IER2bits.T0IRQE = 1;
    TCSR0bits.ECMI = 1;
    TCSR0bits.TME = 1;

    portENABLE_INTERRUPTS();
}

void
init_uart(void)
{
    CRA = 0x10;                     /* Reset command pointer */
    MR1A = 0x13;                    /* No parity, 8 bits per char */
    MR2A = 0x7;                     /* 1 stop bit */
    ACR = 0xE0;                     /* BRG set 2, external clock */
    CSRA = 0xDD;                    /* Timer for baud generation */
    CTUR = 0;                       /* Timer value = 0x0002 */
    CTLR = 0x2;
    (void)STARTCTR;                 /* Start timer */
    CRA = 0x5;                      /* Enable transmitter and receiver */
    (void)ISR;
    IMR = 0x2;
}

int
main(void)
{
    init_uart();

    static const uint8_t ucIPAddress[4] = {0xAB, 0xCD, 0xEF, 200};
    static const uint8_t ucNetMask[4] = {255, 255, 255, 0};
    static const uint8_t ucGatewayAddress[4] = {0xAB, 0xCD, 0xEF, 1};

    static const uint8_t ucDNSServerAddress[4] = {8, 8, 8, 8};

    static const uint8_t ucMACAddress[6] = {0x00, 0xD0, 0x58, 0xAD, 0x1F, 0xBA};

    /* Create a task */
    xTaskCreate(task1, "Task 1", 1024, NULL, 3, &task_handle1);
    xTaskCreate(task2, "Task 2", 1024, NULL, 3, &task_handle2);
    xTaskCreate(task3, "Task 3", 1024, NULL, 2, &task_handle3);
    xTaskCreate(task4, "Task 4", 1024, NULL, 1, &task_handle4);
    xTaskCreate(task5, "Task 5", 1024, NULL, 3, &task_handle5);
    xTaskCreate(task6, "Task 6", 1024, NULL, 2, &task_handle6);
    xTaskCreate(task7, "Task 7", 1024, NULL, 1, &task_handle7);
    xTaskCreate(task8, "Task 8", 1024, NULL, 3, &task_handle8);
    xTaskCreate(task9, "Task 9", 1024, NULL, 2, &task_handle9);
    xTaskCreate(task10, "Task 10", 1024, NULL, 1, &task_handle10);

    if (FreeRTOS_IPInit(ucIPAddress, ucNetMask, ucGatewayAddress,
                        ucDNSServerAddress, ucMACAddress) != pdTRUE) {
        /* IP stack init failed */
        while (true);
    }

    printf("vTaskStartScheduler() \r\n");

    vTaskStartScheduler();

    printf("Scheduler exited\r\n");

    while (true);

    return 0;
}


void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                        char * pcTaskName )
{
    printf("Stack overflow: %s", pcTaskName);
    abort();
}










static void
task1(void *param)
{
    while (true) {
        SYSCONbits.LED ^= 1;

        vTaskDelay(50);
    }
}

static void
task2(void *param)
{
    while (true) {
        SYSCONbits.LED ^= 1;

        vTaskDelay(49);
    }
}

static void
task3(void *param)
{
    while (true) {
        SYSCONbits.LED ^= 1;

        vTaskDelay(48);
    }
}

static void
task4(void *param)
{
    while (true) {
        SYSCONbits.LED ^= 1;

        vTaskDelay(47);
    }
}

static void
task5(void *param)
{
    while (true) {
        SYSCONbits.LED ^= 1;

        vTaskDelay(46);
    }
}

static void
task6(void *param)
{
    while (true) {
        SYSCONbits.LED ^= 1;

        vTaskDelay(45);
    }
}

static void
task7(void *param)
{
    while (true) {
        SYSCONbits.LED ^= 1;

        vTaskDelay(44);
    }
}

static void
task8(void *param)
{
    while (true) {
        SYSCONbits.LED ^= 1;

        vTaskDelay(43);
    }
}

static void
task9(void *param)
{
    while (true) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        SYSCONbits.LED ^= 1;
    }
}

static void
task10(void *param)
{
    while (true) {
        SYSCONbits.LED ^= 1;
        xTaskNotifyGive(task_handle9);

        vTaskDelay(41);
    }
}



BaseType_t
xApplicationGetRandomNumber( uint32_t * pulNumber )
{
    /* TODO: This definitely needs to be more random */
    static uint32_t rand = 0;

    *pulNumber = rand++;

    return pdTRUE;
}

/* Borrowed from MSP432 port */
uint32_t ulApplicationGetNextSequenceNumber( uint32_t ulSourceAddress,
                                             uint16_t usSourcePort,
                                             uint32_t ulDestinationAddress,
                                             uint16_t usDestinationPort )
{
    uint32_t pulNumber = 0;

    xApplicationGetRandomNumber( &pulNumber );

    return pulNumber;
}





void _putchar(char ch)
{
	while (SRAbits.TXEMT == 0);

    HRA = ch;
}





void
JumpToZero(void)
{
    printf("Jump to zero\r\n");
}
