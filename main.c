#include <stdint.h>
#include <stdbool.h>
#include "C2500.h"
#include "HD64570.h"
#include "SCN2681.h"
#include "FreeRTOS-Kernel/include/FreeRTOS.h"
#include "FreeRTOS-Kernel/include/task.h"
#include "FreeRTOS-Kernel/include/stream_buffer.h"
#include "FreeRTOS-Plus-TCP/include/FreeRTOS_IP.h"
#include "FreeRTOS-Plus-TCP/portable/NetworkInterface/C2500/C2500_LANCE.h"

static TaskHandle_t task_handle = NULL;

static void task(void *param);

void __attribute__((interrupt))
IRQ4(void)
{
    /*
     * ISR for IRQ4 - HD64570 timers and LANCE ethernet controller
     */ 
    __INTSRCbits_t intsrc;
    __ISR2bits_t isr2;
    intsrc.u16 = INTSRC;

    if (intsrc.ETH) {
        LANCE_Interrupt_Handler();
    }

    if (intsrc.SER) {
        isr2.u8 = ISR2;

        if (isr2.T0IRQ == 1) {
            /* Clear interrupt from HD64570 timer channel */
            (void)TCSR0;
            (void)TCNT0;

            /* Tick */
            asm volatile("trap #14");
        }
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

int
main(void)
{
    static const uint8_t ucIPAddress[4] = {0xAB, 0xCD, 0xEF, 200};
    static const uint8_t ucNetMask[4] = {255, 255, 255, 0};
    static const uint8_t ucGatewayAddress[4] = {0xAB, 0xCD, 0xEF, 1};

    static const uint8_t ucDNSServerAddress[4] = {8, 8, 8, 8};

    static const uint8_t ucMACAddress[6] = {0x00, 0xD0, 0x58, 0xAD, 0x1F, 0xBA};

    /* Create a task */
    xTaskCreate(task, "Task", 1024, NULL, 3, &task_handle);

    if (FreeRTOS_IPInit(ucIPAddress, ucNetMask, ucGatewayAddress,
                        ucDNSServerAddress, ucMACAddress) != pdTRUE) {
        /* IP stack init failed */
        while (true);
    }

    vTaskStartScheduler();

    return 0;
}

static void
task(void *param)
{
    static uint32_t count = 0;
    static uint8_t ff = 0;

    while (true) {
        /* Blink the OK LED at 1hz */
        SYSCONbits.LED ^= 1;

        // if (ff) {
        //     *(uint32_t *)0x03000000 = count++;
        // }

        ff ^= 1;

        vTaskDelay(50);
    }
}

BaseType_t
xApplicationGetRandomNumber( uint32_t * pulNumber )
{
    /* TODO: This needs to be more random */
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
