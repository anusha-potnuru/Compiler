	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"This Programs calculate if a number is a magic number or not.\n"
.LC1:
	.string	"ENTER NUMBER\n"
.LC2:
	.string	"Sum of digits \n"
.LC3:
	.string	"\nKeep calculating sum of digits until single digit, If  1, it is magical, else not!! \n"
.LC4:
	.string	"Number is magic\n"
.LC5:
	.string	"number is not magic\n"
	.text	
	.globl	sumofdigits
	.type	sumofdigits, @function
sumofdigits: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$92, %rsp
	movq	%rdi, -20(%rbp)
	movl	$10, %eax
	movl 	%eax, -28(%rbp)
	movl 	-20(%rbp), %eax
	cltd
	idivl 	-28(%rbp)
	movl 	%eax, -32(%rbp)
	movl	$0, %eax
	movl 	%eax, -36(%rbp)
	movl	-32(%rbp), %eax
	cmpl	-36(%rbp), %eax
	je .L2
	jmp .L3
	jmp .L4
.L2: 
	movl	-20(%rbp), %eax
	movl 	%eax, -24(%rbp)
	jmp .L4
.L3: 
	movl	$10, %eax
	movl 	%eax, -52(%rbp)
	movl 	-20(%rbp), %eax
cltd
idivl 	-52(%rbp)
movl 	%edx ,-56(%rbp)

	movl 	-56(%rbp), %eax
	movq 	-56(%rbp), %rdi
call	sumofdigits
	movl	%eax, -60(%rbp)
	movl	$10, %eax
	movl 	%eax, -64(%rbp)
	movl 	-20(%rbp), %eax
	cltd
	idivl 	-64(%rbp)
	movl 	%eax, -68(%rbp)
	movl 	-68(%rbp), %eax
	movq 	-68(%rbp), %rdi
call	sumofdigits
	movl	%eax, -72(%rbp)
	movl 	-60(%rbp), %eax
	movl 	-72(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -76(%rbp)
	movl	-76(%rbp), %eax
	movl 	%eax, -24(%rbp)
.L4: 
	movl	-24(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	sumofdigits, .-sumofdigits
	.globl	main
	.type	main, @function
main: 
.LFB1:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$148, %rsp

	movq 	$.LC0, -32(%rbp)
	movl 	-32(%rbp), %eax
	movq 	-32(%rbp), %rdi
call	printStr
	movl	%eax, -36(%rbp)
	movq 	$.LC1, -40(%rbp)
	movl 	-40(%rbp), %eax
	movq 	-40(%rbp), %rdi
call	printStr
	movl	%eax, -44(%rbp)
	leaq	-48(%rbp), %rax
	movq 	%rax, -56(%rbp)
	movl 	-56(%rbp), %eax
	movq 	-56(%rbp), %rdi
call	readInt
	movl	%eax, -60(%rbp)
	movl	-60(%rbp), %eax
	movl 	%eax, -24(%rbp)
.L7: 
	movl	$10, %eax
	movl 	%eax, -72(%rbp)
	movl 	-24(%rbp), %eax
	cltd
	idivl 	-72(%rbp)
	movl 	%eax, -76(%rbp)
	movl	$0, %eax
	movl 	%eax, -80(%rbp)
	movl	-76(%rbp), %eax
	cmpl	-80(%rbp), %eax
	jne .L8
	jmp .L9
.L8: 
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
call	sumofdigits
	movl	%eax, -88(%rbp)
	movl	-88(%rbp), %eax
	movl 	%eax, -24(%rbp)
	jmp .L7
.L9: 
	movq 	$.LC2, -100(%rbp)
	movl 	-100(%rbp), %eax
	movq 	-100(%rbp), %rdi
call	printStr
	movl	%eax, -104(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
call	printInt
	movl	%eax, -112(%rbp)
	movq 	$.LC3, -116(%rbp)
	movl 	-116(%rbp), %eax
	movq 	-116(%rbp), %rdi
call	printStr
	movl	%eax, -120(%rbp)
	movl	$1, %eax
	movl 	%eax, -124(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-124(%rbp), %eax
	je .L10
	jmp .L11
	jmp .L12
.L10: 
	movq 	$.LC4, -128(%rbp)
	movl 	-128(%rbp), %eax
	movq 	-128(%rbp), %rdi
call	printStr
	movl	%eax, -132(%rbp)
	jmp .L12
.L11: 
	movq 	$.LC5, -136(%rbp)
	movl 	-136(%rbp), %eax
	movq 	-136(%rbp), %rdi
call	printStr
	movl	%eax, -140(%rbp)
.L12: 
	movl	$0, %eax
	movl 	%eax, -144(%rbp)
	movl	-144(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident		"Compiled by 16CS30027"
	.section	.note.GNU-stack,"",@progbits
