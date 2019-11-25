#include <ncurses.h>
#include "lib_desenha_spc.h"

/* attron e attroff usados para colorir diferentes objetos de diferentes cores */

void desenha(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae, int *score){
	desenha_borda();
	mvprintw(0, 45, "%010d", *score);
	desenha_tiros(tiros);
	desenha_aliens(aliens);
	desenha_canhao(canhao);
	desenha_barreiras(barreiras);
	desenha_bombas(bombas);
	desenha_nave_mae(nave_mae);	
}

void desenha_borda(){
	mvaddch(0, 0, ACS_ULCORNER);
	mvaddch(38, 0, ACS_LLCORNER);
	mvaddch(0, 100, ACS_URCORNER);
	mvaddch(38, 100, ACS_LRCORNER);		
	mvhline(0, 1, ACS_HLINE, 99);
	mvhline(38, 1, ACS_HLINE, 99);
	mvvline(1, 0, ACS_VLINE, 37);
	mvvline(1, 100, ACS_VLINE,37);
}

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
			desenha_item(aliens->atual->u.col->atual);
			incrementa_atual(aliens->atual->u.col);
		}
		incrementa_atual(aliens);
	}
	attroff(COLOR_PAIR(4));
}
void desenha_tiros(t_lista *tiros){
	int i;
	
	attron(COLOR_PAIR(2));
	inicializa_atual_inicio(tiros);
	for(i = 0; i < tiros->tamanho; i++){
		desenha_item(tiros->atual);
		incrementa_atual(tiros);
	}
	attroff(COLOR_PAIR(2));
}

void desenha_bombas(t_lista *bombas){
	int i;

	attron(COLOR_PAIR(5));	
	inicializa_atual_inicio(bombas);
	for(i = 0; i < bombas->tamanho; i++){
		desenha_item(bombas->atual);
		incrementa_atual(bombas);
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
