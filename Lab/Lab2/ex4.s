.section .data

message:
	.string "Enter your mark: "
lengthMess = . - message - 1 

messGioi:
	.string "Gioi"
messDat:
	.string "Dat"
messKhongDat:
	.string "Khong Dat"
	

	

.section .bss
.lcomm point, 1

.section .text

.globl _start

_start:
        movl $lengthMess, %esi # Take length of input message
        
        # Print input message
	movl $4, %eax
	movl $1, %ebx
	movl $message, %ecx
	movl %esi, %edx
	int $0x80
	
	# Get our input values
	movl $3, %eax
	movl $0, %ebx 
	movl $point, %ecx
	movl $2, %edx # Get 2 bytes because we have 2-char number
	int $0x80 
	

	movl $point, %edi   # Get first byte' address
	movb (%edi), %sil # Get first byte' value
	sub $48, %sil # Convert to number for comparing
	
	cmp $8, %sil # if first byte < 8 
	jl checkNext # Check the next case
	
	# Else "Gioi" message should be poped up
	movl $4, %eax
	movl $1, %ebx
	movl $messGioi, %ecx
	movl $5, %edx
	int $0x80
	
	# Then exit the program
	jmp Exit
	
checkNext:
	# Other case, if first byte < 5
	cmp $5, %sil
	jl printKhongDat # then "Khong Dat" would be output
	
	# Else, check the second byte
	movl $point, %edi # Get first byte' address
	addl $1, %edi # Get second byte' address
	movb (%edi), %sil # Get second byte' value
	sub $48, %sil # Convert to number for comparing
	
	# When 2nd byte < 5 
	cmp $5, %sil
	jl printKhongDat # Then this grade is "Khong Dat"
	
	# Else => "Dat"
	movl $4, %eax
	movl $1, %ebx
	movl $messDat, %ecx
	movl $4, %edx
	int $0x80
	
	# Then exit the program
	jmp Exit

printKhongDat:
	movl $4, %eax
	movl $1, %ebx
	movl $messKhongDat, %ecx
	movl $10, %edx
	int $0x80

Exit:
	movl $1, %eax
	int $0x80
