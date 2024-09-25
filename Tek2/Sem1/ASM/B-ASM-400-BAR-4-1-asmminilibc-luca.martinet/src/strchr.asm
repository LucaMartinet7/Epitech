bits 64

section .text
    global strchr

strchr:
    mov rcx, 0x00
    jmp loop

loop:
    cmp byte [rdi + rcx], sil
    je found
    cmp byte [rdi + rcx], 0x00
    je not_found
    inc rcx
    jmp loop

found:
    mov rax, rdi
    ret

not_found:
    xor rax, rax
    ret
