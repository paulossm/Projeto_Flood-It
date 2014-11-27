#ifndef __flood
#define __flood

#define linhas 18
#define colunas 18
#define jogadas 30
#define elementos 6

/* --- Variáveis de execução do jogo --- */

typedef struct {
	int max_lin;
	int max_col;
	int max_jogadas;
	int max_itens;
}Configuracao;

Configuracao padrao = {18,18,30,6};

typedef enum {
	Falso,
	Verdadeiro
} Booleano;

Booleano vitoria, entrada_invalida;

/* --- Tipos definidos --- */
int aleatorio, contl, contc, l, line, c, column, i, jogada = 0, contador;
int tabuleiro[linhas][colunas];
/* --- comandos universais --- */
char opcao, comando;

/* --- comandos locais --- */
int atual, comando_local, novo_valor;

/* --- manipulação de arquivos --- */

FILE *arquivo;
char url[] = "arquivo.txt"; // caminho padrão para salvamento de arquivos

/* --- Sub-rotinas --- */

/* *
 * Realiza atribuição de valores na matriz
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void gerar_tabela(int l, int c);

/* *
 * Realiza a exibição de valores da matriz
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void exibir_tabela(int l, int c);

/* *
 * Realiza a execução de um novo jogo
 *
 *
 */
void novo_jogo();

/* *
 * Inundação de valores em toda matriz
 * @param utilização de line para linhas
 * @param utilização column para colunas
 * @param utilização atual para a cor da jogada anterior
 * @param utilização novo_valor para a cor da jogada atual
 */
void inundar(int line, int column, int atual, int novo_valor);
/* *
 * Realiza a leitura de um jogo salvo
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void ler_matriz();

/* *
 * Salva a matriz de um jogo
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void escrever_matriz(int l, int c);

/* *
 * Percorre a matriz de um jogo para verificação de ganho
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 * @para referencia para o primeiro elemento da matriz
 */
void checar_vitoria(int L, int C, int referencia);
#endif
