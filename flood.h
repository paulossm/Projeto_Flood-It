#ifndef __flood
#define __flood

#define linhas 14
#define colunas 14
#define jogadas 25
#define elementos 6

/* --- Variáveis de execução do jogo --- */

typedef struct {
	int max_lin;
	int max_col;
	int max_jogadas;
	int max_itens;
	int **matriz;
}Configuracao;

Configuracao padrao = {linhas,colunas,jogadas,elementos};

typedef enum {
	Falso,
	Verdadeiro
} Booleano;

Booleano vitoria, entrada_invalida;

/* --- Tipos definidos --- */
int aleatorio, contl, contc, l, c, i, jogada = 0, contador;
int tabuleiro[colunas][linhas];
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
 * @param maxlin é o número máximo de linhas
 * @param maxcol é o número máximo de colunas
 * @param **tabuleiro é o ponteiro do ponteiro da matriz
 * @param l é a linha atual da matriz
 * @param c é a coluna atual da matriz
 * @param atual é o valor do atual elemento da matriz
 * @param novo_valor é o novo valor que será atribuido, se for igual à referencia da matriz
 */
int inundar(int maxlin, int maxcol, int **tabuleiro, int l, int c, int atual, int novo_valor);

/* *
 * Realiza a leitura de um jogo salvo
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void ler_matriz(int l, int c, int **tabuleiro, int jogada);

/* *
 * Salva a matriz de um jogo
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 * @param jogada é a jogada atual do jogador
 */
void escrever_matriz(int l, int c, int jogada);

/* *
 * Percorre a matriz de um jogo para verificação de ganho
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 * @para referencia para o primeiro elemento da matriz
 */
void checar_vitoria(int L, int C, int referencia);
#endif
