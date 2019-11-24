#ifndef __LIB_LISTA_INI__
#define __LIB_LISTA_INI__

#include "lib_lista.h"

#define ALIEN1    100
#define ALIEN2	  101
#define ALIEN3	  102
#define BARREIRA  200
#define CANHAO    300
#define TIRO      400
#define BOMBA     500
#define NAVE_M	  600

#define VIVO     2
#define MORRENDO 1
#define MORTO    0

#define ALI_COL 11
#define ALI_LIN  5

#define COR_CANHAO   11
#define COR_TIRO     12
#define COR_BARREIRA 13
#define COR_ALIEN    14
#define COR_BOMBA    15
#define COR_N_MAE    16

#define ALIEN1_11 " sss "
#define ALIEN1_12 " iii "
#define ALIEN1_13 ";;;;;"
#define ALIEN1_21 " zzz "
#define ALIEN1_22 " iii "
#define ALIEN1_23 ";; ;;"

#define ALIEN2_11 " --- "
#define ALIEN2_12 " -0- "
#define ALIEN2_13 " --- "
#define ALIEN2_21 "\\ | /"
#define ALIEN2_22 "=\\//="
#define ALIEN2_23 "/ | \\"

#define ALIEN3_11 "[ ? ]"
#define ALIEN3_12 "[ ? ]"
#define ALIEN3_13 "[ ? ]"
#define ALIEN3_21 "] ! ["
#define ALIEN3_22 "] ! ["
#define ALIEN3_23 "] ! ["

#define BAR_ALT  3
#define BAR_LARG 7
#define QNT_BAR  4

#define MAX_BOMBAS 10
#define MAX_TIROS   3

void inicia_cores();

void inicia_jogo(t_lista *aliens, t_lista *canhao, t_lista *tiro, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae);

void inicializa_aliens(t_lista *aliens);

void inicializa_canhao(t_lista *canhao);

void inicializa_tiro(t_lista *tiro);

void inicializa_barreiras(t_lista *barreiras);

void inicializa_bombas(t_lista *bombas);

void inicializa_nave_mae(t_lista *nave_mae);

void inicia_sprite(t_nodo *item);

void novo_tiro(t_lista *tiro, t_coord pos);

void nova_bomba(t_lista *bombas, t_coord pos);

void alterna_sprite(t_nodo *item);
#endif
