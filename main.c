/* ********************************************************************* *\
|                                                                         |
|       PROJETO DO SIMULADOR DO GAME "FLOOD IT" EM LINGUAGEM "C".	  |
|		 BACHARELADO EM TECNOLOGIA DA INFORMAÇÃO - UFRN - 2014.	  |
|			INTRODUÇÃO/PRÁTICAS DE TÉCNICAS DE PROGRAMAÇÃO	  |
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

 /*Estrutura responsável para receber o valor correto para inicar jogo ou carregar uma anterior
  *Só finalizará se receber um char com valor 'n' ou 'o'
  */
	do
	{
		printf("\n\tOpção >> ");
		scanf(" %c", &opcao);
	} while (opcao - 48 < 62 || opcao - 48 > 63);

    /*Estrura utilizada para inicialização do jogo
     *Caso a opção selecionada seja 'n'
     */
    if((int)opcao == 110)
    {
        novo_jogo(); //Criação jogo. Definindo dificuldades
        partida:
        for(;jogada <= padrao.max_jogadas; jogada++)
        {
            printf("\n\t\t\tTentativa: %i/%i\n\n\t's' > salvar o jogo atual\n\t'q' > encerrar o jogo\n", jogada, padrao.max_jogadas);
            printf("\tOpção >> ");
            scanf(" %c", &comando); //Atribuição de valores em cada jogada

            executar((int)comando); //Execução do jogo em cada jogada

				/*Verificação de valor do caractere digitado*/
				if(entrada_invalida){
					jogada--;
					entrada_invalida = Falso;
				}

                /*verificação de vitoria em cada jogada do jogo */
				if(vitoria){
					printf("\n\n\t(i) PARABÉNS! Você venceu!\n");
					exit(1); //Saída do jogo
				}
        }
        printf("\n\n\t(i) Você perdeu!\n");
    }

    /*Caso a opção selecionada seja 'o'
     *Irá para um dos casos da função executar
     */
    else{
        // Carregar um Jogo Anterior
        executar((int)opcao);   //Função responsável pela execução do jogo
        goto partida;   //retorno para partida que se enconta no if do main.c, sem a necessidade de chamar novojogo()
    }
	return 0;
}
