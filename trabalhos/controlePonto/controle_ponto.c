#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int id = 0; //Variavel que guarda o ID de quando se quer inserir um novo employee


typedef struct Date DATE;
struct Date{
	int dia; 
	int mes; 
	int ano;
};


typedef struct Employee EMPLOYEE;
struct Employee{
	int id; 
	char cpf[12];
	char name[20];
	struct Date date;

};
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
		employee_register(id);
		menu();
		break;
	case 2:
		showEmployees();
		menu();
		break;
	default:
		printf("cadastrarFunc()");
	}
}

void employee_register(int id)
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
	scanf("%d", &e.date.dia);
	getchar();
	printf("Digite o número do mês de nascimento do funcionário: ");
	scanf("%d", &e.date.mes);
	getchar();
	printf("Digite o ano de nascimento do funcionário: ");
	scanf("%d", &e.date.ano);
	getchar();

	char resposta;
	printf("Deseja cadastrar o funcionário ss? [s/n] ");
	scanf("%c", &resposta);

	//Inserir funcionário no arquivo funcionarios.csv
	if (resposta != 's')
	{
		menu();
	}

	FILE *p;

	p = fopen("funcionarios.csv", "ab");

	if (!p)
	{
		printf("Arquivo de banco de dados não encontrato");
		menu();
	}

	fwrite(&e,sizeof(EMPLOYEE),1,p);

	//fprintf(p, "%d,%s,%s,%d/%d/%d", e.id, e.name, e.cpf,e.data.dia,e.data.mes,e.data.ano);
	fclose(p);

	setIdEmployee();
}

struct Employee getEmployee(int id)
{
	struct Employee employee;
	return employee;
}

void showEmployees()
{	
    printf("-------------------------------------------------------\n");
	printf("| Sistema de controle de ponto (Lista de funcionários)| \n");
	printf("-------------------------------------------------------\n");
	EMPLOYEE e;
	FILE *p;
	p = fopen("funcionarios.csv", "rb");
	if (!p)
	{
		printf("Arquivo de banco de dados não encontrato");
		menu();
	}

	while(fread(&e,sizeof(EMPLOYEE),1,p) ==1){
		printf("%d %s %s %d/%d/%d\n", e.id, e.name, e.cpf,e.date.dia,e.date.mes,e.date.ano);
	}
	fclose(p);
}

void setIdEmployee(){

	EMPLOYEE e;
	FILE *p;
	p = fopen("funcionarios.csv", "rb");
	if (!p)
	{
		printf("Arquivo de banco de dados não encontrato");
		menu();
	}

	int max = 0; 

	while(fread(&e,sizeof(EMPLOYEE),1,p) ==1){
		if(e.id > max){
			max = e.id;
		}
	}

	fclose(p);

	id = max +1; 

	printf("ID %d\n", id);

}

