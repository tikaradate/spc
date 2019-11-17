#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "lib_lista.h"

#define VIVO 2
#define MORRENDO 1
#define MORTO 0

#define ALI_COL 11
#define ALI_LIN 5

#define MIN_Y 38
#define MIN_X 100

#define ALIEN    100
#define BARREIRA 200
#define CANHAO   300
#define TIRO     400

#define ESQUE -1
#define DIREI  1
#define BAIXO  2
#define CIMA  -2
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
		aliens->atual = aliens->fim->prev;
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

void desenha_item(t_nodo *item){
	int i;
	for(i = 0; i < 3; i++){
		mvprintw(item->pos.y + i, item->pos.x, item->corpo[i]);
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
			strcpy(item->corpo[0], " vUv ");
			strcpy(item->corpo[1], "mmmmm");
			break;
		case TIRO:
			strcpy(item->corpo[0], "i");
			strcpy(item->corpo[1], "I");
	}
}

void desenha_aliens(t_lista *aliens){
	int i, j;
	
	inicializa_atual_inicio(aliens);
	for(i = 0; i < ALI_COL; i++){
		inicializa_atual_inicio(aliens->atual->u.col);	
		for(j = 0; j < ALI_LIN; j++){
			desenha_item(aliens->atual->u.col->atual);
			incrementa_atual(aliens->atual->u.col);
		}
		incrementa_atual(aliens);
	}
}

void move_aliens(int *direcao, t_lista *aliens){
	int vert, i, j;

	inicializa_atual_inicio(aliens);
	vert = 0;
	if(aliens->ini->prox->u.col->ini->prox->pos.x - 1 < 0 ||
	   aliens->fim->prev->u.col->ini->prox->pos.x + 1 > MIN_X - 5){
		*direcao *= -1;  /* inverte sentido do movimento horizontal */
		vert = BAIXO;
	}

	for(i = 0; i < ALI_COL; i++){
		inicializa_atual_inicio(aliens->atual->u.col);	
			for(j = 0; j < ALI_LIN; j++){
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
	t_coord pos;

	pos.x = 50;
	pos.y = 36;
	inicializa_lista(tiro);
	insere_fim_lista(VIVO, TIRO, pos, tiro);
	inicia_sprite(tiro->ini->prox);
}

void desenha_tiro(t_lista *tiro){
	desenha_item(tiro->ini->prox);
}

void move_tiro(t_lista *tiro){
	int tecla;

	tecla = getch();
	if(tecla == ' '){
		move_item(CIMA, tiro->ini->prox);
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

void move_canhao(t_lista *canhao){
	int tecla;

	tecla = getch();
	if(tecla == KEY_LEFT){
		if(canhao->ini->prox->pos.x > 0)
			move_item(ESQUE, canhao->ini->prox);
	} else if(tecla == KEY_RIGHT){
		if(canhao->ini->prox->pos.x < 100 - 5)
			move_item(DIREI, canhao->ini->prox);
	}
}
int main() {
	int x_term, y_term, vert;;
	int i, j, num_col, dir;
	t_lista aliens, canhao, tiro;

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

	inicializa_tiro(&tiro);
	inicializa_aliens(&aliens);
	inicializa_canhao(&canhao);
	tamanho_lista(&num_col, &aliens);
	dir = 1;
	while(1){
		erase();

		move_aliens(&dir, &aliens);
		desenha_aliens(&aliens);
		move_canhao(&canhao);
		desenha_canhao(&canhao);
		move_tiro(&tiro);
		desenha_tiro(&tiro);

		refresh();
		usleep(40000);
	}
}

