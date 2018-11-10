	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"Read and printing array elements of size five\n"
.LC1:
	.string	"\n"
.LC2:
	.string	"\n"
.LC3:
	.string	"\n"
.LC4:
	.string	"\n"
.LC5:
	.string	"\n"
	.text	
	.globl	main
	.type	main, @function
main: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$332, %rsp

	movl	$5, %eax
	movl 	%eax, -44(%rbp)
	movq 	$.LC0, -72(%rbp)
	movl 	-72(%rbp), %eax
	movq 	-72(%rbp), %rdi
call	printStr
	movl	%eax, -76(%rbp)
	movl	$0, %eax
	movl 	%eax, -80(%rbp)
	movl 	-80(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -84(%rbp)
	leaq	-48(%rbp), %rax
	movq 	%rax, -92(%rbp)
	movl 	-92(%rbp), %eax
	movq 	-92(%rbp), %rdi
call	readInt
	movl	%eax, -96(%rbp)
	movq	-96(%rbp), %rdx
	movq	%rdx, -24(%rbp)
	movl	$0, %eax
	movl 	%eax, -112(%rbp)
	movl 	-112(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -116(%rbp)
	movq	-24(%rbp), %rax
	movq 	%rax, -120(%rbp)
	movl 	-120(%rbp), %eax
	movq 	-120(%rbp), %rdi
call	printInt
	movl	%eax, -124(%rbp)
	movq 	$.LC1, -128(%rbp)
	movl 	-128(%rbp), %eax
	movq 	-128(%rbp), %rdi
call	printStr
	movl	%eax, -132(%rbp)
	movl	$1, %eax
	movl 	%eax, -136(%rbp)
	movl 	-136(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -140(%rbp)
	leaq	-52(%rbp), %rax
	movq 	%rax, -144(%rbp)
	movl 	-144(%rbp), %eax
	movq 	-144(%rbp), %rdi
call	readInt
	movl	%eax, -148(%rbp)
	movq	-148(%rbp), %rdx
	movq	%rdx, -28(%rbp)
	movl	$1, %eax
	movl 	%eax, -160(%rbp)
	movl 	-160(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -164(%rbp)
	movq	-28(%rbp), %rax
	movq 	%rax, -168(%rbp)
	movl 	-168(%rbp), %eax
	movq 	-168(%rbp), %rdi
call	printInt
	movl	%eax, -172(%rbp)
	movq 	$.LC2, -176(%rbp)
	movl 	-176(%rbp), %eax
	movq 	-176(%rbp), %rdi
call	printStr
	movl	%eax, -180(%rbp)
	movl	$2, %eax
	movl 	%eax, -184(%rbp)
	movl 	-184(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -188(%rbp)
	leaq	-56(%rbp), %rax
	movq 	%rax, -192(%rbp)
	movl 	-192(%rbp), %eax
	movq 	-192(%rbp), %rdi
call	readInt
	movl	%eax, -196(%rbp)
	movq	-196(%rbp), %rdx
	movq	%rdx, -32(%rbp)
	movl	$2, %eax
	movl 	%eax, -208(%rbp)
	movl 	-208(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -212(%rbp)
	movq	-32(%rbp), %rax
	movq 	%rax, -216(%rbp)
	movl 	-216(%rbp), %eax
	movq 	-216(%rbp), %rdi
call	printInt
	movl	%eax, -220(%rbp)
	movq 	$.LC3, -224(%rbp)
	movl 	-224(%rbp), %eax
	movq 	-224(%rbp), %rdi
call	printStr
	movl	%eax, -228(%rbp)
	movl	$3, %eax
	movl 	%eax, -232(%rbp)
	movl 	-232(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -236(%rbp)
	leaq	-60(%rbp), %rax
	movq 	%rax, -240(%rbp)
	movl 	-240(%rbp), %eax
	movq 	-240(%rbp), %rdi
call	readInt
	movl	%eax, -244(%rbp)
	movq	-244(%rbp), %rdx
	movq	%rdx, -36(%rbp)
	movl	$3, %eax
	movl 	%eax, -256(%rbp)
	movl 	-256(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -260(%rbp)
	movq	-36(%rbp), %rax
	movq 	%rax, -264(%rbp)
	movl 	-264(%rbp), %eax
	movq 	-264(%rbp), %rdi
call	printInt
	movl	%eax, -268(%rbp)
	movq 	$.LC4, -272(%rbp)
	movl 	-272(%rbp), %eax
	movq 	-272(%rbp), %rdi
call	printStr
	movl	%eax, -276(%rbp)
	movl	$4, %eax
	movl 	%eax, -280(%rbp)
	movl 	-280(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -284(%rbp)
	leaq	-64(%rbp), %rax
	movq 	%rax, -288(%rbp)
	movl 	-288(%rbp), %eax
	movq 	-288(%rbp), %rdi
call	readInt
	movl	%eax, -292(%rbp)
	movq	-292(%rbp), %rdx
	movq	%rdx, -40(%rbp)
	movl	$4, %eax
	movl 	%eax, -304(%rbp)
	movl 	-304(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -308(%rbp)
	movq	-40(%rbp), %rax
	movq 	%rax, -312(%rbp)
	movl 	-312(%rbp), %eax
	movq 	-312(%rbp), %rdi
call	printInt
	movl	%eax, -316(%rbp)
	movq 	$.LC5, -320(%rbp)
	movl 	-320(%rbp), %eax
	movq 	-320(%rbp), %rdi
call	printStr
	movl	%eax, -324(%rbp)
	movl	$0, %eax
	movl 	%eax, -328(%rbp)
	movl	-328(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident		"Compiled by 16CS30027"
	.section	.note.GNU-stack,"",@progbits
