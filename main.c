#include "lista.h"
#include "entrada.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main (int argc, char **argv){
	TipoLista lista;
	int opt, andares, ocupacao_max;

	FLVazia(&lista);

	if ( argc < 3 ){/*Mostra as opcoes de execucao do programa no terminal*/
		printf("Numero insuficiente de opcoes, insira ao menos duas:\n\n" );
		show_help(argv[0]);
	}	
	while ((opt=getopt(argc, argv, "hae"))>0){/*Faz a entrada dos arquivos descrevendo o ambiente e os eventos a serem tratados*/
		switch (opt){
			case 'a':
				LeituraAmbiente (&ocupacao_max, &andares);
				break;
			case 'e':
				LeituraEventos (&lista);
				break;	
		}
	}
	Logica(&lista, ocupacao_max);
	return 0;
}