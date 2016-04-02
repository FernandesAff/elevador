#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int partida, destino, chamada, tempoespera, tempoviagem;
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
	TipoItem Item;
	Apontador Prox;
} Celula;

typedef struct {
	Apontador Primeiro, Ultimo;
} TipoLista;