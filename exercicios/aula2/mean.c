#include <stdio.h>
#include <math.h>
/*
Com base na função anterior, crie uma nova função chamada mean(), que recebe um vetor de doubles e seu tamanho, 
e devolve a média aritmética dos elementos desse vetor. 
Teste com um vetor de tamanho 4, preenchido com valores digitados pelo usuário e lidos com a função scanf().
*/

double mean(double v[], int size){

	int contador = 0; 
	double retorno; 

	while(contador <= size){

		retorno = retorno + v[contador];

		contador++; 

	}

	return retorno / size;

}

int main(void){

    double v[4];
    double n = 0.0;

    for (int i = 0; i < 4; i++){
        printf("Digite o número %d ", i+1);
        scanf("%lf", &n);
        v[i] = n;
    }

   	double m = mean(v,4);

	printf("%d",sizeof(v)); 

    printf("A média do vetor é %f\n", m);	

    return 0;
}
