#include "lista.h"

void Logica(TipoLista *Lista, int ocupacao_max){
	Apontador anterior=Lista->Primeiro, aux;
	int tempo=Lista->Primeiro->Prox->Item.chamada, abriu, destino1, andar_elev=0, ocupacao_atual=0, flag_andar=0;

	while(Vazia (*Lista)!=1){
		if(anterior->Prox->Item.temp_entrada==-1){
			destino1=anterior->Prox->Item.and_partida;
		}
		else{
			destino1=anterior->Prox->Item.and_destino;
		}
		do{
			abriu=0;
			if (flag_andar==1){
				if(andar_elev<destino1){
					andar_elev++;
				}
				else{
					andar_elev--;
				}
			}
			while(anterior->Prox->Item.chamada<=tempo){
				if (anterior->Prox->Item.and_partida==andar_elev && anterior->Prox->Item.temp_entrada==-1 && ocupacao_atual<ocupacao_max){
					anterior->Prox->Item.temp_entrada=tempo;
					abriu=1;
				}
				else {
					if (anterior->Prox->Item.and_destino==andar_elev && anterior->Prox->Item.temp_entrada!=-1){
						printf("Tempo de espera:%d\nTempo dentro do elevador:%d\n",anterior->Prox->Item.temp_entrada-anterior->Prox->Item.chamada, tempo-anterior->Prox->Item.temp_entrada );
						abriu=1;
						ExcluirNo(Lista, anterior);
					}
				}
				if (anterior->Prox==Lista->Ultimo || anterior==Lista->Ultimo){
					break;
				}	
				anterior=anterior->Prox;
			}	
			if(abriu==1){
				tempo++;
			}
			tempo++;
			flag_andar=1;
			anterior=Lista->Primeiro;
		}while(andar_elev!=destino1);
	}
}