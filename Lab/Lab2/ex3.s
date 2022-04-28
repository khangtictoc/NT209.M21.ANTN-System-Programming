.section .data
	lowcase:
		.string "Chu thuong"
	upcase:
		.string "Chu hoa"
	noncase:
		.string "Khong hop le"
.section .bss
	.lcomm str, 1

.section .text
	.global _start

_start:
	movl $3, %eax
	movl $0, %ebx
	movl $str, %ecx
	movl $2, %edx
	int $0x80

	mov (str), %cl
	cmp $122, %cl
	jge Noncase
	cmp $97, %cl
	jge Lowcase
	cmp $65, %cl
	jge Upcase
	jmp Noncase

Upcase:
	mov (str), %cl
	cmp $90, %cl
	jge Noncase
	movl $4, %eax
	movl $1, %ebx
	movl $upcase, %ecx
	movl $8, %edx
	int $0x80
	jmp Exit

Lowcase:
	movl $4, %eax
	movl $1, %ebx
	movl $lowcase, %ecx
	movl $11, %edx
	int $0x80
	jmp Exit

Noncase:
	movl $4, %eax
	movl $1, %ebx
	movl $noncase, %ecx
	movl $13, %edx
	int $0x80

Exit:
	movl $1, %eax
	int $0x80
