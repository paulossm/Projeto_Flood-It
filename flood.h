#ifndef __flood
#define __flood

/* --- Tipos definidos --- */
#define linhas 14
#define colunas 14

int aleatorio, contl, contc, l, c, i, jogada, atual, invalido, venceu, contador, comando_local;
int tabuleiro[linhas][colunas];
char opcao, comando;

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
 * Realiza a execução de um novo jogo
 *
 *
 */
void abrir_jogo();

/* *
 * Inundação de valores em toda matriz
 *
 *
 */
void inundar();

/* *
 * Realiza a leitura de um jogo salvo
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void ler_matriz(int l, int c);

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
void percorrer(int L, int C, int referencia);
#endif
