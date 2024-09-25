bits 64

section .text
    global memmove

memmove:
	cmp	rsi, rdi
	jl	cpy
	mov	rax, rdi
	mov	rcx, rdx
	mov	rdx, rsi
	cld
	rep	movsb
	mov	rsi, rdx
	mov	rdi, rax
	ret

cpy:
	mov	rax, rdi
	cmp	rdx, 0x00
	jz	exit

loop:
	dec	rdx
	mov	r8b, BYTE[rsi + rdx]
	mov	BYTE[rdi + rdx], r8b
	cmp	rdx, 0x00
	jnz	loop

exit:
	ret
