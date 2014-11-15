#include <stdio.h>
#include <stdlib.h>
#include "flood.h"
#include <time.h>

void gerar_tabela(int l, int c){

	srand( (unsigned)time(NULL) );
	for(contl = 0; contl < l; contl++){
		for(contc = 0; contc < c; contc++){
			aleatorio = (rand() % 6);
			tabuleiro[contl][contc] = aleatorio;
		}
	}
}

void exibir_tabela(int l, int c){
	for(contl = 0; contl < l; contl++){
		printf("\n");
		for(contc = 0; contc < c; contc++){
			printf("%i ", tabuleiro[contl][contc]);
		}
	}
}

void inundar(int L, int C, int tabuleiro[L][C], int l, int c, int atual, int comando ){
	if(tabuleiro[l][c] == atual) {
		tabuleiro[l][c] = comando;
		if(l < 14){ inundar(14, 14, tabuleiro, l + 1, c, atual, comando); }
		if(l > 0) { inundar(14, 14, tabuleiro, l - 1, c, atual, comando); }
		if(c < 14){ (inundar(14, 14, tabuleiro, l, c + 1, atual, comando)); }
		if(c > 0){ inundar(14, 14, tabuleiro, l, c - 1, atual, comando);}
	}
}

void novo_jogo()
{
	printf("\n\nAqui está o tabuleiro. seu objetivo é preenchê-lo com um único valor começando pelo canto superior esquerdo. você tem 25 tentativas. Boa Sorte!\n");
	gerar_tabela( 14, 14 );
	exibir_tabela ( 14, 14);
	printf("\n");
}

void ler_matriz(int l, int c){
    arquivo = fopen("arquivo.txt","r+");

    if(arquivo)
    {
        erro = 0;
        for(contl = 0; contl < l; contl++)
        {
            for(contc = 0; contc < c; contc++)
            {
            // (!fscanf(arquivo,"%d", &tabuleiro[contl][contc]));
            //  {
            //      erro = 1;
            //      printf("Erro a o ler a entrada (%d,%d) da matriz\n",contl,contc);
            //        break;
            }
        }

            if(erro)
            break;
        }
        fclose(arquivo);
    }
    else
    {
    printf("Erro ao abrir o arquivo texto para leitura");
    }
}

void escrever_matriz(int l, int c){
    arquivo = fopen("arquivo.txt","w+");
      if(arquivo)
      {
        for(contl = 0; contl < l; contl++)
        {
            for(contc = 0; contc < c; contc++)
            {
                fprintf(arquivo,"%d",tabuleiro[contl][contc]);
            }
            fprintf(arquivo,"\n");
        }
        fclose(arquivo);
        printf("Jogo SALVO!!");
      }
      else
      {
        printf("Erro ao abrir o arquivo texto para escrita");
      }
}

/* void menu_opcoes()
{
	printf("\nMenu de Opções:\n");
	printf("1,2,3,4,5 > Preencher o tabuleiro com os valores\n");
	printf("q > sair do jogo\n");
	printf("s > salvar o jogo\n");
	printf("o > carregar um jogo\n");
} */

void executa(int comando)
{
	switch( comando )
	{
		case 48: // comando '0'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 0);
		    break;
		case 49: // comando '1'
			inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 1);
			break;
		case 50: // comando '2'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 2);
		    break;
		case 51: // comando '3'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 3);
		    break;
		case 52: // comando '4'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 4);
		    break;
		case 53: // comando '5'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 5);
		    break;
		case 113: // comando 'q'
			printf("\nO jogo está sendo encerrado...\n");
			exit(1);
		case 115: // comando 's'
			escrever_matriz(14,14);
			exit(1);
			break;
		default:;
	}
}
