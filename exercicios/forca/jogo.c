#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forca.h"

struct Palavra {
    char nome[TAMANHO_NOME_PALAVRA];
    char dica[TAMANHO_DICA_PALAVRA];
};

int verificaSeTemALetra(char letra){

    return 0; 
}


struct Palavra getPalavra()
{

    struct Palavra p;

    FILE *f;

    f = fopen("palavras.txt", "r");
    
    if (f == 0)
    {
        printf("Arquivo não existe \n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s",p.nome);
    }

    fclose(f);

    return p;
}

void main()
{
   struct Palavra palavra = getPalavra();

    printf("%s",palavra.nome);

}
