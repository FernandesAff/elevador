#include "lista.h"
#include "entrada.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv){
	TipoLista lista;
	int opt, andares, ocupacao_max;
	char *eventos_arq, *ambiente_arq;

	FLVazia(&lista);

	if ( argc < 3 ){/*Mostra as opcoes de execucao do programa no terminal*/
		printf("Numero insuficiente de opcoes, insira ao menos duas:\n\n" );
		show_help(argv[0]);
	}	

	while ((opt=getopt(argc, argv, "ha:e:"))>0){/*Faz a entrada dos arquivos descrevendo o ambiente e os eventos a serem tratados*/
		switch (opt){
			case 'a':
				ambiente_arq= optarg;
				break;
			case 'e':
				eventos_arq=optarg;
				break;	
			default:
                fprintf(stderr, "Opcao invalida ou faltando argumento: '%c'\n", optopt) ;
                return -1 ;	
		}
	}

	LeituraAmbiente (&ocupacao_max, &andares, ambiente_arq);
	LeituraEventos (&lista, eventos_arq);
	Logica(&lista, ocupacao_max);

	return 0;
}