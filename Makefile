# List all of the object files that will be combined into your final binary
# in the OBJ variable.
#
# For example, if you have the following source files
#
#   main.c
#   user.c
#   driver.s
#
# then your OBJ list would be
#
#   main.o user.o driver.o
#
# The compiler will automatically choose the correct source file (.c, .s etc)
# according to the object file (.o) to be created.
OBJ=main.o IRQ4.o exceptions_asm.o exceptions_c.o
OBJ+= FreeRTOS-Kernel/portable/GCC/m68k/port.o FreeRTOS-Kernel/portable/GCC/m68k/portasm.o
OBJ+= FreeRTOS-Kernel/tasks.o FreeRTOS-Kernel/queue.o FreeRTOS-Kernel/list.o
OBJ+= FreeRTOS-Kernel/stream_buffer.o FreeRTOS-Kernel/event_groups.o
OBJ+= FreeRTOS-Kernel/timers.o FreeRTOS-Kernel/portable/MemMang/heap_4.o

OBJ+= FreeRTOS-Plus-TCP/FreeRTOS_IP.o FreeRTOS-Plus-TCP/FreeRTOS_ARP.o
OBJ+= FreeRTOS-Plus-TCP/FreeRTOS_DHCP.o FreeRTOS-Plus-TCP/FreeRTOS_DNS.o
OBJ+= FreeRTOS-Plus-TCP/FreeRTOS_Sockets.o FreeRTOS-Plus-TCP/FreeRTOS_UDP_IP.o
OBJ+= FreeRTOS-Plus-TCP/FreeRTOS_TCP_IP.o FreeRTOS-Plus-TCP/FreeRTOS_TCP_WIN.o

OBJ+= FreeRTOS-Plus-TCP/FreeRTOS_Stream_Buffer.o

OBJ+= FreeRTOS-Plus-TCP/portable/NetworkInterface/C2500/NetworkInterface.o
OBJ+= FreeRTOS-Plus-TCP/portable/BufferManagement/BufferAllocation_1.o

# Specify the CPU type that you are targeting your build towards.
#
# Supported architectures can usually be found with the --target-help argument
# passed to gcc, but a quick summary is:
#
# 68000, 68010, 68020, 68030, 68040, 68060, cpu32 (includes 68332 and 68360),
# 68302
CPU=68030

# Uncomment either of the following depending on how you have installed gcc on
# your system. m68k-linux-gnu for Linux installations, m68k-eabi-elf if gcc was
# built from scratch e.g. on a Mac by running the build script.
# PREFIX=m68k-linux-gnu
PREFIX=m68k-eabi-elf

# Dont modify below this line (unless you know what youre doing).
CC=$(PREFIX)-gcc
AS=$(PREFIX)-as
LD=$(PREFIX)-ld
OBJCOPY=$(PREFIX)-objcopy
OBJDUMP=$(PREFIX)-objdump

CFLAGS=-m$(CPU) -Wall -g -static -I../include -I./FreeRTOS-Kernel/include -I./FreeRTOS-Kernel/portable/GCC/m68k -I./FreeRTOS-Plus-TCP/include -I./FreeRTOS-Plus-TCP/portable/Compiler/GCC -I. -msoft-float -MMD -MP -O
LFLAGS=--script=platform.ld -L../libmetal -lmetal

DEP=$(OBJ:%.o=%.d)
INT=$(OBJ:%.o=%.i)

%/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%/%.o: %.S
	$(CC) $(CFLAGS) -c $<

%/%.o: %.s
	$(CC) $(CFLAGS) -c $<

bmbinary: $(OBJ)
	$(LD) -o $@ $(OBJ) $(LFLAGS)

-include $(DEP)

all: bmbinary rom

crt:
	$(CC) $(CFLAGS) -c crt0.S

clean:
	rm -f $(OBJ) $(DEP) $(INT)

rom:
	$(OBJCOPY) -O binary bmbinary bmbinary.rom
	$(OBJCOPY) -O srec bmbinary bmbinary.srec

dump:
	$(OBJDUMP) -m$(CPU) -belf32-m68k -st -j.evt bmbinary
	$(OBJDUMP) -m$(CPU) -belf32-m68k -dt -j.text bmbinary
	$(OBJDUMP) -m$(CPU) -belf32-m68k -st -j.rodata -j.data -j.bss -j.heap -j.stack bmbinary

dumps:
	$(OBJDUMP) -m$(CPU) -belf32-m68k -st -j.evt bmbinary
	$(OBJDUMP) -m$(CPU) -belf32-m68k -St -j.text bmbinary
	$(OBJDUMP) -m$(CPU) -belf32-m68k -st -j.rodata -j.data -j.bss -j.heap -j.stack bmbinary
	$(OBJDUMP) -m$(CPU) -belf32-m68k -t -j.iomem bmbinary

dumpscrt:
	$(OBJDUMP) -m$(CPU) -belf32-m68k -St -j.text crt0.o

hexdump:
	hexdump -C bmbinary.rom
