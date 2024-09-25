bits 64

section .text
    global memcpy

memcpy:
    xor rcx, rcx
    cmp rdi, 0x00
    jz end
    cmp rsi, 0x00
    jz end

loop:
    cmp rcx, rdx
    jz end
    mov al, [rsi + rcx]
    mov [rdi + rcx], al
    inc rcx
    jmp loop

end:
    mov rax, rdi
    ret
