/*
06. Escreva um programa que declare uma matriz 10x10 de inteiros. 
Você deve inicializar a matriz com zeros usando ponteiros para endereçar 
seus elementos. Preencha depois a matriz com os números de 1 a 100, 
também usando ponteiros. Por fim, implemente uma função 
imprimeMatriz(int *pm, int size) 
que deve imprimir a matriz formatada.
*/

#include <stdio.h>
#define LIN 200
#define COL 4
void imprimeMatriz(int *p, int size)
{
    for (int i = 1; i <= size; i++)
    {

        printf("%4d", *p);

        if (i % COL == 0)
        {
            printf("\n");
        }

        *p++;
    }
}

int main()
{

    int m[LIN][COL], *p;
    p = &m;

    //Preenchendo matriz com 1 a 100
    for (int i = 1; i <= LIN * COL; i++)
    {
        *p = i;
        if (i != LIN * COL)
        {
            *p++;
        }
    }
    p = &m;

    imprimeMatriz(p, LIN * COL);

    return 0;
}