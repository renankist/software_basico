/*
01. (2 pontos) Crie um programa que receba um vetor de inteiros v e 
retorne um outro vetor de inteiros alocado dinamicamente com 
todos os valores de v que estejam entre o valor mínimo e máximo 
(que também são passados como parâmetro para a função). 
A função deve obedecer ao seguinte protótipo:
 int* valores_entre(int *v, int n, int min, int max, int *qtd); O 
 parâmetro quantidade é um endereço de memória que deverá contem a quantidade 
de elementos do vetor retornado pela função. Criar uma função que imprima o vetor resultante.
*/

#include <stdio.h>
#include <stdlib.h>


int imprimir(int *v, int t){
    int i = 0;
    for(i = 0; i < t; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}

int *valores_entre(int *v, int n, int min, int max, int *qtd)
{

    int i = 0;

    int *p = (int *)malloc(sizeof(int));

    for (i = 0; i < n; i++)
    {
        if (v[i] > min && v[i] < max)
        {
            p[*qtd] = v[i];

            *qtd = *qtd + 1;
             p = realloc(p, (*qtd + 1) * sizeof(int));
        }
    }

    p = realloc(p, *qtd  * sizeof(int));

    return p;
}

int main()
{

    int v[] = {10, 8, 7, 6, 4, 3, 2};
    int min = 2;
    int max = 6;
    int tamanho_vetor = 6;
    int *vetor_resultante;
    int qtd_elementos = 0;

    vetor_resultante = valores_entre(v, tamanho_vetor, min, max, &qtd_elementos);

    imprimir(vetor_resultante, qtd_elementos);

    free(vetor_resultante);

    return 0;
}