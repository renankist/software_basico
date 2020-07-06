/*
03. (3 pontos) Crie um algoritmo que 
defina uma "matriz" de inteiros que aloque dinamicamente 5 ponteiros para vetores 
de inteiros. Cada vetor de inteiros deve possuir a quantidade de elementos igual a quantidade
 anterior mais 1, iniciando em 1. A imagem abaixo ilustra o 
resultado a ser obtido pelo algoritmo, sendo que os inteiros podem ser obtidos pela entrada de teclado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int **p = (int **)malloc(5 * sizeof(int *)); //Linhas da matriz
    int **v;
    v = p;

    for (int i = 0; i < 5; i++)
    { // Para cada linha da matriz cria-se um vetor (colunas)
        p[i] = (int *)malloc((i+1) * sizeof(int));

        for (int x = 0; x < i+1; x++) //Preenche a as colunas da linha criada anteriormente
        {
            scanf("%d", &p[i][x]);
        }
    }

     p = v;

    //Imprimir em forma de matriz

    for (int i = 0; i < 5; i++)
    { // Para cada linha da matriz cria-se um vetor (colunas)
        for (int x = 0; x < 5; x++) //Preenche a as colunas da linha criada anteriormente
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