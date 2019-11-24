#include <ncurses.h>
#include "lib_lista.h"

#define V_ALIEN_INI 200
#define V_BOMBA     250
#define V_TIRO      75
#define V_NAVE_M    75

#define ESQUERDA -1
#define DIREITA   1
#define NEUTRO    0
#define BAIXO     2
#define CIMA     -2

#ifndef VIVO
#define VIVO 1 
#endif

#ifndef MORTO
#define MORTO 0
#endif

#ifndef TIRO
#define TIRO   400
#endif

#ifndef BOMBA
#define BOMBA  500
#endif

#ifndef NAVE_M
#define NAVE_M 600
#endif

#ifndef MIN_X
#define MIN_X 100
#endif

void move_item(int sentido, t_nodo *item);

void move_aliens(int *velocidade, int *direcao, t_lista *aliens, t_lista *bombas);

void move_canhao(t_lista *canhao, t_lista *tiros, int tecla);

void move_tiro(t_lista *tiros);

void move_bomba(t_lista *bombas);

void move_nave_mae(t_lista *nave_mae);

void movimentacao(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *bombas, t_lista *nave_mae, int cont, int *dir, int *v_alien, int tecla);
