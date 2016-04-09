#include "lista.h"

void FLVazia(TipoLista *Lista){
	Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){
	return (Lista.Primeiro == Lista.Ultimo);
}

void ExcluirNo(TipoLista *Lista, Apontador anterior){
	Apontador atual;

	atual=anterior->Prox;
	
	if(atual==Lista->Ultimo){
		Lista->Ultimo=anterior;
		Lista->Ultimo->Prox=NULL;
	}
	anterior->Prox=atual->Prox;
	free(atual);
}
