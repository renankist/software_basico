/*
11. Implemente sua própria função mystrcpy(char *origem, char *destino) 
usando ponteiros.
*/

#include <stdio.h>

void mystrcpy(char *origem, char *destino)
{
    while (*origem != '\0')
    {
        *destino = *origem;
        *origem++;
        *destino++;
    }

    *destino = '\0';
}

int main()
{
    char origem[6] = {'t', 'e', 's', 't', 'e'};
    char destino[6] = {'p', 'a', 's', 's', 'o'};
    printf("String origem: %s\n", origem);
    printf("String destino: %s\n", destino);

    mystrcpy(origem, destino);

    printf("String origem: %s\n", origem);
    printf("String destino: %s\n", destino);

    return 0;
}
