#ifndef __LIB_LISTA_INI__
#define __LIB_LISTA_INI__

#include <ncurses.h>
#include "lib_lista.h"

#define ALIEN1    100
#define ALIEN2	  101
#define ALIEN3	  102
#define BARREIRA  200
#define CANHAO    300
#define TIRO      400
#define BOMBA     500
#define NAVE_M	  600

#define VIVO      2
#define MORRENDO  1
#define MORTO     0

#define MIN_X 100
#define MIN_Y  38

#define CAN_INI_X 48
#define CAN_INI_Y 36

#define ALI_COL 11
#define ALI_LIN  5

#define COR_CANHAO   11
#define COR_TIRO     12
#define COR_BARREIRA 13
#define COR_ALIEN    14
#define COR_BOMBA    15
#define COR_N_MAE    16
#define COR_APAGOU 17

#define ALIEN1_11 "  s  "
#define ALIEN1_12 " iii "
#define ALIEN1_13 "-ix;-"
#define ALIEN1_21 "  z  "
#define ALIEN1_22 " ;;i "
#define ALIEN1_23 "-i+;-"

#define ALIEN2_11 " --- "
#define ALIEN2_12 " -0- "
#define ALIEN2_13 " --- "
#define ALIEN2_21 "\\ | /"
#define ALIEN2_22 "====="
#define ALIEN2_23 "/ | \\"

#define ALIEN3_11 " /\\//"
#define ALIEN3_12 "\\//\\/"
#define ALIEN3_13 "oOoOo"
#define ALIEN3_21 "\\ //\\"
#define ALIEN3_22 "/\\/\\\\"
#define ALIEN3_23 "ooOOo"

#define CANHAO_11 " vVv "
#define CANHAO_12 "bnnnd"
#define CANHAO_21 " vWv "
#define CANHAO_22 "pnnnq"

#define TIRO_1 "i"
#define TIRO_2 ";"

#define BARREIRA_1 "a"

#define BOMBA_1 "*"

#define NAVE_M_11 "aAaaAa"
#define NAVE_M_12 " ==== "
#define NAVE_M_13 "^V^^V^"
#define NAVE_M_21 "AaAAaA"
#define NAVE_M_22 " ==== "
#define NAVE_M_23 "V^VV^V"

#define BAR_ALT  3
#define BAR_LARG 7
#define QNT_BAR  4

#define MAX_BOMBAS  8
#define MAX_TIROS   3

#define DIREITA 1

#define V_ALIEN_INI 200

int inicia_ncurses(WINDOW **);

void inicia_parametros(int *dir, int *v_alien, int *cont, int *score, int *vitorias);

void inicia_cores();

void inicia_jogo(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae);

void inicializa_aliens(t_lista *aliens);

void inicializa_canhao(t_lista *canhao);

void inicializa_tiros(t_lista *tiros);

void inicializa_barreiras(t_lista *barreiras);

void inicializa_bombas(t_lista *bombas);

void inicializa_nave_mae(t_lista *nave_mae);

void inicia_sprite(t_nodo *item);

void novo_tiro(t_lista *tiros, t_coord pos);

void nova_bomba(t_lista *bombas, t_coord pos);

void alterna_sprite(t_nodo *item);

int ganhou_rodada(t_lista *aliens);

int fim_de_jogo(t_lista *canhao, int tecla);

void termina_jogo(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae);
#endif
