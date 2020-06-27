/*
06. Escreva uma função que receba dois vetores e unifique os mesmos de modo a 
não repetir valores.
A função deve retornar o novo vetor criado dinamicamente para a função que a chamou.
*/
#include <stdio.h>
#include <stdlib.h>

void ordena_vetor(int *v, int tamanho)
{
    //Ordeção seguindo o algoritmo BUBLE SORT melhor caso N pior n*n
    int aux, i, j;
    for (j = tamanho - 1; j >= 1; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
    }
}

int existe(int *v, int tamanho, int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (v[i] == valor)
        {
            return 1;
        }
    }

    return 0;
}

int junta_vetores(int *v1, int tamanho_vetor_1, int *v2, int tamanho_vetor_2, int *vetores_juntos)
{

    int tamanho_novo_vetor = 0;

    for (int i = 0; i < tamanho_vetor_1; i++)
    {
        if (existe(vetores_juntos, tamanho_novo_vetor, v1[i]) == 0)
        {
            tamanho_novo_vetor++;
            vetores_juntos = realloc(vetores_juntos, tamanho_novo_vetor * sizeof(int));
            vetores_juntos[tamanho_novo_vetor - 1] = v1[i];
        }
    }

    for (int i = 0; i < tamanho_vetor_2; i++)
    {
        if (existe(vetores_juntos, tamanho_novo_vetor, v2[i]) == 0)
        {
            tamanho_novo_vetor++;
            vetores_juntos = realloc(vetores_juntos, tamanho_novo_vetor * sizeof(int));
            vetores_juntos[tamanho_novo_vetor - 1] = v2[i];
        }
    }

    return tamanho_novo_vetor;
}

int main()
{

    int v1[4] = {9, 5, 9, 6};
    int v2[4] = {3, 3, 5, 8};
    int *v3 = (int *)malloc(sizeof(int));

    int x = junta_vetores(v1, 4, v2, 4, v3);

    for (int i = 0; i < x; i++)
    {
        printf("%d \n", v3[i]);
    }

    return 0;
}
