#ifndef FREERTOS_IP_CONFIG_H
#define	FREERTOS_IP_CONFIG_H

/* FreeRTOSIPConfig.h for use with Am79C90 (LANCE) */

#define ipconfigNETWORK_MTU 1514

#define ipconfigUSE_DHCP 0

/* The LANCE chip supports the following buffer counts:
 *
 * 1, 2, 4, 8, 16, 32, 64, 128
 * 
 * for both TX and RX rings. Due to FreeRTOS only having a single pool of
 * buffers that is shared between both TX and RX packets, the number of buffers
 * that will be allocated to the RX ring during initialisation will be one half
 * of the number of buffers specified here.
 * 
 * Therefore, specify an EVEN number of buffers! */
#define ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS 32

#define ipconfigEVENT_QUEUE_LENGTH (ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS * 2)

/* IP task priority is maximum */
#define ipconfigIP_TASK_PRIORITY (configMAX_PRIORITIES - 1)

#define ipconfigIP_TASK_STACK_SIZE_WORDS 1024

/* M68k is big endian */
#define ipconfigBYTE_ORDER pdFREERTOS_BIG_ENDIAN

/* LANCE takes care of checksumming */
#define ipconfigDRIVER_INCLUDED_TX_IP_CHECKSUM 1
#define ipconfigDRIVER_INCLUDED_RX_IP_CHECKSUM 1

/* Use no-copy method of buffer management */
#define ipconfigZERO_COPY_TX_DRIVER 1
#define ipconfigZERO_COPY_RX_DRIVER 1

#endif	/* FREERTOS_IP_CONFIG_H */
