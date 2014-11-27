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
                case 49:                //comando 1
                    padrao.max_col = 10;
                    padrao.max_lin = 10;
                    padrao.max_jogadas = 20;
                    padrao.max_itens = 6;
                    break;
                case 50:                //comando 2
                    padrao.max_col = 14;
                    padrao.max_lin = 14;
                    padrao.max_jogadas = 25;
                    padrao.max_itens = 6;
                    break;
                case 51:                //comando 3
                    padrao.max_col = 18;
                    padrao.max_lin = 18;
                    padrao.max_jogadas = 30;
                    padrao.max_itens = 6;
                    break;
                default:                //comando inválido
                    printf("Comando inválido!\n");
                    novo_jogo();
                    break;
                }
					system("clear"); //limprar promt antes da exibição da partida
					printf("\n\n(i)Preencha o tabuleiro com um único valor entre 0 - 5 começando pelo canto superior esquerdo. Você tem %i tentativas. Boa Sorte!\n", padrao.max_jogadas);
					gerar_tabela(padrao.max_lin, padrao.max_col); //Criação da tabela
					exibir_tabela(padrao.max_lin, padrao.max_col); //Exibição da tabela
	
}

void gerar_tabela(int l, int c)
{
	srand( (unsigned)time(NULL) );
	for(contl = 0; contl < l; contl++)
	{
		for(contc = 0; contc < c; contc++)
		{
			aleatorio = (rand() % padrao.max_itens);
			tabuleiro[contl][contc] = aleatorio;
		}
	}
}

void exibir_tabela(int l, int c){
	for(contl = 0; contl < l; contl++){
		printf("\n");
		printf("\t\t\t");
		for(contc = 0; contc < c; contc++){
			printf("%i ", tabuleiro[contl][contc]);
		}
	}
}

void ler_matriz(){
    arquivo = fopen(url,"r+");
    if(arquivo != NULL)
    {
		fscanf(arquivo,"%i ", &padrao.max_lin);
		fscanf(arquivo,"%i ", &padrao.max_col);
		fscanf(arquivo,"%i ", &padrao.max_jogadas);
		fscanf(arquivo,"\n");
        for(contl = 0; contl < padrao.max_lin; contl++)
        {
            for(contc = 0; contc < padrao.max_col; contc++)
            {
				fscanf(arquivo,"%d", &tabuleiro[contl][contc]);
                if(contc < padrao.max_col)
					fscanf(arquivo," ");
				else
					fscanf(arquivo,"\n");
            }
        }
        fscanf(arquivo,"%i", &jogada);
			fclose(arquivo);
        }
    else
    {
    printf("\n\t(X)Erro ao abrir o arquivo texto para leitura. Verifique se o arquivo ou diretório existem.\n");
    printf("\t(!)O jogo será encerrado...\n");
    exit(1);
    }

}

void escrever_matriz(int l, int c){
    arquivo = fopen(url,"w+");
      if(arquivo != NULL)
      {
		fprintf(arquivo,"%i ",padrao.max_lin);
		fprintf(arquivo,"%i ",padrao.max_col);
		fprintf(arquivo,"%i ",padrao.max_jogadas);
		fprintf(arquivo,"\n");
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
        printf("\n\t(!)Partida salva com sucesso!");
      }
      else
      {
        printf("\t(X)Erro ao abrir o arquivo texto para escrita.\n");
        printf("\t(!)O jogo será encerrado...\n");
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
			if(tabuleiro[contl][contc] == referencia)
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
	printf("\n\t(!) Qual partida deseja carregar?\n");
	printf("\n\t'1' > abrir última partida salva na pasta padrão local\n\t'0' > definir um endereço de um arquivo\n\n");
	printf("\tOpção >> ");
	scanf("%i", &comando_local);
	if(comando_local==1){
		ler_matriz();
		exibir_tabela(padrao.max_lin, padrao.max_col);
	}
	else {
		printf("\n\t(!)Digite um caminho para abrir o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/floodit.txt'\n\t");
		scanf(" %s", url);
		ler_matriz();
		exibir_tabela(padrao.max_lin, padrao.max_col);
	}
}

void encerrarJogo()
{
	printf("\n\t(!)O jogo está sendo encerrado...\n");
	exit(1);
}
void salvarJogo()
{
	int comando;
	printf("\n\t(!) Onde você deseja salvar o arquivo do jogo?\n");
	printf("\t'1' salvar na pasta padrão local - '0' definir um endereço\n");
	printf("\topção >> ");
	scanf("%d", &comando);
		if(comando){
			escrever_matriz(padrao.max_lin, padrao.max_col);
			printf("\n\t(!)O jogo está sendo encerrado...\n");
			exit(1);
		}
		else {
			printf("\n\tDigite um caminho para guardar o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/arquivo.txt'\n\t");
			scanf("%s", url);
			escrever_matriz(padrao.max_lin, padrao.max_col);
			printf("\n\t(!)O jogo está sendo encerrado...\n");
			exit(1);
		}
}

void inundar(int line, int column, int atual, int novo_valor)
{
	if(column >= padrao.max_col || line >= padrao.max_lin || line < 0 || column < 0) return;
	if(tabuleiro[line][column] == atual && novo_valor != atual)
	{
		tabuleiro[line][column] = novo_valor;
		inundar(line, column+1, atual, novo_valor);
		inundar(line+1, column, atual, novo_valor);
		inundar(line-1, column, atual, novo_valor);
        inundar(line, column-1, atual, novo_valor);
	}
}

void executar(int comando)
{
	if(comando - 48 >= 0 && comando - 48 <= padrao.max_itens)
	{
		inundar(0, 0, tabuleiro[0][0], comando - 48);
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
			case 115: salvarJogo();
			default:
			printf("\n\t(X) Opção inválida. tente novamente\n");
			exibir_tabela(padrao.max_lin, padrao.max_col);
			entrada_invalida = Verdadeiro;
			break;
		}
	}
}
