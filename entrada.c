#include "lista.h"

void FLVazia(TipoLista *Lista){
	Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

void LeituraEventos (TipoLista *Lista){
	FILE *fp=fopen("eventos.txt", "r");
	int partida, destino, chamada;

	while ((fscanf(fp,"%d %d %d\n", &partida, &destino, &chamada))!=EOF){
		Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
		Lista->Ultimo = Lista->Ultimo->Prox;
		Lista->Ultimo->Item.and_partida = partida;/*andar de partida*/
		Lista->Ultimo->Item.and_destino = destino;/*andar de destino*/
		Lista->Ultimo->Item.chamada = chamada;/*momento da chamada do elevador*/
		/*Lista->Ultimo->Item.temp_espera = 0;
		Lista->Ultimo->Item.temp_viagem = 0;
		Lista->Ultimo->Item.temp_tot = 0;*/
		Lista->Ultimo->Prox = NULL;
	}
	fclose (fp);
}

void LeituraAmbiente (int *andares, int *ocupacao_max){
	FILE *fp=fopen("ambiente.txt", "r");

	fscanf (fp, "%d %d", andares, ocupacao_max);
	fclose (fp);
}