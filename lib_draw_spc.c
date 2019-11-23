#include <curses.h>
#include "lib_draw_spc.h"

void desenha_item(t_nodo *item){
	int i;
	for(i = 0; i < item->spr_alt; i++){
		mvprintw(item->pos.y + i, item->pos.x, item->corpo[item->alterna][i]);
	}
}

void desenha_barreiras(t_lista *barreiras){
	int i, j;

	attron(COLOR_PAIR(3));
	inicializa_atual_inicio(barreiras);
	for(i = 0; i < barreiras->tamanho; i++){
		inicializa_atual_inicio(barreiras->atual->u.col);
		for(j = 0; j < barreiras->atual->u.col->tamanho; j++){
			if(barreiras->atual->u.col->atual->u.estado == VIVO){
				desenha_item(barreiras->atual->u.col->atual);
				incrementa_atual(barreiras->atual->u.col);
			}
		}
		incrementa_atual(barreiras);
	}
	attroff(COLOR_PAIR(3));
}

void desenha_aliens(t_lista *aliens){
	int i, j;

	attron(COLOR_PAIR(4));
	inicializa_atual_inicio(aliens);
	for(i = 0; i < aliens->tamanho; i++){
		inicializa_atual_inicio(aliens->atual->u.col);	
		for(j = 0; j < aliens->atual->u.col->tamanho; j++){
			if(aliens->atual->u.col->atual->u.estado == VIVO){
				desenha_item(aliens->atual->u.col->atual);
				incrementa_atual(aliens->atual->u.col);
			}
		}
		incrementa_atual(aliens);
	}
	attroff(COLOR_PAIR(4));
}
void desenha_tiro(t_lista *tiro){
	int i;
	
	attron(COLOR_PAIR(2));
	inicializa_atual_inicio(tiro);
	for(i = 0; i < tiro->tamanho; i++){
		if(tiro->atual->u.estado == VIVO){
			desenha_item(tiro->atual);
			incrementa_atual(tiro);
		}
	}
	attroff(COLOR_PAIR(2));
}

void desenha_bombas(t_lista *bombas){
	int i;

	attron(COLOR_PAIR(5));
	inicializa_atual_inicio(bombas);
	for(i = 0; i < bombas->tamanho; i++){
		if(bombas->atual->u.estado == VIVO){
			desenha_item(bombas->atual);
			incrementa_atual(bombas);
		}
	}
	attroff(COLOR_PAIR(5));
}

void desenha_canhao(t_lista *canhao){
	inicializa_atual_inicio(canhao);
	attron(COLOR_PAIR(1));
	desenha_item(canhao->atual);
	attroff(COLOR_PAIR(1));
}

void desenha_nave_mae(t_lista *nave_mae){
	if(!lista_vazia(nave_mae)){
		inicializa_atual_inicio(nave_mae);
		attron(COLOR_PAIR(6));
		desenha_item(nave_mae->atual);
		attroff(COLOR_PAIR(6));
	}
}

