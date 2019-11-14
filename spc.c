#include <stdio.h>
#include <curses.h>
#include "lib_lista.h"

int main() {
	int xTerm, yTerm;

	initscr();              /* inicia a tela */
	getmaxyx(stdscr, xTerm, yTerm);
	if(xTerm < 100 || yTerm < 38){
		endwin();
		printf("Tamanho do terminal insuficiente\nTente pelo menos 38x100\n");
		return 0;
	}


    cbreak();               /* desabilita o buffer de entrada */
    noecho();               /* não mostra os caracteres digitados */
    nodelay(stdscr, TRUE);  /* faz com que getch não aguarde a digitação */
    keypad(stdscr, TRUE);   /* permite a leitura das setas */
    curs_set(FALSE);        /* não mostra o cursor na tela */
}

