#ifndef FREERTOS_IP_CONFIG_H
#define	FREERTOS_IP_CONFIG_H

/* FreeRTOSIPConfig.h for use with Am79C90 (LANCE) */

#define ipconfigNETWORK_MTU 1514

#define ipconfigUSE_DHCP 0

/* The LANCE does not automatically pad packets out to the required minimum of
 * 64 bytes, therefore, ask FreeRTOS+TCP to ensure this requirement is met.
 * The value specified below excludes the 4 byte CRC. */
#define ipconfigETHERNET_MINIMUM_PACKET_BYTES 60

/* The LANCE supports the following buffer counts:
 *
 * 1, 2, 4, 8, 16, 32, 64, 128
 * 
 * for both TX and RX rings. FreeRTOS manages only a single pool of buffers
 * which can be allocated to both TX and RX descriptors as required.
 *
 * LANCE_TX_RING_SZ specifies the number of descriptors that will be allocated
 * for the TX ring, and LANCE_RX_RING_SZ is the number of descriptors for the
 * RX ring. LANCE_BUFFERS_EXTRA is a number of additional buffers that will be
 * allocated to provide some wiggle room to allocate buffers for packets to be
 * transmitted and while waiting for RX packets to be processed and their
 * buffers freed up. */
#define LANCE_RX_RING_SZ 32
#define LANCE_TX_RING_SZ 32
#define LANCE_BUFFERS_EXTRA 16

#define ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS (LANCE_RX_RING_SZ + LANCE_TX_RING_SZ + LANCE_BUFFERS_EXTRA)
#define ipconfigEVENT_QUEUE_LENGTH (ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS + 32)

/* IP task properties */
#define ipconfigIP_TASK_PRIORITY (configMAX_PRIORITIES - 1)
#define ipconfigIP_TASK_STACK_SIZE_WORDS 1024

/* M68k is big endian */
#define ipconfigBYTE_ORDER pdFREERTOS_BIG_ENDIAN

/* The LANCE takes care of checksumming the ethernet frame, but IP checksums
 * need to be calculated in software */
#define ipconfigDRIVER_INCLUDED_TX_IP_CHECKSUM 0
#define ipconfigDRIVER_INCLUDED_RX_IP_CHECKSUM 0

/* Use no-copy method of buffer management */
#define ipconfigZERO_COPY_TX_DRIVER 1
#define ipconfigZERO_COPY_RX_DRIVER 1

#endif	/* FREERTOS_IP_CONFIG_H */
