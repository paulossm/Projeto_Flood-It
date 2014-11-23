#include <stdio.h>
#include <stdlib.h>
#include "flood.h"
#include <time.h>

void gerar_tabela(int l, int c)
{
	srand( (unsigned)time(NULL) );
	for(contl = 0; contl < l; contl++)
	{
		for(contc = 0; contc < c; contc++)
		{
			aleatorio = (rand() % 6);
			tabuleiro[contl][contc] = aleatorio;
		}
	}
}

void exibir_tabela(int l, int c)
{
	for(contl = 0; contl < l; contl++)
	{
		printf("\n");
		for(contc = 0; contc < c; contc++){
			printf("%i ", tabuleiro[contl][contc]);
		}
	}
	printf("\n");
}

void inundar(int L, int C, int tabuleiro[L][C], int l, int c, int atual, int comando )
{
	if(tabuleiro[l][c] == atual && comando != atual)
	{
		tabuleiro[l][c] = comando;
<<<<<<< HEAD
			if(l < 14)
				inundar(linhas, colunas, tabuleiro, l + 1, c, atual, comando);
			if(l > 0)
				inundar(linhas, colunas, tabuleiro, l - 1, c, atual, comando);
			if(c < 14)
				inundar(linhas, colunas, tabuleiro, l, c + 1, atual, comando);
			if(c > 0)
				inundar(linhas, colunas, tabuleiro, l, c - 1, atual, comando);
=======
		if(l < 14)
            inundar(linhas, colunas, tabuleiro, l + 1, c, atual, comando);
		if(l > 0)
            inundar(linhas, colunas, tabuleiro, l - 1, c, atual, comando);
		if(c < 14)
            inundar(linhas, colunas, tabuleiro, l, c + 1, atual, comando);
		if(c > 0)
            inundar(linhas, colunas, tabuleiro, l, c - 1, atual, comando);
>>>>>>> d5ae0920f3e0252141abb83b1af002375285c172
	}
}

void novo_jogo()
{
<<<<<<< HEAD
	printf("\n\n(!)Aqui está o tabuleiro. seu objetivo é preenchê-lo com um único valor entre (0) e (5) começando pelo canto superior esquerdo. você tem 25 tentativas. Boa Sorte!\n");
=======
	printf("\n\n(!)Aqui está o tabuleiro. seu objetivo é preenchê-lo com um único valor começando pelo canto superior esquerdo. você tem 25 tentativas. Boa Sorte!\n");
>>>>>>> d5ae0920f3e0252141abb83b1af002375285c172
	gerar_tabela(linhas, colunas);
	exibir_tabela(linhas,colunas);
	i = 1;
}

void ler_matriz(int l, int c)
{
    arquivo = fopen(url,"r");
<<<<<<< HEAD
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
=======

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
>>>>>>> d5ae0920f3e0252141abb83b1af002375285c172

}

void escrever_matriz(int l, int c)
{
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
<<<<<<< HEAD

void percorrer(int l, int c, int referencia)
{
	int contador = 0;
	for(contl = 0; contl < l; contl++)
	{
		for(contc=0; contc < c; contc++)
		{
			if(tabuleiro[contl][contc] == referencia)
				contador++;
		}
	}
	
	if(contador == (linhas * colunas))
		venceu = 1; // verdadeiro
	else
		venceu = 0; // falso
}

void carregarJogo()
{
	int comando_local;
	printf("\n(?) Qual partida deseja carregar?");
	printf("\n'1' abrir última partida salva na pasta padrão local\n'0' definir um endereço de um arquivo\n");
	printf("seu comando: ");
	scanf("%d", &comando_local);
		if(comando_local)
		{
			ler_matriz(linhas, colunas);
			exibir_tabela(linhas, colunas);
		}
		else
		{
			printf("\n(?)Digite um caminho para abrir o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/arquivo.txt'\n");
			scanf(" %s", url);
			ler_matriz(linhas, colunas);
			exibir_tabela(linhas, colunas);
		}
	printf("\n");
}

void encerrarJogo()
{
	printf("\n(!)O jogo está sendo encerrado...\n");
	exit(1);
}
void salvarJogo()
{
	int comando;
	printf("\n(?) Onde você deseja salvar o arquivo do jogo?\n");
	printf("'1' salvar na pasta padrão local - '0' definir um endereço\n");
	printf("seu comando: ");
	scanf("%d", &comando);
		if(comando)
		{
			escrever_matriz(linhas, colunas);
			printf("\nO jogo está sendo encerrado...\n");
			exit(1);
		}
		else
		{
			printf("\nDigite um caminho para guardar o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/arquivo.txt'\n");
			scanf("%s", url);
			escrever_matriz(linhas, colunas);
			printf("\nO jogo está sendo encerrado...\n");
			exit(1);
		}
=======

void percorrer(int l, int c, int referencia)
{
	int contador = 0;
	for(contl = 0; contl < l; contl++)
	{
		for(contc=0; contc < c; contc++)
		{
			if(tabuleiro[contl][contc] == referencia)
				contador++;
		}
	}
			if(contador == (linhas * colunas))
				cond = 1; // verdadeiro
			else
				cond = 0; // falso
>>>>>>> d5ae0920f3e0252141abb83b1af002375285c172
}

void executa (int comando)
{
<<<<<<< HEAD
	if(comando - 48 >= 0 && comando - 48 <= 5)
	{
		inundar(linhas,colunas,tabuleiro, 0, 0, tabuleiro[0][0], comando - 48);
		percorrer(linhas, colunas, comando - 48);
		printf("\n");
		exibir_tabela(linhas, colunas);
	}
	else
	{
		switch( comando )
		{
			case 111: carregarJogo(); break;
			case 113: encerrarJogo();
			case 115: salvarJogo();
			default: 
				printf("(!) comando inválido. tente novamente\n");
				invalido = 1;
=======
	switch(comando)
	{
		case 48: // comando '0'
		    inundar(linhas, colunas, tabuleiro, 0, 0, tabuleiro[0][0], comando - 48);
			percorrer(linhas, colunas, comando - 48);
		    printf("\n");
			exibir_tabela(linhas, colunas);
		    break;
		case 49: // comando '1'
			inundar(linhas, colunas, tabuleiro, 0, 0, tabuleiro[0][0], comando - 48);
			percorrer(linhas, colunas, comando - 48);
			printf("\n");
			exibir_tabela(linhas, colunas);
			break;
		case 50: // comando '2'
		    inundar(linhas, colunas, tabuleiro, 0, 0, tabuleiro[0][0], comando - 48);
		    percorrer(linhas, colunas, comando - 48);
		    printf("\n");
			exibir_tabela(linhas, colunas);
		    break;
		case 51: // comando '3'
		    inundar(linhas, colunas, tabuleiro, 0, 0, tabuleiro[0][0], comando - 48);
		    percorrer(linhas, colunas, comando - 48);
		    printf("\n");
			exibir_tabela(linhas, colunas);
		    break;
		case 52: // comando '4'
		    inundar(linhas, colunas, tabuleiro, 0, 0, tabuleiro[0][0], comando - 48);
		    percorrer(linhas, colunas, comando - 48);
		    printf("\n");
			exibir_tabela(linhas, colunas);
		    break;
		case 53: // comando '5'
		    inundar(linhas, colunas, tabuleiro, 0, 0, tabuleiro[0][0], comando - 48);
		    percorrer(linhas, colunas, comando - 48);
		    printf("\n");
			exibir_tabela(linhas, colunas);
		    break;
		case 111: // comando 'o'
			printf("\n(?) Qual partida deseja carregar?\n");
			printf("'1' abrir última partida salva na pasta padrão local - '0' definir um endereço de um arquivo\n");

			printf("seu comando: ");
			scanf("%d", &comando);
            if(comando){
                ler_matriz(linhas, colunas);
                exibir_tabela(linhas, colunas);
            }
            else {
                printf("\n(?)Digite um caminho para abrir o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/arquivo.txt'\n");
                scanf(" %s", url);
                ler_matriz(linhas, colunas);
                exibir_tabela(linhas, colunas);
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
                escrever_matriz(linhas, colunas);
                printf("\nO jogo está sendo encerrado...\n");
                exit(1);
            }
            else {
                printf("\nDigite um caminho para guardar o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/arquivo.txt'\n");
                scanf("%s", url);
                escrever_matriz(linhas, colunas);
                printf("\nO jogo está sendo encerrado...\n");
                exit(1);
            }
			break;
		default:
			printf("(!) comando inválido. tente novamente\n");
			erro = 1;
>>>>>>> d5ae0920f3e0252141abb83b1af002375285c172
			break;
		}	
	}
}
