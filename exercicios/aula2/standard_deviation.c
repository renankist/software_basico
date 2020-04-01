/*
Com base nas funções anteriores, implemente uma outra função chamada standard_deviation(), que também recebe um vetor de 
doubles e seu respectivo tamanho e que implemente o cálculo do desvio padrão[1]. A função deve retornar o resultado do 
cálculo do desvio padrão da sequência presente no vetor. Faça com que o programa principal fique em repetição, aceitando 
valores do tipo double até que um número negativo seja digitado. Somente após o usuário digitar o número negativo o programa 
deve calcular o desvio padrão de todos os valores digitados
 (menos o último número negativo, que serve apenas para indicar o final da sequência de valores).
*/

#include<stdio.h>
#include<math.h>


double mean(double v[], int size){
	int contador = 0; 
	double retorno; 
	while(contador <= size){
		retorno = retorno + v[contador];
		contador++; 
	}
	return retorno / size;
}

void standart_deviation(double v[], int size){
    double media =  mean(v, size); 
    double dv = 0.0; 
    int contador = 0 ;
    while(contador < size){
        dv = dv + ((v[contador] - media) * (v[contador] - media));    
        contador++;   
    }

    printf("Desvio padrão igual a %.2f\n",sqrt(dv/size));	
}

void main(){
    double n;  
    double v[4]; 
    for (int i = 0; i < 4; i++){
        printf("Digite o número. Para sair digite um negativo.");
        scanf("%lf", &n);
        if(n < 0){
            standart_deviation(v, i);
            i = 5;
        }else{
            v[i] = n;
        }
    }
}