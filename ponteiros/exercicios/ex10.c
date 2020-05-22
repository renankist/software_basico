/*
10. Faça um programa que modifique as vogais de uma frase. O programa deve 
ler uma frase e armazeá-la num vetor. Imprimir a frase lida trocando as vogais:
'a' pelo 'u'
'e' pelo 'o'
'i' pelo 'u'
'o' pelo 'a'
'u' pelo 'e'
Usar uma função sem retorno para realizar a troca e uma função para realizar 
a impressão da frase trocada. A função deve ter como parâmetro um ponteiro char 
referente ao vetor. Dica: Use a função gets() da biblioteca string.h para realizar a
 leitura da frase.
 use o switch para realizar as trocas. Só considere as letras minúsculas.
*/
#include <stdio.h>
#include <string.h>
#define tamanho_frase 21

void troca_vogais(char *frase)
{
    int tamanho_string;
    tamanho_string = strlen(frase);
    for(int i = 0; i < tamanho_string; i++)
    {
        switch (*frase)
        {
        case 'a':
            *frase = 'u';
            break;
        case 'e':
            *frase = 'o';
            break;
        case 'i':
            *frase = 'u';
            break;
        case 'o':
            *frase = 'a';
            break;
        case 'u':
            *frase = 'e';
            break;

        default:
            break;
        }

        frase++;
    }
}

int main()
{
    char frase[tamanho_frase];
    printf("Digite uma frase: ");
    fgets(frase, tamanho_frase, stdin);
    printf("Frase original: %s\n", frase);
    troca_vogais(frase);
    printf("Frase modificada: %s\n", frase);
    return 0;
}