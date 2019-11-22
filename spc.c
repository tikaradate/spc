#include <time.h>
#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "lib_lista.h"

#define VIVO     2
#define MORRENDO 1
#define MORTO    0

#define ALI_COL 11
#define ALI_LIN  5

#define MIN_Y  38
#define MIN_X 100

#define ALIEN    100
#define BARREIRA 200
#define CANHAO   300
#define TIRO     400
#define BOMBA    500
#define NAVE_M	 600

#define ESQUE -1
#define DIREI  1
#define BAIXO  2
#define CIMA  -2

#define BAR_ALT  3
#define BAR_LARG 7
#define QNT_BAR  4

void desenha_item(t_nodo *);
void inicia_sprite(t_nodo *);
void move_item(int sentido, t_nodo *);
void inicializa_aliens(t_lista *aliens);
void desenha_aliens(t_lista *aliens);

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
			insere_fim_lista(VIVO, ALIEN, pos, aliens->atual->u.col);
			inicia_sprite(aliens->atual->u.col->fim->prev);
			pos.y += 4; 
		}
		pos.x += 6;
	}
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
void desenha_item(t_nodo *item){
	int i;
	for(i = 0; i < item->spr_alt; i++){
		mvprintw(item->pos.y + i, item->pos.x, item->corpo[item->alterna][i]);
	}
}


void inicia_sprite(t_nodo *item){
	item->alterna = 0;
	switch(item->tipo){
		case ALIEN:
			item->spr_alt = 3;
			strcpy(item->corpo[0][0], "MMMMM");
			strcpy(item->corpo[0][1], "MMMMM");
			strcpy(item->corpo[0][2], "MMMMM");
			strcpy(item->corpo[1][0], "MMMMM");
			strcpy(item->corpo[1][1], "MMMMM");
			strcpy(item->corpo[1][2], "MMMMM");
			break;
		case CANHAO:
			item->spr_alt = 2;
			strcpy(item->corpo[0][0], " vVv ");
			strcpy(item->corpo[0][1], "NnNnN");
			strcpy(item->corpo[1][0], " VvV ");
			strcpy(item->corpo[1][1], "nNnNn");
			break;
		case TIRO:
			item->spr_alt = 1;
			strcpy(item->corpo[0][0], "i");
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

void desenha_barreiras(t_lista *barreiras){
	int i, j;

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
}

void desenha_aliens(t_lista *aliens){
	int i, j;

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
}

void move_aliens(int *velocidade, int *direcao, t_lista *aliens, t_lista *bombas){
	int vert, i, j, r;
	t_coord pos_bomba;

	inicializa_atual_inicio(aliens);
	vert = 0;
	if(aliens->ini->prox->u.col->ini->prox->pos.x - 1< 0){
		*direcao = DIREI;  /* inverte sentido do movimento horizontal */
		vert = BAIXO;
		*velocidade -= 5;
	} 
	else if(aliens->fim->prev->u.col->ini->prox->pos.x + 1 > MIN_X - 5){
		*direcao = ESQUE;
		vert = BAIXO;
		*velocidade -= 5;
	}

	for(i = 0; i < aliens->tamanho; i++){
		inicializa_atual_inicio(aliens->atual->u.col);	
		for(j = 0; j < aliens->atual->u.col->tamanho; j++){
			move_item(*direcao, aliens->atual->u.col->atual);
			move_item(vert, aliens->atual->u.col->atual);
			r = rand() % 10;
			if((r > 8) && (bombas->tamanho < 10)){		
				pos_bomba = aliens->atual->u.col->atual->pos;
				pos_bomba.x += 2;
				pos_bomba.y += 3;
				insere_fim_lista(VIVO, BOMBA, pos_bomba, bombas);
				inicializa_atual_fim(bombas);
				inicia_sprite(bombas->atual);
			}

			incrementa_atual(aliens->atual->u.col);
		}
		incrementa_atual(aliens);
	}
}

void move_item(int sentido, t_nodo *item){
	switch(sentido){
		case DIREI:
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

void inicializa_tiro(t_lista *tiro){
	inicializa_lista(tiro);
}

void desenha_tiro(t_lista *tiro){
	int i;

	inicializa_atual_inicio(tiro);
	for(i = 0; i < tiro->tamanho; i++){
		if(tiro->atual->u.estado == VIVO){
			desenha_item(tiro->atual);
			incrementa_atual(tiro);
		}
	}
}

void desenha_bombas(t_lista *bombas){
	int i;

	inicializa_atual_inicio(bombas);
	for(i = 0; i < bombas->tamanho; i++){
		if(bombas->atual->u.estado == VIVO){
			desenha_item(bombas->atual);
			incrementa_atual(bombas);
		}
	}
}


void move_tiro(t_lista *tiro){
	if(!lista_vazia(tiro)){
		int i, aux;

		inicializa_atual_inicio(tiro);
		for(i = 0; i < tiro->tamanho; i++){
			move_item(CIMA, tiro->atual);
				incrementa_atual(tiro);
		}
		inicializa_atual_fim(tiro);
		if(tiro->atual->pos.y < 0)
			remove_fim_lista(&aux, tiro);
	}
}

void move_bombas(t_lista *bombas){
	if(!lista_vazia(bombas)){
		int i;

		inicializa_atual_inicio(bombas);
		for(i = 0; i < bombas->tamanho; i++){
			move_item(BAIXO, bombas->atual);
			if(bombas->atual->pos.y + 1 > MIN_Y)
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
		if(r > 50){
			insere_fim_lista(VIVO, NAVE_M, pos, nave_mae);
			inicia_sprite(nave_mae->ini->prox);
		}
	
	} else {
		inicializa_atual_inicio(nave_mae);
		move_item(DIREI, nave_mae->atual);
	}
}

void inicializa_bombas(t_lista *bombas){
	inicializa_lista(bombas);	
}

void inicializa_nave_mae(t_lista *nave_mae){
	inicializa_lista(nave_mae);
}
void inicializa_canhao(t_lista *canhao){
	t_coord pos;

	pos.x = 48;
	pos.y = 36;
	inicializa_lista(canhao);
	insere_fim_lista(VIVO, CANHAO, pos, canhao);
	inicia_sprite(canhao->ini->prox);
}

void desenha_canhao(t_lista *canhao){
	inicializa_atual_inicio(canhao);
	desenha_item(canhao->atual);
}

void desenha_nave_mae(t_lista *nave_mae){
	if(!lista_vazia(nave_mae)){
		inicializa_atual_inicio(nave_mae);
		desenha_item(nave_mae->atual);
	}
}
void move_canhao(t_lista *canhao, t_lista *tiro, WINDOW *tela_tecla){
	int tecla;
	t_coord pos_tiro;

	tecla = wgetch(tela_tecla);
	if(tecla == KEY_LEFT){
		if(canhao->ini->prox->pos.x > 0){
			move_item(ESQUE, canhao->ini->prox);
			canhao->ini->prox->alterna = (canhao->ini->prox->alterna + 1) % 2;
		}
	} else if(tecla == KEY_RIGHT){
		if(canhao->ini->prox->pos.x < 100 - 5){
			move_item(DIREI, canhao->ini->prox);
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

void detecta_colisoes(t_lista *tiro, t_lista *aliens, t_lista *barreiras, t_lista *bombas, t_lista *canhao, t_lista *nave_mae){
	int i, j, k;

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
}

void remove_bombas(t_lista *bombas){
	int i, lixo;
	t_nodo *aux;

	inicializa_atual_inicio(bombas);
	for(i = 0; i < bombas->tamanho; i++){
		if(bombas->atual->u.estado == MORTO){
			aux = bombas->atual->prox;
			remove_item_atual(&lixo, bombas);
			bombas->atual = aux;
		} else {
			incrementa_atual(bombas);
		}
	}
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

void remove_aliens(t_lista *aliens){
	int i, j, lixo;
	t_nodo *aux;

	inicializa_atual_inicio(aliens);
	for(i = 0; i < aliens->tamanho; i++){

		inicializa_atual_inicio(aliens->atual->u.col);
		for(j = 0; j < aliens->atual->u.col->tamanho; j++){
			if(aliens->atual->u.col->atual->u.estado == MORTO){
				aux = aliens->atual->u.col->atual->prox;
				remove_item_atual(&lixo, aliens->atual->u.col);
				aliens->atual->u.col->atual = aux;
			} else {
				incrementa_atual(aliens->atual->u.col);
			}
		}

		incrementa_atual(aliens);
	}

	if(aliens->ini->prox->u.col->tamanho == 0)
		remove_inicio_lista(&lixo, aliens);
	if(aliens->fim->prev->u.col->tamanho == 0)
		remove_fim_lista(&lixo, aliens);
}

int remove_nave_mae(t_lista *nave_mae){
	int lixo;
	
	if(!lista_vazia(nave_mae)){
		inicializa_atual_inicio(nave_mae);
		if(nave_mae->atual->u.estado == MORTO)
			remove_item_atual(&lixo, nave_mae);
		
		return 50;
	}
}
int remove_morto(t_lista *tiro, t_lista *aliens, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae){
	remove_tiro(tiro);
	remove_aliens(aliens);
	remove_barreiras(barreiras);
	remove_bombas(bombas);
	remove_nave_mae(nave_mae);
}

int main() {
	int x_term, y_term;
	int dir, cont, v_alien;
	t_lista aliens, canhao, tiro, barreiras, bombas, nave_mae;
	WINDOW *tela_tecla;

	initscr();              /* inicia a tela */
	getmaxyx(stdscr, y_term, x_term);
	if(y_term < MIN_Y || x_term < MIN_X){
		endwin();
		printf("Tamanho do terminal insuficiente\nTente pelo menos 38x100\n");
		return 0;
	}

	cbreak();               /* desabilita o buffer de entrada */
	noecho();               /* não mostra os caracteres digitados */
	tela_tecla = newwin(0, 0, 0, 0);
	nodelay(tela_tecla, TRUE);  /* faz com que getch não aguarde a digitação */
	keypad(tela_tecla, TRUE);   /* permite a leitura das setas */
	curs_set(FALSE);        /* não mostra o cursor na tela */

	srand(time(NULL));
	inicializa_aliens(&aliens);
	inicializa_canhao(&canhao);
	inicializa_nave_mae(&nave_mae);
	inicializa_tiro(&tiro);
	inicializa_bombas(&bombas);
	inicializa_barreiras(&barreiras);
	dir = DIREI;
	v_alien = 150;
	cont = 0;
	while(1){

		erase();
		move_canhao(&canhao, &tiro, tela_tecla);
		if(cont % v_alien == 0){
			move_aliens(&v_alien, &dir, &aliens, &bombas);
		}
		if(cont % 20 == 0){
			move_tiro(&tiro);
		}
		if(cont % 500 == 0){
			move_bombas(&bombas);
		}
		if(cont % 75 == 0){
			move_nave_mae(&nave_mae);
		}

			
		detecta_colisoes(&tiro, &aliens, &barreiras, &bombas, &canhao, &nave_mae);
		remove_morto(&tiro, &aliens, &barreiras, &bombas, &nave_mae);
		
		desenha_tiro(&tiro);
		desenha_bombas(&bombas);
		desenha_barreiras(&barreiras);
		desenha_canhao(&canhao);
		desenha_aliens(&aliens);
		desenha_barreiras(&barreiras);
		desenha_nave_mae(&nave_mae);

		if(canhao.ini->prox->u.estado == MORTO){
			endwin();
			printf("amigo vc perdeu, nem tente\n");
			return 0;
		}
		refresh();

		if(cont > 1000)
			cont = 0;
		cont++;

		usleep(500);
	}
}

