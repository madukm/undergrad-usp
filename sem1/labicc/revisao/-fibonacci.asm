	.file	"fibonacci.c"
	.text
	.globl	fib
	.type	fib, @function
fib:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	cmpq	$1, -24(%rbp)
	jne	.L4
	movl	$1, %eax
	jmp	.L3
.L4:
	movq	-24(%rbp), %rax
	subq	$1, %rax
	movq	%rax, %rdi
	call	fib
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	subq	$2, %rax
	movq	%rax, %rdi
	call	fib
	addq	%rbx, %rax
.L3:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	fib, .-fib
	.section	.rodata
.LC0:
	.string	"%llu"
.LC1:
	.string	"Fibonacci(%llu) = %llu\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fib
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-10ubuntu2~18.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
