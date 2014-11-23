#include <stdio.h>
#include "flood.h"
#include "flood.c"

/* **  SIMULADOR DO GAME "FLOOD IT!"	*
	*  ITP/PTP - BTI - UFRN - 2014		*
	*  PAULO SERGIO SILVA DE MENDONCA	*
	*  ELIVELTON COSTA DA SILVA         ** */



<<<<<<< HEAD
int main( void )
{
=======
int main( void ){
	//printf("**********************\n");
	//printf("BEM-VINDO AO FLOOD IT!\n");
	//printf("**********************\n");
>>>>>>> d5ae0920f3e0252141abb83b1af002375285c172
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
<<<<<<< HEAD
	} while (opcao - 48 < 62 || opcao - 48 > 63);
=======
	} while ((int)opcao < 110 || (int)opcao > 111);
>>>>>>> d5ae0920f3e0252141abb83b1af002375285c172

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
<<<<<<< HEAD
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
=======
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
>>>>>>> d5ae0920f3e0252141abb83b1af002375285c172
        executa((int)opcao);
        goto partida;
    }
	return 0;
}
