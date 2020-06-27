/*
16. Crie um algoritmo em C que defina uma matriz de 
inteiros dinamicamente alocada de 3 x 2. Preencha os 
valores desta matriz solicitando os valores ao usuário e 
imprima os valores no formato de matriz.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int **p = (int **)malloc(3 * sizeof(int *)); //Linhas da matriz
    int **v;

    v = p;

    for (int i = 0; i < 3; i++)
    { // Para cada linha da matriz cria-se um vetor (colunas)
        p[i] = (int *)malloc(2 * sizeof(int));
        for (int x = 0; x < 2; x++) //Preenche a as colunas da linha criada anteriormente
        {
            scanf("%d", &p[i][x]);
        }
    }

    p = v;

    //Imprimir em forma de matriz

    for (int i = 0; i < 3; i++)
    { // Para cada linha da matriz cria-se um vetor (colunas)
        for (int x = 0; x < 2; x++) //Preenche a as colunas da linha criada anteriormente
        {
          printf("%d", p[i][x]);
        }
        printf("\n");
    }

    //Liberar a memória na ordem inversa ao da locação
    for (int x = 0; x < 2; x++) //Preenche a as colunas da linha criada anteriormente
    {
        free(p[x]);
    }

    free(p);

    return 0;
}