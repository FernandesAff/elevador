#include <unistd.h>
#include "lista.h"

void show_help(char *name) {/*Mostra uma tela de ajuda ao usuario*/
    fprintf(stderr, "\
            [uso] %s <opcoes>\n\n\
            -a AMBIENTE    recebe o nome do arquivo descrevendo o ambiente.\n\
            -e EVENTOS     recebe o nome do arquivo descrevendo os eventos.\n", name);
    exit(-1) ;
}

void LeituraEventos (TipoLista *Lista){/*Le os eventos em um arquivo e passa para uma lista*/
	FILE *fp;
	int partida, destino, chamada;

	fp=fopen("eventos.txt", "r+");
	while ((fscanf(fp,"%d %d %d\n", &partida, &destino, &chamada))!=EOF){
		Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
		Lista->Ultimo = Lista->Ultimo->Prox;
		Lista->Ultimo->Item.and_partida = partida;
		Lista->Ultimo->Item.and_destino = destino;
		Lista->Ultimo->Item.chamada = chamada;
		Lista->Ultimo->Item.temp_entrada = -1;
		Lista->Ultimo->Prox = NULL;
	}
	fclose (fp);
}

void LeituraAmbiente (int *ocupacao_max, int *andares){/*Le o limite de passageiros do elevador e o numero de andares do predio*/
	FILE *fp=fopen("ambiente.txt", "r");

	fscanf (fp, "%d %d", ocupacao_max, andares);
	fclose (fp);
}