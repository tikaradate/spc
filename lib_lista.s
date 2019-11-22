	.file	"lib_lista.c"
	.text
	.p2align 4,,15
	.globl	inicializa_lista
	.type	inicializa_lista, @function
inicializa_lista:
.LFB41:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	movl	$88, %edi
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	malloc@PLT
	testq	%rax, %rax
	je	.L4
	movl	$88, %edi
	movq	%rax, %rbx
	call	malloc@PLT
	testq	%rax, %rax
	je	.L4
	movq	%rax, 16(%rbp)
	movq	%rax, 8(%rbx)
	movq	%rbx, (%rax)
	movq	$0, 8(%rax)
	movl	$1, %eax
	movq	%rbx, 0(%rbp)
	movq	$0, 8(%rbp)
	movl	$0, 24(%rbp)
	movq	$0, (%rbx)
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
.L4:
	.cfi_restore_state
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE41:
	.size	inicializa_lista, .-inicializa_lista
	.p2align 4,,15
	.globl	lista_vazia
	.type	lista_vazia, @function
lista_vazia:
.LFB42:
	.cfi_startproc
	movl	24(%rdi), %edx
	xorl	%eax, %eax
	testl	%edx, %edx
	sete	%al
	ret
	.cfi_endproc
.LFE42:
	.size	lista_vazia, .-lista_vazia
	.p2align 4,,15
	.globl	destroi_lista
	.type	destroi_lista, @function
destroi_lista:
.LFB43:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movl	24(%rdi), %edx
	movq	(%rdi), %rax
	testl	%edx, %edx
	jle	.L12
	movq	8(%rax), %rdi
	movq	8(%rdi), %rbx
	movq	%rdi, 8(%rbp)
	testq	%rbx, %rbx
	je	.L12
	.p2align 4,,10
	.p2align 3
.L13:
	movq	(%rbx), %rax
	movq	$0, (%rax)
	movq	(%rbx), %rax
	movq	$0, 8(%rax)
	call	free@PLT
	movq	%rbx, 8(%rbp)
	movq	%rbx, %rdi
	movq	8(%rbx), %rbx
	testq	%rbx, %rbx
	jne	.L13
	movq	0(%rbp), %rax
.L12:
	movq	16(%rbp), %rdi
	movq	$0, 8(%rax)
	call	free@PLT
	movq	0(%rbp), %rdi
	call	free@PLT
	movq	$0, 0(%rbp)
	movq	$0, 8(%rbp)
	movq	$0, 16(%rbp)
	movl	$0, 24(%rbp)
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE43:
	.size	destroi_lista, .-destroi_lista
	.p2align 4,,15
	.globl	insere_inicio_lista
	.type	insere_inicio_lista, @function
insere_inicio_lista:
.LFB44:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movl	%edi, %r13d
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movl	$88, %edi
	movl	%esi, %ebp
	movq	%rdx, %r12
	movq	%rcx, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	call	malloc@PLT
	movq	%rax, %rdi
	xorl	%eax, %eax
	testq	%rdi, %rdi
	je	.L19
	movq	(%rbx), %rax
	movl	%r13d, 24(%rdi)
	movq	%r12, 16(%rdi)
	movl	%ebp, 32(%rdi)
	movq	%rax, (%rdi)
	movq	8(%rax), %rax
	movq	%rax, 8(%rdi)
	movq	%rdi, (%rax)
	movq	(%rdi), %rax
	movq	%rdi, 8(%rax)
	addl	$1, 24(%rbx)
	movl	$1, %eax
.L19:
	addq	$8, %rsp
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
	.cfi_endproc
.LFE44:
	.size	insere_inicio_lista, .-insere_inicio_lista
	.p2align 4,,15
	.globl	tamanho_lista
	.type	tamanho_lista, @function
tamanho_lista:
.LFB45:
	.cfi_startproc
	movl	24(%rsi), %eax
	movl	%eax, (%rdi)
	movl	$1, %eax
	ret
	.cfi_endproc
.LFE45:
	.size	tamanho_lista, .-tamanho_lista
	.p2align 4,,15
	.globl	insere_fim_lista
	.type	insere_fim_lista, @function
insere_fim_lista:
.LFB46:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movl	%edi, %r13d
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movl	$88, %edi
	movl	%esi, %ebp
	movq	%rdx, %r12
	movq	%rcx, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	call	malloc@PLT
	movq	%rax, %rdi
	xorl	%eax, %eax
	testq	%rdi, %rdi
	je	.L26
	movq	16(%rbx), %rdx
	movl	%r13d, 24(%rdi)
	movq	%r12, 16(%rdi)
	movl	%ebp, 32(%rdi)
	movq	(%rdx), %rax
	movq	%rdx, 8(%rdi)
	movq	%rax, (%rdi)
	movq	%rdi, 8(%rax)
	movq	8(%rdi), %rax
	movq	%rdi, (%rax)
	addl	$1, 24(%rbx)
	movl	$1, %eax
.L26:
	addq	$8, %rsp
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
	.cfi_endproc
.LFE46:
	.size	insere_fim_lista, .-insere_fim_lista
	.p2align 4,,15
	.globl	insere_ordenado_lista
	.type	insere_ordenado_lista, @function
insere_ordenado_lista:
.LFB47:
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
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movl	24(%rcx), %r14d
	testl	%r14d, %r14d
	je	.L41
	movl	%edi, %ebx
	movl	$88, %edi
	movq	%rcx, %r13
	movq	%rdx, %r12
	movl	%esi, %ebp
	call	malloc@PLT
	testq	%rax, %rax
	je	.L38
	movq	16(%r13), %rdx
	movl	%ebx, 24(%rdx)
	movq	0(%r13), %rdx
	movq	8(%rdx), %r8
	cmpl	24(%r8), %ebx
	movq	%r8, 8(%r13)
	jle	.L35
	.p2align 4,,10
	.p2align 3
.L36:
	movq	8(%r8), %r8
	cmpl	%ebx, 24(%r8)
	jl	.L36
	movq	%r8, 8(%r13)
.L35:
	cmpq	$0, 8(%r8)
	je	.L42
	movq	(%r8), %rdx
	movl	%ebx, 24(%rax)
	movq	%r8, 8(%rax)
	movq	%r12, 16(%rax)
	movl	%ebp, 32(%rax)
	movq	%rdx, (%rax)
	movq	%rax, 8(%rdx)
	movq	8(%rax), %rdx
	movq	%rax, (%rdx)
	leal	1(%r14), %eax
	movl	%eax, 24(%r13)
	movl	$1, %eax
	popq	%rbx
	.cfi_remember_state
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
	.p2align 4,,10
	.p2align 3
.L41:
	.cfi_restore_state
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	jmp	insere_inicio_lista
	.p2align 4,,10
	.p2align 3
.L38:
	.cfi_restore_state
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L42:
	.cfi_restore_state
	movq	%rax, %rdi
	call	free@PLT
	movq	%r13, %rcx
	movq	%r12, %rdx
	movl	%ebp, %esi
	movl	%ebx, %edi
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
	jmp	insere_fim_lista
	.cfi_endproc
.LFE47:
	.size	insere_ordenado_lista, .-insere_ordenado_lista
	.p2align 4,,15
	.globl	remove_inicio_lista
	.type	remove_inicio_lista, @function
remove_inicio_lista:
.LFB48:
	.cfi_startproc
	movl	24(%rsi), %eax
	testl	%eax, %eax
	jne	.L52
	rep ret
	.p2align 4,,10
	.p2align 3
.L52:
	movq	(%rsi), %rdx
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rsi, %rbx
	movq	8(%rdx), %rax
	movq	8(%rax), %rcx
	movq	%rcx, 8(%rsi)
	movl	24(%rax), %ecx
	movl	%ecx, (%rdi)
	movq	$0, 8(%rax)
	movq	8(%rdx), %rdi
	movq	$0, (%rax)
	call	free@PLT
	movq	8(%rbx), %rax
	movq	(%rbx), %rdx
	movq	%rax, 8(%rdx)
	movq	%rdx, (%rax)
	movl	$1, %eax
	subl	$1, 24(%rbx)
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE48:
	.size	remove_inicio_lista, .-remove_inicio_lista
	.p2align 4,,15
	.globl	remove_fim_lista
	.type	remove_fim_lista, @function
remove_fim_lista:
.LFB49:
	.cfi_startproc
	movl	24(%rsi), %eax
	testl	%eax, %eax
	jne	.L62
	rep ret
	.p2align 4,,10
	.p2align 3
.L62:
	movq	16(%rsi), %rdx
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rsi, %rbx
	movq	(%rdx), %rax
	movq	(%rax), %rcx
	movq	%rcx, 8(%rsi)
	movl	24(%rax), %ecx
	movl	%ecx, (%rdi)
	movq	$0, (%rax)
	movq	(%rdx), %rdi
	call	free@PLT
	movq	8(%rbx), %rax
	movq	16(%rbx), %rdx
	movq	%rax, (%rdx)
	movq	%rdx, 8(%rax)
	movl	$1, %eax
	subl	$1, 24(%rbx)
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE49:
	.size	remove_fim_lista, .-remove_fim_lista
	.p2align 4,,15
	.globl	remove_item_lista
	.type	remove_item_lista, @function
remove_item_lista:
.LFB50:
	.cfi_startproc
	movl	24(%rdx), %eax
	testl	%eax, %eax
	je	.L68
	movq	16(%rdx), %rax
	movl	%edi, 24(%rax)
	movq	(%rdx), %rax
	movq	8(%rax), %rax
	movl	24(%rax), %ecx
	movq	%rax, 8(%rdx)
	cmpl	%ecx, %edi
	jle	.L66
	.p2align 4,,10
	.p2align 3
.L67:
	movq	8(%rax), %rax
	movl	24(%rax), %ecx
	cmpl	%edi, %ecx
	jl	.L67
	movq	%rax, 8(%rdx)
.L66:
	movq	8(%rax), %rdi
	testq	%rdi, %rdi
	je	.L68
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdx, %rbx
	movq	(%rax), %rdx
	movl	%ecx, (%rsi)
	movq	%rdi, 8(%rdx)
	movq	8(%rax), %rcx
	movq	%rax, %rdi
	movq	%rdx, (%rcx)
	call	free@PLT
	subl	$1, 24(%rbx)
	movl	$1, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L68:
	.cfi_restore 3
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE50:
	.size	remove_item_lista, .-remove_item_lista
	.p2align 4,,15
	.globl	pertence_lista
	.type	pertence_lista, @function
pertence_lista:
.LFB51:
	.cfi_startproc
	movl	24(%rsi), %eax
	testl	%eax, %eax
	je	.L77
	movq	16(%rsi), %rax
	movl	%edi, 24(%rax)
	movq	(%rsi), %rax
	movq	8(%rax), %rax
	cmpl	24(%rax), %edi
	movq	%rax, 8(%rsi)
	je	.L79
	.p2align 4,,10
	.p2align 3
.L80:
	movq	8(%rax), %rax
	cmpl	%edi, 24(%rax)
	jne	.L80
	movq	%rax, 8(%rsi)
.L79:
	cmpq	$0, 8(%rax)
	setne	%al
	movzbl	%al, %eax
.L77:
	rep ret
	.cfi_endproc
.LFE51:
	.size	pertence_lista, .-pertence_lista
	.p2align 4,,15
	.globl	inicializa_atual_inicio
	.type	inicializa_atual_inicio, @function
inicializa_atual_inicio:
.LFB52:
	.cfi_startproc
	movl	24(%rdi), %eax
	testl	%eax, %eax
	je	.L85
	movq	(%rdi), %rax
	movq	8(%rax), %rax
	movq	%rax, 8(%rdi)
	movl	$1, %eax
.L85:
	rep ret
	.cfi_endproc
.LFE52:
	.size	inicializa_atual_inicio, .-inicializa_atual_inicio
	.p2align 4,,15
	.globl	inicializa_atual_fim
	.type	inicializa_atual_fim, @function
inicializa_atual_fim:
.LFB53:
	.cfi_startproc
	movl	24(%rdi), %eax
	testl	%eax, %eax
	je	.L90
	movq	16(%rdi), %rax
	movq	(%rax), %rax
	movq	%rax, 8(%rdi)
	movl	$1, %eax
.L90:
	rep ret
	.cfi_endproc
.LFE53:
	.size	inicializa_atual_fim, .-inicializa_atual_fim
	.p2align 4,,15
	.globl	incrementa_atual
	.type	incrementa_atual, @function
incrementa_atual:
.LFB54:
	.cfi_startproc
	movq	8(%rdi), %rax
	testq	%rax, %rax
	je	.L95
	movq	8(%rax), %rax
	cmpq	16(%rdi), %rax
	movl	$0, %edx
	cmove	%rdx, %rax
	movq	%rax, 8(%rdi)
.L95:
	rep ret
	.cfi_endproc
.LFE54:
	.size	incrementa_atual, .-incrementa_atual
	.p2align 4,,15
	.globl	decrementa_atual
	.type	decrementa_atual, @function
decrementa_atual:
.LFB55:
	.cfi_startproc
	movq	8(%rdi), %rax
	testq	%rax, %rax
	je	.L101
	movq	(%rax), %rax
	cmpq	(%rdi), %rax
	movl	$0, %edx
	cmove	%rdx, %rax
	movq	%rax, 8(%rdi)
.L101:
	rep ret
	.cfi_endproc
.LFE55:
	.size	decrementa_atual, .-decrementa_atual
	.p2align 4,,15
	.globl	consulta_item_atual
	.type	consulta_item_atual, @function
consulta_item_atual:
.LFB56:
	.cfi_startproc
	movq	8(%rsi), %rdx
	xorl	%eax, %eax
	testq	%rdx, %rdx
	je	.L107
	movl	24(%rdx), %eax
	movl	%eax, (%rdi)
	movl	$1, %eax
.L107:
	rep ret
	.cfi_endproc
.LFE56:
	.size	consulta_item_atual, .-consulta_item_atual
	.p2align 4,,15
	.globl	remove_item_atual
	.type	remove_item_atual, @function
remove_item_atual:
.LFB57:
	.cfi_startproc
	movl	24(%rsi), %eax
	testl	%eax, %eax
	je	.L119
	movq	8(%rsi), %rdx
	xorl	%eax, %eax
	testq	%rdx, %rdx
	je	.L119
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	24(%rdx), %eax
	movq	%rsi, %rbx
	movq	8(%rdx), %rcx
	movl	%eax, (%rdi)
	movq	(%rdx), %rax
	movq	%rdx, %rdi
	movq	%rcx, 8(%rax)
	movq	8(%rdx), %rcx
	movq	%rax, (%rcx)
	call	free@PLT
	subl	$1, 24(%rbx)
	movl	$1, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L119:
	.cfi_restore 3
	rep ret
	.cfi_endproc
.LFE57:
	.size	remove_item_atual, .-remove_item_atual
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
