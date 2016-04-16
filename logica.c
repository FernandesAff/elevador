#include "lista.h"

void Logica(TipoLista *Lista, int ocupacao_max){
	Apontador anterior=Lista->Primeiro;
	int tempo=Lista->Primeiro->Prox->Item.chamada, abriu, destino1, andar_elev=0, ocupacao_atual=0, flag_andar=0, passageiro=0;

	while(Vazia (*Lista)!=1){/*mantem o simulador funcionando enquanto ainda estiverem eventos a serem tratados*/
		if(anterior->Prox->Item.temp_entrada==-1){/*Define a prioridade do elevador, que eh o andar de entrada ou de saida do primeiro da lista, semelhante ao FIFO*/
			destino1=anterior->Prox->Item.and_partida;
		}
		else{
			destino1=anterior->Prox->Item.and_destino;
		}
		do{
			abriu=0;
			if (flag_andar==1){/*Determina se o elevador deve descer ou subir até o proximo destino*/
				if(andar_elev<destino1){
					andar_elev++;
				}
				else{
					andar_elev--;
				}
			}
			while(anterior->Prox->Item.chamada<=tempo){/*Verifica todos os eventos a serem tratados no andar em que o elevador esta*/
				if (anterior->Prox->Item.and_partida==andar_elev && anterior->Prox->Item.temp_entrada==-1 && ocupacao_atual<ocupacao_max){/*Gerencia a entrada de alguem no elevador, considerando se ele esta lotado e a ordem de chamada*/
					if(ocupacao_atual==ocupacao_max-1){
						if(anterior->Prox==Lista->Primeiro->Prox){
							anterior->Prox->Item.temp_entrada=tempo;
							ocupacao_atual++;
							abriu=1;
						}
					}
					else{
						anterior->Prox->Item.temp_entrada=tempo;
						ocupacao_atual++;
						abriu=1;
					}	
				}
				else {
					if (anterior->Prox->Item.and_destino==andar_elev && anterior->Prox->Item.temp_entrada!=-1){/*gerencia a saida de alguem do elevador, retirando o no correspondente da lista*/
						passageiro++;
						printf("Passageiro %d	Tempo de espera:%d	Tempo dentro do elevador:%d\n",passageiro,anterior->Prox->Item.temp_entrada-anterior->Prox->Item.chamada, tempo-anterior->Prox->Item.temp_entrada );/*Imprime o tempo de espera e o tempo dentro do elevador no terminal*/
						abriu=1;
						ExcluirNo(Lista, anterior);
						ocupacao_atual--;
					}
				}
				if (anterior->Prox==Lista->Ultimo || anterior==Lista->Ultimo){/*Verifica se o ponteiro que acompanha o evento a ser tratado aponta para o ultimo elemento da lista e para o loop antes que ele seja incrementado*/
					break;
				}	
				anterior=anterior->Prox;
				/*printf("t%d ta%d and%d dest%d ocup%d\n",tempo,anterior->Prox->Item.chamada, andar_elev,destino1, ocupacao_atual);*/
			}	
			if(abriu==1){/*incrementa o tempo caso a porta do elevador tenha sido aberta*/
				tempo++;
			}
			tempo++;
			flag_andar=1;
			anterior=Lista->Primeiro;
		}while(andar_elev!=destino1);/*Mantem o loop ate que o elemento em prioridade chegue entre ou saia do elevador*/
	}
}