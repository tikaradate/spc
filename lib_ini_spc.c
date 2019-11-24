#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "lib_ini_spc.h"
#include "lib_lista.h"

void inicia_cores(){
	start_color();
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COR_CANHAO, 400, 800, 800);
	init_color(COR_TIRO, 200, 900, 700);
	init_color(COR_BARREIRA, 200, 1000, 500);
	init_color(COR_ALIEN, 1000, 320, 200);
	init_color(COR_BOMBA, 1000, 800, 200);
	init_color(COR_N_MAE, 1000, 200, 200);
	init_pair(1, COR_CANHAO, COLOR_BLACK);
	init_pair(2, COR_TIRO, COLOR_BLACK);
	init_pair(3, COR_BARREIRA, COLOR_BLACK);
	init_pair(4, COR_ALIEN, COLOR_BLACK);
	init_pair(5, COR_BOMBA, COLOR_BLACK);
	init_pair(6, COR_N_MAE, COLOR_BLACK);
}
void inicia_jogo(t_lista *aliens, t_lista *canhao, t_lista *tiro, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae){	
	inicializa_aliens(aliens);
	inicializa_canhao(canhao);
	inicializa_nave_mae(nave_mae);
	inicializa_tiro(tiro);
	inicializa_bombas(bombas);
	inicializa_barreiras(barreiras);
}
void inicializa_aliens(t_lista *aliens){
	int i, j;
	t_coord pos;

	inicializa_lista(aliens);

	pos.x = 5;
	for(i = 0; i < ALI_COL; i++){
		insere_fim_lista(0, 0, pos, aliens);
		inicializa_atual_fim(aliens);
		aliens->atual->u.col = (t_lista *) malloc(sizeof(t_lista));
		inicializa_lista(aliens->atual->u.col);

		pos.y = 5;
		for(j = 0; j < ALI_LIN; j++){
			if(j == 0)
				insere_fim_lista(VIVO, ALIEN1, pos, aliens->atual->u.col);
			else if(j == 1 || j == 2)
				insere_fim_lista(VIVO, ALIEN2, pos, aliens->atual->u.col);
			else
				insere_fim_lista(VIVO, ALIEN3, pos, aliens->atual->u.col);
			inicia_sprite(aliens->atual->u.col->fim->prev);
			pos.y += 4; 
		}
		pos.x += 6;
	}
}

void inicializa_canhao(t_lista *canhao){
	t_coord pos;

	pos.x = 48;
	pos.y = 36;
	inicializa_lista(canhao);
	insere_fim_lista(VIVO, CANHAO, pos, canhao);
	inicia_sprite(canhao->ini->prox);
}

void inicializa_tiro(t_lista *tiro){
	inicializa_lista(tiro);
}

void inicializa_barreiras(t_lista *barreiras){
	int i, j, k;
	t_coord pos;

	inicializa_lista(barreiras);
	pos.x = 20;
	for(i = 0; i < QNT_BAR; i++){
		insere_fim_lista(0, 0, pos, barreiras);
		inicializa_atual_fim(barreiras);
		barreiras->atual->u.col = (t_lista *) malloc(sizeof(t_lista));
		inicializa_lista(barreiras->atual->u.col);
		for(j = 0; j < BAR_LARG; j++){
			pos.y = 27;
			for(k = 0; k < BAR_ALT; k++){
				insere_fim_lista(VIVO, BARREIRA, pos, barreiras->atual->u.col);
				inicia_sprite(barreiras->atual->u.col->fim->prev);
				pos.y += 1;
			}
			pos.x += 1;
		}
		pos.x += 13;
	}
}

void inicializa_bombas(t_lista *bombas){
	inicializa_lista(bombas);	
}

void inicializa_nave_mae(t_lista *nave_mae){
	inicializa_lista(nave_mae);
}

void inicia_sprite(t_nodo *item){
	item->alterna = 0;
	switch(item->tipo){
		case ALIEN1:
			item->spr_alt = 3;
			strcpy(item->corpo[0][0], ALIEN1_11);
			strcpy(item->corpo[0][1], ALIEN1_12);
			strcpy(item->corpo[0][2], ALIEN1_13);
			strcpy(item->corpo[1][0], ALIEN1_21);
			strcpy(item->corpo[1][1], ALIEN1_22);
			strcpy(item->corpo[1][2], ALIEN1_23);
			break;
		case ALIEN2:
			item->spr_alt = 3;
			strcpy(item->corpo[0][0], ALIEN2_11);
			strcpy(item->corpo[0][1], ALIEN2_12);
			strcpy(item->corpo[0][2], ALIEN2_13);
			strcpy(item->corpo[1][0], ALIEN2_21);
			strcpy(item->corpo[1][1], ALIEN2_22);
			strcpy(item->corpo[1][2], ALIEN2_23);
			break;
		case ALIEN3:
			item->spr_alt = 3;
			strcpy(item->corpo[0][0], ALIEN3_11);
			strcpy(item->corpo[0][1], ALIEN3_12);
			strcpy(item->corpo[0][2], ALIEN3_13);
			strcpy(item->corpo[1][0], ALIEN3_21);
			strcpy(item->corpo[1][1], ALIEN3_22);
			strcpy(item->corpo[1][2], ALIEN3_23);
			break;
		case CANHAO:
			item->spr_alt = 2;
			strcpy(item->corpo[0][0], " vVv ");
			strcpy(item->corpo[0][1], "bnnnd");
			strcpy(item->corpo[1][0], " VvV ");
			strcpy(item->corpo[1][1], "pmmmq");
			break;
		case TIRO:
			item->spr_alt = 1;
			strcpy(item->corpo[0][0], ";");
			strcpy(item->corpo[1][0], "i");
			break;
		case BARREIRA:
			item->spr_alt = 1;
			strcpy(item->corpo[0][0], "a");
			break;
		case BOMBA:
			item->spr_alt = 1;
			strcpy(item->corpo[0][0], "*");
			strcpy(item->corpo[1][0], "0");
			break;
		case NAVE_M:
			item->spr_alt = 3;
			strcpy(item->corpo[0][0], "AaAaAa");
			strcpy(item->corpo[0][1], "aAaAaA");
			strcpy(item->corpo[0][2], "AaAaAa");
			strcpy(item->corpo[1][0], "aAaAaA");
			strcpy(item->corpo[1][1], "AaAaAa");
			strcpy(item->corpo[1][2], "aAaAaA");
			break;	
	}
}

void novo_tiro(t_lista *tiro, t_coord pos_canhao){
	t_coord pos_tiro;

	if(tiro->tamanho < MAX_TIROS){
		pos_tiro.x = pos_canhao.x + 2;
		pos_tiro.y = pos_canhao.y - 1;
		insere_fim_lista(VIVO, TIRO, pos_tiro, tiro);
		inicializa_atual_fim(tiro);
		inicia_sprite(tiro->atual);
	}
}

void nova_bomba(t_lista *bombas, t_coord pos_alien){
	int r;
	t_coord pos_bomba;

	r = rand() % 20;
	if((r > 18) && (bombas->tamanho < MAX_BOMBAS)){
		pos_bomba.x = pos_alien.x + 2;
		pos_bomba.y = pos_alien.y + 3;
		insere_fim_lista(VIVO, BOMBA, pos_bomba, bombas);
		inicializa_atual_fim(bombas);
		inicia_sprite(bombas->atual);
	}
}

void alterna_sprite(t_nodo *item){
	if(item->alterna == 1)
		item->alterna = 0;
	else
		item->alterna = 1;
}
