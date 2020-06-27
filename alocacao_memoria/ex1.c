/*
Escreva um programa que descubra qual é o maior segmento 
de memória que é possível reservar no seu computador.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *p;
    int x = 1;

    p = (int *)malloc(x * sizeof(int));

    while (p)
    {
        printf("Memória alocada %d ", x * sizeof(int));
        free(p);
        x++;
        p = (int *)malloc(x * sizeof(int));
    }

    free(p);

    return 0;
}
