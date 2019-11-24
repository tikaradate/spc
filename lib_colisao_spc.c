#include "lib_colisao_spc.h"

void detecta_colisoes(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae){
	colisao_aliens_tiros(aliens, tiros);
	colisao_tiros_barreiras(tiros, barreiras);
	colisao_tiros_bombas(tiros, bombas);
	colisao_tiros_nave_mae(tiros, nave_mae);
	colisao_bombas_barreiras(bombas, barreiras);
	colisao_canhao_bombas(canhao, bombas);
	colisao_aliens_barreiras(aliens, barreiras);
	colisao_aliens_chao(aliens, canhao);
}

void colisao_aliens_tiros(t_lista *aliens, t_lista *tiros){
	int i, j, k;

	inicializa_atual_inicio(tiros);
	for(i = 0; i < tiros->tamanho; i++){

		inicializa_atual_inicio(aliens);
		for(j = 0; j < aliens->tamanho; j++){

			inicializa_atual_inicio(aliens->atual->u.col);
			for(k = 0; k < aliens->atual->u.col->tamanho; k++){
				if(tiros->atual->pos.x >= aliens->atual->u.col->atual->pos.x &&
				   tiros->atual->pos.x <= aliens->atual->u.col->atual->pos.x + 4 &&
		  		   tiros->atual->pos.y >= aliens->atual->u.col->atual->pos.y &&
				   tiros->atual->pos.y <= aliens->atual->u.col->atual->pos.y + 2){
					tiros->atual->u.estado = MORTO;
					aliens->atual->u.col->atual->u.estado = MORRENDO;
				}
				incrementa_atual(aliens->atual->u.col);
			}
			incrementa_atual(aliens);
		}
		incrementa_atual(tiros);
	}
}

void colisao_tiros_barreiras(t_lista *tiros, t_lista *barreiras){
	int i, j, k;
	
	inicializa_atual_inicio(tiros);
	for(i = 0; i < tiros->tamanho; i++){

		inicializa_atual_inicio(barreiras);
		for(j = 0; j < barreiras->tamanho; j++){

			inicializa_atual_inicio(barreiras->atual->u.col);
			for(k = 0; k < barreiras->atual->u.col->tamanho; k++){
				if(tiros->atual->pos.x == barreiras->atual->u.col->atual->pos.x &&
				   tiros->atual->pos.y == barreiras->atual->u.col->atual->pos.y){
					tiros->atual->u.estado = MORTO;
					barreiras->atual->u.col->atual->u.estado = MORTO;
				}
				incrementa_atual(barreiras->atual->u.col);
			}
			incrementa_atual(barreiras);
		}
		incrementa_atual(tiros);
	}
}


void colisao_tiros_bombas(t_lista *tiros, t_lista *bombas){
	int i, j;

	inicializa_atual_inicio(tiros);
	for(i = 0; i < tiros->tamanho; i++){

		inicializa_atual_inicio(bombas);
		for(j = 0; j < bombas->tamanho; j++){
			
			if(tiros->atual->pos.x == bombas->atual->pos.x &&
			   tiros->atual->pos.y == bombas->atual->pos.y){  
				tiros->atual->u.estado = MORTO;
				bombas->atual->u.estado = MORRENDO;
			}
			incrementa_atual(bombas);
		}
		incrementa_atual(tiros);
	}
}

void colisao_bombas_barreiras(t_lista *bombas, t_lista *barreiras){
	int i, j, k;

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
}

void colisao_canhao_bombas(t_lista *canhao, t_lista *bombas){
	int i;

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
}

void colisao_aliens_barreiras(t_lista *aliens, t_lista *barreiras){
	int i, j, k ,l;

	inicializa_atual_inicio(barreiras);
	for(i = 0; i < barreiras->tamanho; i++){

		inicializa_atual_inicio(barreiras->atual->u.col);
		for(j = 0; j < barreiras->atual->u.col->tamanho; j++){

			inicializa_atual_inicio(aliens);
			for(k = 0; k < aliens->tamanho; k++){

				inicializa_atual_inicio(aliens->atual->u.col);
				for(l = 0; l < aliens->atual->u.col->tamanho; l++){
					if(barreiras->atual->u.col->atual->pos.x >= aliens->atual->u.col->atual->pos.x &&
						barreiras->atual->u.col->atual->pos.x <= aliens->atual->u.col->atual->pos.x + 4 &&
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
}

void colisao_tiros_nave_mae(t_lista *tiros, t_lista *nave_mae){
	if(!lista_vazia(nave_mae)){	
		int i;
		
		inicializa_atual_inicio(tiros);
		inicializa_atual_inicio(nave_mae);
		for(i = 0; i < tiros->tamanho; i++){
			if(tiros->atual->pos.x >= nave_mae->atual->pos.x &&
				tiros->atual->pos.x <= nave_mae->atual->pos.x + 5&&
				tiros->atual->pos.y >= nave_mae->atual->pos.y &&
				tiros->atual->pos.y <= nave_mae->atual->pos.y + 3){
				
				tiros->atual->u.estado = MORTO;
				nave_mae->atual->u.estado = MORRENDO;
			}
			incrementa_atual(tiros);
		}
	}
}

void colisao_aliens_chao(t_lista *aliens, t_lista *canhao){
	int i;

	inicializa_atual_inicio(aliens);
	for(i = 0; i < aliens->tamanho; i++){
		inicializa_atual_fim(aliens->atual->u.col);
		/* ao chegar na altura do canhao, o jogo acaba */
		if(aliens->atual->u.col->atual->pos.y + 2 == MIN_Y - 2)
			canhao->atual->u.estado = MORTO;
		incrementa_atual(aliens);
	}
}
