global loader

;Declare the kmain function as extern
extern kmain

;Setup multiboot header constants
MAGIC_NUMBER equ 0x1BADB002
FLAGS        equ 0x0
CHECKSUM     equ -MAGIC_NUMBER

;Define the stack size of the kernel
KERNEL_STACK_SIZE equ 4096

;Place the multiboot header in first section
section .multiboot
align 4
  dd MAGIC_NUMBER
  dd FLAGS
  dd CHECKSUM

;Allocate memory for the stack
section  .bss
align 4
  resb KERNEL_STACK_SIZE

;Here goes the code
section .text:
align 4

;Entrypoint of the kernel
loader:
    ;Set the stack pointer on top of the stack
    mov esp, loader+KERNEL_STACK_SIZE
    ;Call the extern C function
    call kmain

;Infinite loop
.loop:
    ;Disable all interupts
    cli
    ;Wait infinite for the next interupt
    hlt
    jmp .loop
