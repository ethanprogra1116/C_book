	.file	"variables.c"
	.text
	.section	.rodata
.LC0:
	.string	"Este string no es modificable"
	.align 8
.LC1:
	.string	"String modificable %s\nString no modificable%s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	$10, -4(%rbp)
	movl	$100, -8(%rbp)
	movl	$1000, -12(%rbp)
	movabsq	$8315087661994635080, %rax
	movabsq	$7956016061199967604, %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movabsq	$7237123112350064743, %rax
	movabsq	$7308324465734674025, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movb	$0, -32(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 14.2.0-19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
