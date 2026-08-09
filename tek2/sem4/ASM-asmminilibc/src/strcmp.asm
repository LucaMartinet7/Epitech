bits 64

section .text
    global strcmp

strcmp:
	xor	rax, rax

loop:
	mov	al, BYTE [rdi]
	cmp	BYTE [rsi], al
	jnz	diff
	cmp	al, 0x00
	jz	exit
	inc	rdi
	inc	rsi
	jmp	loop

diff:
	xor	ecx, ecx
	mov	cl, BYTE [rsi]
	sub	eax, ecx

exit:
	ret
