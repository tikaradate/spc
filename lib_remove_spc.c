#include "lib_remove_spc.h"

/* o estado morrendo eh usado para contar os pontos adequadamente */

int remove_morto(t_lista *aliens, t_lista *tiros, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae){
	int score;

	score = 0;
	remove_tiros(tiros);
	remove_barreiras(barreiras);
	
	score += remove_aliens(aliens);
	score += remove_bombas(bombas);
	score += remove_nave_mae(nave_mae);

	return score;
}

int remove_bombas(t_lista *bombas){
	int i, lixo, score;
	t_nodo *aux;

	score = 0;
	inicializa_atual_inicio(bombas);
	for(i = 0; i < bombas->tamanho; i++){
		if(bombas->atual->u.estado == MORTO){
			aux = bombas->atual->prox;
			remove_item_atual(&lixo, bombas);
			bombas->atual = aux;
		} else if(bombas->atual->u.estado == MORRENDO){
			score += 2;
			bombas->atual->u.estado = MORTO;
		}
			incrementa_atual(bombas);
	}
	return score;
}

void remove_tiros(t_lista *tiros){
	int i, lixo;
	t_nodo *aux;

	inicializa_atual_inicio(tiros);
	for(i = 0; i < tiros->tamanho; i++){
		if(tiros->atual->u.estado == MORTO){
			aux = tiros->atual->prox;
			remove_item_atual(&lixo, tiros);
			tiros->atual = aux;
		} else {
			incrementa_atual(tiros);
		}
	}	
}

void remove_barreiras(t_lista *barreiras){
	int i, j, lixo;
	t_nodo *aux;

	inicializa_atual_inicio(barreiras);
	for(i = 0; i < barreiras->tamanho; i++){

		inicializa_atual_inicio(barreiras->atual->u.col);
		for(j = 0; j < barreiras->atual->u.col->tamanho; j++){
			if(barreiras->atual->u.col->atual->u.estado == MORTO){
				aux = barreiras->atual->u.col->atual->prox;
				remove_item_atual(&lixo, barreiras->atual->u.col);
				barreiras->atual->u.col->atual = aux;
			} else {
				incrementa_atual(barreiras->atual->u.col);
			}
		}
		incrementa_atual(barreiras);
	}
}

int remove_aliens(t_lista *aliens){
	int i, j, lixo, score;
	t_nodo *aux;

	score = 0;
	inicializa_atual_inicio(aliens);
	for(i = 0; i < aliens->tamanho; i++){

		inicializa_atual_inicio(aliens->atual->u.col);
		for(j = 0; j < aliens->atual->u.col->tamanho; j++){
			if(aliens->atual->u.col->atual->u.estado == MORTO){
				aux = aliens->atual->u.col->atual->prox;
				remove_item_atual(&lixo, aliens->atual->u.col);
				aliens->atual->u.col->atual = aux;
			} else if(aliens->atual->u.col->atual->u.estado == MORRENDO){
				score += 10;
				aliens->atual->u.col->atual->u.estado = MORTO;
			} else {
				incrementa_atual(aliens->atual->u.col);
			}
		}

		incrementa_atual(aliens);
	}

/* remove a lista do comeco ou do fim se estiverem vazias */
	if(aliens->tamanho != 0){
		if(aliens->ini->prox->u.col->tamanho == 0){
			destroi_lista(aliens->ini->prox->u.col);
			remove_inicio_lista(&lixo, aliens);
		}
	}
	if(aliens->tamanho != 0){
		if(aliens->fim->prev->u.col->tamanho == 0){
			destroi_lista(aliens->fim->prev->u.col);
			remove_fim_lista(&lixo, aliens);
		}
	}

	return score;
}

int remove_nave_mae(t_lista *nave_mae){
	int lixo;
	
	if(!lista_vazia(nave_mae)){

		inicializa_atual_inicio(nave_mae);
		if(nave_mae->atual->u.estado == MORTO)
			remove_item_atual(&lixo, nave_mae);

		else if(nave_mae->atual->u.estado == MORRENDO){
			nave_mae->atual->u.estado = MORTO;
			return 50;
		}
	}
	return 0;
}
