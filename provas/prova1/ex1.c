/*
01 (1.5 pontos). Crie um programa em C que permita o cadastro de até 15 produtos em um vetor.
O programa deve possuir um menu que permita inserir um produto, listar todos os produtos e sair.
Cada produto deve ter nome, preço e data de fabricação.
O produto e a data de fabricação devem ser representados por structs.
A data de fabricação não deve ser solicitada ao usuário, mas deve ser gerada aleatoriamente através da função abaixo.

DataFabricacao geraData() {
    DataFabricacao data;
    data.m = 1 + (rand() % 4);
    data.a = 2020;
    data.d = 1 + (data.m == 4 ? rand() % 17 : (rand() % 30));
    
    return data;
}
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Data DATA_FABRICACAO;
struct Data{
	int dia; 
	int mes; 
	int ano;
};

typedef struct Produto PRODUTO;
struct Produto{
	char nome[20]; 
	float preco;
	struct Data data_fabricacao;

};

PRODUTO produtos[14];
int quantidade_produtos = 0;

DATA_FABRICACAO geraData() {
    DATA_FABRICACAO data;
    data.mes = 1 + (rand() % 4);
    data.ano = 2020;
    data.dia = 1 + (data.mes == 4 ? rand() % 17 : (rand() % 30));
    
    return data;
}

void cadastrar_produto(){

    printf("-------------------------------------------------------\n");
	printf("| Sistema de produtos (Cadastro de produto)             | \n");
    printf("-------------------------------------------------------\n");

    if(quantidade_produtos >= 15){
          printf("Já existem %d produtos cadastrados, nao há mais espaço", quantidade_produtos);
          menu();
    }


    printf("Digite o nome do produto: ");
	fgets( produtos[quantidade_produtos].nome, 20, stdin);
    printf("Digite o valor do produto: ");
    scanf("%f",& produtos[quantidade_produtos].preco);
    produtos[quantidade_produtos].data_fabricacao = geraData();
   
    printf("\nProduto cadastrado com sucesso!\n\n");

    quantidade_produtos = quantidade_produtos + 1; 
    menu();

}

void listar_produtos(){
    
    printf("-------------------------------------------------------\n");
	printf("| Sistema de produtos (Lista de produtos)             | \n");
    printf("-------------------------------------------------------\n");


    for(int x = 0; x < quantidade_produtos; x++){
        printf("%d) Produto: %s  Valor: %f  Fabricação: %d/%d/%d \n",x+1,produtos[x].nome, produtos[x].preco,produtos[x].data_fabricacao.dia,produtos[x].data_fabricacao.mes,produtos[x].data_fabricacao.ano );
    }

    menu();

}

void menu()
{	
	int option;

	printf("-------------------------------------------------\n");
	printf("| Sistema de cadastro de produtos               | \n");
	printf("-------------------------------------------------\n");
	printf(" [1] Cadastrar um novo produto\n");
	printf(" [2] Listar podutos cadastrados\n");
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
		cadastrar_produto();
		break;
	case 2:
		listar_produtos();
		break;
	default:
		printf("Valor inválido");
	}
}

void main(){
    menu();
}