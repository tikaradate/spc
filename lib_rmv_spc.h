#include "lib_lista.h"

#ifndef MORRENDO
#define MORRENDO 1
#endif

#ifndef MORTO
#define MORTO 0
#endif

int remove_morto(t_lista *aliens, t_lista *tiro, t_lista *barreiras, t_lista *bombas, t_lista *nave_mae);

int remove_aliens(t_lista *aliens);

void remove_tiro(t_lista *tiro);

void remove_barreiras(t_lista *barreiras);

int remove_bombas(t_lista *bombas);

int remove_nave_mae(t_lista *nave_mae);
