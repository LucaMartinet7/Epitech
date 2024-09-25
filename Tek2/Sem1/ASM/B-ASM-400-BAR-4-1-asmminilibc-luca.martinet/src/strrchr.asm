bits 64

section .text
    global strrchr

strrchr:
    mov rcx, 0x00
    xor rax, rax
    jmp loop

loop:
    cmp byte [rdi + rcx], sil
    je found
    cmp byte [rdi + rcx], 0x00
    je not_found
    inc rcx
    jmp loop

found:
    lea rax, [rdi + rcx]
    inc rcx
    jmp loop

not_found:
    ret
