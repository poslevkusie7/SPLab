global  main            ; let the linker know about main
segment .data
segment .text
main:
        push    ebp             ; prepare stack frame for main
        mov     ebp, esp
        sub     esp, 8
        mov     edi, dword[ebp+8]    ; get argc into edi
        mov     esi, dword[ebp+12]   ; get first argv string into esi
start_loop:
        xor     eax, eax
        xor     edx, edx
        xor     ecx, ecx
        xor     ebx, ebx
        msg     db esi, 0      
        push    dword [esi]     ; must dereference esi; points to argv
        mov	    edx, 6		; message length
        mov	    ecx, msg		; message to write - надо в меседж записывать элементы аргв
        mov	    ebx, 1		; file descriptor (stdout)
        mov	    eax, 4		; system call number (sys_write)
        int	    0x80		; call kernel
        add     esi, 4          ; advance to the next pointer in argv
        dec     edi             ; decrement edi from argc to 0
        cmp     edi, 0          ; when it hits 0, we're done
        jnz     start_loop      ; end with NULL pointer
end_loop:
        xor     eax, eax
        xor     edx, edx
        xor     ecx, ecx
        xor     ebx, ebx
        leave
        ret
        


 