.section .data

output: 
	.string "From UIT"
length = . - output

.section .bss
.lcomm test,  1

	
.section .text 

.globl _start
_start:

	addl $48, %esi
	add $length, %esi
	subl $1, %esi
	movl %esi, (test) 
	
	movl $4, %eax 
	movl $1, %ebx 
	movl $test, %ecx
	movl $1, %edx 
	int $0x80
	
	 
	movl $1, %eax 
	int $0x80
