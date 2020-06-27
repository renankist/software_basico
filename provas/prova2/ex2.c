#include <stdio.h>
#include <string.h>
#define TAM_NOME 20

int qtd_pessoas = 0;

struct Pessoa
{
    char nome[TAM_NOME];
    float peso;
    float altura;
    float imc;
};
typedef struct Pessoa PESSOA;

void listar(PESSOA *p)
{
    printf("--------------------------------------------------------\n");
    printf("|Sistema de IMC  (Listar todas pessoas)                | \n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < qtd_pessoas; i++)
    {

        printf("Nome: %s\n", p->nome);
        printf("Peso: %f\n", p->peso);
        printf("Altura: %f\n", p->altura);
        printf("IMC: %f\n", p->imc);
        printf("------------------------------------------------------\n");

        p++;
    }
}

void diagnostico(float imc)
{
    if (imc < 18.5)
    {
        printf("Abaixo do peso");
    }

    if (imc >= 18.5 && imc <= 24.9)
    {
        printf("Peso normal");
    }

    if (imc >= 25.0 && imc <= 29.9)
    {
        printf("Sobrepeso");
    }

    if (imc >= 30.0 && imc <= 34.9)
    {
        printf("Obesidade grau 1");
    }

    if (imc >= 35.0 && imc <= 39.9)
    {
        printf("Obesidade grau 2");
    }

    if (imc > 40.0)
    {
        printf("Obesidade grau 3");
    }
}

float cadastraIMC(PESSOA *p, char nome[], float peso, float altura)
{

    p->imc = peso / (altura * altura);

    strcpy(p->nome, nome);
    p->peso = peso;
    p->altura = altura;

    qtd_pessoas++;

    return p->imc;
}

int main()
{

    struct Pessoa pessoas[10];
    struct Pessoa *p = pessoas;

    int option;

    do
    {

        printf("-------------------------------------------------\n");
        printf("| IMC pessoas (Menu)                            | \n");
        printf("-------------------------------------------------\n");
        printf(" [1] Inserir IMC de pessoa\n");
        printf(" [2] Listar pessoas \n");
        printf(" [0] Sair do sistema\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 0:
            printf("Sistema finalizando..\n ");
            break;
        case 1:
            system("clear");
            for (int x = 0; x < qtd_pessoas; x++)
            {
                p++;
            }

            printf("--------------------------------------------------------\n");
            printf("|Sistema de IMC (Cadastro de pessoa)                   | \n");
            printf("--------------------------------------------------------\n");

            char nome[TAM_NOME];
            float altura, peso;

            printf("Digite o nome da pessoa: ");
            fgets(nome, TAM_NOME, stdin);
            printf("Digite a altura: ");
            scanf("%f", &altura);
            printf("Digite o peso: ");
            scanf("%f", &peso);

    

            float imc = cadastraIMC(p, nome, peso, altura);
            printf("\n");
            diagnostico(imc);
            printf("\n");
            break;

        case 2:
            system("clear");
            p = pessoas;
            listar(p);
            break;
            break;
        default:
            printf("Valor inválido");
        }
    } while (option != 0);

    return 0;
}
