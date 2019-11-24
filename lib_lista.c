#include <stdio.h>
#include <stdlib.h>
#include "lib_lista.h"

int inicializa_lista(t_lista *l){
	t_nodo *ini, *fim;
	
	ini = (t_nodo *) malloc(1 * sizeof(t_nodo));
	if(ini == NULL)
		return 0;
	
	fim = (t_nodo *) malloc(1 * sizeof(t_nodo));
	if(fim == NULL)
		return 0;
		
	l->ini = ini;
	l->atual = NULL;
	l->fim = fim;
	l->tamanho = 0;

	ini->prev = NULL;
	ini->prox = fim;

	fim->prev = ini;
	fim->prox = NULL;
	
	return 1;
}

int lista_vazia(t_lista *l){
	return(l->tamanho == 0);
}

void destroi_lista(t_lista *l){
	t_nodo *aux;

/* vai liberando 1 a 1, usando um auxiliar para nao perder posicao */	
	if(l->tamanho > 0){
		l->atual = l->ini->prox;
		while(l->atual->prox != NULL){
			aux = l->atual->prox;
			aux->prev->prev = NULL;
			aux->prev->prox = NULL;
			free(l->atual);
			l->atual = aux;
		}
		aux = NULL;
	}

	l->ini->prox = NULL;
	l->fim->prev = NULL;
	free(l->fim);
	free(l->ini);
	l->ini = NULL;
	l->atual = NULL;
	l->fim = NULL;
	l->tamanho = 0;
}

int insere_inicio_lista(int estado, int tipo, t_coord pos, t_lista *l){
	t_nodo *novo;
	
	novo = (t_nodo*) malloc(1 * sizeof(t_nodo));
	if(novo == NULL)
		return 0;
	
	novo->u.estado = estado;
	novo->pos = pos;
	novo->tipo = tipo;
	novo->prev = l->ini;
	novo->prox = l->ini->prox;
	novo->prox->prev = novo;
	novo->prev->prox = novo;
	
	l->tamanho++;
	return 1;
}

int tamanho_lista(int *tam, t_lista *l){
	*tam = l->tamanho;
	return 1;
}

int insere_fim_lista(int estado, int tipo, t_coord pos, t_lista *l){
	t_nodo *novo;

	novo = (t_nodo *) malloc(1 * sizeof(t_nodo));
	if(novo == NULL)
		return 0;

	novo->u.estado = estado;
	novo->pos = pos;
	novo->tipo = tipo;
	novo->prev = l->fim->prev;
	novo->prox = l->fim;
	novo->prev->prox = novo;
	novo->prox->prev = novo;
	
	l->tamanho++;
	return 1;
}

int insere_ordenado_lista(int estado, int tipo, t_coord pos, t_lista *l){
	t_nodo *novo;

	if(lista_vazia(l))
		return(insere_inicio_lista(estado, tipo, pos, l));	

	novo = (t_nodo *) malloc(1 * sizeof(t_nodo));
	if(novo == NULL)
		return 0;

	/* sentinela */
	l->fim->u.estado = estado;

	l->atual = l->ini->prox;
	while(l->atual->u.estado < estado)
		l->atual = l->atual->prox;
	
	if(l->atual->prox == NULL){
		free(novo);
		return(insere_fim_lista(estado, tipo, pos, l));
	}
			
	novo->u.estado = estado;
	novo->pos = pos;
	novo->tipo = tipo;
	novo->prev = l->atual->prev;
	novo->prox = l->atual;

	novo->prev->prox = novo;
	novo->prox->prev = novo;

	l->tamanho++;
	return 1;
}

int remove_inicio_lista(int *estado, t_lista *l){
	if(lista_vazia(l))
		return 0;
	
	l->atual = l->ini->prox->prox;
	
	*estado = l->ini->prox->u.estado;

	l->ini->prox->prev = NULL;
	l->ini->prox->prox = NULL;
	
	free(l->ini->prox);
	l->ini->prox = l->atual;
	l->atual->prev = l->ini;
	
	l->tamanho--;

	return 1;
}

int remove_fim_lista(int *estado, t_lista *l){
	if(lista_vazia(l))
		return 0;

	l->atual = l->fim->prev->prev;

	*estado = l->fim->prev->u.estado;

	l->fim->prev->prev = NULL;
	l->fim->prev->prox = NULL;

	free(l->fim->prev);

	l->fim->prev = l->atual;
	l->atual->prox = l->fim;

	l->tamanho--;

	return 1;
}

int remove_item_lista(int chave, int *estado, t_lista *l){
	if(lista_vazia(l))
		return 0;

	l->fim->u.estado = chave;
	l->atual = l->ini->prox;
	while(l->atual->u.estado < chave)
		l->atual = l->atual->prox;

	if(l->atual->prox == NULL)
		return 0;
	
	*estado = l->atual->u.estado;
	l->atual->prev->prox = l->atual->prox;
	l->atual->prox->prev = l->atual->prev;
	free(l->atual);
	l->tamanho--;
	
	return 1;
}

int pertence_lista(int chave, t_lista *l){
	if(lista_vazia(l))
		return 0;

	l->fim->u.estado = chave;
	l->atual = l->ini->prox;
	while(l->atual->u.estado != chave)
		l->atual = l->atual->prox;
	
	if(l->atual->prox == NULL)
		return 0;
		
	return 1;
}

int inicializa_atual_inicio(t_lista *l){
	if(lista_vazia(l))
		return 0;

	l->atual = l->ini->prox;
	return 1;
}

int inicializa_atual_fim(t_lista *l){
	if(lista_vazia(l))
		return 0;

	l->atual = l->fim->prev;
	return 1;
}

void incrementa_atual(t_lista *l){
	if(l->atual == NULL)
		return;
	if(l->atual->prox == l->fim){
		l->atual = NULL;
		return;
	}

	l->atual = l->atual->prox;
}

void decrementa_atual(t_lista *l){
	if(l->atual == NULL)
		return;
	if(l->atual->prev == l->ini){
		l->atual = NULL;
		return;
	}

	l->atual = l->atual->prev;
}

int consulta_item_atual(int *item, t_lista *l){
	if(l->atual == NULL)
		return 0;
	
	*item = l->atual->u.estado;
	return 1;
}

int remove_item_atual(int *item, t_lista *l){
	if(lista_vazia(l) || l->atual == NULL)
		return 0;

	*item = l->atual->u.estado;
	l->atual->prev->prox = l->atual->prox;
	l->atual->prox->prev = l->atual->prev;
	free(l->atual);
	l->tamanho--;
	
	return 1;
}
