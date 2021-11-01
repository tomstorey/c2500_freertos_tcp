#ifndef LANCE_H
#define LANCE_H

#ifndef __ASSEMBLER__
#include <stdint.h>


#define LANCE_RDP (*(volatile uint16_t *)(0x02130000))

#define LANCE_RAP (*(volatile uint16_t *)(0x02130002))
typedef union {
    struct {
        uint16_t :14;
        uint16_t CSR1:1;
        uint16_t CSR0:1;
    };
    struct {
        uint16_t :14;
        uint16_t CSR:2;
    };
    struct {
        uint16_t u16;
    };
} __LANCE_RAPbits_t;
#define LANCE_RAPbits (*(volatile __LANCE_RAPbits_t *)(0x02130002))

#define LANCE_CSR0 (*(volatile uint16_t *)(0x02130000))
typedef union {
    struct {
        uint16_t ERR:1;
        uint16_t BABL:1;
        uint16_t CERR:1;
        uint16_t MISS:1;
        uint16_t MERR:1;
        uint16_t RINT:1;
        uint16_t TINT:1;
        uint16_t IDON:1;
        uint16_t INTR:1;
        uint16_t INEA:1;
        uint16_t RXON:1;
        uint16_t TXON:1;
        uint16_t TDMD:1;
        uint16_t STOP:1;
        uint16_t STRT:1;
        uint16_t INIT:1;
    };
    struct {
        uint16_t u16;
    };
} __LANCE_CSR0bits_t;
#define LANCE_CSR0bits (*(volatile __LANCE_CSR0bits_t *)(0x02130000))

#define LANCE_CSR1 (*(volatile uint16_t *)(0x02130000))
typedef union {
    struct {
        uint16_t IADR15:1;
        uint16_t IADR14:1;
        uint16_t IADR13:1;
        uint16_t IADR12:1;
        uint16_t IADR11:1;
        uint16_t IADR10:1;
        uint16_t IADR9:1;
        uint16_t IADR8:1;
        uint16_t IADR7:1;
        uint16_t IADR6:1;
        uint16_t IADR5:1;
        uint16_t IADR4:1;
        uint16_t IADR3:1;
        uint16_t IADR2:1;
        uint16_t IADR1:1;
        uint16_t :1;
    };
    struct {
        uint16_t IADR:15;
        uint16_t :1;
    };
    struct {
        uint16_t u16;
    };
} __LANCE_CSR1bits_t;
#define LANCE_CSR1bits (*(volatile __LANCE_CSR1bits_t *)(0x02130000))

#define LANCE_CSR2 (*(volatile uint16_t *)(0x02130000))
typedef union {
    struct {
        uint16_t :8;
        uint16_t IADR23:1;
        uint16_t IADR22:1;
        uint16_t IADR21:1;
        uint16_t IADR20:1;
        uint16_t IADR19:1;
        uint16_t IADR18:1;
        uint16_t IADR17:1;
        uint16_t IADR16:1;
    };
    struct {
        uint16_t :8;
        uint16_t IADR:8;
    };
    struct {
        uint16_t u16;
    };
} __LANCE_CSR2bits_t;
#define LANCE_CSR2bits (*(volatile __LANCE_CSR2bits_t *)(0x02130000))

#define LANCE_CSR3 (*(volatile uint16_t *)(0x02130000))
typedef union {
    struct {
        uint16_t :13;
        uint16_t BSWP:1;
        uint16_t ACON:1;
        uint16_t BCON:1;
    };
    struct {
        uint16_t u16;
    };
} __LANCE_CSR3bits_t;
#define LANCE_CSR3bits (*(volatile __LANCE_CSR3bits_t *)(0x02130000))

#endif /* __ASSEMBLER__ */

#endif /* LANCE_H */
