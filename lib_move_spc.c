#include <stdlib.h>
#include "lib_move_spc.h"

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
	int vert, i, j, r;
	t_coord pos_bomba;

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
			/* fazer funcao para isso */
			r = rand() % 20;
			if((r > 18) && (bombas->tamanho < 10)){		
				pos_bomba = aliens->atual->u.col->atual->pos;
				pos_bomba.x += 2;
				pos_bomba.y += 3;
				insere_fim_lista(VIVO, BOMBA, pos_bomba, bombas);
				inicializa_atual_fim(bombas);
				inicia_sprite(bombas->atual);
			}
			/*------------------------*/
			if(aliens->atual->u.col->atual->alterna == 1)
				aliens->atual->u.col->atual->alterna = 0;
			else
				aliens->atual->u.col->atual->alterna++;
			incrementa_atual(aliens->atual->u.col);
		}
		incrementa_atual(aliens);
	}
}

void move_canhao(t_lista *canhao, t_lista *tiro, int tecla){
	t_coord pos_tiro;

	if(tecla == KEY_LEFT){
		if(canhao->ini->prox->pos.x > 0){
			move_item(ESQUE, canhao->ini->prox);
			if(canhao->ini->prox->alterna == 1)
				canhao->ini->prox->alterna = 0;
			else
				canhao->ini->prox->alterna++;
		}
	} else if(tecla == KEY_RIGHT){
		if(canhao->ini->prox->pos.x < 100 - 5){
			move_item(DIREITA, canhao->ini->prox);
			if(canhao->ini->prox->alterna == 1)
				canhao->ini->prox->alterna = 0;
			else
				canhao->ini->prox->alterna++;
		}
	} else if(tecla == ' '){
		if(tiro->tamanho < 3){
			inicializa_atual_inicio(canhao);
			pos_tiro = canhao->atual->pos;
			pos_tiro.x += 2;
			pos_tiro.y += -1;
			insere_fim_lista(VIVO, TIRO, pos_tiro, tiro);
			inicializa_atual_fim(tiro);
			inicia_sprite(tiro->atual);
		}
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
				if(tiro->atual->alterna == 1)
					tiro->atual->alterna = 0;
				else
					tiro->atual->alterna++;
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
		r = rand()%100;
		if(r > 98){
			insere_fim_lista(VIVO, NAVE_M, pos, nave_mae);
			inicia_sprite(nave_mae->ini->prox);
		}
	
	} else {
		inicializa_atual_inicio(nave_mae);
		move_item(DIREITA, nave_mae->atual);
		if(nave_mae->atual->alterna == 1)
			nave_mae->atual->alterna = 0;
		else
			nave_mae->atual->alterna++;
		if(nave_mae->atual->pos.x + 6 > 100)
			nave_mae->atual->u.estado = MORTO;
	}
}

