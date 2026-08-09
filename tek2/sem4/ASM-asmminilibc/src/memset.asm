bits 64

section .text
    global memset

memset:
    xor rcx, rcx
    xor rax, rax
    cmp rdi, 0x00
    jz end

loop:
    cmp rcx, rdx
    jz end
    mov byte [rdi + rcx], sil
    inc rcx
    jmp loop

end:
    mov rax, rdi
    ret
