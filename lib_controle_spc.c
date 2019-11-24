#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "lib_controle_spc.h"
#include "lib_lista.h"

int inicia_ncurses(WINDOW **tela_tecla){
	int y_term, x_term;

	initscr();              		/* inicia a tela */
	
	getmaxyx(stdscr, y_term, x_term);
	if(y_term < MIN_Y || x_term < MIN_X){
		endwin();
		printf("Tamanho do terminal insuficiente\nTente pelo menos 38x100\n");
		return 0;
	}

	cbreak();               		/* desabilita o buffer de entrada */
	noecho();               		/* não mostra os caracteres digitados */
	*tela_tecla = newwin(0, 0, 0, 0);/* nova tela para o wgetch, pois getch atrapalha no refresh */
	nodelay(*tela_tecla, TRUE);  	/* faz com que wgetch não aguarde a digitação */
	keypad(*tela_tecla, TRUE);   	/* permite a leitura das setas */
	curs_set(FALSE); 	      		/* não mostra o cursor na tela */
	return 1;
}

void inicia_parametros(int *dir, int *v_alien, int *cont, int *score, int *vitorias){
	srand(time(NULL));
	*dir = DIREITA;
	*v_alien = V_ALIEN_INI;
	*cont = 0;
	*score = 0;
	*vitorias = 0;
}

void inicia_cores(){
	start_color();
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COR_CANHAO, 400, 800, 800);
	init_color(COR_TIRO, 200, 900, 700);
	init_color(COR_BARREIRA, 200, 1000, 500);
	init_color(COR_ALIEN, 1000, 320, 200);
	init_color(COR_BOMBA, 1000, 800, 200);
	init_color(COR_N_MAE, 1000, 200, 200);
	init_color(COR_APAGOU, 500, 500, 500);
	init_pair(1, COR_CANHAO, COLOR_BLACK);
	init_pair(2, COR_TIRO, COLOR_BLACK);
	init_pair(3, COR_BARREIRA, COLOR_BLACK);
	init_pair(4, COR_ALIEN, COLOR_BLACK);
	init_pair(5, COR_BOMBA, COLOR_BLACK);
	init_pair(6, COR_N_MAE, COLOR_BLACK);
	init_pair(7, COR_APAGOU, COLOR_BLACK);
}
void inicia_jogo(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae){	
	inicializa_aliens(aliens);
	inicializa_canhao(canhao);
	inicializa_nave_mae(nave_mae);
	inicializa_tiros(tiros);
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

void inicializa_tiros(t_lista *tiros){
	inicializa_lista(tiros);
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
			strcpy(item->corpo[0][0], CANHAO_11);
			strcpy(item->corpo[0][1], CANHAO_12);
			strcpy(item->corpo[1][0], CANHAO_21);
			strcpy(item->corpo[1][1], CANHAO_22);
			break;
		case TIRO:
			item->spr_alt = 1;
			strcpy(item->corpo[0][0], TIRO_1);
			strcpy(item->corpo[1][0], TIRO_2);
			break;
		case BARREIRA:
			item->spr_alt = 1;
			strcpy(item->corpo[0][0], BARREIRA_1);
			break;
		case BOMBA:
			item->spr_alt = 1;
			strcpy(item->corpo[0][0], BOMBA_1);
			break;
		case NAVE_M:
			item->spr_alt = 3;
			strcpy(item->corpo[0][0], NAVE_M_11);
			strcpy(item->corpo[0][1], NAVE_M_12);
			strcpy(item->corpo[0][2], NAVE_M_13);
			strcpy(item->corpo[1][0], NAVE_M_21);
			strcpy(item->corpo[1][1], NAVE_M_22);
			strcpy(item->corpo[1][2], NAVE_M_23);
			break;	
	}
}

void novo_tiro(t_lista *tiros, t_coord pos_canhao){
	t_coord pos_tiros;

	if(tiros->tamanho < MAX_TIROS){
		pos_tiros.x = pos_canhao.x + 2;
		pos_tiros.y = pos_canhao.y - 1;
		insere_fim_lista(VIVO, TIRO, pos_tiros, tiros);
		inicializa_atual_fim(tiros);
		inicia_sprite(tiros->atual);
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
	else if (item->alterna == 0)
		item->alterna = 1;
}

int ganhou_rodada(t_lista *aliens){
	return(aliens->tamanho == 0);
}

int fim_de_jogo(t_lista *canhao, int tecla){
	inicializa_atual_inicio(canhao);
	if(canhao->atual->u.estado == MORTO || tecla == 'q'){
		return 1;
	}
	return 0;
}

void termina_jogo(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae){
	int i;
	
	inicializa_atual_inicio(aliens);
	for(i = 0; i < aliens->tamanho; i++){
		destroi_lista(aliens->atual->u.col);
		incrementa_atual(aliens);
	}
	destroi_lista(aliens);

	inicializa_atual_inicio(barreiras);
	for(i = 0; i < barreiras->tamanho; i++){
		destroi_lista(barreiras->atual->u.col);
		incrementa_atual(barreiras);
	}
	destroi_lista(barreiras);
	destroi_lista(canhao);
	destroi_lista(tiros);
	destroi_lista(bombas);
	destroi_lista(nave_mae);
}
