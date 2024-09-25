bits 64

section .text
    global strncmp

strncmp:
	xor	rax, rax
	cmp	rdx, 0x00
	jz	exit
	dec	rdx

loop:
	mov	al, BYTE [rdi]
	cmp	BYTE [rsi], al
	jnz	diff
	cmp	BYTE [rdi], 0x00
	jz	exit
	cmp	rdx, 0x00
	jz	exit
	inc	rdi
	inc	rsi
	dec	rdx
	jmp	loop

diff:
	xor	ecx, ecx
	mov	cl, BYTE [rsi]
	sub	eax, ecx
	ret

exit:
	xor	rax, rax
	ret
