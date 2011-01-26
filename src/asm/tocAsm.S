#define ASM 1
#include "machine/toc.h"

/* This file is a gnu assembler file, therefore AT&T Syntax is needed*/

.global toc_go, toc_switch

/*
; TOC_SWITCH : switch of context, the current registers are saved and the 
;              registers of the new 'thread of control' are imported
;
; C Prototyp: void toc_switch (struct toc* regs_now,
;                              struct toc* reg_then);
*/

toc_switch:
	movl 4(%esp), %edx //edx <- regs_now (cdecl, reverse order)

	movl %ebx, EBX_OFFSET(%edx)
	movl %esi, ESI_OFFSET(%edx)
	movl %edi, EDI_OFFSET(%edx)
	movl %ebp, EBP_OFFSET(%edx)
	movl %esp, ESP_OFFSET(%edx)

	addl $4, %esp //[esp + 4] is reg_then
	//fall through

/*
; TOC_GO : initial start of the process used for all new processes
;
; C Prototyp: void toc_go (struct toc* regs);
*/

toc_go:
	movl 4(%esp), %edx //edx <- regs

	movl EBX_OFFSET(%edx), %ebx
	movl ESI_OFFSET(%edx), %esi
	movl EDI_OFFSET(%edx), %edi
	movl EBP_OFFSET(%edx), %ebp
	movl ESP_OFFSET(%edx), %esp

	ret
