; TSS implementation in Assembly by Huguini79 (https://github.com/Huguini79)

section .asm

global tss_load

tss_load:
	push ebp
	mov ebp, esp

	mov ax, [ebp + 8]
	ltr ax
	pop ebp
	ret
