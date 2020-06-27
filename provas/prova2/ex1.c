/*
01. Crie um programa que permita armazenar dados de uma frota de veículos, 
utilizando um vetor de structs. Cada veículo deve conter a placa, ano, modelo,
 quilometragem da última troca de óleo e quilometragem da última troca de pneus. 
 O programa deve, na tela de abertura, apresentar opções para: inserir um veículo, 
 consultar veículo pela placa, listar o veículo mais novo e mais antigo e listar 
 todos os veículos. Para cada uma destas 4 opções deve ser criada uma função. 
O vetor de structs deve ser manipulado exclusivamente através de ponteiros.
*/

#include <stdio.h>
#include <string.h>
#define TAM_PLACA 8
#define TAM_MODELO 10
#define QTD_VEICULOS 5

int qtd_veiculos = 0;

//Struct para armazenar dados de veículos
struct Veiculo
{
    char placa[TAM_PLACA];
    int ano;
    char modelo[TAM_MODELO];
    int km_ultima_troca_oleo;
    int km_ultima_troca_pneu;
};
typedef struct Veiculo VEICULO;

void listar_mais_novo_e_mais_velho(VEICULO *v)
{
    printf("--------------------------------------------------------\n");
    printf("|Sistema de frotas de veículos(Listar mais novo e mais velho)| \n");
    printf("--------------------------------------------------------\n");

    char placa_veiculo_novo[TAM_PLACA];
    char placa_veiculo_velho[TAM_PLACA];
    int ano_veiculo_novo = 0;
    int ano_veiculo_velho = 2020;
    char modelo_veiculo_novo[TAM_MODELO];
    char modelo_veiculo_velho[TAM_MODELO];

    for (int i = 0; i < qtd_veiculos; i++)
    {

        if (v->ano > ano_veiculo_novo)
        {
            ano_veiculo_novo = v->ano;
            strcpy(placa_veiculo_novo, v->placa);
            strcpy(modelo_veiculo_novo, v->modelo);
        }
        if (v->ano < ano_veiculo_velho)
        {
            ano_veiculo_velho = v->ano;
            strcpy(placa_veiculo_velho, v->placa);
            strcpy(modelo_veiculo_velho, v->modelo);
        }

        v++;
    }

    printf("Veiculo mais novo: \n \n");
    printf("Placa: %s\n", placa_veiculo_novo);
    printf("Modelo: %s\n", modelo_veiculo_novo);
    printf("Ano: %d\n", ano_veiculo_novo);

    printf("------------------------------------------------------\n");

    printf("Veiculo mais velho: \n \n");
    printf("Placa: %s\n", placa_veiculo_velho);
    printf("Modelo: %s\n", modelo_veiculo_velho);
    printf("Ano: %d\n", ano_veiculo_velho);
    printf("------------------------------------------------------\n");
}

void listar_todos_veiculos(VEICULO *v)
{
    printf("--------------------------------------------------------\n");
    printf("|Sistema de frotas de veiculos (Listar todos veiculos)  | \n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < qtd_veiculos; i++)
    {

        printf("Placa: %s\n", v->placa);
        printf("Modelo: %s\n", v->modelo);
        printf("Ano: %d\n", v->ano);
        printf("Última troca de óleo %d km\n", v->km_ultima_troca_oleo);
        printf("Última troca de pneu %d km\n", v->km_ultima_troca_oleo);
        printf("------------------------------------------------------\n");

        v++;
    }
}
void consultarVeiculo(VEICULO *v)
{
    printf("--------------------------------------------------------\n");
    printf("|Sistema de frotas de ponto (Consulta de veiculo)      | \n");
    printf("--------------------------------------------------------\n");

    v = v;
    //Colocar o ponteiro em sua posição inicial
    char placa_consulta[TAM_PLACA];

    printf("Digite a placa do veiculo a ser consultado: ");
    fgets(placa_consulta, TAM_PLACA, stdin);
    placa_consulta[strlen(placa_consulta) - 1] = '\0';
    for (int i = 0; i <= qtd_veiculos; i++)
    {

        if (strcmp(v->placa, placa_consulta) == 0)
        {
            printf("Placa: %s\n", v->placa);
            printf("Modelo: %s\n", v->modelo);
            printf("Ano: %d\n", v->ano);
            printf("Última troca de óleo %d km\n", v->km_ultima_troca_oleo);
            printf("Última troca de pneu %d km\n", v->km_ultima_troca_oleo);
        }

        v++;
    }
}

void inserirVeiculo(VEICULO *v)
{

    printf("--------------------------------------------------------\n");
    printf("|Sistema de frotas de veículos (Cadastro de veiculo)      | \n");
    printf("--------------------------------------------------------\n");

    //acessa o endereço livre para inserir novo veiculo

    printf("Digite a placa do veiculo: ");
    fgets(v->placa, TAM_PLACA, stdin);
    v->placa[strlen(v->placa) - 1] = '\0';
    printf("Digite o ano do veiculo: ");
    scanf("%d", &v->ano);
    getchar();
    printf("Digite o modelo do veiculo: ");
    fgets(v->modelo, TAM_MODELO, stdin);
    v->modelo[strlen(v->modelo) - 1] = '\0';
    printf("Digite a KM da última troca de oléo do veiculo: ");
    scanf("%d", &v->km_ultima_troca_oleo);
    printf("Digite a KM da última troca de pneus do veiculo: ");
    scanf("%d", &v->km_ultima_troca_pneu);
    getchar();

    printf("Veiculo inserido com sucesso.\n\n");

    qtd_veiculos++;
}

int main()
{

    struct Veiculo veiculos[QTD_VEICULOS];
    struct Veiculo *p = veiculos;

    int option;

    do
    {

        printf("-------------------------------------------------\n");
        printf("| Frota de veículos (Menu)                      | \n");
        printf("-------------------------------------------------\n");
        printf(" [1] Inserir veículo\n");
        printf(" [2] Consultar veiculo\n");
        printf(" [3] Listar o veiculo mais novo e o mais antigo\n");
        printf(" [4] Listar veiculos\n");
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
            for (int x = 0; x < qtd_veiculos; x++)
            {
                p++;
            }
            inserirVeiculo(p);
            break;
        case 2:
            system("clear");
            p = veiculos;
            consultarVeiculo(p);
            break;
        case 3:
            system("clear");
            p = veiculos;
            listar_mais_novo_e_mais_velho(p);
            break;
        case 4:
            system("clear");
            p = veiculos;
            listar_todos_veiculos(p);
            break;
        default:
            printf("Valor inválido");
        }
    } while (option != 0);

    return 0;
}
