#include "lib_lista_complementar.h"
#include <stdio.h>

#define MAX 5

int testa_inicializa(t_lista *l, t_lista *m, t_lista *n, t_lista *o)
{
	if (!(inicializa_lista(l)))
		return 0;
	else if (!(inicializa_lista(m)))
		return 0;
	else if (!(inicializa_lista(n)))
		return 0;
	else if (!(inicializa_lista(o)))
		return 0;
	else
		return 1;
}

void testa_vazias(t_lista *l, t_lista *m, t_lista *n, t_lista *o)
{
	if (lista_vazia(l))
		printf("lista l esta vazia\n");
	else
		printf("lista l nao vazia\n"); 
	if (lista_vazia(m))
		printf("lista m esta vazia\n");
        else
        	printf("lista m nao vazia\n"); 
	if (lista_vazia(n))
		printf("lista n esta vazia\n");
        else
        	printf("lista n nao vazia\n"); 
	if (lista_vazia(o))
		printf("lista o esta vazia\n");
        else
        	printf("lista o nao vazia\n");
}

int testa_insere_ini(t_lista *l)
{
	int i;
	for (i=0 ; i<MAX ; i++)
	{
		if (!(insere_inicio_lista(2*i,l)))
		{
			return 0;
		}
	}						
	printf("Inserido na lista l com sucesso\n");
	printf("l -> ");
	imprime_lista(l);
	return 1;	
}							

int testa_insere_fim(t_lista *m)
{
	int i;
	for (i=0 ; i<MAX ; i++)
	{
		if (!(insere_fim_lista(2*i+1,m)))
		{
			return 0;
		}
	}						
	printf("Inserido na lista m com sucesso\n");
	printf("m -> ");
	imprime_lista(m);
	return 1;	
}							

int testa_insere_ord(t_lista *n)
{
	if (!insere_ordenado_lista(12,n))
		return 0;
	else if (!insere_ordenado_lista(9,n))
		return 0;
	else if (!insere_ordenado_lista(10,n))
		return 0;
	else if (!insere_ordenado_lista(15,n))
		return 0;
	else if (!insere_ordenado_lista(7,n))
		return 0;
	else
	{
		printf("Inserido na lista n com sucesso\n");
		printf("n -> ");
		imprime_lista (n);
		return 1;
	}
}

int testa_insercoes(t_lista *l, t_lista *m, t_lista *n)
{
	if (testa_insere_ini(l))
        	printf("Inserido no inicio com sucesso\n");
	else
		return 0;
        
        if (testa_insere_fim(m))
        	printf("Insere no fim com sucesso\n");
	else
		return 0;
        
        if (testa_insere_ord(n))
        	printf("Insere ordenado com sucesso\n");
	else
		return 0;
	return 1;
}

int testa_remove_ini(t_lista *o)
{
	int i;
	int item;
	for (i=0 ; i<MAX ; i++)
	{
		if (!remove_inicio_lista(&item,o))
			return 0;
	}
	printf("Remocao no inicio com sucesso\n");
	printf("o -> ");
	imprime_lista(o);
	return 1;
}

int testa_remove_fim(t_lista *o)
{
	int i;
	int item;
	for (i=0 ; i<MAX ; i++)
	{
		if (!remove_fim_lista(&item,o))
			return 0;
	}
	printf("Remocao no fim com sucesso\n");
	printf("o -> ");
	imprime_lista(o);
	return 1;
}

int testa_remove_item(t_lista *o)
{					/* 7 9 10 12 15*/
	int item;
	inicializa_atual_inicio(o);
	if (!remove_item_lista(7,&item,o))
		return 0;
	else if (!remove_item_lista(15,&item,o))
        	return 0;
        else if (!remove_item_lista(10,&item,o))
        	return 0;
        else if (remove_item_lista(2,&item,o))
		return 0;
	else if (!remove_item_lista(12,&item,o))
        	return 0;
        else if (!remove_item_lista(9,&item,o))
        	return 0;
        else if (remove_item_lista(10,&item,o))
		return 0;
	else
	{
		printf("Remocao por item com sucesso\n");
		printf("o -> ");
		imprime_lista (o);
		return 1;
	}							
}

int testa_remocoes(t_lista *l, t_lista *m, t_lista *n, t_lista *o)
{
	if (!copia_lista(l,o))
		return 0;
	if (!testa_remove_ini(o))
		return 0;

	if (!copia_lista(m,o))
		return 0;
	if (!testa_remove_fim(o))
		return 0;

	if (!copia_lista(n,o))
		return 0;
	if (!testa_remove_item(o))
		return 0;
	return 1;
}

int testa_pertence(t_lista *l, t_lista *m, t_lista *n)
{
	if (!pertence_lista(8,l))
		return 0;
	else if (!pertence_lista(0,l))
		return 0;
	else if (!pertence_lista(4,l))
		return 0;
	else if (pertence_lista(10,l))
		return 0;
	else if (!pertence_lista(1,m))
		return 0;
	else if (!pertence_lista(9,m))
		return 0;
	else if (!pertence_lista(5,m))
		return 0;
	else if (pertence_lista(0,m))
		return 0;
	else if (!pertence_lista(7,n))
		return 0;
	else if (!pertence_lista(15,n))
		return 0;
	else if (!pertence_lista(10,n))
		return 0;
	else if (pertence_lista(8,n))
		return 0;
	else
		return 1;
}

int testa_atual(t_lista *l, t_lista *m, t_lista *n, t_lista *o)
{
	if (!copia_lista(n,o))
		return 0;
	if (!inicializa_atual_inicio(l))
		return 0;
	else if (!inicializa_atual_fim(m))
		return 0;
	else if (!inicializa_atual_inicio(n))
		return 0;
	else if (!inicializa_atual_fim(o))
		return 0;
	int i;
	int item;
	for (i=0 ; i<MAX ; i++)
	{
		if (consulta_item_atual(&item,l))
		{
			printf("%d ",item);
		}
		incrementa_atual(l);
	}
	printf("\n");
	printf("l -> ");
	imprime_lista(l);
	for (i=0 ; i<MAX ; i++)
        {
        	if (consulta_item_atual(&item,m))
        	{
        		printf("%d ",item);
        	}
        	decrementa_atual(m);
        }	
	printf("\n");
	printf("m -> ");
	imprime_lista(m);			 
	for (i=0 ; i<MAX ; i++)                  	
        {
        	if (remove_item_atual(&item,n))
        	{
        		printf("%d ",item);
        	}
        }	
	printf("\n");	
	printf("n -> ");
	imprime_lista(n);			 
	for (i=0 ; i<MAX ; i++)
        {
        	if (remove_item_atual(&item,o))
        	{
        		printf("%d ",item);
        	}
        }
	printf("\n");
	printf("o -> ");
	imprime_lista(o);
	return 1;	 
}

int destroi_listas(t_lista *l, t_lista *m, t_lista *n, t_lista *o)
{
	destroi_lista(l);
	destroi_lista(m);
	destroi_lista(n);
	destroi_lista(o);
	printf("Listas destruidas\n");
	return 1;
}

int testa_concatena(t_lista *l, t_lista *m)
{
	if (!concatena_listas(l,m))
		return 0;
	printf("l -> ");
	imprime_lista(l);
	return 1;
}

int testa_ordena(t_lista *l)
{
	if (!ordena_lista(l))
		return 0;
	printf("l -> ");
	imprime_lista(l);
	return 1;
}

int testa_intercala(t_lista *l, t_lista *o, t_lista *n)
{
	if (!intercala_listas(l,o,n))
		return 0;
	printf("n -> ");
	imprime_lista(n);
	return 1;
}

int main ()
{
	t_lista l,m,n,o;
	
	if (testa_inicializa(&l,&m,&n,&o))
		printf("Inicializado com sucesso\n");
	printf("\n");
	
	testa_vazias(&l,&m,&n,&o);
	printf("\n");

	if (testa_insercoes(&l,&m,&n))
		printf("Insercoes realizadas com sucesso\n");
	printf("\n");
	
	if (testa_remocoes(&l,&m,&n,&o))
		printf("Remocoes realizadas com sucesso\n");
	printf("\n");
	
	if (testa_pertence(&l,&m,&n))
		printf("Pertencimentos realizados com sucesso\n");
	printf("\n");

	if (testa_atual(&l,&m,&n,&o))
		printf("Pertencimentos realizados com sucesso\n");
	printf("\n");
	
	if (testa_concatena(&l,&m))
		printf("Concatena realizada com sucesso\n");
	printf("\n");

	if (testa_ordena(&l))
		printf("Ordena realizada com sucesso\n");
	printf("\n");
	
	destroi_lista(&n);
	inicializa_lista(&n);
	
	if (testa_intercala(&l,&o,&n))
		printf("Intercala realizado com sucesso\n");
	printf("\n");
	
	destroi_listas(&l,&m,&n,&o);
	printf("\n");
	
	return 1;
}
