#include <time.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "lib_lista.h"
#include "lib_controle_spc.h"
#include "lib_move_spc.h"
#include "lib_desenha_spc.h"
#include "lib_colisao_spc.h"
#include "lib_remove_spc.h"

int main() {
	int dir, cont, v_alien, score, tecla, vitorias;
	t_lista aliens, canhao, tiros, barreiras, bombas, nave_mae;
	WINDOW *tela_tecla;

	tela_tecla = NULL;
	if(!inicia_ncurses(&tela_tecla)){
		return 0;
	}
	inicia_cores();
	inicia_jogo(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae);
	inicia_parametros(&dir, &v_alien, &cont, &score, &vitorias);

/* loop principal */
	while(1){

		erase();
		tecla = wgetch(tela_tecla);
		
		if(ganhou_rodada(&aliens)){
			vitorias++;
			termina_jogo(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae);
			inicia_jogo(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae);
			v_alien = V_ALIEN_INI - (vitorias * 15);
		}

		movimentacao(&aliens, &canhao, &tiros, &bombas, &nave_mae, cont, &dir, &v_alien, tecla);	
		
		detecta_colisoes(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae);
		
		score += remove_morto(&aliens, &tiros, &barreiras, &bombas, &nave_mae);
		
		desenha(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae, &score);
	
		if(fim_de_jogo(&canhao, tecla)){
			endwin();
			termina_jogo(&aliens, &canhao, &tiros, &barreiras, &bombas, &nave_mae);
			printf("fim de jogo\np = %d\n", score);
			return 0;
		}

		/* contador mestre, velocidades baseiam-se nele */
		if(cont > 1000)
			cont = 0;
		cont++;

		refresh();
		usleep(500);
	}

	return 0;
}
