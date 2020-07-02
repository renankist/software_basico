/*
15. Crie um algoritmo em C que defina um struct pessoa, 
contendo os atributos nome, idade e pai (variável do tipo pessoa -
chamamos isso de estrutura auto-referenciada). Aloque dinamicamente 
memória para um vetor de 5 structs do tipo pessoa, solicite os dados
da pessoa ao usuário e exiba-os na tela. Preencha o atributo pai com a
 pessoa anteriormente informada.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa PESSOA;
struct Pessoa
{
    char nome[20];
    int idade;
    PESSOA *pai;
};

int main()
{
    PESSOA *p = (PESSOA *)malloc(5 * sizeof(PESSOA));

    PESSOA *v = p; 

    if (p)
    {
        for (int i = 0; i < 5; i++)
        {
            printf("Digite o nome da pessoa: ");
            fgets(p->nome, 20, stdin);
            printf("Informe a idade da pessoa: ");
            scanf("%d", &p->idade);
            getchar();
            if(i != 0){
                p->pai = &v[i - 1]; // recebe o endereço do ponteiro incicial 
            } 
            p++;
        }
    }

    p = v; 

    for (int i = 0; i < 5; i++)
    {
        printf("Nome da pessoa %d = %s", i + 1, p->nome);
        printf("idade da pessoa %d = %d ", i + 1, p->idade);
        printf("Pai da pessoa %d = %s", i + 1, p->pai->nome);
        p++;
    }

    free(p);

    return 0;
}