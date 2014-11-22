#include <stdio.h>
#include "flood.h"
#include "flood.c"

/* **** RASCUNHO DO PROGRAMA QUE SIMULA O JOGO FLOOD IT *
	*  ITP/PTP - BTI - UFRN - 2014 *
	*  PAULO SERGIO SILVA DE MENDONCA
	*  ELIVELTON COSTA DA SILVA**** */



int main( void ){
	//printf("**********************\n");
	//printf("BEM-VINDO AO FLOOD IT!\n");
	//printf("**********************\n");
	printf("******************************\n\n");
	printf("*** *   **** **** ***    * ***\n");
	printf("*   *   *  * *  * *  *   *  *\n");
	printf("**  *   *  * *  * *  *   *  *\n");
	printf("*   *** **** **** ***    *  *");
	printf("\n\n******************************");
	printf("\n\n(?) Selecione uma entre as opções a seguir:\n");
	printf("'n' Novo Jogo - 'o' Carregar um jogo salvo\n");

	do
	{
		printf("\nSeu comando: ");
		scanf(" %c", &opcao);
	} while ((int)opcao < 110 || (int)opcao > 111);

    if((int)opcao == 110)
    {
        novo_jogo();
        partida:
        for(;jogada <= 25; jogada++)
        {
            printf("\n(!) Tentativa: %i/25\n", jogada);
            printf("------------------\n");
            printf("(?) Opções: 's' salvar o jogo atual - 'q' encerrar o jogo\n");
            printf("seu comando: ");
            scanf(" %c", &comando);
            executa((int)comando);
            if(erro == 1){
                jogada--;
                erro = 0;
            }
            if(cond == 1){
                printf("\n\n(!)Você venceu.!\n");
                exit(1);
            }
        }
        printf("\n\n(!)Você perdeu.\n");
    }

    else{
        /* CARREGAR UM JOGO ANTERIOR */
        executa((int)opcao);
        goto partida;
    }
	return 0;
}
