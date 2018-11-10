	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"got into function \n"
.LC1:
	.string	"ans in diff fn: \n"
.LC2:
	.string	"returning from function \n"
.LC3:
	.string	"Enter two numbers : \n"
.LC4:
	.string	"x :"
.LC5:
	.string	"\n y:"
.LC6:
	.string	"\n"
.LC7:
	.string	"difference of the two number is equal to\n "
.LC8:
	.string	"\n"
	.text	
	.globl	diff
	.type	diff, @function
diff: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$84, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	movq 	$.LC0, -32(%rbp)
	movl 	-32(%rbp), %eax
	movq 	-32(%rbp), %rdi
call	printStr
	movl	%eax, -36(%rbp)
	movl 	-20(%rbp), %eax
	movl 	-16(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	$.LC1, -52(%rbp)
	movl 	-52(%rbp), %eax
	movq 	-52(%rbp), %rdi
call	printStr
	movl	%eax, -56(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
call	printInt
	movl	%eax, -64(%rbp)
	movq 	$.LC2, -68(%rbp)
	movl 	-68(%rbp), %eax
	movq 	-68(%rbp), %rdi
call	printStr
	movl	%eax, -72(%rbp)
	movl	-24(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	diff, .-diff
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

	movq 	$.LC3, -48(%rbp)
	movl 	-48(%rbp), %eax
	movq 	-48(%rbp), %rdi
call	printStr
	movl	%eax, -52(%rbp)
	leaq	-36(%rbp), %rax
	movq 	%rax, -60(%rbp)
	movl 	-60(%rbp), %eax
	movq 	-60(%rbp), %rdi
call	readInt
	movl	%eax, -64(%rbp)
	movl	-64(%rbp), %eax
	movl 	%eax, -24(%rbp)
	leaq	-40(%rbp), %rax
	movq 	%rax, -76(%rbp)
	movl 	-76(%rbp), %eax
	movq 	-76(%rbp), %rdi
call	readInt
	movl	%eax, -80(%rbp)
	movl	-80(%rbp), %eax
	movl 	%eax, -28(%rbp)
	movq 	$.LC4, -92(%rbp)
	movl 	-92(%rbp), %eax
	movq 	-92(%rbp), %rdi
call	printStr
	movl	%eax, -96(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
call	printInt
	movl	%eax, -104(%rbp)
	movq 	$.LC5, -108(%rbp)
	movl 	-108(%rbp), %eax
	movq 	-108(%rbp), %rdi
call	printStr
	movl	%eax, -112(%rbp)
	movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rdi
call	printInt
	movl	%eax, -116(%rbp)
	movq 	$.LC6, -120(%rbp)
	movl 	-120(%rbp), %eax
	movq 	-120(%rbp), %rdi
call	printStr
	movl	%eax, -124(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rsi
call	diff
	movl	%eax, -132(%rbp)
	movl	-132(%rbp), %eax
	movl 	%eax, -32(%rbp)
	movq 	$.LC7, -144(%rbp)
	movl 	-144(%rbp), %eax
	movq 	-144(%rbp), %rdi
call	printStr
	movl	%eax, -148(%rbp)
	movl 	-32(%rbp), %eax
	movq 	-32(%rbp), %rdi
call	printInt
	movl	%eax, -152(%rbp)
	movq 	$.LC8, -156(%rbp)
	movl 	-156(%rbp), %eax
	movq 	-156(%rbp), %rdi
call	printStr
	movl	%eax, -160(%rbp)
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
