#include "lista.h"

void FLVazia(TipoLista *Lista){
	Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

void Leitura (TipoLista *Lista){
	FILE *fp=fopen("arquivo.txt", "r");
	int partida, destino, chamada;

	while ((fscanf(arq,"%d %d %d\n", &partida, &destino, &chamada))!=EOF){
		Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
		Lista->Ultimo = Lista->Ultimo->Prox;
		Lista->Ultimo->Item.partida = partida/*andar de partida*/;
		Lista->Ultimo->Item.destino = destino/*andar de destino*/;
		Lista->Ultimo->Item.chamada = chamada/*momento da chamada do elevador*/;
		Lista->Ultimo->Item.tempoespera = 0 ;/*ainda nao sei se isso vai ser util*/
		Lista->Ultimo->Item.tempoviagem = 0 ;/*ainda nao sei se isso vai ser util*/
		Lista->Ultimo->Prox = NULL;
	}
}