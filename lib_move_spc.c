#include <stdlib.h>
#include "lib_controle_spc.h"
#include "lib_move_spc.h"

void move_item(int sentido, t_nodo *item){
	switch(sentido){
		case DIREITA:
			item->pos.x++;
			break;
		case ESQUERDA:
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
	vert = NEUTRO;

/* checa se os aliens bateram na borda da direita ou da esquerda
utilizando-se da lista de listas, onde uma lista vazia eh retirada
de tal forma que atualiza a primeira e ultima coluna */

	if(aliens->ini->prox->u.col->ini->prox->pos.x - 2 < 0){
		*direcao = DIREITA; 
		vert = BAIXO;
		if(*velocidade - 7 > 0){
			*velocidade -= 7;
		}
	} 
		else if(aliens->fim->prev->u.col->ini->prox->pos.x + 2 > MIN_X - 5){
		*direcao = ESQUERDA;
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

void move_canhao(t_lista *canhao, t_lista *tiros, int tecla){
	
	inicializa_atual_inicio(canhao);
	if(tecla == KEY_LEFT || tecla == 'a'){
		if(canhao->atual->pos.x > 0){
			move_item(ESQUERDA, canhao->atual);
			alterna_sprite(canhao->atual);
		}
 	} else if(tecla == KEY_RIGHT || tecla == 'd'){
		if(canhao->atual->pos.x < 100 - 5){
			move_item(DIREITA, canhao->atual);
			alterna_sprite(canhao->atual);
		}
	} else if(tecla == KEY_UP || tecla == ' '){
		novo_tiro(tiros, canhao->atual->pos);
	}
}

void move_tiro(t_lista *tiros){
	if(!lista_vazia(tiros)){
		int i;

		inicializa_atual_inicio(tiros);
		for(i = 0; i < tiros->tamanho; i++){
			if(tiros->atual->pos.y - 2 < 0){
				tiros->atual->u.estado = MORTO;
			} else {
				move_item(CIMA, tiros->atual);
				alterna_sprite(tiros->atual);
			}
			incrementa_atual(tiros);
		}
	}
}

void move_bomba(t_lista *bombas){
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
		r = rand() % 200 + 1;
		if(r > NAVE_M_CHANCE){
			insere_fim_lista(VIVO, NAVE_M, pos, nave_mae);
			inicializa_atual_inicio(nave_mae);
			inicia_sprite(nave_mae->atual);
		}
	
	} else {
		inicializa_atual_inicio(nave_mae);
		if(nave_mae->atual->pos.x + 7 > 100){
			nave_mae->atual->u.estado = MORTO;
		} else {
			move_item(DIREITA, nave_mae->atual);
			alterna_sprite(nave_mae->atual);
		}
	}
}

/* velocidade calculada com o mod de certos numeros, desta forma apenas movendo em tempos especificos */
void movimentacao(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *bombas, t_lista *nave_mae, int cont, int *dir, int *v_alien, int tecla){
	move_canhao(canhao, tiros, tecla);

	if(cont % *v_alien == 0){
		move_aliens(v_alien, dir, aliens, bombas);
	}
	if(cont % V_TIRO == 0){
		move_tiro(tiros);
	}
	if(cont % V_BOMBA == 0){
		move_bomba(bombas);
	}
	if(cont % V_NAVE_M == 0){
		move_nave_mae(nave_mae);
	}
}

