/*
06. Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até 10 pessoas. 
Cada pessoa deve ser representada por uma struct dentro de um vetor. A data de nascimento também deve ser uma struct. 
O nome e a altura de cada pessoa devem ser informados pelo teclado. A geração da data de nascimento deve ser feita aleatoriamente
 através da função abaixo

Data CriaData() {
    Data d;
    d.Mes = 1 + (rand() % 12);
    d.Ano = 1950 + (rand() % 49);
    d.Dia = 1 + (rand() % 30);
    
    return d;
}

O programa deve, na tela de abertura, apresentar opções para:
    inserir um nome;
    listar todos os nomes e respectivas alturas;
    listar os nomes das pessoas que nasceram antes de uma certa data fornecida.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Data
{
    int dia;
    int ano;
    int mes;
};

struct Pessoa
{
    char nome[20];
    char altura[10];
    struct Data data_nascimento;
};

struct Data CriaData()
{
    struct Data d;
    d.mes = 1 + (rand() % 12);
    d.ano = 1950 + (rand() % 49);
    d.dia = 1 + (rand() % 30);
    return d;
}

int calculaDiasData(struct Data data_pessoa, struct Data data_filtro)
{

    int meses[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //Pegar dados data1
    //Verificar a quantidade de dias até o ano anterior ao indicado na data
    int dias_data_pessoa = data_pessoa.ano * 365;
    //Verificar a quantidade de dias até o mes anterior ao indicado na data
    for (int x = 0; x < data_pessoa.mes; x++)
    {
        dias_data_pessoa = dias_data_pessoa + meses[x];
    }
    dias_data_pessoa = dias_data_pessoa + data_pessoa.dia;

    //Pegar dados data2
    //Verificar a quantidade de dias até o ano anterior ao indicado na data
    int dias_data_filtro = data_filtro.ano * 365;
    //Verificar a quantidade de dias até o mes anterior ao indicado na data
    for (int x = 0; x < data_filtro.mes; x++)
    {
        dias_data_filtro = dias_data_filtro + meses[x];
    }
    dias_data_filtro = dias_data_filtro + data_filtro.dia;

    int diferenca_dias = dias_data_pessoa - dias_data_filtro;

    return diferenca_dias;
}

void cadastraPessoa(int id_vetor, struct Pessoa p[])
{
    while (getchar() != '\n')
        ;
    printf("---------------Cadastrar pessoa %d:----------------\n", id_vetor + 1);
    printf("\nNome da pessoa:");
    fgets(p[id_vetor].nome, 20, stdin);
    printf("\nAltura da pessoa:");
    fgets(p[id_vetor].altura, 20, stdin);
    p[id_vetor].data_nascimento = CriaData();
}

void listaPessoas(struct Pessoa p[], int quantidade)
{
    printf("---------------Lista de pessoas:----------------\n");

    for (int i = 0; i < quantidade; i++)
    {
        printf("---------Dados pes soa %d---------\n", i + 1);
        printf("   Nome: %s   Altura: %s   Data de nascimento: %d/%d/%d\n", p[i].nome, p[i].altura, p[i].data_nascimento.dia, p[i].data_nascimento.mes, p[i].data_nascimento.ano);
    }
    printf("\n");
}

void listaConformeData(int quantidade, struct Pessoa p[])
{
    struct Data data_filtro;
    data_filtro.ano = 0;
    data_filtro.dia = 0;
    data_filtro.mes = 0;
    printf("---------------Digite uma data:----------------\n");
    printf("Ano:");
    scanf("%d", &data_filtro.ano);
    printf("Mês:");
    scanf("%d", &data_filtro.mes);
    printf("Dias:");
    scanf("%d", &data_filtro.dia);
    printf("---------Dados pessoas com nascimento anterior a data selecionada---------\n");
    for (int i = 0; i < quantidade; i++)
    {
        if (calculaDiasData(p[i].data_nascimento, data_filtro) < 0)
        {
            printf("   Nome: %s   Altura: %s   Data de nascimento: %d/%d/%d\n", p[i].nome, p[i].altura, p[i].data_nascimento.dia, p[i].data_nascimento.mes, p[i].data_nascimento.ano);
        }
    }
    printf("\n");
}

void printMenu()
{

    printf("---------------Selecione uma das opções abaixo:----------------\n");
    printf("1) Cadastrar pessoa\n");
    printf("2) Listar pessoas\n");
    printf("3) Pessoas por data de nascimento\n");
    printf("4) Sair\n");
}

void printMenuSemCadastro()
{

    printf("---------------Selecione uma das opções abaixo:----------------\n");
    printf("2) Listar pessoas\n");
    printf("3) Pessoas por data de nascimento\n");
    printf("4) Sair\n");
}

void main()
{
    struct Pessoa pessoas[3];
    int escolha = 1;
    int qtd_cadastros = 0;
    while (qtd_cadastros <= 2)
    {
        printMenu();
        fflush(stdin);
        scanf("%d", &escolha);

        if (escolha == 1)
        {
            cadastraPessoa(qtd_cadastros, pessoas);
            qtd_cadastros++;
        }
        if (escolha == 2)
        {
            listaPessoas(pessoas, qtd_cadastros);
        }

        if (escolha == 3)
        {
            listaConformeData(qtd_cadastros, pessoas);
        }

        if (escolha == 4)
        {
            exit(0);
        }
    }
    while (escolha != 4)
    {
        printMenuSemCadastro();
        fflush(stdin);
        scanf("%d", &escolha);

        if (escolha == 2)
        {
            listaPessoas(pessoas, qtd_cadastros);
        }
        if (escolha == 3)
        {

            listaConformeData(qtd_cadastros, pessoas);
        }
    }
}