/*
01. Faça um programa que leia uma string qualquer do usuário e que classifique os caracteres utilizando 
as funções isalnum, isalpha, isdigit, islower, ispunct, isspace e isupper. 
Uma contagem para cada caso deve ser apresentada no final do programa. 
Dica: estas funções estão presentes no include ctype.h.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 20

void main()
{

    int isalnum, isalpha, isdigit, islower, ispunct, isspace, isupper = 0;

    char string[SIZE];

    printf("Say somenthing (max 20 characteres ):");
    fgets(string, SIZE, stdin);
    char caract;

    for (int x = 0; string[x] != '\0'; x++)
    {
        caract = string[x];
        if (isalnum(caract) != 0)
        {
            if (caract != '\0')
            {
                isalnum++;
            }
        }

        if (isalpha(caract) != 0)
        {
            isalpha++;
        }

        if (isdigit(caract) != 0)
        {
            isdigit++;
        }

        if (islower(caract) != 0)
        {
            islower++;
        }

        if (ispunct(caract) != 0)
        {
            ispunct++;
        }

        if (isupper(caract) != 0)
        {
            isupper++;
        }
    }

    printf("isalnum: %d\n", isalnum);
    printf("isalpha: %d\n", isalpha);
    printf("isdigit: %d\n", isdigit);
    printf("islower: %d\n", islower);
    printf("ispunct: %d\n", ispunct);
    printf("isspace: %d\n", isspace);
    printf("isupper: %d\n", isupper);
}