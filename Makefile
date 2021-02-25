    OBJECTS = loader.o kmain.o stdio.o
    CC = gcc
    CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
             -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
    LDFLAGS = -T linker.ld -melf_i386
    AS = nasm
    ASFLAGS = -f elf

    all: kernel.elf

    kernel.elf: $(OBJECTS)
			ld $(LDFLAGS) $(OBJECTS) -o kernel.elf
    run: kernel.elf
			qemu-system-x86_64 --kernel kernel.elf

    %.o: %.c
			$(CC) $(CFLAGS)  $< -o $@

    %.o: %.s
			$(AS) $(ASFLAGS) $< -o $@

    clean:
			rm -rf *.o kernel.elf
