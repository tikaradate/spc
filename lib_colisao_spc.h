#include "lib_lista.h"

#ifndef MIN_Y
#define MIN_Y 38
#endif

#ifndef MORRENDO
#define MORRENDO 1
#endif

#ifndef MORTO
#define MORTO 0
#endif

/* funcao que chama todas as subsequentes */
void detecta_colisoes(t_lista *aliens, t_lista *canhao, t_lista *tiros, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae);

void colisao_aliens_tiros(t_lista *aliens, t_lista *tiros);
	
void colisao_tiros_barreiras(t_lista *tiros, t_lista *barreiras);
	
void colisao_tiros_bombas(t_lista *tiros, t_lista *bombas);
	
void colisao_tiros_nave_mae(t_lista *tiros, t_lista *nave_mae);
	
void colisao_bombas_barreiras(t_lista *bombas, t_lista *barreiras);
	
void colisao_canhao_bombas(t_lista *canhao, t_lista *bombas);
	
void colisao_aliens_barreiras(t_lista *aliens, t_lista *barreiras);

void colisao_aliens_chao(t_lista *aliens, t_lista *canhao);
