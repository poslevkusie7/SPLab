	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 13, 0
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	stur	x1, [x29, #-16]
	stur	x2, [x29, #-24]
	mov	w8, #1
	stur	w8, [x29, #-28]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-28]
	ldur	w9, [x29, #-8]
	subs	w8, w8, w9
	b.ge	LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	x8, [x29, #-16]
	ldursw	x9, [x29, #-28]
	ldr	x8, [x8, x9, lsl #3]
	mov	x9, sp
	mov	x10, #1
	str	x10, [sp, #24]                  ; 8-byte Folded Spill
	str	x10, [x9]
	str	x8, [x9, #8]
	mov	x8, #7
	str	x8, [x9, #16]
	mov	w0, #4
	str	w0, [sp, #32]                   ; 4-byte Folded Spill
	bl	_syscall
	ldr	x8, [sp, #24]                   ; 8-byte Folded Reload
	ldr	w0, [sp, #32]                   ; 4-byte Folded Reload
	mov	x9, sp
	str	x8, [x9]
	adrp	x8, l_.str@PAGE
	add	x8, x8, l_.str@PAGEOFF
	str	x8, [x9, #8]
	mov	x8, #1
	str	x8, [x9, #16]
	bl	_syscall
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-28]
	add	w8, w8, #1
	stur	w8, [x29, #-28]
	b	LBB0_1
LBB0_4:
	mov	x9, sp
	mov	x8, #1
	str	x8, [x9]
	adrp	x8, l_.str.1@PAGE
	add	x8, x8, l_.str.1@PAGEOFF
	str	x8, [x9, #8]
	mov	x8, #1
	str	x8, [x9, #16]
	mov	w0, #4
	bl	_syscall
	mov	w0, #0
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	" "

l_.str.1:                               ; @.str.1
	.asciz	"\n"

.subsections_via_symbols
