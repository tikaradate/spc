	.file	"spc.c"
	.text
	.p2align 4,,15
	.globl	desenha_item
	.type	desenha_item, @function
desenha_item:
.LFB65:
	.cfi_startproc
	movl	36(%rdi), %eax
	testl	%eax, %eax
	jle	.L6
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	xorl	%r12d, %r12d
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	xorl	%ebp, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %rbx
	.p2align 4,,10
	.p2align 3
.L3:
	movslq	40(%rbx), %rax
	movl	20(%rbx), %edi
	movl	16(%rbx), %esi
	addl	%ebp, %edi
	addl	$1, %ebp
	leaq	(%rax,%rax,4), %rdx
	leaq	44(%rax,%rdx,4), %rdx
	xorl	%eax, %eax
	addq	%r12, %rdx
	addq	$7, %r12
	addq	%rbx, %rdx
	call	mvprintw@PLT
	cmpl	%ebp, 36(%rbx)
	jg	.L3
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	rep ret
	.cfi_endproc
.LFE65:
	.size	desenha_item, .-desenha_item
	.p2align 4,,15
	.globl	inicia_sprite
	.type	inicia_sprite, @function
inicia_sprite:
.LFB66:
	.cfi_startproc
	movl	32(%rdi), %eax
	movl	$0, 40(%rdi)
	cmpl	$300, %eax
	je	.L12
	jle	.L19
	cmpl	$500, %eax
	je	.L16
	cmpl	$600, %eax
	je	.L17
	cmpl	$400, %eax
	je	.L20
	rep ret
	.p2align 4,,10
	.p2align 3
.L19:
	cmpl	$100, %eax
	je	.L14
	cmpl	$200, %eax
	jne	.L21
	movl	$97, %eax
	movl	$1, 36(%rdi)
	movw	%ax, 44(%rdi)
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	movl	$42, %r10d
	movl	$48, %r11d
	movl	$1, 36(%rdi)
	movw	%r10w, 44(%rdi)
	movw	%r11w, 65(%rdi)
	ret
	.p2align 4,,10
	.p2align 3
.L20:
	movl	$59, %eax
	movl	$1, 36(%rdi)
	movw	%ax, 44(%rdi)
	movl	$105, %eax
	movw	%ax, 65(%rdi)
	ret
	.p2align 4,,10
	.p2align 3
.L21:
	rep ret
	.p2align 4,,10
	.p2align 3
.L12:
	movl	$32, %eax
	movl	$113, %edx
	movl	$2, 36(%rdi)
	movw	%ax, 48(%rdi)
	movl	$100, %eax
	movl	$1985377824, 44(%rdi)
	movw	%ax, 55(%rdi)
	movl	$32, %eax
	movl	$1852730978, 51(%rdi)
	movl	$1450595872, 65(%rdi)
	movw	%ax, 69(%rdi)
	movl	$1835887984, 72(%rdi)
	movw	%dx, 76(%rdi)
	ret
	.p2align 4,,10
	.p2align 3
.L14:
	movl	$97, %ecx
	movl	$65, %esi
	movl	$99, %r8d
	movl	$65, %r9d
	movl	$3, 36(%rdi)
	movl	$543236193, 44(%rdi)
	movw	%cx, 48(%rdi)
	movl	$1092632864, 51(%rdi)
	movb	$0, 55(%rdi)
	movl	$1092632897, 58(%rdi)
	movw	%si, 62(%rdi)
	movl	$543367267, 65(%rdi)
	movw	%r8w, 69(%rdi)
	movl	$757083424, 72(%rdi)
	movb	$0, 76(%rdi)
	movl	$1025523009, 79(%rdi)
	movw	%r9w, 83(%rdi)
	ret
	.p2align 4,,10
	.p2align 3
.L17:
	movl	$24897, %eax
	movl	$16737, %edx
	movl	$24897, %ecx
	movl	$16737, %esi
	movl	$24897, %r8d
	movl	$16737, %r9d
	movl	$3, 36(%rdi)
	movl	$1631674689, 44(%rdi)
	movw	%ax, 48(%rdi)
	movb	$0, 50(%rdi)
	movl	$1096892769, 51(%rdi)
	movw	%dx, 55(%rdi)
	movb	$0, 57(%rdi)
	movl	$1631674689, 58(%rdi)
	movw	%cx, 62(%rdi)
	movb	$0, 64(%rdi)
	movl	$1096892769, 65(%rdi)
	movw	%si, 69(%rdi)
	movb	$0, 71(%rdi)
	movl	$1631674689, 72(%rdi)
	movw	%r8w, 76(%rdi)
	movb	$0, 78(%rdi)
	movl	$1096892769, 79(%rdi)
	movw	%r9w, 83(%rdi)
	movb	$0, 85(%rdi)
	ret
	.cfi_endproc
.LFE66:
	.size	inicia_sprite, .-inicia_sprite
	.p2align 4,,15
	.globl	inicializa_aliens
	.type	inicializa_aliens, @function
inicializa_aliens:
.LFB63:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movabsq	$107374182400, %r13
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movl	$5, %r12d
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	%rdi, %rbx
	call	inicializa_lista@PLT
	.p2align 4,,10
	.p2align 3
.L24:
	movl	%r12d, %ebp
	movq	%rbx, %rcx
	xorl	%esi, %esi
	movq	%rbp, %rdx
	xorl	%edi, %edi
	orq	%r13, %rdx
	call	insere_fim_lista@PLT
	movq	%rbx, %rdi
	call	inicializa_atual_fim@PLT
	movq	8(%rbx), %r14
	movl	$32, %edi
	call	malloc@PLT
	movq	%rax, %rdi
	movq	%rax, 24(%r14)
	movl	$5, %r14d
	call	inicializa_lista@PLT
.L23:
	movq	8(%rbx), %rax
	movq	%r14, %rdx
	movl	$100, %esi
	salq	$32, %rdx
	movl	$2, %edi
	addl	$4, %r14d
	orq	%rbp, %rdx
	movq	24(%rax), %rcx
	call	insere_fim_lista@PLT
	movq	8(%rbx), %rax
	movq	24(%rax), %rax
	movq	16(%rax), %rax
	movq	(%rax), %rdi
	call	inicia_sprite
	cmpl	$25, %r14d
	jne	.L23
	addl	$6, %r12d
	cmpl	$71, %r12d
	jne	.L24
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE63:
	.size	inicializa_aliens, .-inicializa_aliens
	.p2align 4,,15
	.globl	inicializa_barreiras
	.type	inicializa_barreiras, @function
inicializa_barreiras:
.LFB64:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movl	$20, %r14d
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	call	inicializa_lista@PLT
.L32:
	movabsq	$128849018880, %rax
	movl	%r14d, %edx
	movq	%rbx, %rcx
	orq	%rax, %rdx
	xorl	%esi, %esi
	xorl	%edi, %edi
	call	insere_fim_lista@PLT
	movq	%rbx, %rdi
	leal	7(%r14), %r13d
	movl	%r14d, %ebp
	call	inicializa_atual_fim@PLT
	movq	8(%rbx), %r12
	movl	$32, %edi
	call	malloc@PLT
	movq	%rax, %rdi
	movq	%rax, 24(%r12)
	call	inicializa_lista@PLT
	.p2align 4,,10
	.p2align 3
.L29:
	movl	$27, %r15d
	movl	%ebp, %r12d
.L30:
	movq	8(%rbx), %rax
	movq	%r15, %rdx
	movl	$200, %esi
	salq	$32, %rdx
	movl	$2, %edi
	addl	$1, %r15d
	orq	%r12, %rdx
	movq	24(%rax), %rcx
	call	insere_fim_lista@PLT
	movq	8(%rbx), %rax
	movq	24(%rax), %rax
	movq	16(%rax), %rax
	movq	(%rax), %rdi
	call	inicia_sprite
	cmpl	$30, %r15d
	jne	.L30
	addl	$1, %ebp
	cmpl	%r13d, %ebp
	jne	.L29
	addl	$20, %r14d
	cmpl	$100, %r14d
	jne	.L32
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE64:
	.size	inicializa_barreiras, .-inicializa_barreiras
	.p2align 4,,15
	.globl	desenha_barreiras
	.type	desenha_barreiras, @function
desenha_barreiras:
.LFB67:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rdi, %rbp
	movq	stdscr(%rip), %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	xorl	%edx, %edx
	movl	$768, %esi
	call	wattr_on@PLT
	movq	%rbp, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%rbp), %esi
	testl	%esi, %esi
	jle	.L37
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L41:
	movq	8(%rbp), %rax
	movq	24(%rax), %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%rbp), %rdx
	movq	24(%rdx), %rax
	movl	24(%rax), %ecx
	testl	%ecx, %ecx
	jle	.L38
	xorl	%ebx, %ebx
	jmp	.L40
	.p2align 4,,10
	.p2align 3
.L39:
	movq	24(%rdx), %rax
	addl	$1, %ebx
	cmpl	%ebx, 24(%rax)
	jle	.L38
.L40:
	movq	8(%rax), %rdi
	cmpl	$2, 24(%rdi)
	jne	.L39
	call	desenha_item
	movq	8(%rbp), %rax
	addl	$1, %ebx
	movq	24(%rax), %rdi
	call	incrementa_atual@PLT
	movq	8(%rbp), %rdx
	movq	24(%rdx), %rax
	cmpl	%ebx, 24(%rax)
	jg	.L40
	.p2align 4,,10
	.p2align 3
.L38:
	movq	%rbp, %rdi
	addl	$1, %r12d
	call	incrementa_atual@PLT
	cmpl	%r12d, 24(%rbp)
	jg	.L41
.L37:
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	movq	stdscr(%rip), %rdi
	xorl	%edx, %edx
	movl	$768, %esi
	jmp	wattr_off@PLT
	.cfi_endproc
.LFE67:
	.size	desenha_barreiras, .-desenha_barreiras
	.p2align 4,,15
	.globl	desenha_aliens
	.type	desenha_aliens, @function
desenha_aliens:
.LFB68:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rdi, %rbp
	movq	stdscr(%rip), %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	xorl	%edx, %edx
	movl	$1024, %esi
	call	wattr_on@PLT
	movq	%rbp, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%rbp), %esi
	testl	%esi, %esi
	jle	.L46
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L50:
	movq	8(%rbp), %rax
	movq	24(%rax), %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%rbp), %rdx
	movq	24(%rdx), %rax
	movl	24(%rax), %ecx
	testl	%ecx, %ecx
	jle	.L47
	xorl	%ebx, %ebx
	jmp	.L49
	.p2align 4,,10
	.p2align 3
.L48:
	movq	24(%rdx), %rax
	addl	$1, %ebx
	cmpl	%ebx, 24(%rax)
	jle	.L47
.L49:
	movq	8(%rax), %rdi
	cmpl	$2, 24(%rdi)
	jne	.L48
	call	desenha_item
	movq	8(%rbp), %rax
	addl	$1, %ebx
	movq	24(%rax), %rdi
	call	incrementa_atual@PLT
	movq	8(%rbp), %rdx
	movq	24(%rdx), %rax
	cmpl	%ebx, 24(%rax)
	jg	.L49
	.p2align 4,,10
	.p2align 3
.L47:
	movq	%rbp, %rdi
	addl	$1, %r12d
	call	incrementa_atual@PLT
	cmpl	%r12d, 24(%rbp)
	jg	.L50
.L46:
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	movq	stdscr(%rip), %rdi
	xorl	%edx, %edx
	movl	$1024, %esi
	jmp	wattr_off@PLT
	.cfi_endproc
.LFE68:
	.size	desenha_aliens, .-desenha_aliens
	.p2align 4,,15
	.globl	move_item
	.type	move_item, @function
move_item:
.LFB70:
	.cfi_startproc
	cmpl	$-1, %edi
	je	.L56
	jle	.L61
	cmpl	$1, %edi
	je	.L59
	cmpl	$2, %edi
	jne	.L62
	addl	$1, 20(%rsi)
	ret
	.p2align 4,,10
	.p2align 3
.L59:
	addl	$1, 16(%rsi)
	ret
	.p2align 4,,10
	.p2align 3
.L61:
	cmpl	$-2, %edi
	jne	.L63
	subl	$1, 20(%rsi)
	ret
	.p2align 4,,10
	.p2align 3
.L56:
	subl	$1, 16(%rsi)
	ret
	.p2align 4,,10
	.p2align 3
.L62:
	rep ret
	.p2align 4,,10
	.p2align 3
.L63:
	rep ret
	.cfi_endproc
.LFE70:
	.size	move_item, .-move_item
	.p2align 4,,15
	.globl	move_aliens
	.type	move_aliens, @function
move_aliens:
.LFB69:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdx, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rcx, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	movq	%rdx, %rdi
	movq	%rsi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	call	inicializa_atual_inicio@PLT
	movq	(%r15), %rax
	movq	8(%rax), %rax
	movq	24(%rax), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movl	16(%rax), %esi
	testl	%esi, %esi
	jle	.L77
	movq	16(%r15), %rax
	xorl	%r12d, %r12d
	movq	(%rax), %rax
	movq	24(%rax), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	cmpl	$94, 16(%rax)
	jg	.L78
.L66:
	movl	24(%r15), %ecx
	testl	%ecx, %ecx
	jle	.L64
	xorl	%r14d, %r14d
	.p2align 4,,10
	.p2align 3
.L72:
	movq	8(%r15), %rax
	movq	24(%rax), %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%r15), %rax
	movq	24(%rax), %rax
	movl	24(%rax), %edx
	testl	%edx, %edx
	jle	.L68
	xorl	%ebx, %ebx
	jmp	.L71
	.p2align 4,,10
	.p2align 3
.L70:
	call	incrementa_atual@PLT
	movq	8(%r15), %rax
	addl	$1, %ebx
	movq	24(%rax), %rax
	cmpl	%ebx, 24(%rax)
	jle	.L68
.L71:
	movq	8(%rax), %rsi
	movl	0(%rbp), %edi
	call	move_item
	movq	8(%r15), %rax
	movl	%r12d, %edi
	movq	24(%rax), %rax
	movq	8(%rax), %rsi
	call	move_item
	call	rand@PLT
	movl	$1717986919, %edx
	movl	%eax, %ecx
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movq	8(%r15), %rax
	cmpl	$9, %ecx
	movq	24(%rax), %rdi
	jne	.L70
	cmpl	$9, 24(%r13)
	jg	.L70
	movq	8(%rdi), %rax
	movl	$500, %esi
	movl	$2, %edi
	movl	20(%rax), %edx
	movl	16(%rax), %ecx
	addl	$3, %edx
	movq	%rdx, %rax
	leal	2(%rcx), %edx
	movq	%r13, %rcx
	salq	$32, %rax
	orq	%rax, %rdx
	call	insere_fim_lista@PLT
	movq	%r13, %rdi
	call	inicializa_atual_fim@PLT
	movq	8(%r13), %rdi
	call	inicia_sprite
	movq	8(%r15), %rax
	movq	24(%rax), %rdi
	jmp	.L70
	.p2align 4,,10
	.p2align 3
.L68:
	movq	%r15, %rdi
	addl	$1, %r14d
	call	incrementa_atual@PLT
	cmpl	%r14d, 24(%r15)
	jg	.L72
.L64:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L78:
	.cfi_restore_state
	movl	$-1, 0(%rbp)
	movl	$2, %r12d
	subl	$5, (%rbx)
	jmp	.L66
	.p2align 4,,10
	.p2align 3
.L77:
	movl	$1, 0(%rbp)
	movl	$2, %r12d
	subl	$5, (%rbx)
	jmp	.L66
	.cfi_endproc
.LFE69:
	.size	move_aliens, .-move_aliens
	.p2align 4,,15
	.globl	inicializa_tiro
	.type	inicializa_tiro, @function
inicializa_tiro:
.LFB71:
	.cfi_startproc
	jmp	inicializa_lista@PLT
	.cfi_endproc
.LFE71:
	.size	inicializa_tiro, .-inicializa_tiro
	.p2align 4,,15
	.globl	desenha_tiro
	.type	desenha_tiro, @function
desenha_tiro:
.LFB72:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	xorl	%edx, %edx
	movl	$512, %esi
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	stdscr(%rip), %rdi
	call	wattr_on@PLT
	movq	%rbp, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%rbp), %eax
	testl	%eax, %eax
	jle	.L81
	xorl	%ebx, %ebx
	jmp	.L83
	.p2align 4,,10
	.p2align 3
.L82:
	addl	$1, %ebx
	cmpl	%ebx, 24(%rbp)
	jle	.L81
.L83:
	movq	8(%rbp), %rdi
	cmpl	$2, 24(%rdi)
	jne	.L82
	call	desenha_item
	movq	%rbp, %rdi
	addl	$1, %ebx
	call	incrementa_atual@PLT
	cmpl	%ebx, 24(%rbp)
	jg	.L83
.L81:
	movq	stdscr(%rip), %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	xorl	%edx, %edx
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	movl	$512, %esi
	jmp	wattr_off@PLT
	.cfi_endproc
.LFE72:
	.size	desenha_tiro, .-desenha_tiro
	.p2align 4,,15
	.globl	desenha_bombas
	.type	desenha_bombas, @function
desenha_bombas:
.LFB73:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	xorl	%edx, %edx
	movl	$1280, %esi
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	stdscr(%rip), %rdi
	call	wattr_on@PLT
	movq	%rbp, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%rbp), %eax
	testl	%eax, %eax
	jle	.L87
	xorl	%ebx, %ebx
	jmp	.L89
	.p2align 4,,10
	.p2align 3
.L88:
	addl	$1, %ebx
	cmpl	%ebx, 24(%rbp)
	jle	.L87
.L89:
	movq	8(%rbp), %rdi
	cmpl	$2, 24(%rdi)
	jne	.L88
	call	desenha_item
	movq	%rbp, %rdi
	addl	$1, %ebx
	call	incrementa_atual@PLT
	cmpl	%ebx, 24(%rbp)
	jg	.L89
.L87:
	movq	stdscr(%rip), %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	xorl	%edx, %edx
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	movl	$1280, %esi
	jmp	wattr_off@PLT
	.cfi_endproc
.LFE73:
	.size	desenha_bombas, .-desenha_bombas
	.p2align 4,,15
	.globl	move_tiro
	.type	move_tiro, @function
move_tiro:
.LFB74:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %rbx
	call	lista_vazia@PLT
	testl	%eax, %eax
	je	.L100
.L92:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L100:
	.cfi_restore_state
	movq	%rbx, %rdi
	movl	%eax, %ebp
	call	inicializa_atual_inicio@PLT
	movl	24(%rbx), %eax
	testl	%eax, %eax
	jle	.L92
	xorl	%r12d, %r12d
	jmp	.L97
	.p2align 4,,10
	.p2align 3
.L94:
	movl	40(%rax), %ecx
	subl	$1, %edx
	movl	%edx, 20(%rax)
	leal	1(%rcx), %edx
	cmpl	$1, %ecx
	cmove	%r12d, %edx
	movl	%edx, 40(%rax)
.L95:
	movq	%rbx, %rdi
	addl	$1, %ebp
	call	incrementa_atual@PLT
	cmpl	24(%rbx), %ebp
	jge	.L92
.L97:
	movq	8(%rbx), %rax
	movl	20(%rax), %edx
	testl	%edx, %edx
	jg	.L94
	movl	$0, 24(%rax)
	jmp	.L95
	.cfi_endproc
.LFE74:
	.size	move_tiro, .-move_tiro
	.p2align 4,,15
	.globl	move_bombas
	.type	move_bombas, @function
move_bombas:
.LFB75:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	lista_vazia@PLT
	testl	%eax, %eax
	je	.L107
.L101:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L107:
	.cfi_restore_state
	movq	%rbx, %rdi
	movl	%eax, %ebp
	call	inicializa_atual_inicio@PLT
	movl	24(%rbx), %eax
	testl	%eax, %eax
	jle	.L101
	.p2align 4,,10
	.p2align 3
.L104:
	movq	8(%rbx), %rdx
	movl	20(%rdx), %eax
	addl	$1, %eax
	cmpl	$37, %eax
	movl	%eax, 20(%rdx)
	jle	.L103
	movl	$0, 24(%rdx)
.L103:
	movq	%rbx, %rdi
	addl	$1, %ebp
	call	incrementa_atual@PLT
	cmpl	24(%rbx), %ebp
	jl	.L104
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE75:
	.size	move_bombas, .-move_bombas
	.p2align 4,,15
	.globl	move_nave_mae
	.type	move_nave_mae, @function
move_nave_mae:
.LFB76:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	lista_vazia@PLT
	testl	%eax, %eax
	je	.L109
	call	rand@PLT
	movl	$1374389535, %edx
	movl	%eax, %ecx
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$5, %edx
	subl	%eax, %edx
	imull	$100, %edx, %edx
	subl	%edx, %ecx
	cmpl	$95, %ecx
	jg	.L115
.L108:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L109:
	.cfi_restore_state
	movq	%rbx, %rdi
	movl	%eax, %ebp
	call	inicializa_atual_inicio@PLT
	movq	8(%rbx), %rax
	movl	16(%rax), %esi
	movl	40(%rax), %ecx
	leal	1(%rsi), %edx
	leal	1(%rcx), %esi
	cmpl	$1, %ecx
	cmovne	%esi, %ebp
	cmpl	$94, %edx
	movl	%edx, 16(%rax)
	movl	%ebp, 40(%rax)
	jle	.L108
	movl	$0, 24(%rax)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L115:
	.cfi_restore_state
	movq	%rbx, %rcx
	movl	$2, %edi
	movabsq	$4294967297, %rdx
	movl	$600, %esi
	call	insere_fim_lista@PLT
	movq	(%rbx), %rax
	movq	8(%rax), %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	inicia_sprite
	.cfi_endproc
.LFE76:
	.size	move_nave_mae, .-move_nave_mae
	.p2align 4,,15
	.globl	inicializa_bombas
	.type	inicializa_bombas, @function
inicializa_bombas:
.LFB97:
	.cfi_startproc
	jmp	inicializa_lista@PLT
	.cfi_endproc
.LFE97:
	.size	inicializa_bombas, .-inicializa_bombas
	.p2align 4,,15
	.globl	inicializa_nave_mae
	.type	inicializa_nave_mae, @function
inicializa_nave_mae:
.LFB99:
	.cfi_startproc
	jmp	inicializa_lista@PLT
	.cfi_endproc
.LFE99:
	.size	inicializa_nave_mae, .-inicializa_nave_mae
	.p2align 4,,15
	.globl	inicializa_canhao
	.type	inicializa_canhao, @function
inicializa_canhao:
.LFB79:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	call	inicializa_lista@PLT
	movq	%rbx, %rcx
	movl	$2, %edi
	movabsq	$154618822704, %rdx
	movl	$300, %esi
	call	insere_fim_lista@PLT
	movq	(%rbx), %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	movq	8(%rax), %rdi
	jmp	inicia_sprite
	.cfi_endproc
.LFE79:
	.size	inicializa_canhao, .-inicializa_canhao
	.p2align 4,,15
	.globl	desenha_canhao
	.type	desenha_canhao, @function
desenha_canhao:
.LFB80:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	call	inicializa_atual_inicio@PLT
	movq	stdscr(%rip), %rdi
	xorl	%edx, %edx
	movl	$256, %esi
	call	wattr_on@PLT
	movq	8(%rbx), %rdi
	call	desenha_item
	popq	%rbx
	.cfi_def_cfa_offset 8
	movq	stdscr(%rip), %rdi
	xorl	%edx, %edx
	movl	$256, %esi
	jmp	wattr_off@PLT
	.cfi_endproc
.LFE80:
	.size	desenha_canhao, .-desenha_canhao
	.p2align 4,,15
	.globl	desenha_nave_mae
	.type	desenha_nave_mae, @function
desenha_nave_mae:
.LFB81:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	call	lista_vazia@PLT
	testl	%eax, %eax
	je	.L125
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L125:
	.cfi_restore_state
	movq	%rbx, %rdi
	call	inicializa_atual_inicio@PLT
	movq	stdscr(%rip), %rdi
	xorl	%edx, %edx
	movl	$1536, %esi
	call	wattr_on@PLT
	movq	8(%rbx), %rdi
	call	desenha_item
	popq	%rbx
	.cfi_def_cfa_offset 8
	movq	stdscr(%rip), %rdi
	xorl	%edx, %edx
	movl	$1536, %esi
	jmp	wattr_off@PLT
	.cfi_endproc
.LFE81:
	.size	desenha_nave_mae, .-desenha_nave_mae
	.p2align 4,,15
	.globl	move_canhao
	.type	move_canhao, @function
move_canhao:
.LFB82:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	movq	%rdx, %rdi
	movq	%rsi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	wgetch@PLT
	cmpl	$260, %eax
	je	.L134
	cmpl	$261, %eax
	je	.L135
	cmpl	$32, %eax
	je	.L136
.L126:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L135:
	.cfi_restore_state
	movq	(%rbx), %rax
	movq	8(%rax), %rax
	movl	16(%rax), %edx
	cmpl	$94, %edx
	jg	.L126
	addl	$1, %edx
	jmp	.L133
	.p2align 4,,10
	.p2align 3
.L134:
	movq	(%rbx), %rax
	movq	8(%rax), %rax
	movl	16(%rax), %edx
	testl	%edx, %edx
	jle	.L126
	subl	$1, %edx
.L133:
	movl	40(%rax), %ecx
	movl	%edx, 16(%rax)
	movl	$0, %edx
	leal	1(%rcx), %esi
	cmpl	$1, %ecx
	cmovne	%esi, %edx
	movl	%edx, 40(%rax)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L136:
	.cfi_restore_state
	cmpl	$2, 24(%rbp)
	jg	.L126
	movq	%rbx, %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%rbx), %rax
	movl	$400, %esi
	movl	$2, %edi
	movl	20(%rax), %edx
	movl	16(%rax), %ecx
	subl	$1, %edx
	movq	%rdx, %rax
	leal	2(%rcx), %edx
	movq	%rbp, %rcx
	salq	$32, %rax
	orq	%rax, %rdx
	call	insere_fim_lista@PLT
	movq	%rbp, %rdi
	call	inicializa_atual_fim@PLT
	movq	8(%rbp), %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	inicia_sprite
	.cfi_endproc
.LFE82:
	.size	move_canhao, .-move_canhao
	.p2align 4,,15
	.globl	detecta_colisoes
	.type	detecta_colisoes, @function
detecta_colisoes:
.LFB83:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rcx, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbp
	movq	%rsi, %r12
	movq	%rdx, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	%r8, 8(%rsp)
	call	inicializa_atual_inicio@PLT
	movl	24(%rbp), %eax
	testl	%eax, %eax
	jle	.L138
	movl	$0, 4(%rsp)
	.p2align 4,,10
	.p2align 3
.L144:
	movq	%r12, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%r12), %eax
	testl	%eax, %eax
	jle	.L139
	xorl	%r14d, %r14d
	.p2align 4,,10
	.p2align 3
.L143:
	movq	8(%r12), %rax
	movq	24(%rax), %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%r12), %rdx
	movq	24(%rdx), %rax
	movl	24(%rax), %r15d
	testl	%r15d, %r15d
	jle	.L140
	xorl	%r15d, %r15d
	.p2align 4,,10
	.p2align 3
.L142:
	movq	8(%rbp), %rdi
	movq	8(%rax), %r8
	movl	16(%rdi), %esi
	movl	16(%r8), %eax
	cmpl	%eax, %esi
	jl	.L141
	addl	$4, %eax
	cmpl	%eax, %esi
	jg	.L141
	movl	20(%rdi), %esi
	movl	20(%r8), %eax
	cmpl	%eax, %esi
	jl	.L141
	addl	$2, %eax
	cmpl	%eax, %esi
	jg	.L141
	movl	$0, 24(%rdi)
	movq	24(%rdx), %rax
	movq	8(%rax), %rax
	movl	$0, 24(%rax)
	.p2align 4,,10
	.p2align 3
.L141:
	movq	24(%rdx), %rdi
	addl	$1, %r15d
	call	incrementa_atual@PLT
	movq	8(%r12), %rdx
	movq	24(%rdx), %rax
	cmpl	%r15d, 24(%rax)
	jg	.L142
.L140:
	movq	%r12, %rdi
	addl	$1, %r14d
	call	incrementa_atual@PLT
	cmpl	%r14d, 24(%r12)
	jg	.L143
.L139:
	movq	%rbp, %rdi
	call	incrementa_atual@PLT
	addl	$1, 4(%rsp)
	movl	4(%rsp), %eax
	cmpl	%eax, 24(%rbp)
	jg	.L144
.L138:
	movq	%rbp, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%rbp), %r12d
	testl	%r12d, %r12d
	jle	.L145
	xorl	%r14d, %r14d
	.p2align 4,,10
	.p2align 3
.L151:
	movq	%rbx, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%rbx), %r11d
	testl	%r11d, %r11d
	jle	.L146
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L150:
	movq	8(%rbx), %rax
	movq	24(%rax), %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%rbx), %rax
	movq	24(%rax), %rdx
	movl	24(%rdx), %r10d
	testl	%r10d, %r10d
	jle	.L147
	xorl	%r15d, %r15d
	.p2align 4,,10
	.p2align 3
.L149:
	movq	8(%rbp), %rcx
	movq	8(%rdx), %rdx
	movq	16(%rdx), %rsi
	cmpq	%rsi, 16(%rcx)
	jne	.L148
	movl	$0, 24(%rcx)
	movq	24(%rax), %rdx
	movq	8(%rdx), %rdx
	movl	$0, 24(%rdx)
.L148:
	movq	24(%rax), %rdi
	addl	$1, %r15d
	call	incrementa_atual@PLT
	movq	8(%rbx), %rax
	movq	24(%rax), %rdx
	cmpl	%r15d, 24(%rdx)
	jg	.L149
.L147:
	movq	%rbx, %rdi
	addl	$1, %r12d
	call	incrementa_atual@PLT
	cmpl	%r12d, 24(%rbx)
	jg	.L150
.L146:
	movq	%rbp, %rdi
	addl	$1, %r14d
	call	incrementa_atual@PLT
	cmpl	%r14d, 24(%rbp)
	jg	.L151
.L145:
	movq	%rbp, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%rbp), %r9d
	testl	%r9d, %r9d
	jle	.L152
	xorl	%r14d, %r14d
	.p2align 4,,10
	.p2align 3
.L156:
	movq	%r13, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%r13), %r8d
	testl	%r8d, %r8d
	jle	.L153
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L155:
	movq	8(%rbp), %rdx
	movq	8(%r13), %rax
	movq	16(%rax), %rcx
	cmpq	%rcx, 16(%rdx)
	jne	.L154
	movl	$0, 24(%rdx)
	movl	$0, 24(%rax)
.L154:
	movq	%r13, %rdi
	addl	$1, %r12d
	call	incrementa_atual@PLT
	cmpl	%r12d, 24(%r13)
	jg	.L155
.L153:
	movq	%rbp, %rdi
	addl	$1, %r14d
	call	incrementa_atual@PLT
	cmpl	%r14d, 24(%rbp)
	jg	.L156
.L152:
	movq	%r13, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%r13), %edi
	testl	%edi, %edi
	jle	.L157
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L163:
	movq	%rbx, %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%rbx), %esi
	testl	%esi, %esi
	jle	.L158
	xorl	%ebp, %ebp
	.p2align 4,,10
	.p2align 3
.L162:
	movq	8(%rbx), %rax
	movq	24(%rax), %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%rbx), %rax
	movq	24(%rax), %rdx
	movl	24(%rdx), %ecx
	testl	%ecx, %ecx
	jle	.L159
	xorl	%r14d, %r14d
	.p2align 4,,10
	.p2align 3
.L161:
	movq	8(%r13), %rcx
	movq	8(%rdx), %rdx
	movq	16(%rdx), %rsi
	cmpq	%rsi, 16(%rcx)
	jne	.L160
	movl	$0, 24(%rcx)
	movq	24(%rax), %rdx
	movq	8(%rdx), %rdx
	movl	$0, 24(%rdx)
.L160:
	movq	24(%rax), %rdi
	addl	$1, %r14d
	call	incrementa_atual@PLT
	movq	8(%rbx), %rax
	movq	24(%rax), %rdx
	cmpl	%r14d, 24(%rdx)
	jg	.L161
.L159:
	movq	%rbx, %rdi
	addl	$1, %ebp
	call	incrementa_atual@PLT
	cmpl	%ebp, 24(%rbx)
	jg	.L162
.L158:
	movq	%r13, %rdi
	addl	$1, %r12d
	call	incrementa_atual@PLT
	cmpl	%r12d, 24(%r13)
	jg	.L163
.L157:
	movq	%r13, %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%rsp), %rdi
	call	inicializa_atual_inicio@PLT
	movl	24(%r13), %eax
	testl	%eax, %eax
	jle	.L137
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L166:
	movq	8(%rsp), %rax
	movq	8(%r13), %rsi
	movq	8(%rax), %rcx
	movl	16(%rsi), %edx
	movl	16(%rcx), %eax
	cmpl	%eax, %edx
	jl	.L165
	addl	$4, %eax
	cmpl	%eax, %edx
	jg	.L165
	movl	20(%rsi), %edx
	movl	20(%rcx), %eax
	cmpl	%eax, %edx
	jl	.L165
	addl	$1, %eax
	cmpl	%eax, %edx
	jg	.L165
	movl	$0, 24(%rsi)
	movl	$0, 24(%rcx)
	.p2align 4,,10
	.p2align 3
.L165:
	movq	%r13, %rdi
	addl	$1, %ebx
	call	incrementa_atual@PLT
	cmpl	%ebx, 24(%r13)
	jg	.L166
.L137:
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE83:
	.size	detecta_colisoes, .-detecta_colisoes
	.p2align 4,,15
	.globl	remove_bombas
	.type	remove_bombas, @function
remove_bombas:
.LFB84:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	xorl	%r12d, %r12d
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	%rdi, %rbx
	subq	$16, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	inicializa_atual_inicio@PLT
	movl	24(%rbx), %ecx
	testl	%ecx, %ecx
	jle	.L180
	xorl	%ebp, %ebp
	leaq	4(%rsp), %r14
	jmp	.L184
	.p2align 4,,10
	.p2align 3
.L189:
	movq	%rbx, %rsi
	movq	%r14, %rdi
	movq	8(%rax), %r13
	addl	$2, %r12d
	addl	$1, %ebp
	call	remove_item_atual@PLT
	cmpl	%ebp, 24(%rbx)
	movq	%r13, 8(%rbx)
	jle	.L180
.L184:
	movq	8(%rbx), %rax
	movl	24(%rax), %edx
	testl	%edx, %edx
	je	.L189
	movq	%rbx, %rdi
	addl	$1, %ebp
	call	incrementa_atual@PLT
	cmpl	%ebp, 24(%rbx)
	jg	.L184
.L180:
	movq	8(%rsp), %rdx
	xorq	%fs:40, %rdx
	movl	%r12d, %eax
	jne	.L190
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L190:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE84:
	.size	remove_bombas, .-remove_bombas
	.p2align 4,,15
	.globl	remove_tiro
	.type	remove_tiro, @function
remove_tiro:
.LFB85:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	inicializa_atual_inicio@PLT
	movl	24(%rbx), %ecx
	testl	%ecx, %ecx
	jle	.L191
	xorl	%ebp, %ebp
	leaq	4(%rsp), %r13
	jmp	.L195
	.p2align 4,,10
	.p2align 3
.L199:
	movq	%rbx, %rsi
	movq	%r13, %rdi
	movq	8(%rax), %r12
	addl	$1, %ebp
	call	remove_item_atual@PLT
	cmpl	%ebp, 24(%rbx)
	movq	%r12, 8(%rbx)
	jle	.L191
.L195:
	movq	8(%rbx), %rax
	movl	24(%rax), %edx
	testl	%edx, %edx
	je	.L199
	movq	%rbx, %rdi
	addl	$1, %ebp
	call	incrementa_atual@PLT
	cmpl	%ebp, 24(%rbx)
	jg	.L195
.L191:
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L200
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L200:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE85:
	.size	remove_tiro, .-remove_tiro
	.p2align 4,,15
	.globl	remove_barreiras
	.type	remove_barreiras, @function
remove_barreiras:
.LFB86:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subq	$16, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	inicializa_atual_inicio@PLT
	movl	24(%rbp), %esi
	testl	%esi, %esi
	jle	.L201
	leaq	4(%rsp), %r13
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L207:
	movq	8(%rbp), %rax
	movq	24(%rax), %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%rbp), %rax
	movq	24(%rax), %rsi
	movl	24(%rsi), %ecx
	testl	%ecx, %ecx
	jle	.L203
	xorl	%ebx, %ebx
	jmp	.L206
	.p2align 4,,10
	.p2align 3
.L212:
	movq	%r13, %rdi
	movq	8(%rax), %r14
	addl	$1, %ebx
	call	remove_item_atual@PLT
	movq	8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%r14, 8(%rax)
	movq	8(%rbp), %rax
	movq	24(%rax), %rsi
	cmpl	%ebx, 24(%rsi)
	jle	.L203
.L206:
	movq	8(%rsi), %rax
	movl	24(%rax), %edx
	testl	%edx, %edx
	je	.L212
	movq	%rsi, %rdi
	addl	$1, %ebx
	call	incrementa_atual@PLT
	movq	8(%rbp), %rax
	movq	24(%rax), %rsi
	cmpl	%ebx, 24(%rsi)
	jg	.L206
.L203:
	movq	%rbp, %rdi
	addl	$1, %r12d
	call	incrementa_atual@PLT
	cmpl	%r12d, 24(%rbp)
	jg	.L207
.L201:
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L213
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L213:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE86:
	.size	remove_barreiras, .-remove_barreiras
	.p2align 4,,15
	.globl	remove_aliens
	.type	remove_aliens, @function
remove_aliens:
.LFB87:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r14
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	xorl	%ebp, %ebp
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	inicializa_atual_inicio@PLT
	movl	24(%r14), %r8d
	testl	%r8d, %r8d
	jle	.L215
	leaq	4(%rsp), %r13
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L220:
	movq	8(%r14), %rax
	movq	24(%rax), %rdi
	call	inicializa_atual_inicio@PLT
	movq	8(%r14), %rax
	movq	24(%rax), %rsi
	movl	24(%rsi), %edi
	testl	%edi, %edi
	jle	.L216
	xorl	%ebx, %ebx
	jmp	.L219
	.p2align 4,,10
	.p2align 3
.L228:
	movq	%r13, %rdi
	movq	8(%rax), %r15
	addl	$10, %ebp
	call	remove_item_atual@PLT
	movq	8(%r14), %rax
	addl	$1, %ebx
	movq	24(%rax), %rax
	movq	%r15, 8(%rax)
	movq	8(%r14), %rax
	movq	24(%rax), %rsi
	cmpl	%ebx, 24(%rsi)
	jle	.L216
.L219:
	movq	8(%rsi), %rax
	movl	24(%rax), %ecx
	testl	%ecx, %ecx
	je	.L228
	movq	%rsi, %rdi
	addl	$1, %ebx
	call	incrementa_atual@PLT
	movq	8(%r14), %rax
	movq	24(%rax), %rsi
	cmpl	%ebx, 24(%rsi)
	jg	.L219
.L216:
	movq	%r14, %rdi
	addl	$1, %r12d
	call	incrementa_atual@PLT
	cmpl	%r12d, 24(%r14)
	jg	.L220
.L215:
	movq	(%r14), %rax
	movq	8(%rax), %rax
	movq	24(%rax), %rdi
	movl	24(%rdi), %edx
	testl	%edx, %edx
	je	.L229
.L221:
	movq	16(%r14), %rax
	movq	(%rax), %rax
	movq	24(%rax), %rdi
	movl	24(%rdi), %eax
	testl	%eax, %eax
	jne	.L214
	call	destroi_lista@PLT
	leaq	4(%rsp), %rdi
	movq	%r14, %rsi
	call	remove_fim_lista@PLT
.L214:
	movq	8(%rsp), %rdx
	xorq	%fs:40, %rdx
	movl	%ebp, %eax
	jne	.L230
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L229:
	.cfi_restore_state
	call	destroi_lista@PLT
	leaq	4(%rsp), %rdi
	movq	%r14, %rsi
	call	remove_inicio_lista@PLT
	jmp	.L221
.L230:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE87:
	.size	remove_aliens, .-remove_aliens
	.p2align 4,,15
	.globl	remove_nave_mae
	.type	remove_nave_mae, @function
remove_nave_mae:
.LFB88:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	xorl	%ebx, %ebx
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	lista_vazia@PLT
	testl	%eax, %eax
	je	.L237
.L231:
	movq	8(%rsp), %rdx
	xorq	%fs:40, %rdx
	movl	%ebx, %eax
	jne	.L238
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L237:
	.cfi_restore_state
	movq	%rbp, %rdi
	movl	%eax, %ebx
	call	inicializa_atual_inicio@PLT
	movq	8(%rbp), %rax
	movl	24(%rax), %eax
	testl	%eax, %eax
	jne	.L231
	leaq	4(%rsp), %rdi
	movq	%rbp, %rsi
	movl	$50, %ebx
	call	remove_item_atual@PLT
	jmp	.L231
.L238:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE88:
	.size	remove_nave_mae, .-remove_nave_mae
	.p2align 4,,15
	.globl	remove_morto
	.type	remove_morto, @function
remove_morto:
.LFB89:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rdx, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rcx, %r12
	movq	%rsi, %rbx
	movq	%r8, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	call	remove_tiro
	movq	%r13, %rdi
	call	remove_barreiras
	movq	%rbx, %rdi
	call	remove_aliens
	movq	%r12, %rdi
	movl	%eax, %ebx
	call	remove_bombas
	movq	%rbp, %rdi
	addl	%eax, %ebx
	call	remove_nave_mae
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	addl	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE89:
	.size	remove_morto, .-remove_morto
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Tamanho do terminal insuficiente\nTente pelo menos 38x100"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%d"
.LC2:
	.string	"fim de jogo\np = %d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB90:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$280, %rsp
	.cfi_def_cfa_offset 336
	movq	%fs:40, %rax
	movq	%rax, 264(%rsp)
	xorl	%eax, %eax
	call	initscr@PLT
	movq	stdscr(%rip), %rax
	testq	%rax, %rax
	je	.L242
	cmpw	$36, 4(%rax)
	jle	.L242
	cmpw	$98, 6(%rax)
	jle	.L242
	call	cbreak@PLT
	call	noecho@PLT
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	xorl	%esi, %esi
	xorl	%edi, %edi
	leaq	64(%rsp), %r15
	leaq	224(%rsp), %r14
	call	newwin@PLT
	movl	$1, %esi
	movq	%rax, %rbx
	movq	%rax, %rdi
	movq	%rax, 24(%rsp)
	leaq	128(%rsp), %rbp
	leaq	192(%rsp), %r13
	call	nodelay@PLT
	movl	$1, %esi
	movq	%rbx, %rdi
	leaq	160(%rsp), %r12
	call	keypad@PLT
	xorl	%edi, %edi
	call	curs_set@PLT
	call	start_color@PLT
	xorl	%edi, %edi
	movl	$30, %ecx
	movl	$30, %edx
	movl	$30, %esi
	call	init_color@PLT
	movl	$800, %ecx
	movl	$800, %edx
	movl	$400, %esi
	movl	$11, %edi
	call	init_color@PLT
	movl	$700, %ecx
	movl	$900, %edx
	movl	$200, %esi
	movl	$12, %edi
	call	init_color@PLT
	movl	$500, %ecx
	movl	$1000, %edx
	movl	$200, %esi
	movl	$13, %edi
	call	init_color@PLT
	movl	$200, %ecx
	movl	$320, %edx
	movl	$1000, %esi
	movl	$14, %edi
	call	init_color@PLT
	movl	$200, %ecx
	movl	$800, %edx
	movl	$1000, %esi
	movl	$15, %edi
	call	init_color@PLT
	movl	$200, %ecx
	movl	$200, %edx
	movl	$1000, %esi
	movl	$16, %edi
	call	init_color@PLT
	xorl	%edx, %edx
	movl	$11, %esi
	movl	$1, %edi
	call	init_pair@PLT
	xorl	%edx, %edx
	movl	$12, %esi
	movl	$2, %edi
	call	init_pair@PLT
	xorl	%edx, %edx
	movl	$13, %esi
	movl	$3, %edi
	call	init_pair@PLT
	xorl	%edx, %edx
	movl	$14, %esi
	movl	$4, %edi
	call	init_pair@PLT
	xorl	%edx, %edx
	movl	$15, %esi
	movl	$5, %edi
	call	init_pair@PLT
	xorl	%edx, %edx
	movl	$16, %esi
	movl	$6, %edi
	call	init_pair@PLT
	xorl	%edi, %edi
	xorl	%ebx, %ebx
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movq	%r15, %rdi
	call	inicializa_aliens
	leaq	96(%rsp), %rax
	movq	%rax, %rdi
	movq	%rax, 16(%rsp)
	call	inicializa_canhao
	movq	%r14, %rdi
	call	inicializa_lista@PLT
	movq	%rbp, %rdi
	call	inicializa_lista@PLT
	movq	%r13, %rdi
	call	inicializa_lista@PLT
	movq	%r12, %rdi
	call	inicializa_barreiras
	leaq	56(%rsp), %rax
	movl	$1, 56(%rsp)
	movl	$200, 60(%rsp)
	movl	$0, 12(%rsp)
	movq	%rax, 32(%rsp)
	leaq	60(%rsp), %rax
	movq	%rax, 40(%rsp)
	jmp	.L252
	.p2align 4,,10
	.p2align 3
.L246:
	movl	$1374389535, %eax
	mull	%ebx
	shrl	$6, %edx
	imull	$200, %edx, %edx
	cmpl	%edx, %ebx
	je	.L259
.L247:
	movl	$274877907, %eax
	mull	%ebx
	shrl	$5, %edx
	imull	$500, %edx, %edx
	cmpl	%edx, %ebx
	je	.L260
.L248:
	movl	$458129845, %edx
	movl	%ebx, %eax
	mull	%edx
	shrl	$3, %edx
	imull	$75, %edx, %edx
	cmpl	%edx, %ebx
	je	.L261
.L249:
	movq	16(%rsp), %r8
	movq	%r14, %r9
	movq	%r13, %rcx
	movq	%r12, %rdx
	movq	%r15, %rsi
	movq	%rbp, %rdi
	call	detecta_colisoes
	movq	%r14, %r8
	movq	%r13, %rcx
	movq	%r12, %rdx
	movq	%r15, %rsi
	movq	%rbp, %rdi
	call	remove_morto
	addl	%eax, 12(%rsp)
	leaq	.LC1(%rip), %rdx
	movl	$50, %esi
	movl	12(%rsp), %ecx
	xorl	%edi, %edi
	xorl	%eax, %eax
	call	mvprintw@PLT
	movq	%rbp, %rdi
	call	desenha_tiro
	movq	%r13, %rdi
	call	desenha_bombas
	movq	%r12, %rdi
	call	desenha_barreiras
	movq	16(%rsp), %rdi
	call	desenha_canhao
	movq	%r15, %rdi
	call	desenha_aliens
	movq	%r12, %rdi
	call	desenha_barreiras
	movq	%r14, %rdi
	call	desenha_nave_mae
	movq	96(%rsp), %rax
	movq	8(%rax), %rax
	movl	24(%rax), %eax
	testl	%eax, %eax
	je	.L262
	movq	stdscr(%rip), %rdi
	call	wrefresh@PLT
	leal	1(%rbx), %eax
	cmpl	$1001, %ebx
	movl	$500, %edi
	movl	$1, %ebx
	cmovl	%eax, %ebx
	call	usleep@PLT
.L252:
	movq	stdscr(%rip), %rdi
	call	werase@PLT
	movq	24(%rsp), %rdx
	movq	16(%rsp), %rdi
	movq	%rbp, %rsi
	call	move_canhao
	movl	%ebx, %eax
	cltd
	idivl	60(%rsp)
	testl	%edx, %edx
	jne	.L246
	movq	32(%rsp), %rsi
	movq	40(%rsp), %rdi
	movq	%r13, %rcx
	movq	%r15, %rdx
	call	move_aliens
	jmp	.L246
	.p2align 4,,10
	.p2align 3
.L261:
	movq	%r14, %rdi
	call	move_nave_mae
	jmp	.L249
	.p2align 4,,10
	.p2align 3
.L260:
	movq	%r13, %rdi
	call	move_bombas
	jmp	.L248
	.p2align 4,,10
	.p2align 3
.L259:
	movq	%rbp, %rdi
	call	move_tiro
	jmp	.L247
.L262:
	call	endwin@PLT
	movl	12(%rsp), %edx
	leaq	.LC2(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
.L245:
	xorl	%eax, %eax
	movq	264(%rsp), %rsi
	xorq	%fs:40, %rsi
	jne	.L263
	addq	$280, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L242:
	.cfi_restore_state
	call	endwin@PLT
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	jmp	.L245
.L263:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE90:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
