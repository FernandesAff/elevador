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

	while ((opt=getopt(argc, argv, "a:e:"))>0){
		switch (opt){
			case 'a':/*ambiente do elevador*/
				LeituraAmbiente (&ocupacao_max);
			case 'e':/*eventos a serem tratados*/
				LeituraEventos (&lista);
				break;
		}
	}

	printf("vazia%d\n", Vazia(lista));

	Logica(&lista, ocupacao_max);
	return 0;
}