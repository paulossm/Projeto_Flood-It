#include <stdio.h>
#include "flood.h"
#include "flood.c"

/* **** RASCUNHO DO PROGRAMA QUE SIMULA O JOGO FLOOD IT *
	*  ITP/PTP - BTI - UFRN - 2014 *
	*  PAULO SERGIO SILVA DE MENDONCA
	*  ELIVELTON COSTA DA SILVA**** */



int main( void ){
	printf("**********************\n");
	printf("BEM-VINDO AO FLOOD IT!\n");
	printf("**********************\n");
	printf("\n(?) Selecione uma entre as opções a seguir:\n");
	printf("'n' Novo Jogo - ");
	printf("'o' Carregar um jogo salvo\n");

	do
	{
		printf("\nSeu comando: "); scanf(" %c", &opcao);
		acao = (int)opcao;
	} while (acao < 110 || acao > 111);
		if(acao==110)
		{
			novo_jogo();
			partida:
			for(jogada = i;jogada <= 25; jogada++)
			{
				printf("\n(!) Tentativa: %i/25\n", jogada);
				printf("------------------\n");
				printf("(?) Opções: 's' salvar o jogo atual - 'q' encerrar o jogo\n");
				printf("seu comando: ");
				scanf(" %c", &comando);
				executa((int)comando);
					if(erro==1){
						i--;
						erro = 0;
					}
				printf("\n");
				exibir_tabela(14,14);
			}
		}
		if(acao==111) {
			/* CARREGAR UM JOGO ANTERIOR */
			executa(acao);
			goto partida;
		}
	return 0;
}
