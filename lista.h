#include <stdio.h>
#include <stdlib.h>
#ifndef LISTA_H
#define LISTA_H

typedef struct {
	int and_partida, and_destino, chamada, temp_entrada;
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
	TipoItem Item;
	Apontador Prox;
} Celula;

typedef struct {
	Apontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *);
int Vazia(TipoLista);
void ExcluirNo(TipoLista *, Apontador );

#endif