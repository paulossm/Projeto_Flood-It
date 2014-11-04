#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
		int tabuleiro[14][14];
		int aleatorio, contl, contc;
		srand( (unsigned)time(NULL) );
		
		for(contl = 0; contl < 14; contl++){
			printf("\n");
			for(contc = 0; contc < 14; contc++){
				aleatorio = rand() % 6;
				tabuleiro[contl][contc] = aleatorio;
				printf("%i ", tabuleiro[contl][contc]);
				}
			}
		return 0;
}
