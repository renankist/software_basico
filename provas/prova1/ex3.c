/*
03 (1.5 pontos). Crie um programa que permita cadastrar quatro informações relacionadas: estação do ano,
 produto, vendedor e quantidade. Os dados cadastrados deverão ser salvos em um arquivo ao sair 
 do programa.
O mesmo programa deve permitir acessar relatórios pela linha de comando. Ao ser executado 
por linha de comando, o programa deve carregar os dados, gerar o relatório, exibir para o usuário 
e finalizar o programa. Os parâmetros que poderão ser informados para geração do relatório são (ex.: 
./programa rep2):
- rep1 para agrupar por estação do ano;
- rep2 para agrupar por produto;
- rep3 para agrupar por vendedor.

Exemplo de um relatório:

Vendedor    Quantidade
José           131
Maria          32
Francisco     99
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Vendedor VENDEDOR;
struct Vendedor
{
    char nome[20];
};

typedef struct Estacao ESTACAO;
struct Estacao
{
    char nome[20];
};

typedef struct Produto PRODUTO;
struct Produto
{
    char descricao[20];
};

typedef struct Venda VENDA;
struct Venda
{
    int quantidade;
    struct Produto produto;
    struct Estacao estacao_ano;
    struct Vendedor vendedor;
};

VENDA vendas[20];
int quantidade_vendas = 0;

void relatorio(char s[5])
{

    VENDA v;
    FILE *p;
    p = fopen("vendas", "rb");
    if (!p)
    {
        printf("Arquivo de banco de dados não encontrato");
    }

    int indice = 0;
    while (1)
    {

        VENDA v;

        // fread ler os dados
        // retorna a quantidade de elementos lidos com sucesso
        size_t r = fread(&v, sizeof(VENDA), 1, p);

        // se retorno for menor que o count, então sai do loop
        if (r < 1)
            break;
        else
            vendas[indice++] = v;
    }

    fclose(p); // fecha o arquivo

    //Agrupar por
    if (strcmp(s, "rep1") == 0)
    {
        printf("-------------------------------------------------------\n");
        printf("| Sistema de vendas (Lista de vendas por vendedor)         | \n");
        printf("-----------------------------------------------------------\n");
        printf("Vendedor | Quantidade \n ");

       for(int x = 0; x < indice; x++){
         
            printf("%s %d \n", vendas[x].vendedor.nome, vendas[x].quantidade);
        }
        
    }

      if (strcmp(s, "rep2") == 0)
    {
        printf("-------------------------------------------------------\n");
        printf("| Sistema de vendas (Lista de vendas por produto)      | \n");
        printf("--------------------------------------------------------\n");
        printf("Produto | Quantidade \n ");

        for(int x = 0; x < indice; x++){
         
            printf("%s %d \n", vendas[x].produto.descricao, vendas[x].quantidade);
        }
    }

      if (strcmp(s, "rep3") == 0)
    {
        printf("-------------------------------------------------------\n");
        printf("| Sistema de vendas (Lista de vendas por estacao)      | \n");
        printf("--------------------------------------------------------\n");
        printf("Estacao | Quantidade \n ");
        
        for(int x = 0; x < indice; x++){
    
            printf("%s %d \n", vendas[x].estacao_ano.nome, vendas[x].quantidade);
        }
    }
}

void salvar_vendas()
{

    FILE *p;

    p = fopen("vendas", "w");

    if (!p)
    {
        printf("Arquivo de banco de dados não encontrato");
    }

    for (int x = 0; x < quantidade_vendas; x++)
    {
        fwrite(&vendas[x], sizeof(VENDA), 1, p);
    }
}

void main(int argc, char *argv[])
{

    if (argc > 1)
    {
        relatorio(argv[1]);
        exit(0);
    }

    int resp = 1;
    do
    {
        printf("-------------------------------------------------------------------------------------\n");
        printf("| Sistema de vendas (Cadastro de venda)digite enter na primeira venda               | \n");
        printf("-------------------------------------------------------------------------------------\n");

        while (getchar() != '\n')
            ;
        printf("Digite o nome do vendedor: ");
        fgets(vendas[quantidade_vendas].vendedor.nome, 20, stdin);
        printf("Digite a descrição do produto: ");
        fgets(vendas[quantidade_vendas].produto.descricao, 20, stdin);
        printf("Digite a estação do ano da venda: ");
        fgets(vendas[quantidade_vendas].estacao_ano.nome, 20, stdin);
        printf("Digite a quantidade da venda: ");
        scanf("%d", &vendas[quantidade_vendas].quantidade);

        printf("\nVenda cadastrada com sucesso!\n\n");
        quantidade_vendas = quantidade_vendas + 1;

        printf("Digite 1 para continuar ou 2 para sair\n");
        scanf("%d", &resp);

    } while ((resp == 1));

    salvar_vendas();

    return 0;
}