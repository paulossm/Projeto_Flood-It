#include <stdio.h>
#include <stdlib.h>
#include <tabuleiro_numeros_aleatorios.c>
 

/***** RASCUNHO DO PROGRAMA QUE SIMULA O JOGO FLOOD IT *
	*  ITP/PTP - BTI - UFRN - 2014 *****/

void preencher() {
	
	for(i=0;i<n;i++){
		
		int cor_atual = tabuleiro[0][0];
		
		if(cor_atual==tabuleiro[i++][i])
			tabuleiro[i++][i] = cor_atual; 
	}
	
	
}

int main(void)
{ 
	int i;
    for(i=0;i<25;i++){ /* controlador das rodadas do jogo. */
		
		/* parte do código que se repetirá até o fim de jogo. */
			char comando_atual;
			
			leitura_do_comando:
			printf("Digite um Comando: ");
			scanf("%c\n", &comando_atual); /* LEITURA DE UM COMANDO */
			
				if(comando_atual >=0 && comando_atual <= 5) { /* o usuário digitou o numero correspondente a uma cor */
					tabuleiro[0][0] = comando_atual;
				}
				else {  	/* o usuário digitou algum comando de controle */
					switch(comando_atual){
						case 111: ; 	/** letra: "o" - ler uma configuração de arquivo **/
						case 113: ; 	/** letra: "q" - interromper o jogo **/
						case 115: ; 	/** letra: "s" - salvar a configuração atual do jogo em arquivo **/
						
						default: 		/* o comando digitado pelo usuário não faz parte de nenhum dos comandos utilizáveis */
							goto: leitura_do_comando;
					}
				}
				
			/* comparar as células vizinhas para preencher com a cor escolhida   *
			* verificar possibilidade de implantar uma sub-rotina recursiva aqui *
			* varreduras de linhas e colunas 									*/
		 
		 
			// !important: "será preciso, a cada rodada, verificar se o tabuleiro está completo para encerrar o jogo? 
	}
}
