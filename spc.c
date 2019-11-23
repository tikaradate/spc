#include <time.h>
#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "lib_lista.h"
#include "lib_ini_spc.h"
#include "lib_draw_spc.h"
#include "lib_move_spc.h"

#define MIN_Y  38
#define MIN_X 100

#define V_ALIEN_INI 200

#define ESQUE -1
#define DIREITA  1
#define BAIXO  2
#define CIMA  -2
void detecta_colisoes(t_lista *aliens, t_lista *canhao, t_lista *tiro, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae){
	int i, j, k, l;

/* tiro com aliens */
	inicializa_atual_inicio(tiro);
	for(i = 0; i < tiro->tamanho; i++){

		inicializa_atual_inicio(aliens);
		for(j = 0; j < aliens->tamanho; j++){

			inicializa_atual_inicio(aliens->atual->u.col);
			for(k = 0; k < aliens->atual->u.col->tamanho; k++){
				if(tiro->atual->pos.x >= aliens->atual->u.col->atual->pos.x &&
				   tiro->atual->pos.x <= aliens->atual->u.col->atual->pos.x + 4 &&
		  		   tiro->atual->pos.y >= aliens->atual->u.col->atual->pos.y &&
				   tiro->atual->pos.y <= aliens->atual->u.col->atual->pos.y + 2){
					tiro->atual->u.estado = MORTO;
					aliens->atual->u.col->atual->u.estado = MORTO;
				}
				incrementa_atual(aliens->atual->u.col);
			}
			incrementa_atual(aliens);
		}
		incrementa_atual(tiro);
	}

/* tiro com barreira */
	inicializa_atual_inicio(tiro);
	for(i = 0; i < tiro->tamanho; i++){

		inicializa_atual_inicio(barreiras);
		for(j = 0; j < barreiras->tamanho; j++){

			inicializa_atual_inicio(barreiras->atual->u.col);
			for(k = 0; k < barreiras->atual->u.col->tamanho; k++){
				if(tiro->atual->pos.x == barreiras->atual->u.col->atual->pos.x &&
				   tiro->atual->pos.y == barreiras->atual->u.col->atual->pos.y){
					tiro->atual->u.estado = MORTO;
					barreiras->atual->u.col->atual->u.estado = MORTO;
				}
				incrementa_atual(barreiras->atual->u.col);
			}
			incrementa_atual(barreiras);
		}
		incrementa_atual(tiro);
	}

/* tiro com bombas */
	inicializa_atual_inicio(tiro);
	for(i = 0; i < tiro->tamanho; i++){

		inicializa_atual_inicio(bombas);
		for(j = 0; j < bombas->tamanho; j++){
			
			if(tiro->atual->pos.x == bombas->atual->pos.x &&
			   tiro->atual->pos.y == bombas->atual->pos.y){  
				tiro->atual->u.estado = MORTO;
				bombas->atual->u.estado = MORTO;
			}
			incrementa_atual(bombas);
		}
		incrementa_atual(tiro);
	}

/* bombas com barreiras */
	inicializa_atual_inicio(bombas);
	for(i = 0; i < bombas->tamanho; i++){

		inicializa_atual_inicio(barreiras);
		for(j = 0; j < barreiras->tamanho; j++){

			inicializa_atual_inicio(barreiras->atual->u.col);
			for(k = 0; k < barreiras->atual->u.col->tamanho; k++){
				if(bombas->atual->pos.x == barreiras->atual->u.col->atual->pos.x &&
				   bombas->atual->pos.y == barreiras->atual->u.col->atual->pos.y){
					bombas->atual->u.estado = MORTO;
					barreiras->atual->u.col->atual->u.estado = MORTO;
				}
				incrementa_atual(barreiras->atual->u.col);
			}
			incrementa_atual(barreiras);
		}
		incrementa_atual(bombas);
	}

/* bomba com jogador */
	inicializa_atual_inicio(bombas);
	inicializa_atual_inicio(canhao);
	for(i = 0; i < bombas->tamanho; i++){
		if(bombas->atual->pos.x >= canhao->atual->pos.x &&
		   bombas->atual->pos.x <= canhao->atual->pos.x + 4 &&
		   bombas->atual->pos.y >= canhao->atual->pos.y &&
		   bombas->atual->pos.y <= canhao->atual->pos.y + 1 ){
			bombas->atual->u.estado = MORTO;
			canhao->atual->u.estado = MORTO;
		}
		incrementa_atual(bombas);
	}

/* aliens com barreira */
	inicializa_atual_inicio(barreiras);
	for(i = 0; i < barreiras->tamanho; i++){

		inicializa_atual_inicio(barreiras->atual->u.col);
		for(j = 0; j < barreiras->atual->u.col->tamanho; j++){

			inicializa_atual_inicio(aliens);
			for(k = 0; k < aliens->tamanho; k++){

				inicializa_atual_inicio(aliens->atual->u.col);
				for(l = 0; l < aliens->atual->u.col->tamanho; l++){
					if(barreiras->atual->u.col->atual->pos.x >= aliens->atual->u.col->atual->pos.x &&
						barreiras->atual->u.col->atual->pos.x <= aliens->atual->u.col->atual->pos.x + 3 &&
						barreiras->atual->u.col->atual->pos.y >= aliens->atual->u.col->atual->pos.y &&
						barreiras->atual->u.col->atual->pos.y <= aliens->atual->u.col->atual->pos.y + 2){
						barreiras->atual->u.col->atual->u.estado = MORTO;
					}
					incrementa_atual(aliens->atual->u.col);
				}
				incrementa_atual(aliens);
			}
			incrementa_atual(barreiras->atual->u.col);
		}
		incrementa_atual(barreiras);
	}

/* tiro com nave mae */
	if(!lista_vazia(nave_mae)){	
		inicializa_atual_inicio(tiro);
		inicializa_atual_inicio(nave_mae);
		for(i = 0; i < tiro->tamanho; i++){
			if(tiro->atual->pos.x >= nave_mae->atual->pos.x &&
				tiro->atual->pos.x <= nave_mae->atual->pos.x + 5&&
				tiro->atual->pos.y >= nave_mae->atual->pos.y &&
				tiro->atual->pos.y <= nave_mae->atual->pos.y + 3){
				tiro->atual->u.estado = MORTO;
				nave_mae->atual->u.estado = MORTO;
			}
			incrementa_atual(tiro);
		}
	}
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
			score += 2;
		} else {
			incrementa_atual(bombas);
		}}

	return score;
}

void remove_tiro(t_lista *tiro){
	int i, lixo;
	t_nodo *aux;

	inicializa_atual_inicio(tiro);
	for(i = 0; i < tiro->tamanho; i++){
		if(tiro->atual->u.estado == MORTO){
			aux = tiro->atual->prox;
			remove_item_atual(&lixo, tiro);
			tiro->atual = aux;
		} else {
			incrementa_atual(tiro);
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
				score += 10;
			} else {
				incrementa_atual(aliens->atual->u.col);
			}
		}

		incrementa_atual(aliens);
	}

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
		if(nave_mae->atual->u.estado == MORTO){
			remove_item_atual(&lixo, nave_mae);
			return 50;
			}
	}
	return 0;
}
int remove_morto(t_lista *aliens, t_lista *tiro, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae){
	int score;

	score = 0;	
	remove_tiro(tiro);
	remove_barreiras(barreiras);
	
	score += remove_aliens(aliens);
	score += remove_bombas(bombas);
	score += remove_nave_mae(nave_mae);

	return score;
}

int main() {
	int x_term, y_term;
	int dir, cont, v_alien, score, tecla, vitorias;
	t_lista aliens, canhao, tiro, barreiras, bombas, nave_mae;
	WINDOW *tela_tecla;

	initscr();              /* inicia a tela */
	
	getmaxyx(stdscr, y_term, x_term);
	if(y_term < MIN_Y || x_term < MIN_X){
		endwin();
		printf("Tamanho do terminal insuficiente\nTente pelo menos 38x100\n");
		return 0;
	}

	cbreak();               		/* desabilita o buffer de entrada */
	noecho();               		/* não mostra os caracteres digitados */
	tela_tecla = newwin(0, 0, 0, 0);
	nodelay(tela_tecla, TRUE);  	/* faz com que getch não aguarde a digitação */
	keypad(tela_tecla, TRUE);   	/* permite a leitura das setas */
	curs_set(FALSE);        		/* não mostra o cursor na tela */

	inicia_cores();
	inicia_jogo(&aliens, &canhao, &tiro, &barreiras, &bombas, &nave_mae);

	srand(time(NULL));
	dir = DIREITA;
	v_alien = V_ALIEN_INI;
	cont = 0;
	score = 0;
	vitorias = 0;
	while(1){

		erase();
		if(aliens.tamanho == 0){
			vitorias++;
	//		termina_jogo(&aliens, &canhao, &tiro, &barreiras, &bombas, &nave_mae);
			inicia_jogo(&aliens, &canhao, &tiro, &barreiras, &bombas, &nave_mae);
			v_alien = V_ALIEN_INI - (vitorias * 15);
		}
		tecla = wgetch(tela_tecla);
		move_canhao(&canhao, &tiro, tecla);
		if(cont % v_alien == 0){
			move_aliens(&v_alien, &dir, &aliens, &bombas);
		}
		if(cont % 75 == 0){
			move_tiro(&tiro);
		}
		if(cont % 500 == 0){
			move_bombas(&bombas);
		}
		if(cont % 75 == 0){
			move_nave_mae(&nave_mae);
		}

			
		detecta_colisoes(&aliens, &canhao, &tiro, &barreiras, &bombas, &nave_mae);
		score += remove_morto(&aliens, &tiro, &barreiras, &bombas, &nave_mae);
		mvprintw(0, 50, "%d %d", score, v_alien);
		desenha_tiro(&tiro);
		desenha_bombas(&bombas);
		desenha_barreiras(&barreiras);
		desenha_canhao(&canhao);
		desenha_aliens(&aliens);
		desenha_barreiras(&barreiras);
		desenha_nave_mae(&nave_mae);
		
		/* FUNCAO */
		if(canhao.ini->prox->u.estado == MORTO){
			endwin();
			printf("fim de jogo\np = %d\n", score);
			return 0;
		}
		
		/*       */
		refresh();

		if(cont > 1000)
			cont = 0;
		cont++;

		usleep(500);

	}
}
