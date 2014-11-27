#include <stdio.h>
#include <stdlib.h>
#include "flood.h"
#include <time.h>

void novo_jogo()
{           /*Definição de qual nível de dificuldade escolhida
             *Atribuindo valores de linhas, colunas, itens, jogadas
             */
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
/*Criação de uma matriz com os valores estabelecidados em dificuldade
*/
void gerar_tabela(int l, int c)
{
	srand( (unsigned)time(NULL) ); //função para a criação de um número aleatório
	for(contl = 0; contl < l; contl++) //for para linhas
	{
		for(contc = 0; contc < c; contc++) //for para colunas
		{
			aleatorio = (rand() % padrao.max_itens); //criação de um valor aleatório
			tabuleiro[contl][contc] = aleatorio; //Atribuição de um valor aleatório ao elemento da matriz
		}
	}
}
/*Exibição da matriz com os valor estabelecidos em dificuldade
*/
void exibir_tabela(int l, int c){
	for(contl = 0; contl < l; contl++){ //contador de linhas
		printf("\n");   //quebra de linha
		printf("\t\t\t"); //tabulações
		for(contc = 0; contc < c; contc++){ //contador de colunas
			printf("%i ", tabuleiro[contl][contc]); //exibindo o valor de um determinado elemento
		}
	}
}

/*Leitura de matriz a partir de um arquivo txt
*/
void ler_matriz(){
    arquivo = fopen(url,"r+"); //abertura do arquivo
    if(arquivo != NULL) //Se existir tal aquivo o if será acionado
    {
		fscanf(arquivo,"%i ", &padrao.max_lin); //leitura do valor de linhas
		fscanf(arquivo,"%i ", &padrao.max_col); //leitura do valor de colunas
		fscanf(arquivo,"%i ", &padrao.max_jogadas); //leitura do valor de jogadas
		fscanf(arquivo,"\n");
        for(contl = 0; contl < padrao.max_lin; contl++) //contador de linhas
        {
            for(contc = 0; contc < padrao.max_col; contc++) //contador de colunas
            {
				fscanf(arquivo,"%d", &tabuleiro[contl][contc]); //leitura do valor d eum determinado elemento da matriz salva
                if(contc < padrao.max_col)
					fscanf(arquivo," "); //espaçamento entre elementos
				else
					fscanf(arquivo,"\n"); //se for o ultimo elemento de uma coluna terá uma quebra de linhas
            }
        }
        fscanf(arquivo,"%i", &jogada); //leitura do valor de jogadas
			fclose(arquivo); //fechamento de arquivo
        }
    else //Se não exitir arquivo
    {
    printf("\n\t(X)Erro ao abrir o arquivo texto para leitura. Verifique se o arquivo ou diretório existem.\n");
    printf("\t(!)O jogo será encerrado...\n");
    exit(1); //saída do jogo
    }

}

/*Salvar jogo em um arquivo txt
*/
void escrever_matriz(int l, int c){
    arquivo = fopen(url,"w+"); //abertura do arquivo
      if(arquivo != NULL)
      {
		fprintf(arquivo,"%i ",padrao.max_lin);
		fprintf(arquivo,"%i ",padrao.max_col);
		fprintf(arquivo,"%i ",padrao.max_jogadas);
		fprintf(arquivo,"\n");
        for(contl = 0; contl < l; contl++) //contador de linhas
        {
            for(contc = 0; contc < c; contc++) //contador de colunas
            {
                fprintf(arquivo,"%d",tabuleiro[contl][contc]); //Salvando valor do determinado elemento da matriz
                if(contc < c-1)
					fprintf(arquivo," "); //espaçamento entre elementos
				else
					fprintf(arquivo,"\n"); //se for o ultimo elemento de uma coluna terá uma quebra de linhas
            }
        }
		fprintf(arquivo,"%d", jogada); //Salvamento do valor de jogadas
        fclose(arquivo); //fechando arquivo
        printf("\n\t(!)Partida salva com sucesso!");
      }
      else
      {
        printf("\t(X)Erro ao abrir o arquivo texto para escrita.\n");
        printf("\t(!)O jogo será encerrado...\n");
        exit(1);
      }
}
/*Verificação periodica de vitória
*/
void checar_vitoria(int l, int c, int referencia)
{
	int contador = 0;
	for(contl = 0; contl < l; contl++) //contador linha
	{
		for(contc=0; contc < c; contc++) //contadot coluna
		{
			if(tabuleiro[contl][contc] == referencia) //Determinado elemento da matriz for igual ao primeiro elemento da matriz
				contador++; //atribuição de valor na variável contador
		}
	}

    if(contador == (padrao.max_lin * padrao.max_col)) //verificação de elementos completando a matriz ao total de elementos
        vitoria = Verdadeiro; // Ganhou jogo
    else
        vitoria = Falso; // Ainda não ganhou jogo
}
/*Objetivo de abrir um jogo que foi salvo em um arquivo txt
*/
void carregarJogo()
{
	int comando_local;
	printf("\n\t(!) Qual partida deseja carregar?\n");
	printf("\n\t'1' > abrir última partida salva na pasta padrão local\n\t'0' > definir um endereço de um arquivo\n\n");
	printf("\tOpção >> ");
	scanf("%i", &comando_local);
	if(comando_local==1){ //Abertura de um arquivo na pasta local do jogo
		ler_matriz(); //Leitura da matriz salva
		exibir_tabela(padrao.max_lin, padrao.max_col); //Exibição da matriz
	}
	else { //abertura de um arquivo com endereço determinado
		printf("\n\t(!)Digite um caminho para abrir o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/floodit.txt'\n\t");
		scanf(" %s", url); //Determinado endereço do arquivo
		ler_matriz(); //Leitura da matriz salva
		exibir_tabela(padrao.max_lin, padrao.max_col); //Exibição da matriz
	}
}

/* encerramento de jogo*/
void encerrarJogo()
{
	printf("\n\t(!)O jogo está sendo encerrado...\n");
	exit(1); //Saída jogo
}

/*Salvar jogo */
void salvarJogo()
{
	int comando;
	printf("\n\t(!) Onde você deseja salvar o arquivo do jogo?\n");
	printf("\t'1' salvar na pasta padrão local - '0' definir um endereço\n");
	printf("\topção >> ");
	scanf("%d", &comando); //Escolha do local onde será salvo o arquivo txt
		if(comando){ //Pasta local
			escrever_matriz(padrao.max_lin, padrao.max_col); //Escrita da matriz
			printf("\n\t(!)O jogo está sendo encerrado...\n");
			exit(1); //saída do jogo
		}
		else { //Determinando endereço
			printf("\n\tDigite um caminho para guardar o arquivo da jogada. Ex: 'C:/Usuario/Meus Documentos/arquivo.txt'\n\t");
			scanf("%s", url); //Atribuição do endereço do arquivo txt
			escrever_matriz(padrao.max_lin, padrao.max_col);//Escrita da matriz
			printf("\n\t(!)O jogo está sendo encerrado...\n");
			exit(1); //saída do jogo
		}
}

/*Função recursiva com objetivo de deixar matriz com uma única cor(número)
*/
void inundar(int line, int column, int atual, int novo_valor)
{
	if(column >= padrao.max_col || line >= padrao.max_lin || line < 0 || column < 0) return 0; //Elementos fora da matriz

	if(tabuleiro[line][column] == atual && novo_valor != atual) //verificação de determinando elemento da matriz é igual ao primeiro elemento. Verificação se a cor(número) não é igual à jogada anterior
	{
		tabuleiro[line][column] = novo_valor; //Determinado elemento da matriz recebendo novo valor da jogada atual
		inundar(line, column+1, atual, novo_valor);
		inundar(line+1, column, atual, novo_valor);
		inundar(line-1, column, atual, novo_valor);
        inundar(line, column-1, atual, novo_valor);
	}
}
/*Painel de controle do jogo
*/
void executar(int comando)
{
	if(comando - 48 >= 0 && comando - 48 <= padrao.max_itens)
	{
		inundar(0, 0, tabuleiro[0][0], comando - 48); //Imundar matriz
		checar_vitoria(padrao.max_lin, padrao.max_col, comando - 48); //Verificando vitória
		printf("\n");
		exibir_tabela(padrao.max_lin, padrao.max_col); //Exibição de tabela
	}
	else
	{
		switch( comando )
		{
			case 111: carregarJogo(); break; //Carregamento da jogada anterior
			case 113: encerrarJogo(); //Encerrando jogo
			case 115: salvarJogo(); //salvamento do jogo
			default:
			printf("\n\t(X) Opção inválida. tente novamente\n");
			exibir_tabela(padrao.max_lin, padrao.max_col); //exibição da matriz
			entrada_invalida = Verdadeiro; //A entrada foi inválida
			break;
		}
	}
}
