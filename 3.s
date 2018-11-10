	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"Entered the fibonacci function\n"
.LC1:
	.string	"Enter the i for finding its fibonacci number : "
.LC2:
	.string	"\nYou Entered : "
.LC3:
	.string	"\nNow, entering the function to calculate fibonacci numbers for i:\n"
.LC4:
	.string	"\nThe fibonacci number calculated is : "
.LC5:
	.string	"\nReturned from the fib function\n"
	.text	
	.globl	fibonacci
	.type	fibonacci, @function
fibonacci: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$112, %rsp
	movq	%rdi, -20(%rbp)
	movq 	$.LC0, -28(%rbp)
	movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rdi
call	printStr
	movl	%eax, -32(%rbp)
	movl	$1, %eax
	movl 	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -36(%rbp)
	movl	$0, %eax
	movl 	%eax, -48(%rbp)
	movl	-48(%rbp), %eax
	movl 	%eax, -44(%rbp)
	movl	$1, %eax
	movl 	%eax, -56(%rbp)
	movl	-56(%rbp), %eax
	movl 	%eax, -52(%rbp)
.L2: 
	movl	-52(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl .L3
	jmp .L4
.L3: 
	movl	-36(%rbp), %eax
	movl 	%eax, -60(%rbp)
	movl 	-36(%rbp), %eax
	movl 	-44(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -72(%rbp)
	movl	-72(%rbp), %eax
	movl 	%eax, -36(%rbp)
	movl	-60(%rbp), %eax
	movl 	%eax, -44(%rbp)
	movl	$1, %eax
	movl 	%eax, -92(%rbp)
	movl 	-52(%rbp), %eax
	movl 	-92(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -96(%rbp)
	movl	-96(%rbp), %eax
	movl 	%eax, -52(%rbp)
	jmp .L2
.L4: 
	movl	-36(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	fibonacci, .-fibonacci
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
	subq	$128, %rsp

	movq 	$.LC1, -28(%rbp)
	movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rdi
call	printStr
	movl	%eax, -32(%rbp)
	leaq	-40(%rbp), %rax
	movq 	%rax, -48(%rbp)
	movl 	-48(%rbp), %eax
	movq 	-48(%rbp), %rdi
call	readInt
	movl	%eax, -52(%rbp)
	movl	-52(%rbp), %eax
	movl 	%eax, -36(%rbp)
	movq 	$.LC2, -64(%rbp)
	movl 	-64(%rbp), %eax
	movq 	-64(%rbp), %rdi
call	printStr
	movl	%eax, -68(%rbp)
	movl 	-36(%rbp), %eax
	movq 	-36(%rbp), %rdi
call	printInt
	movl	%eax, -76(%rbp)
	movq 	$.LC3, -80(%rbp)
	movl 	-80(%rbp), %eax
	movq 	-80(%rbp), %rdi
call	printStr
	movl	%eax, -84(%rbp)
	movl 	-36(%rbp), %eax
	movq 	-36(%rbp), %rdi
call	fibonacci
	movl	%eax, -96(%rbp)
	movl	-96(%rbp), %eax
	movl 	%eax, -88(%rbp)
	movq 	$.LC4, -108(%rbp)
	movl 	-108(%rbp), %eax
	movq 	-108(%rbp), %rdi
call	printStr
	movl	%eax, -112(%rbp)
	movl 	-88(%rbp), %eax
	movq 	-88(%rbp), %rdi
call	printInt
	movl	%eax, -116(%rbp)
	movq 	$.LC5, -120(%rbp)
	movl 	-120(%rbp), %eax
	movq 	-120(%rbp), %rdi
call	printStr
	movl	%eax, -124(%rbp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident		"Compiled by 16CS30027"
	.section	.note.GNU-stack,"",@progbits
