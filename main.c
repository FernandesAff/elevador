#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lista.h"
#include "entrada.h"

int main (int argc, char **argv){
	TipoLista lista;
	int opt, andares, ocupacao_max;

	FLvazia (&lista);

	while ((opt=getopt(argc, argv, "a:e:"))>0){
		switch (opt){
			case 'a':/*ambiente do elevador*/
				LeituraAmbiente (&andares,&ocupacao_max);
				break;
			case 'e':/*eventos a serem tratados*/
				LeituraEventos (&lista);
				break;
		}
	}

	return 0;
}