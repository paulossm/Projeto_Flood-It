#include <stdio.h>
#include "flood.h"
#include "flood.c"

/* **  SIMULADOR DO GAME "FLOOD IT!"	*
	*  ITP/PTP - BTI - UFRN - 2014		*
	*  PAULO SERGIO SILVA DE MENDONCA	*
	*  ELIVELTON COSTA DA SILVA         ** */



int main( void )
{
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
	} while (opcao - 48 < 62 || opcao - 48 > 63);

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
				if(invalido){
					jogada--;
					invalido = 0;
				}
				if(venceu){
					printf("\n\n(!)PARABÉNS! Você venceu!\n");
					exit(1);
				}
        }
        printf("\n\n(!)Você perdeu!\n");
    }

    else{
        // Carregar um Jogo Anterior
        executa((int)opcao);
        goto partida;
    }
	return 0;
}
