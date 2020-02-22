/*
Crie uma função chamada max() 
que recebe quatro parâmetros 
inteiros e sem valor de retorno 
(ou seja, void). Esta função deve 
imprimir na tela o maior valor fornecido.
 Teste chamando a partir da função main() com 
 valores fixos e distintos.

*/
#include <stdio.h>

void max(int x, int y, int z, int w){ 
    int maior = x; 
		if(y > maior){
			maior = y; 
		}
		if(z > maior){
			maior = z; 
		}
		if(w > maior){
			maior  = w; 
		}
	printf("O maior número é %d\n", maior);	
}

int main(void){
	max(4,1,2,3);
	return 0; 
}



