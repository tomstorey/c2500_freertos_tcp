        .title "crt0.S for m68k bare metal - standalone"

/* Uncomment the following if you dont want the EVT to be automatically copied
 * to RAM address 0 when the ROM has been remapped away from address 0 */
/* #define NO_EVT_COPY */

#define USEVBR (defined(mc68010) || defined(mc68020) || defined(mc68030) || defined(mc68040) || defined(mc68060) || defined(mc68332))

        /* A bunch of variables supplied by the linker */
        .extern _stack_end
        .extern _rom_base
        .extern _bss_start
        .extern _bss_end
        .extern _text_end
        .extern _data_start
        .extern _data_end
        .weak hardware_init_hook
        .weak software_init_hook
        .weak JumpToZero
        .extern main

        .section .text
        .align 2

        .type _start, @function
        .globl _start
_start:
        move.l  #0, (0x03000000)        /* Clear debug display */
        move.w  #0x2700, %sr            /* Mask interrupts, supervisor mode */

        movea.l #_stack_end, %sp        /* Manually configure the ISP value,
                                         * this allows the SP value in the ROM
                                         * image to be used e.g. to store a
                                         * checksum instead. */
        clr.l   %d0                     /* Set MSP and USP to 0 */
        movea.l %d0, %a0
        move.l  %a0, %usp               /* USP first */
        ori.w   #0x1000, %sr            /* A little dance for MSP */
        move.l  %a0, %sp
        andi.w  #0xEFFF, %sr

        /* --- Begin Cisco specific startup code --- */
        /* Startup delay */
        move.l  #1000, %d0
0:      subq.l  #1, %d0
        bne     0b

        /* Clear BEV bit in SCR */
        andi.w  #0xFFFE, (0x02110000)

        /* Configure ROM and RAM sizes in MCR */
        move.w  #0x0E34, (0x02110002)   /* 8MByte RAM, 4Mbit ROMs */

        /* Enable access to peripherals */
        ori.w   #0x3F, (0x02110004)
        nop
        nop
        nop
        nop
        andi.w  #0xFFC0, (0x02110004)
        /* --- End Cisco specific startup code --- */

        /* Setup caches */
        /* move.w  #0x0808, %d0 */
        /* movec   %d0, %cacr */
        /* move.w  #0x2101, %d0 */
        /* movec   %d0, %cacr */

#if USEVBR
        /* If using a CPU with a VBR, point it to the beginning of ROM */
        movea.l #_rom_base, %a0
        movec   %a0, %vbr
#else /* USEVBR */
#ifndef NO_EVT_COPY
        /* For CPUs without a VBR, if ROM/RAM remapping is being used, copy the
         * exception vector table to RAM. This is determined by the base addr
         * of the ROM being non-zero. */
        move.l  #_rom_base, %d0         /* Skip EVT copy if ROM is at addr 0 */
        beq     1f

        move.w  #511, %d0               /* Number of words to copy, less 1 for
                                         * dbf loop */
        movea.l #_rom_base, %a0         /* Source address */
        movea.l #0, %a1                 /* Destination address */

0:      move.w  %a0@+, %a1@+
        dbf     %d0, 0b
#endif /* NO_EVT_COPY */
#endif /* USEVBR */

        /* Initialise (clear) the BSS area */
1:      movea.l #_bss_start, %a0        /* Starting address */
        movea.l #_bss_end, %a1          /* End address */

2:      cmpa.l  %a1, %a0                /* Check if start < end */
        bge     3f

        clr.w   %a0@+                   /* Clear word and increment start */

        bra     2b

        /* Copy initialised data from ROM to RAM */
3:      movea.l #_text_end, %a0         /* Source address */
        movea.l #_data_start, %a1       /* Destination start address */
        movea.l #_data_end, %a2         /* Destination end address */

4:      cmpa.l  %a2, %a1                /* Check if start < end */
        bge     5f

        move.w  %a0@+, %a1@+            /* Copy a word from ROM to RAM */

        bra     4b

        /* Execute hardware init hook if present */
5:      move.l  #hardware_init_hook, %d0
        beq     6f
        movea.l %d0, %a0
        jsr     (%a0)

        /* Execute software init hook if present */
6:      move.l  #software_init_hook, %d0
        beq     7f
        movea.l %d0, %a0
        jsr     (%a0)

7:      /* Install a "jump to zero" handler at address 0 */
        move.w  #0x4EB9, (0)
        move.l  #JumpToZero, (2)

        /* Jump to main() */
        jmp     main

        /* In a bare metal environment, main() should not return as there is
         * nowhere to resume execution from. Behaviour is undefined if this
         * happens! */


/*
 * __DefaultInterrupt handles all interrupt and exception vectors that have not
 * been overridden by the programmer.
 *
 * Unless handled more specifically, all exceptions and interrupts are masked
 * and the CPU stops executing.
 */
        .type __DefaultInterrupt, @function
        .weak __DefaultInterrupt
        .globl __DefaultInterrupt
__DefaultInterrupt:
        move.l  #0x00FF00FF, (0x03000000)
        stop    #0x2700
        bra     .

        .end
