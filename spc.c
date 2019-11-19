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
	switch(item->tipo){
		case ALIEN:
			for(i = 0; i < 3; i++){
				mvprintw(item->pos.y + i, item->pos.x, item->corpo[i]);
			}
			break;
		case CANHAO:
			for(i = 0; i < 2; i++){
				mvprintw(item->pos.y + i, item->pos.x, item->corpo[i]);
			}
			break;
		case TIRO:
			mvprintw(item->pos.y, item->pos.x, item->corpo[0]);
			break;
		case BARREIRA:
			mvprintw(item->pos.y, item->pos.x, item->corpo[0]);
	}

}


void inicia_sprite(t_nodo *item){
	switch(item->tipo){
		case ALIEN:
			strcpy(item->corpo[0], "MMMMM");
			strcpy(item->corpo[1], "MMMMM");
			strcpy(item->corpo[2], "MMMMM");
			break;
		case CANHAO:
			strcpy(item->corpo[0], " v~v ");
			strcpy(item->corpo[1], "mmmmm");
			break;
		case TIRO:
			strcpy(item->corpo[0], "i");
			break;
		case BARREIRA:
			strcpy(item->corpo[0], "a");
	}
}

void desenha_barreiras(t_lista *barreiras){
	int i, j, k;

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

void move_aliens(int *direcao, t_lista *aliens){
	int vert, i, j;

	inicializa_atual_inicio(aliens);
	vert = 0;
	if(aliens->ini->prox->u.col->ini->prox->pos.x - 1 < 0){
		*direcao = DIREI;  /* inverte sentido do movimento horizontal */
		vert = BAIXO;
	} else if(aliens->fim->prev->u.col->ini->prox->pos.x + 1 > MIN_X- 5){
		*direcao = ESQUE;
		vert = BAIXO;
	}

	for(i = 0; i < aliens->tamanho; i++){
		inicializa_atual_inicio(aliens->atual->u.col);	
			for(j = 0; j < aliens->atual->u.col->tamanho; j++){
			move_item(*direcao, aliens->atual->u.col->atual);
			move_item(vert, aliens->atual->u.col->atual);
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

void inicializa_canhao(t_lista *canhao){
	t_coord pos;

	pos.x = 48;
	pos.y = 36;
	inicializa_lista(canhao);
	insere_fim_lista(VIVO, CANHAO, pos, canhao);
	inicia_sprite(canhao->ini->prox);
}

void desenha_canhao(t_lista *canhao){
	desenha_item(canhao->ini->prox);
}

void move_canhao(t_lista *canhao, t_lista *tiro){
	int tecla;
	t_coord pos_tiro;

	tecla = getch();
	if(tecla == KEY_LEFT){
		if(canhao->ini->prox->pos.x > 0)
			move_item(ESQUE, canhao->ini->prox);
	} else if(tecla == KEY_RIGHT){
		if(canhao->ini->prox->pos.x < 100 - 5)
			move_item(DIREI, canhao->ini->prox);
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

void detecta_colisoes(t_lista *tiro, t_lista *aliens, t_lista *barreiras){
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


void remove_morto(t_lista *tiro, t_lista *aliens, t_lista *barreiras){
	remove_tiro(tiro);
	remove_aliens(aliens);
	remove_barreiras(barreiras);
}

int main() {
	int x_term, y_term;
	int dir, cont;
	t_lista aliens, canhao, tiro, barreiras;
	initscr();              /* inicia a tela */
	getmaxyx(stdscr, y_term, x_term);
	if(y_term < 38 || x_term < 100){
		endwin();
		printf("Tamanho do terminal insuficiente\nTente pelo menos 38x100\n");
		return 0;
	}

    cbreak();               /* desabilita o buffer de entrada */
    noecho();               /* não mostra os caracteres digitados */
    nodelay(stdscr, TRUE);  /* faz com que getch não aguarde a digitação */
    keypad(stdscr, TRUE);   /* permite a leitura das setas */
    curs_set(FALSE);        /* não mostra o cursor na tela */

	inicializa_aliens(&aliens);
	inicializa_canhao(&canhao);
	inicializa_tiro(&tiro);
	inicializa_barreiras(&barreiras);
	dir = DIREI;
	cont = 0;
	while(1){
		erase();
		
		if(cont % 10 == 0){
			move_aliens(&dir, &aliens);
		}

		move_canhao(&canhao, &tiro);

		if(cont % 2 == 0){
			move_tiro(&tiro);
		}
		
		detecta_colisoes(&tiro, &aliens, &barreiras);
		remove_morto(&tiro, &aliens, &barreiras);
		desenha_tiro(&tiro);
		desenha_aliens(&aliens);
		desenha_canhao(&canhao);
		desenha_barreiras(&barreiras);
		refresh();

		cont++;
		if(cont > 10)
			cont = 0;
		usleep(20000);
	}
}

