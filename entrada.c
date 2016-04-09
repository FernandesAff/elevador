#include "lista.h"

void LeituraEventos (TipoLista *Lista){
	FILE *fp;
	int partida, destino, chamada;

	fp=fopen("eventos.txt", "r+");
	while ((fscanf(fp,"%d %d %d\n", &partida, &destino, &chamada))!=EOF){
		Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
		Lista->Ultimo = Lista->Ultimo->Prox;
		Lista->Ultimo->Item.and_partida = partida;/*andar de partida*/
		Lista->Ultimo->Item.and_destino = destino;/*andar de destino*/
		Lista->Ultimo->Item.chamada = chamada;/*momento da chamada do elevador*/
		Lista->Ultimo->Item.temp_entrada = -1;
		/*Lista->Ultimo->Item.temp_viagem = 0;
		Lista->Ultimo->Item.temp_tot = 0;*/
		Lista->Ultimo->Prox = NULL;
	}
	fclose (fp);
}

void LeituraAmbiente (int *ocupacao_max){
	FILE *fp=fopen("ambiente.txt", "r");

	fscanf (fp, "%d", ocupacao_max);
	fclose (fp);
}