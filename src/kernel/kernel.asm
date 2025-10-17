; Unx kernel wrote by Huguini79 (https://github.com/Huguini79)

; 32 BITS
BITS 32

; text section
section .text

; Define multiboot grub headers
align 4
dd 0x1BADB002
dd 0x00
dd - (0x1BADB002 + 0x00)

; Extern the kernel main function to make it global
extern kernel_main

; Define the start function(important for the linker)
global start

start:
	; Disable interrupt
	cli
	; Call C kernel_main function
	call kernel_main
	; Wait for another interrupt
	hlt

; bss section
section .bss

; Define 64 KB of stack
stack_space: resb 65536 ; 64 KB
