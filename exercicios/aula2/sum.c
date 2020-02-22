/*
Faça uma função sum() 
que receba dois parâmetros: um vetor de 
valores do tipo double e um inteiro 
(representando o tamanho do vetor). 
A função deve calcular o somatório de 
todos os elementos do vetor e retornar 
o valor double resultante. Teste com o 
vetor {1.2, 3.4, 5.6, 7.8, 9.0}, cujo 
resultado deve ser 27.0.*/

#include <stdio.h>


double sum(double v[], int size){

	int contador = 0; 
	double retorno; 

	while(contador <= size){

		retorno = retorno + v[contador];

		contador++; 

	}

	return retorno;

}

int main(void){

	int size = 6; 

	double v[] = {1.2, 3.4, 5.6, 7.8, 9.0};

	double soma = sum(v,size);

    printf("Soma número é %f\n", soma);	

	return 0; 
}



