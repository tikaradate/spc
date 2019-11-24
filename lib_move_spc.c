#include <stdlib.h>
#include "lib_move_spc.h"
#include "lib_ini_spc.h"

void move_item(int sentido, t_nodo *item){
	switch(sentido){
		case DIREITA:
			item->pos.x++;
			break;
		case ESQUE:
			item->pos.x--;
			break;
		case BAIXO:
			item->pos.y++;
			break;
		case CIMA:
			item->pos.y--;
			break;
	}
}
void move_aliens(int *velocidade, int *direcao, t_lista *aliens, t_lista *bombas){
	int vert, i, j;

	inicializa_atual_inicio(aliens);
	vert = 0;
	if(aliens->ini->prox->u.col->ini->prox->pos.x - 1< 0){
		*direcao = DIREITA;  /* inverte sentido do movimento horizontal */
		vert = BAIXO;
		if(*velocidade - 7 > 0){
			*velocidade -= 7;
		}
	} 
		else if(aliens->fim->prev->u.col->ini->prox->pos.x + 1 > 100 - 5){
		*direcao = ESQUE;
		vert = BAIXO;
		if(*velocidade - 7 > 0){
			*velocidade -= 7;
		}
	}

	for(i = 0; i < aliens->tamanho; i++){
		inicializa_atual_inicio(aliens->atual->u.col);	
		for(j = 0; j < aliens->atual->u.col->tamanho; j++){
			move_item(*direcao, aliens->atual->u.col->atual);
			move_item(vert, aliens->atual->u.col->atual);
			alterna_sprite(aliens->atual->u.col->atual);
			nova_bomba(bombas, aliens->atual->u.col->atual->pos);
			incrementa_atual(aliens->atual->u.col);
		}
		incrementa_atual(aliens);
	}
}

void move_canhao(t_lista *canhao, t_lista *tiro, int tecla){
	
	inicializa_atual_inicio(canhao);
	if(tecla == KEY_LEFT || tecla == 'a'){
		if(canhao->atual->pos.x > 0){
			move_item(ESQUE, canhao->atual);
			alterna_sprite(canhao->atual);
		}
 	} else if(tecla == KEY_RIGHT || tecla == 'd'){
		if(canhao->atual->pos.x < 100 - 5){
			move_item(DIREITA, canhao->atual);
			alterna_sprite(canhao->atual);
		}
	} else if(tecla == ' ' || tecla == KEY_UP){
		novo_tiro(tiro, canhao->atual->pos);
	}
}

void move_tiro(t_lista *tiro){
	if(!lista_vazia(tiro)){
		int i, aux;

		inicializa_atual_inicio(tiro);
		for(i = 0; i < tiro->tamanho; i++){
			if(tiro->atual->pos.y - 1 < 0){
				tiro->atual->u.estado = MORTO;
			} else {
				move_item(CIMA, tiro->atual);
				alterna_sprite(tiro->atual);
			}
			incrementa_atual(tiro);
		}
	}
}

void move_bombas(t_lista *bombas){
	if(!lista_vazia(bombas)){
		int i;

		inicializa_atual_inicio(bombas);
		for(i = 0; i < bombas->tamanho; i++){
			move_item(BAIXO, bombas->atual);
			if(bombas->atual->pos.y + 1 > 38)
				bombas->atual->u.estado = MORTO;
			incrementa_atual(bombas);
		}
	}
}

void move_nave_mae(t_lista *nave_mae){
	int r;
	t_coord pos;

	if(lista_vazia(nave_mae)){
		pos.x = 1;
		pos.y = 1;
		r = rand() % 100 + 1;
		if(r > 99){
			insere_fim_lista(VIVO, NAVE_M, pos, nave_mae);
			inicializa_atual_inicio(nave_mae);
			inicia_sprite(nave_mae->atual);
		}
	
	} else {
		inicializa_atual_inicio(nave_mae);
		if(nave_mae->atual->pos.x + 6 > 100){
			nave_mae->atual->u.estado = MORTO;
		} else {
			move_item(DIREITA, nave_mae->atual);
			alterna_sprite(nave_mae->atual);
		}
	}
}
