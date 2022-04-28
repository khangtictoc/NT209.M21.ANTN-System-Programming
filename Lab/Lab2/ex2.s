.section .bss
	.lcomm num1, 1
	.lcomm num2, 1
	.lcomm num3, 1
	.lcomm num4, 1
	.lcomm result 1

.section .text
	.global _start

_start:
	# num1
	movl $3, %eax
	movl $0, %ebx
	movl $num1, %ecx
	movl $2, %edx
	int $0x80
	
	# num2
	movl $3, %eax
	movl $0, %ebx
	movl $num2, %ecx
	movl $2, %edx
	int $0x80
	
	# num3
	movl $3, %eax
	movl $0, %ebx
	movl $num3, %ecx
	movl $2, %edx
	int $0x80
	
	# num4
	movl $3, %eax
	movl $0, %ebx
	movl $num4, %ecx
	movl $2, %edx
	int $0x80

	mov (num1), %al
	sub $48, %al

	mov (num2), %bl
	sub $48, %bl
	add %bl, %al
	
	mov (num3), %bl
	sub $48, %bl 
	add %bl, %al
	
	mov (num4), %bl
	sub $48, %bl 
	add %bl, %al
	
	sar $2, %al 
	
	add $48, %al
	mov %al, (result)
	
	
	
	mov $4, %eax
	mov $1, %ebx
	mov $result, %ecx
	mov $1, %edx
	int $0x80
	
	movl $1, %eax
	int $0x80
