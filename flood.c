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
	printf("\n");
}

void inundar(int L, int C, int tabuleiro[L][C], int l, int c, int atual, int comando ){
	if(tabuleiro[l][c] == atual && comando != atual) {
		tabuleiro[l][c] = comando;
		if(l < 14) inundar(14, 14, tabuleiro, l + 1, c, atual, comando);
		if(l > 0) inundar(14, 14, tabuleiro, l - 1, c, atual, comando);
		if(c < 14) inundar(14, 14, tabuleiro, l, c + 1, atual, comando);
		if(c > 0) inundar(14, 14, tabuleiro, l, c - 1, atual, comando);
	}
}

void novo_jogo()
{
	printf("\n\n(!)Aqui está o tabuleiro. seu objetivo é preenchê-lo com um único valor começando pelo canto superior esquerdo. você tem 25 tentativas. Boa Sorte!\n");
	gerar_tabela( 14, 14 );
	exibir_tabela(14,14);
	i = 1;
}
//void abrir_jogo()
//{
//	exibir_tabela (14, 14);
//

void ler_matriz(int l, int c){
    arquivo = fopen(url,"r");

    if(arquivo != NULL)
    {
        for(contl = 0; contl < l; contl++)
        {
            for(contc = 0; contc < c; contc++)
            {
				fscanf(arquivo,"%d", &tabuleiro[contl][contc]);
                if(contc < c-1)
					fscanf(arquivo," ");
				else
					fscanf(arquivo,"\n"); 
            }
        }
        fscanf(arquivo,"%d", &jogada);
			fclose(arquivo);
        }
    else 
    {
    printf("\n(!)Erro ao abrir o arquivo texto para leitura. Verifique se o arquivo ou diretório existem.\n");
    printf("(!)O jogo será encerrado...\n");
    exit(1);
    }
    
}

void escrever_matriz(int l, int c){
    arquivo = fopen(url,"w+");
      if(arquivo != NULL)
      {
        for(contl = 0; contl < l; contl++)
        {
            for(contc = 0; contc < c; contc++)
            {
                fprintf(arquivo,"%d",tabuleiro[contl][contc]);
                if(contc < c-1)
					fprintf(arquivo," ");
				else
					fprintf(arquivo,"\n");
            }
        }
		fprintf(arquivo,"%d", jogada);
        fclose(arquivo);
        printf("\n(!)Partida salva com sucesso!");
      }
      else
      {
        printf("(!)Erro ao abrir o arquivo texto para escrita.\n");
        printf("(!)O jogo será encerrado...\n");
        exit(1);
      }
}
void trapaceia(int cor){
	int v, b;
	for(v=0;v<14;v++)
	{
		for(b=0;b<14;b++)
		{
			tabuleiro[v][b] = cor;
		}
	}
}

void percorrer(int L, int C, int referencia)
{
	int d, e, contador = 0;
	for(d=0;d<L;d++)
	{
		for(e=0;e<C;e++)
		{
			if(tabuleiro[d][e] == referencia)
				contador++;
		}
	}
			if(contador == (L * C))
				cond = 1; // verdadeiro
			else
				cond = 0; // falso
}

void executa (int comando)
{
	switch( comando )
	{
		case 48: // comando '0'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], comando - 48);
			// trapaceia(0); // --> usada para simular o preenchimento do tabuleiro completo.
			percorrer(14,14,0);
		    printf("\n");
			exibir_tabela(14,14);
		    break;
		case 49: // comando '1'
			inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], comando - 48);
			percorrer(14,14,1);
			printf("\n");
			exibir_tabela(14,14);
			break;
		case 50: // comando '2'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 2);
		    percorrer(14,14,2);
		    printf("\n");
			exibir_tabela(14,14);
		    break;
		case 51: // comando '3'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 3);
		    percorrer(14,14,3);
		    printf("\n");
			exibir_tabela(14,14);
		    break;
		case 52: // comando '4'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 4);
		    percorrer(14,14,4);
		    printf("\n");
			exibir_tabela(14,14);
		    break;
		case 53: // comando '5'
		    inundar(14, 14, tabuleiro, 0, 0, tabuleiro[0][0], 5);
		    percorrer(14,14,5);
		    printf("\n");
			exibir_tabela(14,14);
		    break;
		case 111: // comando 'o'
			printf("\n(?) Qual partida deseja carregar?\n");
			printf("'1' abrir última partida salva na pasta padrão local - '0' definir um endereço de um arquivo\n");
			
			printf("seu comando: ");
			scanf("%d", &comando);
				if(comando){
					ler_matriz(14,14);
					exibir_tabela(14,14);
				}
				else {
					printf("\n(?)Digite um caminho para abrir o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/arquivo.txt'\n");
					scanf(" %s", url);
					ler_matriz(14,14);
					exibir_tabela(14,14);
				}
				printf("\n");
				break;
		case 113: // comando 'q'
			printf("\n(!)O jogo está sendo encerrado...\n");
			exit(1);
		case 115: // comando 's'
			printf("\n(?) Onde você deseja salvar o arquivo do jogo?\n");
			printf("'1' salvar na pasta padrão local - '0' definir um endereço\n");
			printf("seu comando: ");
			scanf("%d", &comando);
				if(comando){
					escrever_matriz(14,14);
					printf("\nO jogo está sendo encerrado...\n");
					exit(1);
				}
				else {
					printf("\nDigite um caminho para guardar o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/arquivo.txt'\n");
					scanf("%s", url);
					escrever_matriz(14,14);
					printf("\nO jogo está sendo encerrado...\n");
					exit(1);
				}
			break;
		default:
			printf("(!) comando inválido. tente novamente\n");
			erro = 1;
			break;
	}
}
