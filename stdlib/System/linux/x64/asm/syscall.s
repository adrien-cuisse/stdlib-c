
;
; Executes a system call from its number
;
; See codes.h for call numbers
;

bits 64

;  Define variables in the data section
SECTION .data

;  Code goes in the text section
SECTION .text

;	Global to call it from C code
	GLOBAL __system_call

	__system_call:

;		1st argument (call number) is sent to rdi
;		Optional arguments are stored in rsi, rdx, rcx, r8, r9, other ones are pushed to the stack
;		System calls expects arguments in rax, rdi, rsi, rdx, r10, r9 and r9
;		Gotta do some shifting
		mov rax, rdi
		mov rdi, rsi
		mov rsi, rdx
		mov rdx, rcx
		mov r10, r8
		mov r8, r9
		syscall  ; 64 bits system have syscall instruction
		ret
