#include <curses.h>
#include "lib_lista.h"

#define ESQUE -1
#define DIREITA  1
#define BAIXO  2
#define CIMA  -2

#ifndef VIVO
#define VIVO 2
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

void move_item(int sentido, t_nodo *item);

void move_aliens(int *velocidade, int *direcao, t_lista *aliens, t_lista *bombas);

void move_canhao(t_lista *canhao, t_lista *tiro, int tecla);

void move_tiro(t_lista *tiro);

void move_bombas(t_lista *bombas);

void move_nave_mae(t_lista *nave_mae);
