/*
Faça um programa que leia um valor n e crie dinamicamente um 
vetor de n elementos e passe esse vetor para uma função que vai 
ler do usuários os elementos a serem armazenados nesse vetor. 
De volta para a função main, o vetor preenchido deve ser impresso. 
Além disso, antes de finalizar o programa, deve-se liberar a área de memória alocada.
*/
#include <stdio.h>
#include <stdlib.h>

void ler(int *p, int tam_vetor)
{
    for (int x = 0; x < tam_vetor; x++)
    {
        printf("Digite um número: ");
        scanf("%d", &p[x]);
    }
}

int main()
{
    int *p;
    int tam_vetor;

    // Pega o o que o usuário digitar e coloca como o valor da variável tam_vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam_vetor);

    //Aloca a meméria conforme valor da variável tam_vetor
    p = (int *)malloc(tam_vetor * sizeof(int));

    //Chama a função que irá ler do usuários os valores que serão inseridos no espaço de memória alocado
    ler(p, tam_vetor);

    //Imprimir o espaço de memória/vetor com os elementos preenchidos pelo usuário

    for (int x = 0; x < tam_vetor; x++)
    {
        printf("%d\n", p[x]);
    }

    free(p);

    return 0;
}