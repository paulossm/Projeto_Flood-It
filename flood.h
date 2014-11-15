#ifndef __flood
#define __flood

/* --- Tipos definidos --- */

int aleatorio, contl, contc, l, c, jogada, atual, acao, erro;
int tabuleiro[14][14];
char opcao, comando;
FILE *arquivo;



/* --- Sub-rotinas --- */

/* *
 * Realiza atribuição de valores.
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void gerar_tabela(int l, int c);

/* *
 * Realiza a exibição de valores
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void exibir_tabela(int l, int c);

/* *
 * Realiza a execução de um novo jogo
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void novo_jogo();

/* *
 * Inundação de valores em toda tabela
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void inundar();

void ler_matriz(int l, int c);

/* *
 * Salvar a matriz de um jogo
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void escrever_matriz(int l, int c);

#endif
