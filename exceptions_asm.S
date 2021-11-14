        .title "Exception handling routines"

        .extern Exception_Handler

        .macro DEF_VECTOR name, vect
        .type \name, @function
        .weak \name
        .globl \name
\name:
        /* If you modify what gets pushed here, be sure to update SP offsets
         * in exceptions_c.c! */
        ori.w   #0x0700, %sr            /* Mask out all interrupts */
        move.w  %sr, %sp@-              /* Push the EH status reg */
        move.w  #\vect, %sp@-           /* Push vector number to stack */
        move.l  %sp, %sp@-              /* Push current SP to stack */
        movem.l %d0-%fp, %sp@-          /* Push D0-A6(FP) to stack */

        /* Push the other two stack pointers */
        move.l  %usp, %a0               /* Push USP to stack */
        move.l  %a0, %sp@-
        ori.w   #0x1000, %sr            /* Push MSP to stack */
        move.l  %sp, %a0
        andi.w  #0xEFFF, %sr
        move.l  %a0, %sp@-

        jsr     Exception_Handler

        movem.l %sp@+, %d0-%fp          /* Restore regs from before handler */
        adda.l  #6, %sp                 /* Skip saved SP and vector num */

        rte
        .endm

        .section .text
        .align 2

DEF_VECTOR BusError, 0x08
DEF_VECTOR AddressError, 0x0C
DEF_VECTOR IllegalInstruction, 0x10
DEF_VECTOR ZeroDivide, 0x14
DEF_VECTOR CHKInstruction, 0x18
DEF_VECTOR TRAPVInstruction, 0x1C
DEF_VECTOR PrivilegeViolation, 0x20
DEF_VECTOR Trace, 0x24
DEF_VECTOR Line1010Emulator, 0x28
DEF_VECTOR Line1111Emulator, 0x2C
DEF_VECTOR HardwareBreakpoint, 0x30
DEF_VECTOR CoprocessorProtocolViolation, 0x34
DEF_VECTOR FormatError, 0x38
DEF_VECTOR UninitializedInterruptVector, 0x3C
/* 40-5C reserved */
DEF_VECTOR SpuriousInterrupt, 0x60
DEF_VECTOR IRQ1, 0x64
DEF_VECTOR IRQ2, 0x68
DEF_VECTOR IRQ3, 0x6C
DEF_VECTOR IRQ4, 0x70
DEF_VECTOR IRQ5, 0x74
DEF_VECTOR IRQ6, 0x78
DEF_VECTOR IRQ7, 0x7C
DEF_VECTOR TRAP0, 0x80
DEF_VECTOR TRAP1, 0x84
DEF_VECTOR TRAP2, 0x88
DEF_VECTOR TRAP3, 0x8C
DEF_VECTOR TRAP4, 0x90
DEF_VECTOR TRAP5, 0x94
DEF_VECTOR TRAP6, 0x98
DEF_VECTOR TRAP7, 0x9C
DEF_VECTOR TRAP8, 0xA0
DEF_VECTOR TRAP9, 0xA4
DEF_VECTOR TRAP10, 0xA8
DEF_VECTOR TRAP11, 0xAC
DEF_VECTOR TRAP12, 0xB0
DEF_VECTOR TRAP13, 0xB4
DEF_VECTOR TRAP14, 0xB8
DEF_VECTOR TRAP15, 0xBC

        .end
