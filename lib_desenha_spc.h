#include "lib_lista.h"

#ifndef VIVO
#define VIVO 2
#endif

#ifndef MORRENDO
#define MORRENDO 1
#endif

#ifndef MORTO
#define MORTO 0
#endif

void desenha(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae, int *score);

void desenha_borda();

void desenha_item(t_nodo *item);

void desenha_aliens(t_lista *aliens);

void desenha_canhao(t_lista *canhao);

void desenha_tiros(t_lista *tiros);

void desenha_barreiras(t_lista *barreiras);

void desenha_bombas(t_lista *bombas);

void desenha_nave_mae(t_lista *nave_mae);

void desenha_morrendo1x1(t_nodo *item);

void desenha_morrendo3x3(t_nodo *item);
