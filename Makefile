OBJECTS = loader.o kmain.o framebuffer.o io.o stdio.o security/stacksmash.o panic.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fstack-protector-strong \
		 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T linker.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

run: kernel.elf
	qemu-system-x86_64 --kernel kernel.elf

debug: debug_kernel.elf
	echo "To debug open gdb and type \"target remote localhost:1234\""
	qemu-system-x86_64 --kernel kernel.elf -s

debug_kernel.elf: CFLAGS += -g
debug_kernel.elf: ASFLAGS += -g
debug_kernel.elf: kernel.elf;

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf
