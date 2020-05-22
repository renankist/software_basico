/*
04. Escreva uma função que receba um vetor de inteiros e retorne
 o maior elemento e o menor elemento. Observe que a função deve 
 retornar ao local da chamada os dois valores (não imprimir ao usuário). Portanto,
 você precisará usar passagem de parâmetro por referência.
*/

#include<stdio.h>

void busca(int v[], int *pmaior, int *pmenor, int size){
	int i;
	*pmaior = v[0];
	*pmenor = v[0];
	for(i = 1; i < size; i++){
		if(v[i] > *pmaior){
			*pmaior = v[i];
		}
		if(v[i] < *pmenor){
			*pmenor = v[i];
		}
	}
}

int main(void){
	int v[] = {4, 5, 6, 3, 1};
	int size = sizeof(v) / sizeof(v[0]);
	int maior, menor;
	busca(v, &maior, &menor, size);
	printf("MAIOR: %d\n", maior);
	printf("MENOR: %d\n", menor);
	return 0;
}