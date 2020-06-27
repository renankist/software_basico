/*
13. Crie um algoritmo em C que defina um struct pessoa, 
contendo os atributos nome e idade. Aloque dinamicamente memória para 
uma struct do tipo pessoa, solicite os dados da pessoa ao usuário e exiba-os na tela.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa PESSOA;
struct Pessoa
{
    char nome[20];
    int idade;
};

int main()
{

    PESSOA *p = (PESSOA *)malloc(sizeof(PESSOA));

    if (p)
    {
        printf("Digite o nome da pessoa: ");
        fgets(p->nome, 20, stdin);
        printf("Informe a idade da pessoa: ");
        scanf("%d", &p->idade);
    }

    printf("Nome da pessoa = %s \n", p->nome);
    printf("idade da pessoa = %d ", p->idade);

    return 0;
}