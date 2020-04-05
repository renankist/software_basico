#include "tipos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void menu()
{
	int option;

	printf("-------------------------------------------------\n");
	printf("| Sistema de controle de ponto (Menu)           | \n");
	printf("-------------------------------------------------\n");
	printf(" [1] Cadastrar um novo funcionário\n");
	printf(" [2] Listar funcionários cadastrados\n");
	printf(" [3] Exibir relatório de ponto de um funcionário\n");
	printf(" [4] Exibir relatório de pendências de registro\n");
	printf(" [5] Gravar registro do ponto\n");
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
		employee_register(1);
		break;
	default:
		printf("cadastrarFunc()");
	}
}

int employee_register(int id)
{
	printf("--------------------------------------------------------\n");
	printf("|Sistema de controle de ponto (Cadastro de funcionário)| \n");
	printf("--------------------------------------------------------\n");

	//Pegar dados do funcionário
	struct Employee e;
	e.id = id;
	printf("Digite o nome do funcionário: ");
	fgets(e.name, 20, stdin);
	e.name[strlen(e.name) - 1] = '\0';
	printf("Digite o CPF do funcionário: ");
	fgets(e.cpf, 12, stdin);
	e.cpf[strlen(e.cpf) - 1] = '\0';
	printf("Digite o dia de nascimento nascimento do funcionário: ");
	scanf("%d", &e.data.dia);
	getchar();
	printf("Digite o número do mês de nascimento do funcionário: ");
	scanf("%d", &e.data.mes);
	getchar();
	printf("Digite o ano de nascimento do funcionário: ");
	scanf("%d", &e.data.ano);
	getchar();

	char resposta;
	printf("Deseja cadastrar o funcionário? [s/n] ");
	scanf("%c", &resposta);

	//Inserir funcionário no arquivo funcionarios.csv
	if (resposta != 's')
	{
		menu();
	}

	FILE *p;

	p = fopen("funcionarios.csv", "a");

	if (!p)
	{
		printf("Arquivo de banco de dados não encontrato");
		menu();
	}

	//Concatenar arquivos
	char resultado[256];
	fputs("\n", p);
	fprintf(p, "%d,%s,%s,%d/%d/%d", e.id, e.name, e.cpf,e.data.dia,e.data.mes,e.data.ano);
	fclose(p);
	return 0;
}

struct Employee getEmployee(int id)
{
	struct Employee employee;
	return employee;
}
