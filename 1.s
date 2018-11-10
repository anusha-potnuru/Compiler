	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"Testing print string"
.LC1:
	.string	"Testing read int \n"
.LC2:
	.string	"Enter integer: "
.LC3:
	.string	"printing the read integer: "
.LC4:
	.string	"Error in reading int"
.LC5:
	.string	"Testing pointers!"
	.text	
	.globl	f
	.type	f, @function
f: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$60, %rsp
	movq	%rdi, -20(%rbp)
	movq	-20(%rbp), %rax
	movl	(%rax),%eax
	movl 	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	$2, %eax
	movl 	%eax, -40(%rbp)
	movl 	-24(%rbp), %eax
	movl 	-40(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
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
	subq	$168, %rsp

	movq 	$.LC0, -32(%rbp)
	movl 	-32(%rbp), %eax
	movq 	-32(%rbp), %rdi
call	printStr
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
call	printInt
	movl	%eax, -52(%rbp)
	movl	$12, %eax
	movl 	%eax, -56(%rbp)
	movl 	-56(%rbp), %eax
	movq 	-56(%rbp), %rdi
call	printInt
	movl	%eax, -60(%rbp)
	movl	-60(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
call	printInt
	movl	%eax, -72(%rbp)
	movq 	$.LC1, -76(%rbp)
	movl 	-76(%rbp), %eax
	movq 	-76(%rbp), %rdi
call	printStr
	movl	%eax, -80(%rbp)
	movq 	$.LC2, -84(%rbp)
	movl 	-84(%rbp), %eax
	movq 	-84(%rbp), %rdi
call	printStr
	movl	%eax, -88(%rbp)
	leaq	-24(%rbp), %rax
	movq 	%rax, -100(%rbp)
	movl 	-100(%rbp), %eax
	movq 	-100(%rbp), %rdi
call	readInt
	movl	%eax, -104(%rbp)
	movl	-104(%rbp), %eax
	movl 	%eax, -92(%rbp)
	movq 	$.LC3, -108(%rbp)
	movl 	-108(%rbp), %eax
	movq 	-108(%rbp), %rdi
call	printStr
	movl	%eax, -112(%rbp)
	movl	$0, %eax
	movl 	%eax, -116(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-116(%rbp), %eax
	je .L4
	jmp .L5
	jmp .L6
.L4: 
	movl 	-92(%rbp), %eax
	movq 	-92(%rbp), %rdi
call	printInt
	movl	%eax, -120(%rbp)
	jmp .L6
.L5: 
	movq 	$.LC4, -124(%rbp)
	movl 	-124(%rbp), %eax
	movq 	-124(%rbp), %rdi
call	printStr
	movl	%eax, -128(%rbp)
.L6: 
	movq 	$.LC5, -136(%rbp)
	movl 	-136(%rbp), %eax
	movq 	-136(%rbp), %rdi
call	printStr
	movl	%eax, -140(%rbp)
	leaq	-24(%rbp), %rax
	movq 	%rax, -148(%rbp)
	movl 	-148(%rbp), %eax
	movq 	-148(%rbp), %rdi
call	f
	movl	%eax, -152(%rbp)
	movl	-152(%rbp), %eax
	movl 	%eax, -132(%rbp)
	movl	$0, %eax
	movl 	%eax, -164(%rbp)
	movl	-164(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident		"Compiled by 16CS30027"
	.section	.note.GNU-stack,"",@progbits
