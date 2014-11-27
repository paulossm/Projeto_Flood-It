================
PROJETO DO SIMULADOR DO GAME "FLOOD IT" EM LINGUAGEM "C".
================
______________________

Autores

Elivelton Costa Silva,
Paulo Sergio Silva de Mendonça.
______________________

#Descrição do que foi feito:

	> Modularização do Programa:
		1. main.c - método principal.
		2. flood.c - implementação das sub-rotinas responsáveis pelo funcionamento do jogo.
		3. flood.h - cabeçalho onde consta as definições. nele são declaradas variáveis, sub-rotinas e toda a estrutura necessária para a implementação do jogo assim como a inclusão das bibliotecas necessárias.
	
	> Compilação:
		1. stdio.h
		2. stdlib.h
		3. time.h
	
	> Recursos utilizados:
		1. Recursividade - sub-rotina recursiva que preenche o tabuleiro de acordo com as instruções do usuário.
		2. Manipulação de Arquivos:
			2.1 fopen
			2.2 fclose
			2.3 fprintf
			2.4 fscanf
			2.5 FILE *arquivo
		3. Enumerações - estrutura de enumeração para atribuir valores baseados em lógica booleana (falso = 0, verdadeiro = 1)
		4. Geração de números aleatórios com as funções srand() e rand()
		5. Uso do typedef
	
	> Recurso não utilizado:
		1. union
		2. ponteiros
	
	> Contribuições dos Autores:
		1. Elivelton Costa Silva:
			"Criação da Sub-rotina recursiva 'inundar()', como também 'ler_matriz()', 'escrever_matriz()'
			além da interface inicial do jogo e da estrutura necessária para criação
			de elementos aleatórios no tabuleiro."

		2. Paulo Sergio Silva de Mendonça:
			"Criação da condição de término do jogo; manipulação dos comandos do
			usuário e ações de execução do jogo; salvamento e carregamento do jogo.
		
		3. Idéias desenvolvidas em conjunto:
			"Criação do menu de opções de acordo com os requisitos; manipulação
			dos erros eventuais de entrada; definição de tipos e variáveis necessárias;
			inclusão de bibliotecas necessárias e modularização do programa.

	> Informações Extras:
		1. O Projeto foi desenvolvido usando controle de versão com repositório no GitHub.com <https://github.com/paulossm/Projeto_Flood-It>
		
		
	
