#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>


void hex_dump(const void *start, uint32_t len, uint8_t size);


typedef struct {
    uint32_t msp;
    uint32_t usp;
    uint32_t d0;
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;
    uint32_t d4;
    uint32_t d5;
    uint32_t d6;
    uint32_t d7;
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t fp;
    uint32_t sp;
    uint16_t vect;
    uint16_t eh_sr;
    uint16_t sr;
    uint32_t pc;
    uint16_t format:4;
    uint16_t offset:12;
} frame_format_0_t;

typedef struct {
    uint32_t msp;
    uint32_t usp;
    uint32_t d0;
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;
    uint32_t d4;
    uint32_t d5;
    uint32_t d6;
    uint32_t d7;
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t fp;
    uint32_t sp;
    uint16_t vect;
    uint16_t eh_sr;
    uint16_t sr;
    uint32_t pc;
    uint16_t format:4;
    uint16_t offset:12;
} frame_format_1_t;

typedef struct {
    uint32_t msp;
    uint32_t usp;
    uint32_t d0;
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;
    uint32_t d4;
    uint32_t d5;
    uint32_t d6;
    uint32_t d7;
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t fp;
    uint32_t sp;
    uint16_t vect;
    uint16_t eh_sr;
    uint16_t sr;
    uint32_t pc;
    uint16_t format:4;
    uint16_t offset:12;
} frame_format_2_t;

typedef struct {
    uint32_t msp;
    uint32_t usp;
    uint32_t d0;
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;
    uint32_t d4;
    uint32_t d5;
    uint32_t d6;
    uint32_t d7;
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t fp;
    uint32_t sp;
    uint16_t vect;
    uint16_t eh_sr;
    uint16_t sr;
    uint32_t pc;
    uint16_t format:4;
    uint16_t offset:12;
} frame_format_9_t;

typedef struct {
    uint32_t msp;
    uint32_t usp;
    uint32_t d0;
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;
    uint32_t d4;
    uint32_t d5;
    uint32_t d6;
    uint32_t d7;
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t fp;
    uint32_t sp;
    uint16_t vect;
    uint16_t eh_sr;
    uint16_t sr;
    uint32_t pc;
    uint16_t format:4;
    uint16_t offset:12;
    uint16_t :16;
    union {
        struct {
            uint16_t FC:1;
            uint16_t FB:1;
            uint16_t RC:1;
            uint16_t RB:1;
            uint16_t :3;
            uint16_t DF:1;
            uint16_t RM:1;
            uint16_t RW:1;
            uint16_t SIZE1:1;
            uint16_t SIZE0:1;
            uint16_t :1;
            uint16_t FC2:1;
            uint16_t FC1:1;
            uint16_t FC0:1;
        };
        struct {
            uint16_t :10;
            uint16_t SIZE:2;
            uint16_t :1;
            uint16_t FUNC:3;
        };
        uint16_t u16;
    } ssw;
    uint16_t inst_c;
    uint16_t inst_b;
    uint32_t fault_addr;
    uint16_t :16;
    uint16_t :16;
    uint32_t data_out_buf;
    uint16_t :16;
    uint16_t :16;
} frame_format_A_t;

typedef struct {
    uint32_t msp;
    uint32_t usp;
    uint32_t d0;
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;
    uint32_t d4;
    uint32_t d5;
    uint32_t d6;
    uint32_t d7;
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t fp;
    uint32_t sp;
    uint16_t vect;
    uint16_t eh_sr;
    uint16_t sr;
    uint32_t pc;
    uint16_t format:4;
    uint16_t offset:12;
    uint16_t :16;
    union {
        struct {
            uint16_t FC:1;
            uint16_t FB:1;
            uint16_t RC:1;
            uint16_t RB:1;
            uint16_t :3;
            uint16_t DF:1;
            uint16_t RM:1;
            uint16_t RW:1;
            uint16_t SIZE1:1;
            uint16_t SIZE0:1;
            uint16_t :1;
            uint16_t FC2:1;
            uint16_t FC1:1;
            uint16_t FC0:1;
        };
        struct {
            uint16_t :10;
            uint16_t SIZE:2;
            uint16_t :1;
            uint16_t FUNC:3;
        };
        uint16_t u16;
    } ssw;
    uint16_t inst_c;
    uint16_t inst_b;
    uint32_t fault_addr;
    uint16_t :16;
    uint16_t :16;
    uint32_t data_out_buf;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint32_t stage_b_addr;
    uint16_t :16;
    uint16_t :16;
    uint32_t data_in_buf;
} frame_format_B_t;


void __attribute__((optimize("no-omit-frame-pointer")))
Exception_Handler(void)
{
    uint32_t *fp;
    uint32_t *sp;
    uint8_t *active_sp = NULL;
    frame_format_0_t *f0;
    // frame_format_1_t *f1;
    // frame_format_2_t *f2;
    // frame_format_9_t *f9;
    frame_format_A_t *fA;
    frame_format_B_t *fB;

    /* Get the frame pointer, used to setup pointers for stack frames. Add 2
     * to exclude the previous frame address and return address that were
     * pushed to get into this routine. */
    fp = __builtin_frame_address(0);
    fp += 2;
    sp = fp;

    /* Assign pointers for all of the different stack frame types */
    f0 = (frame_format_0_t *)fp;
    // f1 = (frame_format_1_t *)fp;
    // f2 = (frame_format_2_t *)fp;
    // f9 = (frame_format_9_t *)fp;
    fA = (frame_format_A_t *)fp;
    fB = (frame_format_B_t *)fp;

    /* Adjust the stack pointer according to the type of frame on stack to get
     * back to where it was during normal program execution.
     *
     * The offset comprises the following context information (words):
     *
     *   2 + 2 + 30 + 2 + 1 + 1 = 38
     *
     * (MSP, USP, D0-FP, ISP, vector number, SR)
     *
     * Then add in number of words as required for the stack frame type itself.
     */
    if (f0->format == 0) {
        sp = (uint32_t *)((uint16_t *)sp + 38 + 4);
    } else if (f0->format == 1) {
        sp = (uint32_t *)((uint16_t *)sp + 38 + 4);
    } else if (f0->format == 2) {
        sp = (uint32_t *)((uint16_t *)sp + 38 + 6);
    } else if (f0->format == 9) {
        sp = (uint32_t *)((uint16_t *)sp + 38 + 10);
    } else if (f0->format == 0xA) {
        sp = (uint32_t *)((uint16_t *)sp + 38 + 16);
    } else if (f0->format == 0xB) {
        sp = (uint32_t *)((uint16_t *)sp + 38 + 46);
    } else {
        /* TODO: some kind of format error? */
    }

    /* Print the exception type that has occurred */
    printf("\r\n********************************************************************************\r\n");

    switch (f0->vect) {
        case 0x08:
            printf("Bus Error   (08)\r\n");
            break;
        case 0x0C:
            printf("Address Error   (0C)\r\n");
            break;
        case 0x10:
            printf("Illegal Instruction   (10)\r\n");
            break;
        case 0x14:
            printf("Zero Divide   (14)\r\n");
            break;
        case 0x18:
            printf("CHK Instruction   (18)\r\n");
            break;
        case 0x1C:
            printf("TRAPV Instruction   (1C)\r\n");
            break;
        case 0x20:
            printf("Privilege Violation   (20)\r\n");
            break;
        case 0x24:
            printf("Trace   (24)\r\n");
            break;
        case 0x28:
            printf("Line 1010 Emulator   (28)\r\n");
            break;
        case 0x2C:
            printf("Line 1111 Emulator   (2C)\r\n");
            break;
        case 0x30:
            printf("Hardware Breakpoint   (30)\r\n");
            break;
        case 0x34:
            printf("Coprocessor Protocol Violation   (34)\r\n");
            break;
        case 0x38:
            printf("Format Error   (38)\r\n");
            break;
        case 0x3C:
            printf("Uninitialized Interrupt Vector   (3C)\r\n");
            break;
        case 0x60:
            printf("Spurious Interrupt   (60)\r\n");
            break;
        case 0x64:
            printf("IRQ1   (64)\r\n");
            break;
        case 0x68:
            printf("IRQ2   (68)\r\n");
            break;
        case 0x6C:
            printf("IRQ3   (6C)\r\n");
            break;
        case 0x70:
            printf("IRQ4   (70)\r\n");
            break;
        case 0x74:
            printf("IRQ5   (74)\r\n");
            break;
        case 0x78:
            printf("IRQ6   (78)\r\n");
            break;
        case 0x7C:
            printf("IRQ7   (7C)\r\n");
            break;
        case 0x80:
            printf("Trap #0   (80)\r\n");
            break;
        case 0x84:
            printf("Trap #1   (84)\r\n");
            break;
        case 0x88:
            printf("Trap #2   (88)\r\n");
            break;
        case 0x8C:
            printf("Trap #3   (8C)\r\n");
            break;
        case 0x90:
            printf("Trap #4   (90)\r\n");
            break;
        case 0x94:
            printf("Trap #5   (94)\r\n");
            break;
        case 0x98:
            printf("Trap #6   (98)\r\n");
            break;
        case 0x9C:
            printf("Trap #7   (9C)\r\n");
            break;
        case 0xA0:
            printf("Trap #8   (A0)\r\n");
            break;
        case 0xA4:
            printf("Trap #9   (A4)\r\n");
            break;
        case 0xA8:
            printf("Trap #0   (A8)\r\n");
            break;
        case 0xAC:
            printf("Trap #1   (AC)\r\n");
            break;
        case 0xB0:
            printf("Trap #2   (B0)\r\n");
            break;
        case 0xB4:
            printf("Trap #3   (B4)\r\n");
            break;
        case 0xB8:
            printf("Trap #4   (B8)\r\n");
            break;
        case 0xBC:
            printf("Trap #5   (BC)\r\n");
            break;
        default:
            printf("Unknown vector: %04X\r\n", f0->vect);
    }

    /* Dump registers */
    printf(
        "\r\n"
        "D0 0x%08X   D4 0x%08X   A0 0x%08X   A4 0x%08X   SR 0x%04X (EH 0x%04X)\r\n"
        "D1 0x%08X   D5 0x%08X   A1 0x%08X   A5 0x%08X   PC 0x%08X\r\n"
        "D2 0x%08X   D6 0x%08X   A2 0x%08X   FP 0x%08X  USP 0x%08X\r\n"
        "D3 0x%08X   D7 0x%08X   A3 0x%08X  ISP 0x%08X  MSP 0x%08X\r\n"
        "\r\n"
        "Frame format %1X\r\n",
        f0->d0, f0->d4, f0->a0, f0->a4, f0->sr, f0->eh_sr,
        f0->d1, f0->d5, f0->a1, f0->a5, f0->pc,
        f0->d2, f0->d6, f0->a2, f0->fp, f0->usp,
        f0->d3, f0->d7, f0->a3, (uint32_t)sp, f0->msp,
        f0->format
    );

    if ((f0->sr & 0x2000) == 0) {
        active_sp = (uint8_t *)f0->usp;

        printf("USP was active stack pointer\r\n");
    } else if ((f0->sr & 0x3000) == 0x2000) {
        active_sp = (uint8_t *)sp;
        
        printf("ISP was active stack pointer\r\n");
    } else if ((f0->sr & 0x3000) == 0x3000) {
        active_sp = (uint8_t *)f0->msp;
        
        printf("MSP was active stack pointer\r\n");
    }

    /* Print information about where the PC points in relation to the error */
    switch (f0->vect) {
        case 0x08: /* Bus Error */
        case 0x0C: /* Address Error */
            if (f0->format == 0xA) {
                printf("PC points to next instruction\r\n\r\n");
            } else {
                printf("PC points to address of instruction in execution when the fault occurred\r\n\r\n");
            }

            break;
        
        case 0x10: /* Illegal Instruction */
            printf("PC points to illegal instruction\r\n\r\n");
            break;
        
        case 0x14: /* Zero Divide */
        case 0x18: /* CHK Instruction */
        case 0x1C: /* TRAPV Instruction */
        case 0x24: /* Trace */
        case 0x64: /* IRQ1 */
        case 0x68: /* IRQ2 */
        case 0x6C: /* IRQ3 */
        case 0x70: /* IRQ4 */
        case 0x74: /* IRQ5 */
        case 0x78: /* IRQ6 */
        case 0x7C: /* IRQ7 */
        case 0x80: /* TRAP #0 */
        case 0x84: /* TRAP #1 */
        case 0x88: /* TRAP #2 */
        case 0x8C: /* TRAP #3 */
        case 0x90: /* TRAP #4 */
        case 0x94: /* TRAP #5 */
        case 0x98: /* TRAP #6 */
        case 0x9C: /* TRAP #7 */
        case 0xA0: /* TRAP #8 */
        case 0xA4: /* TRAP #9 */
        case 0xA8: /* TRAP #10 */
        case 0xAC: /* TRAP #11 */
        case 0xB0: /* TRAP #12 */
        case 0xB4: /* TRAP #13 */
        case 0xB8: /* TRAP #14 */
        case 0xBC: /* TRAP #15 */
            printf("PC points to next instruction\r\n\r\n");
            break;

        case 0x20: /* Privilege Violation */
            printf("PC points to first word of instruction that caused the privilege violation\r\n\r\n");
            break;

        case 0x28: /* Line 1010 Emulator */
        case 0x2C: /* Line 1111 Emulator */
            printf("PC points to A-line/F-line instruction\r\n\r\n");
            break;

        case 0x38: /* Format Error */
            printf("PC points to RTE or cpRESTORE instruction\r\n\r\n");
            break;
    }

    const char *sizes[] = {
        "32 bits",
        "16 bits",
        "8 bits",
        "Insert wait states"
    };

    const char *funcs[] = {
        "(Undefined, reserved)",
        "User Data Space",
        "User Program Space",
        "(Undefined, reserved)",
        "(Undefined, reserved)",
        "Supervisor Data Space",
        "Supervisor Program Space",
        "CPU Space"
    };

    /* Decode the Special Status Word */
    if (f0->format == 0xA || f0->format == 0xB) {
        printf(
            "Special Status Word: %04X\r\n"
            "\r\n"
            "%u... .... .... .... = FC: Fault on stage C of the instruction pipe\r\n"
            ".%u.. .... .... .... = FB: Fault on stage B of the instruction pipe\r\n"
            "..%u. .... .... .... = RC: Rerun flag for stage C of the instruction pipe*\r\n"
            "...%u .... .... .... = RB: Rerun flag for stage B of the instruction pipe*\r\n"
            ".... ...%u .... .... = DF: Fault/rerun flag for data cycle*\r\n"
            ".... .... %u... .... = RM: Read-modify-write on data cycle\r\n"
            ".... .... .%u.. .... = RW: Read/write for data cycle (1=read, 0=write)\r\n"
            ".... .... ..%u%u .... = SIZE1..0: %s\r\n"
            ".... .... .... .%u%u%u = FC2..0: %s\r\n"
            "* 1=Rerun bus cycle or run pending prefetch, 0=Do not rerun bus cycle\r\n"
            "\r\n"
            "Instruction pipe stage C: %04X\r\n"
            "Instruction pipe stage B: %04X\r\n"
            "Data cycle fault address: 0x%08X\r\n"
            "Data output buffer: %08X\r\n",
            fA->ssw.u16,
            fA->ssw.FC,
            fA->ssw.FB,
            fA->ssw.RC,
            fA->ssw.RB,
            fA->ssw.DF,
            fA->ssw.RM,
            fA->ssw.RW,
            fA->ssw.SIZE1, fA->ssw.SIZE0, sizes[fA->ssw.SIZE],
            fA->ssw.FC2, fA->ssw.FC1, fA->ssw.FC0, funcs[fA->ssw.FUNC],
            fA->inst_c,
            fA->inst_b,
            fA->fault_addr,
            fA->data_out_buf
        );

        if (f0->format == 0xB) {
            printf(
                "Stage B address: 0x%08X\r\n"
                "Data input buffer: %08X\r\n"
                "\r\n",
                fB->stage_b_addr,
                fB->data_in_buf
            );
        }
    }

    /* Decode some extra info for Format Errors */
    if (f0->vect == 0x38) {
        uint16_t sr_to_restore = *(uint16_t *)sp;
        uint32_t pc_to_restore = (uint32_t)*(uint16_t *)sp + 1;
        uint16_t format_word = *(uint16_t *)sp + 3;

        printf(
            "SR to restore: 0x%04X\r\n"
            "PC to restore: 0x%08X\r\n"
            "Format word: 0x%04X\r\n\r\n",
            sr_to_restore,
            pc_to_restore,
            format_word
        );

    }

    printf("Dump surrounding PC:\r\n");
    hex_dump((uint8_t *)f0->pc - 16, 32, 1);

    printf("\r\nDump surrounding stack pointer:\r\n");
    hex_dump((uint8_t *)active_sp - 16, 32, 1);

    while (true);
}





/* Hex dump some data
 *
 * start is a pointer to the address to start dumping from
 * len is the number of bytes to dump
 * size is the size of data to read and dump at a time (1 for byte, 2 for word,
 *      4 for long)
 *
 * len should be a multiple of size.
 *
 *
 *
 */
void
hex_dump(const void *start, uint32_t len, uint8_t size)
{
    const void *end = (uint8_t *)start + len;
    const void *read1;
    const void *read2;
    uint8_t read_ctr;
    uint32_t read_amt;
    uint8_t space_len = 0;

    if (size != 1 && size != 2 && size != 4) {
        /* Bad size */
        return;
    }

    if (len & (size - 1)) {
        /* Not a multiple */
        return;
    }

    /* TODO: install new Bus Error vector to catch bad reads and e.g. display
     * X's in the dump where memory could not be read */

    const char *spaces = "                                        ";

    read1 = start;
    read2 = start;

    printf(" -------- -------- -------- -------- --------  ----------------\r\n");

    while (read1 < end) {
        read_amt = end - read1;

        if (read_amt > 16) {
            read_amt = 16;
        }

        /* Print the address being dumped from aligned to 16 bytes */
        printf(" %08x ", (uint32_t)read1 & ~0xF);

        /* If not dumping from an address aligned to 16 bytes, print some
         * spaces to nicely align the data when it starts being dumped */
        if ((uint32_t)read1 & 0xF) {
            /* If the amount of data to read will exceed the length of a row
             * (16 bytes), trim the length so it will fit */
            if (read_amt + ((uint32_t)read1 & 0xF) > 16) {
                read_amt -= (uint32_t)read1 & 0xF;
            }
            
            space_len = ((uint32_t)read1 & 0xF) * 2;

            /* Add column spacers */
            if (space_len >= 24) {
                space_len += 3;
            } else if (space_len >= 16) {
                space_len += 2;
            } else if (space_len >= 8) {
                space_len++;
            }

            printf("%s", spaces + (40 - space_len));
        }

        /* Dump a rows worth of bytes in hex format */
        for (read_ctr = read_amt; read_ctr > 0; read_ctr--) {
            printf("%02x", *(uint8_t *)read1++);

            if (((uint32_t)read1 & 0xF) == 0) {
                printf("  ");
            } else if (((uint32_t)read1 & 0x3) == 0) {
                printf(" ");
            }
        }

        /* If dumping ended before a 16 byte boundary, print required number of
         * spaces at the end of the row to line up the character dump */
        if ((uint32_t)read1 & 0xF) {
            space_len = (16 - ((uint32_t)read1 & 0xF)) * 2;

            /* Add column spacers */
            if (space_len > 24) {
                space_len += 3;
            } else if (space_len > 16) {
                space_len += 2;
            } else if (space_len > 8) {
                space_len++;
            }

            /* Plus 2 spaces between hex and char data */
            space_len += 2;

            printf("%s", spaces + (40 - space_len));
        }

        /* Likewise for character dump, if not dumping from an address aligned
         * to 16 bytes, print some spaces to align output nicely */
        if ((uint32_t)read2 & 0xF) {
            space_len = (uint32_t)read2 & 0xF;

            printf("%s", spaces + (40 - space_len));
        }

        /* Dump a rows worth of characters */
        for (read_ctr = read_amt; read_ctr > 0; read_ctr--) {
            if (*(uint8_t *)read2 >= 0x20 && *(uint8_t *)read2 <= 0x7E) {
                printf("%c", *(char *)read2);
            } else {
                printf(".");
            }

            read2++;
        }

        printf("\r\n");
    }

    /* TODO: restore original Bus Error vector */
}

