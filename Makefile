CC = riscv64-unknown-elf-gcc
CFLAGS = -Wall -O0 -ffreestanding -nostdlib -march=rv32im -mabi=ilp32

SRC = start.S kernel/rtos.c app/app.c
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
