/* ********************************************************************* *\
|                                                                         |
|       PROJETO DO SIMULADOR DO GAME "FLOOD IT" EM LINGUAGEM "C".		  | 
|		 BACHARELADO EM TECNOLOGIA DA INFORMAÇÃO - UFRN - 2014.			  |
|			INTRODUÇÃO/PRÁTICAS DE TÉCNICAS DE PROGRAMAÇÃO				  |
|                                                                         |
\* ********************************************************************* */

/* ------------------------------------------------------------------------
								Autores			
                        ______________________

                        Elivelton Costa Silva
                   Paulo Sergio Silva de Mendonça.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include "flood.h"
#include "flood.c"

int main( void ){
	printf("\t******************************\n\n");
	printf("\t*** *   **** **** ***    * ***\n");
	printf("\t*   *   *  * *  * *  *   *  *\n");
	printf("\t**  *   *  * *  * *  *   *  *\n");
	printf("\t*   *** **** **** ***    *  *");
	printf("\n\n\t******************************");
	printf("\n\n\t'n' > Novo Jogo\n\t'o' > Carregar Jogo\n");

	do
	{
		printf("\n\tOpção >> ");
		scanf(" %c", &opcao);
	} while (opcao - 48 < 62 || opcao - 48 > 63);

    if((int)opcao == 110)
    {
        novo_jogo();
        partida:
        for(;jogada <= padrao.max_jogadas; jogada++)
        {
            printf("\n\t\t\tTentativa: %i/%i\n\n\t's' > salvar o jogo atual\n\t'q' > encerrar o jogo\n", jogada, padrao.max_jogadas);
            printf("\tOpção >> ");
            scanf(" %c", &comando);
            
            executar((int)comando);
				
				if(entrada_invalida){
					jogada--;
					entrada_invalida = Falso;
				}
				
				if(vitoria){
					printf("\n\n\t(i) PARABÉNS! Você venceu!\n");
					exit(1);
				}
        }
        printf("\n\n\t(i) Você perdeu!\n");
    }

    else{
        // Carregar um Jogo Anterior
        executar((int)opcao);
        goto partida;
    }
	return 0;
}
