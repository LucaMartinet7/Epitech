bits 64

section .text
    global strlen

strlen:
    mov rcx, 0x00
    jmp loop

loop:
    cmp byte [rdi + rcx], 0x00
    je end
    inc rcx
    jmp loop

end:
    mov rax, rcx
    ret
