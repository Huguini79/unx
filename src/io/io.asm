; Unx I/O driver wrote by Huguini79 (https://github.com/Huguini79)

global insb ; insb function to read a byte from I/O port

insb:
	; Let C to call this function
	push ebp
	mov ebp, esp

	; Clean the trash
	xor eax, eax

	; Read the I/O port that we wrote in our function
	mov edx, [ebp + 8]

	; Finally, read from that address
	in al, dx

	; Put ebp register into his original state
	pop ebp

	; Get out of the function
	ret
