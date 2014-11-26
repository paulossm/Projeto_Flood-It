#include <stdio.h>
#include <stdlib.h>
#include "flood.h"
#include <time.h>

void novo_jogo()
{
	
	unsigned char dificuldade;
		    printf("\n\tSelecione a Dificuldade:\n");
		    printf("\t1 - Fácil\n");
		    printf("\t2 - Normal\n");
		    printf("\t3 - Díficil\n");
		    printf("\n\t opção >> ");
		    scanf(" %c", &dificuldade);

		    switch((int)dificuldade){
                case 49:
                    padrao.max_col = 10;
                    padrao.max_lin = 10;
                    padrao.max_jogadas = 20;
                    padrao.max_itens = 6;
                    break;
                case 50:
                    padrao.max_col = 14;
                    padrao.max_lin = 14;
                    padrao.max_jogadas = 25;
                    padrao.max_itens = 6;
                    break;
                case 51:
                    padrao.max_col = 18;
                    padrao.max_lin = 18;
                    padrao.max_jogadas = 30;
                    padrao.max_itens = 6;
                    break;
                default:
                    printf("Comando inválido!\n");
                    novo_jogo();
                    break;
                }
					system("clear");
					printf("\n\n(i)Preencha o tabuleiro com um único valor entre 0 - 5 começando pelo canto superior esquerdo. Você tem %i tentativas. Boa Sorte!\n", padrao.max_jogadas);
					gerar_tabela(padrao.max_lin, padrao.max_col);
					exibir_tabela(padrao.max_lin, padrao.max_col);
}

void gerar_tabela(int l, int c)
{
	padrao.matriz = (int **) malloc(l * sizeof(int));
	if(padrao.matriz == NULL)
	{
		printf("(!)ERRO: Sem memória disponível para execução do Programa! :(\n");
		printf("(!)O jogo está sendo encerrado...\n");
		exit(1);
	}
	srand( (unsigned)time(NULL) );
	for(contl = 0; contl < l; contl++)
	{
		*(padrao.matriz + contl) = (int *) malloc(c * sizeof(int));
		
		for(contc = 0; contc < c; contc++)
		{
			aleatorio = (rand() % padrao.max_itens);
			padrao.matriz[contl][contc] = aleatorio;
		}
	}
}

void exibir_tabela(int l, int c){
	for(contl = 0; contl < l; contl++){
		printf("\n");
		printf("\t\t\t");
		for(contc = 0; contc < c; contc++){
			printf("%i ", padrao.matriz[contl][contc]);
		}
	}
	printf("\n");
}

void ler_matriz(int l, int c, int **tabuleiro, int jogada)
{
    arquivo = fopen(url,"r");

    if(arquivo != NULL)
    {
        for(contl = 0; contl < l; contl++)
        {
            for(contc = 0; contc < c; contc++)
            {
				printf("%i ", contl * l + contc);
				fscanf(arquivo,"%d", *(tabuleiro+(contl * l + contc)));
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
    printf("\n(i)Erro ao abrir o arquivo texto para leitura. Verifique se o arquivo ou diretório existem.\n");
    printf("(i)O jogo será encerrado...\n");
    exit(1);
    }
}

void escrever_matriz(int l, int c, int jogada){
    arquivo = fopen(url,"w+");
      if(arquivo != NULL)
      {
        for(contl = 0; contl < l; contl++)
        {
            for(contc = 0; contc < c; contc++)
            {
                fprintf(arquivo,"%d", padrao.matriz[contl][contc]);
                if(contc < c-1)
					fprintf(arquivo," ");
				else
					fprintf(arquivo,"\n");
            }
        }
		fprintf(arquivo,"%d", jogada);
        fclose(arquivo);
        printf("\n\t(i)Partida salva com sucesso!");
      }
      else
      {
        printf("\t(i)Erro ao abrir o arquivo texto para escrita.\n");
        printf("\t(i)O jogo será encerrado...\n");
        exit(1);
      }
}

void checar_vitoria(int l, int c, int referencia)
{
	int contador = 0;
	for(contl = 0; contl < l; contl++)
	{
		for(contc=0; contc < c; contc++)
		{
			if(padrao.matriz[contl][contc] == referencia)
				contador++;
		}
	}
    if(contador == (padrao.max_lin * padrao.max_col))
        vitoria = Verdadeiro; // verdadeiro
    else
        vitoria = Falso; // falso
}

void carregarJogo()
{
	int comando_local;
	printf("\n(i) Qual partida deseja carregar?\n");
	printf("\n\t'1' > abrir última partida salva na pasta padrão local\n\t'0' > definir um endereço de um arquivo\n\n");
	printf("\tOpção >> ");
	scanf("%d", &comando_local);
	if(comando_local){
		ler_matriz(padrao.max_lin, padrao.max_col, padrao.matriz, jogada);
		exibir_tabela(padrao.max_lin, padrao.max_col);
	}
	else {
		printf("\n(i)Digite um caminho para abrir o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/floodit.txt'\n");
		scanf(" %s", url);
		ler_matriz(padrao.max_lin, padrao.max_col, padrao.matriz, jogada);
		exibir_tabela(padrao.max_lin, padrao.max_col);
	}
	printf("\n");
}

void encerrarJogo()
{
	printf("\n\t(i)O jogo está sendo encerrado...\n");
	exit(1);
}
void salvarJogo(int jogada)
{
	int comando;
	printf("\n(i) Onde você deseja salvar o arquivo do jogo?\n");
	printf("'1' salvar na pasta padrão local - '0' definir um endereço\n");
	printf("seu comando: ");
	scanf("%d", &comando);
		if(comando){
			escrever_matriz(padrao.max_lin, padrao.max_col, jogada);
			printf("\nO jogo está sendo encerrado...\n");
			exit(1);
		}
		else {
			printf("\nDigite um caminho para guardar o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/arquivo.txt'\n");
			scanf("%s", url);
			escrever_matriz(padrao.max_lin, padrao.max_col, jogada);
			printf("\nO jogo está sendo encerrado...\n");
			exit(1);
		}
}

int inundar(int maxlin, int maxcol, int **tabuleiro, int l, int c, int atual, int novo_valor){
	if(c >= maxcol || l >= maxlin || l < 0 || c < 0) return 0;

	if(tabuleiro[l][c] == atual && novo_valor != atual)
	{
		tabuleiro[l][c] = novo_valor;
        inundar(maxlin, maxcol, tabuleiro, l, c+1, atual, novo_valor);
		inundar(maxlin, maxcol, tabuleiro, l+1, c, atual, novo_valor);
        inundar(maxlin, maxcol, tabuleiro, l-1, c, atual, novo_valor);
        inundar(maxlin, maxcol, tabuleiro, l, c-1, atual, novo_valor);
	}
	return 0;
}

void executar(int comando, int jogada)
{
	if(comando - 48 >= 0 && comando - 48 <= padrao.max_itens)
	{
		inundar(padrao.max_lin, padrao.max_col, padrao.matriz, 0, 0, padrao.matriz[0][0], comando - 48);
		checar_vitoria(padrao.max_lin, padrao.max_col, comando - 48);
		printf("\n");
		exibir_tabela(padrao.max_lin, padrao.max_col);
	}
	else
	{
		switch( comando )
		{
			case 111: carregarJogo(); break;
			case 113: encerrarJogo();
			case 115: salvarJogo(jogada);
			default:
			printf("\n\t(i) opção inválida. tente novamente\n");
			exibir_tabela(padrao.max_lin, padrao.max_col);
			entrada_invalida = Verdadeiro;
			break;
		}
	}
}
