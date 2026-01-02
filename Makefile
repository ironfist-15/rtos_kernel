CC = riscv64-unknown-elf-gcc
CFLAGS = -Wall -O0 -ffreestanding -nostdlib -march=rv32im -mabi=ilp32

SRC = start.S kernel/rtos.c bsp/uart_qemu.c app/app.c
# SRC = start.S kernel/rtos.c bsp/uart_hw.c app/app.c    #un comment this if using real hardware and coment other src

OUT = build/rtos.elf

all:
	$(CC) $(CFLAGS) -T linker.ld $(SRC) -o $(OUT)

run: all
	qemu-system-riscv32 \
	-machine virt \
	-nographic \
	-bios none \
	-kernel $(OUT)

clean:
	rm -f build/*
