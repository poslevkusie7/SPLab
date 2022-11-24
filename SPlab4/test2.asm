section .text

global _add

_add:
    mov rax, rcx
    add rax, rdx
ret