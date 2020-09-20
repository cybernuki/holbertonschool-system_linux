BITS 64

section .data

section .bss

section .text
	global asm_strlen

; string length funciton
asm_strlen:
	push rbp		
	mov rbp, rsp
	push rbx		
	push rcx		
	mov rbx, rdi	
	mov rcx, 0		
count_c:			
	inc rcx			
	cmp byte [rbx + rcx - 1], 0x00	
	jne count_c		
	dec rcx			
	mov rax, rcx		
	pop rcx			
	pop rbx			
	mov rsp, rbp	
	pop rbp
	ret			
