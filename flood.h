#ifndef __flood
#define __flood

/* --- Tipos definidos --- */

int aleatorio, contl, contc, l, c, jogada, atual, acao;
int tabuleiro[14][14];
char opcao, comando;

/* --- Sub-rotinas --- */

/* *
 * Realiza atribuição de valores.
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void gerar_tabela(int l, int c);

/* *
 * Realiza a atribuição de valores
 * @param utilização de l para linhas
 * @param utilização de c para colunas
 */
void exibir_tabela(int l, int c);
void novo_jogo();
void inundar();

#endif
