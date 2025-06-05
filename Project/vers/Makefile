# Makefile for ARM VersatilePB with GDB and UART debugging

# Toolchain
CC      = arm-none-eabi-gcc
AS      = arm-none-eabi-as
LD      = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

# Flags
CFLAGS  = -mcpu=arm926ej-s -nostdlib -nostartfiles -Wall -g -O0
LDFLAGS = -T linker.ld

# Files
TARGET = uartvers
OBJS   = startup.o main.o

# Default target
all: $(TARGET).bin

startup.o: startup.s
	$(AS) -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.bin: %
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f *.o *.bin *.elf $(TARGET)

.PHONY: all clean
