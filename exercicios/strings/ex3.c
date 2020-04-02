/*
03. Escreva um programa que leia um nome de uma pessoa (sem acentos) e imprima apenas suas iniciais, 
em letras maiúsculas. Uma letra é considerada inicial se começa o nome ou é precedida por um caractere 
de espaço (' '). Por exemplo, a entrada de "jorge benjor" geraria uma saída de "JB".
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void imprimiIniciais(char nome[20])
{
    int tam = strlen(nome); //16
    char abreviado[5];
    abreviado[0] = nome[0]; //R
    int flag_espaco = 0;
    int indice__vetor_abreviado = 1;

    for (int x = 1; x < tam; x++)
    {

        if (flag_espaco == 1)
        {
            abreviado[indice__vetor_abreviado] = nome[x];          // L U I S K
            indice__vetor_abreviado = indice__vetor_abreviado + 1; //1
            flag_espaco = 0;
        }

        if (isspace(nome[x]) != 0)
        {
            flag_espaco = 1;
        }
    }
    int tam2 = strlen(abreviado);
    for (int i = 0; i < tam2; i++)
    {
        printf("%c", abreviado[i]);
    }
}

void main()
{
    char nome[20] = "Renan Luis Kist Silva";
    imprimiIniciais(nome);
}