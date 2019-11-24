#include <time.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "lib_lista.h"
#include "lib_ini_spc.h"
#include "lib_draw_spc.h"
#include "lib_move_spc.h"
#include "lib_colisao_spc.h"
#include "lib_rmv_spc.h"

#define MIN_Y  38
#define MIN_X 100

#define V_ALIEN_INI 200

#define ESQUE -1
#define DIREITA  1
#define BAIXO  2
#define CIMA  -2

int main() {
	int x_term, y_term;
	int dir, cont, v_alien, score, tecla, vitorias;
	t_lista aliens, canhao, tiros, barreiras, bombas, nave_mae;
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
	inicia_jogo(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae);

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
	//		termina_jogo(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae);
			inicia_jogo(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae);
			v_alien = V_ALIEN_INI - (vitorias * 15);
		}
		tecla = wgetch(tela_tecla);
		move_canhao(&canhao, &tiros, tecla);
		if(cont % v_alien == 0){
			move_aliens(&v_alien, &dir, &aliens, &bombas);
		}
		if(cont % 75 == 0){
			move_tiros(&tiros);
		}
		if(cont % 500 == 0){
			move_bombas(&bombas);
		}
		if(cont % 75 == 0){
			move_nave_mae(&nave_mae);
		}

			
		detecta_colisoes(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae);
		score += remove_morto(&aliens, &tiros, &barreiras, &bombas, &nave_mae);
		mvprintw(0, 45, "%010d", score);
		desenha_tiros(&tiros);
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
