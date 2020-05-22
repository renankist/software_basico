/*
12. Crie um programa para manipular vetores. O seu programa deve implementar uma função 
chamada inverte_vetor, que recebe como parâmetro dois vetores V1 e V2, ambos de tamanho N. 
A função deve copiar os elementos de V1 para V2 na ordem inversa. Ou seja, se a função receber 
V1 = {1,2,3,4,5}, 
a função deve copiar os elementos para V2 na seguinte ordem: V2 = {5,4,3,2,1}. Além disso, 
a função também deve retornar o maior valor encontrado em V1. A função deve obedecer ao seguinte 
protótipo: int inverte_vetor(int *v1, int *v2, int n);

Em seguida, implemente no mesmo modulo outra função chamada 
multiplica_escalar, que recebe como parâmetro dois vetores V1 e V2 
(ambos de tamanho N), e um número inteiro X. A função deve multiplicar cada um
 dos elementos de V1 por X e armazenar os resultados em V2. A função deve obedecer 
 ao seguinte protótipo: void multiplica_escalar(int *v1, int *v2, int x, int n);

Em seguida crie a função principal do programa utilizando as funções 
inverte_vetor e multiplica_escalar para inverter um vetor de tamanho 10 
fornecido pelo usuário e em seguida multiplicar esse vetor pelo maior valor 
retornado da função inverte_vetor. Por último, o programa deverá exibir o vetor resultante.
*/
#include <stdio.h> 
#define TAMANHO 5

//Coloca no vetor v2 os valores do v1 inversamente e retornar o maior valor de v1.  
int inverte_vetor(int *v1, int *v2, int tamanho){
    int maior_valor_v1 = *v1; 
    v2 = v2 + (tamanho - 1);
    for(int i = 0; i < tamanho; i++){
        if(*v1 > maior_valor_v1){
            maior_valor_v1 = *v1;
        }
        *v2 = *v1;
        *v1++;
        *v2--;
    }
    return maior_valor_v1;
}

void multiplica_escalar(int *v1, int *v2, int x, int tamanho){
    for(int i = 0; i < tamanho; i++){
        *v2  = *v1 * x;
        v1++;
        v2++;
    }
}

void imprime(int *v, int tamanho){

    for(int i = 0; i < tamanho; i++){
        printf(" %d", *v);
        v++;
    }

    printf("\n");

}

int main(){

    int v1[TAMANHO] = {1,2,3,4,5}; 
    int v2[TAMANHO];
    
    int maior = inverte_vetor(v1,v2, TAMANHO);

    imprime(v1, TAMANHO);
    imprime(v2, TAMANHO);

    multiplica_escalar(v2,v1,maior, TAMANHO);

    imprime(v1, TAMANHO);
    
    return 0;
}
