#include <stdio.h>
#include "lib_lista_complementar.h"

void imprime_lista(t_lista *l){
	if(!lista_vazia(l)){
		int i, tam, atual;
	
		inicializa_atual_inicio(l);
		tamanho_lista(&tam, l);
		for(i = 0; i < tam; i++){
			consulta_item_atual(&atual, l);
			printf("%d ", atual);
			incrementa_atual(l);
		}
		printf("\n");
	}
}

int copia_lista(t_lista *l, t_lista *c){
	int i, tam, atual;

	if(lista_vazia(l))
		return 0;

	destroi_lista(c);
	inicializa_lista(c);	
	inicializa_atual_inicio(l);
	tamanho_lista(&tam, l);
	for(i = 0; i < tam; i++){
		consulta_item_atual(&atual, l);
		insere_fim_lista(atual, c);
		incrementa_atual(l);
	}

	return 1;
}

int concatena_listas(t_lista *l, t_lista *m){
	int i, tam, atual;

	if(lista_vazia(m))
		return 0;
	
	inicializa_atual_inicio(m);
	tamanho_lista(&tam, m);
	for(i = 0; i < tam; i++){
		consulta_item_atual(&atual, m);
		insere_fim_lista(atual, l);
		incrementa_atual(m);
	}
	destroi_lista(m);

	return 1;
}

int ordena_lista(t_lista *l){
	if(lista_vazia(l))
		return 0;
		
	int i, tam, atual;
	t_lista aux;
	
	inicializa_lista(&aux);
	inicializa_atual_inicio(l);
	tamanho_lista(&tam, l);
	for(i = 0; i < tam ; i++){
		consulta_item_atual(&atual, l);
		insere_ordenado_lista(atual, &aux);
		incrementa_atual(l);
	}

	copia_lista(&aux, l);
	destroi_lista(&aux);
	return 1;
}

int intercala_listas(t_lista *l, t_lista *m, t_lista *i){
	int tam1, tam2, p, item1, item2;
	
	inicializa_lista(i);
	inicializa_atual_inicio(l);
	inicializa_atual_inicio(m);
	tamanho_lista(&tam1, l);
	tamanho_lista(&tam2, m);

	if(tam1 > tam2){
		for(p = 0; p < tam2 ; p++){
			consulta_item_atual(&item1, l);	
			consulta_item_atual(&item2, m);
			insere_fim_lista(item1, i);
			insere_fim_lista(item2, i);
			incrementa_atual(l);
			incrementa_atual(m);
		}

		for(p = 0; p < tam1 - tam2; p++){
			consulta_item_atual(&item1, l);
			insere_fim_lista(item1, i);
			incrementa_atual(l);
		}
		return 1;
	}

	for(p = 0; p < tam1; p++){
		consulta_item_atual(&item1, l);	
		consulta_item_atual(&item2, m);
		insere_fim_lista(item1, i);
		insere_fim_lista(item2, i);
		incrementa_atual(l);
		incrementa_atual(m);
	}

	for(p = 0; p < tam2 - tam1; p++){
		consulta_item_atual(&item1, m);
		insere_fim_lista(item1, i);
		incrementa_atual(m);
		}
	return 1;
	
}
