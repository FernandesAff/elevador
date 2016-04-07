#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int and_partida, and_destino, chamada/*, temp_espera, temp_viagem,temp_tot*/;
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
	TipoItem Item;
	Apontador Prox;
} Celula;

typedef struct {
	Apontador Primeiro, Ultimo;
} TipoLista;
