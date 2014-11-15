#include <stdio.h>
#include "flood.h"
#include "flood.c"


/* **** RASCUNHO DO PROGRAMA QUE SIMULA O JOGO FLOOD IT *
	*  ITP/PTP - BTI - UFRN - 2014 *
	*  PAULO SERGIO SILVA DE MENDONCA
	*  ELIVELTON COSTA DA SILVA**** */



int main( void ){

	printf("\nBem-Vindo ao Flood it!\n");
	printf("Selecione um dos comandos a seguir:\n\n");
	printf("'n' Novo Jogo\n");
	printf("'o' Carregar uma jogada anterior\n");

	do
	{
		printf("\nSeu comando: "); scanf(" %c", &opcao);
		acao = (int)opcao;
	} while (acao < 110 || acao > 111);
		if(acao==110)
		{
			novo_jogo();
			for(jogada = 1; jogada <= 25; jogada++)
			{
				printf("\nTentativa: %i/25\n", jogada);
				printf("Quer salvar o jogo? Digite s\n");
				printf("seu comando: ");
				scanf(" %c", &comando);
				executa((int)comando);
				printf("\n");
				exibir_tabela(14,14);
			}
		}
		if(acao==111) {
			/* CARREGAR UM JOGO ANTERIOR */
			ler_matriz(14,14);
		}
	return 0;
}
