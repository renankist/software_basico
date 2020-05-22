/*
07. Escreva uma função que recebe uma string de caracteres e uma letra e devolve um vetor 
de inteiros contendo as posições (índices no vetor da string) onde a letra foi encontrada)
 e um inteiro contendo o tamanho do vetor criado (total de letras iguais encontradas). 
Utilize o retorno de um inteiro para o tamanho do vetor e um ponteiro para o vetor de índices.
*/
#include <stdio.h>

int conta_letras(char string[], char letra, int *vetor)
{
    int num_caracteres_string = 0;
    int tamanho_vetor = 0; 
    
    while (string[num_caracteres_string] != '\0')
    {
        if (string[num_caracteres_string] == letra)
        {
            *vetor = num_caracteres_string;
            *vetor++;
             tamanho_vetor++;
        }
        num_caracteres_string++;
    }

    return tamanho_vetor;
}

int main()
{
    char str[] = "a vaca morreu\0";
    int v[sizeof(str)], *p;
    p = v;

    int vetor_size = conta_letras(str, 'a', p);

    printf("Tamanho do vetor = %d\n", vetor_size);

    for(int i = 0; i < vetor_size; i++){
        printf("%d\n",v[i]);
    }


    return 0;
}
