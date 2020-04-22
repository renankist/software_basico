#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int id = 0; //Variavel que guarda o ID de quando se quer inserir um novo employee

struct Date
{
	int day;
	int month;
	int year;
};
typedef struct Date DATE;

struct Hour
{
	int hour;
	int minute;
};
typedef struct Hour HOUR;

struct Employee
{
	int id;
	char cpf[12];
	char name[20];
	DATE date;
};
typedef struct Employee EMPLOYEE;

struct Point
{
	EMPLOYEE employee;
	DATE date;
	HOUR hour;
	char type;		 //e (in) s (out)
	char work_shift; // turno da saída m (manhã) t(tarde) e n(notie)
};
typedef struct Point POINT;

void menu()
{
	int option;

	do
	{

		printf("-------------------------------------------------\n");
		printf("| Sistema de controle de ponto (Menu)           | \n");
		printf("-------------------------------------------------\n");
		printf(" [1] Cadastrar um novo funcionário\n");
		printf(" [2] Listar funcionários cadastrados\n");
		printf(" [3] Exibir relatório de ponto de um funcionário\n");
		printf(" [4] Exibir relatório de pendências de registro\n");
		printf(" [5] Gravar registro do ponto\n");
		printf(" [6] Buscar um funcionário \n");
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
			employee_register(id);
			menu();
			break;
		case 2:
			system("clear");
			showEmployees();
			menu();
			break;
		case 3:
			system("clear");
			employee_point_report();
			menu();
			break;
		case 5:
			system("clear");
			point_register();
			menu();
			break;
		case 6:
			system("clear");
			showEmployee();
			menu();
			break;
		default:
			printf("Valor inválido");
		}
	} while (option != 0);
}

EMPLOYEE getEmployee(int id)
{
	EMPLOYEE e;

	FILE *p;
	p = fopen("funcionarios.csv", "rb");
	if (!p)
	{
		return;
	}
	while (fread(&e, sizeof(EMPLOYEE), 1, p) == 1)
	{
		if (e.id == id)
		{
			return e;
		}
	}

	fclose(p);

	return e;
}

void employee_point_report()
{
	//Passo 1) Consultar o funcionário do ponto

	int control = 1;
	int id_employee_tmp;
	EMPLOYEE e;

	printf("--------------------------------------------------------\n");
	printf("|Sistema de controle de ponto (Listagem de pontos)      | \n");
	printf("--------------------------------------------------------\n");

	do
	{
		printf("Digite o id do funcionário: ");
		scanf("%d", &id_employee_tmp);
		e = getEmployee(id_employee_tmp);

		if (e.id == id_employee_tmp)
		{
			break;
		}
		printf("Funcionário de ID %d não encontrado. \n", id_employee_tmp);

	} while (control == 1);

	system("clear");

	int option;

	do
	{
		POINT p;
		p.employee = e;
		printf("-------------------------------------------------------\n");
		printf("| Sistema de controle de ponto (Listagem de ponto)    | \n");
		printf("-------------------------------------------------------\n");
		printf("Funcionário: %s \n",p.employee.name);
		printf("Data de admissão: %d/%d/%d\n", p.employee.date.day, p.employee.date.month,p.employee.date.year);
	    printf("? Tipo de registro: e = entrada s = saída\n");
		printf("? Turno do registro: m = manhã t = tarde n = noite\n");
		printf("----------------------Registros---------------------------\n");
		FILE *f;
		f = fopen("ponto.csv", "rb");
		if (!f)
		{
			printf("Arquivo de banco de dados não encontrato");
			menu();
		}

		printf(" Data       |     Hora      |      Tipo  |      Turno  \n");
		while (fread(&p, sizeof(POINT), 1, f) == 1)
		{
			if(p.employee.id == e.id){
				printf("%d/%d/%d         %d:%d              %c             %c\n",p.date.day,p.date.month,p.date.year,p.hour.hour, p.hour.minute, p.type,p.work_shift);
			}
		}
		fclose(f);

		printf("Digite 1 para listar novamente ou 2 para voltar ao menu: ");
		scanf("%d", &option);
		system("clear");

	} while ((option == 1));
}

void point_register()
{

	//Passo 1) Consultar o funcionário do ponto

	int control = 1;
	int id_employee_tmp;
	EMPLOYEE e;

	printf("--------------------------------------------------------\n");
	printf("|Sistema de controle de ponto (Cadastro de ponto)      | \n");
	printf("--------------------------------------------------------\n");

	do
	{
		printf("Digite o id do funcionário: ");
		scanf("%d", &id_employee_tmp);
		e = getEmployee(id_employee_tmp);

		if (e.id == id_employee_tmp)
		{
			break;
		}
		printf("Funcionário de ID %d não encontrado. \n", id_employee_tmp);

	} while (control == 1);

	// 2) Pegar dados do ponto
	int resp = 1;
	do
	{

		POINT p;
		p.employee = e;

		system("clear");
		printf("--------------------------------------------------------\n");
		printf("|Registro de ponto  (%s) \n", p.employee.name);
		printf("--------------------------------------------------------\n");
		printf("Digite o dia do ponto: ");
		scanf("%d", &p.date.day);
		getchar();
		printf("Digite o número do mês do ponto: ");
		scanf("%d", &p.date.month);
		getchar();
		printf("Digite o ano do ponto: ");
		scanf("%d", &p.date.year);
		printf("Digite a hora do ponto: ");
		scanf("%d", &p.hour.hour);
		printf("Digite os minutos do ponto: ");
		scanf("%d", &p.hour.minute);
		getchar();
		printf("Tipo de registo e(entrada) ou s(saída): ");
		scanf("%c", &p.type);
		getchar();
		printf("Turno do registro: m(manhã), t(tarde) ou n(noite): ");
		scanf("%c", &p.work_shift);
		getchar();
		char resposta;
		printf("Deseja realizar o lançamento do ponto? [s/n] ");
		scanf("%c", &resposta);

		if (resposta != 's')
		{
			system("clear");
			return;
		}

		FILE *f;

		f = fopen("ponto.csv", "ab");

		if (!f)
		{
			printf("Arquivo de banco de dados não encontrato");
			return;
		}

		fwrite(&p, sizeof(POINT), 1, f);

		printf("Ponto lançado  com sucesso! \n");

		fclose(f);

		printf("Digite 1 para fazer outro lançamento de ponto ou 2 para voltar ao menu\n");
		scanf("%d", &resp);
		system("clear");

	} while ((resp == 1));
}

void employee_register(int id)
{
	int resp = 1;
	do
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
		scanf("%d", &e.date.day);
		getchar();
		printf("Digite o número do mês de nascimento do funcionário: ");
		scanf("%d", &e.date.month);
		getchar();
		printf("Digite o ano de nascimento do funcionário: ");
		scanf("%d", &e.date.year);
		getchar();

		char resposta;
		printf("Deseja cadastrar o funcionário? [s/n]");
		scanf("%c", &resposta);

		//Inserir funcionário no arquivo funcionarios.csv
		if (resposta != 's')
		{
			system("clear");
			return;
		}

		FILE *p;

		p = fopen("funcionarios.csv", "ab");

		if (!p)
		{
			printf("Arquivo de banco de dados não encontrato");
			return;
		}

		fwrite(&e, sizeof(EMPLOYEE), 1, p);

		printf("Funcionário %s cadastrado com sucesso! \n", e.name);

		fclose(p);

		setIdEmployee();

		printf("Digite 1 para cadastrar outro funcionário ou 2 para voltar ao menu\n");
		scanf("%d", &resp);
		system("clear");
		fgets(e.name, 20, stdin);

	} while ((resp == 1));
}

showEmployee()
{
	int option;

	do
	{
		EMPLOYEE e;
		int id_user;
		printf("--------------------------------------------------------\n");
		printf("| Sistema de controle de ponto (Consulta de funcionário)| \n");
		printf("--------------------------------------------------------\n");

		printf("Digite o ID do funcionário: ");
		scanf("%d", &id_user);

		FILE *p;
		p = fopen("funcionarios.csv", "rb");
		if (!p)
		{
			printf("Arquivo de banco de dados não encontrato");
			return;
		}

		//Verifica se existe um usuário com o código passado
		int has_user = 0;
		while (fread(&e, sizeof(EMPLOYEE), 1, p) == 1)
		{
			if (e.id == id_user)
			{
				has_user = 1;
				break;
			}
		}

		if (has_user == 1)
		{
			printf("ID | NOME | CPF | DATA DE ADMISSÃO\n");
			printf("%d %s %s %d/%d/%d\n", e.id, e.name, e.cpf, e.date.day, e.date.month, e.date.year);
		}
		else
		{
			printf("Funcionário não encontrado \n");
		}

		has_user = 0;

		fclose(p);

		printf("Digite 1 para consultar outro usuário ou 2 para voltar ao menu: ");
		scanf("%d", &option);
		system("clear");

	} while ((option == 1));
}

void showEmployees()
{
	int option;

	do
	{
		printf("-------------------------------------------------------\n");
		printf("| Sistema de controle de ponto (Lista de funcionários)| \n");
		printf("-------------------------------------------------------\n");
		printf("ID | NOME | CPF | DATA DE NASCIMENTO\n");
		EMPLOYEE e;
		FILE *p;
		p = fopen("funcionarios.csv", "rb");
		if (!p)
		{
			printf("Arquivo de banco de dados não encontrato");
			menu();
		}

		while (fread(&e, sizeof(EMPLOYEE), 1, p) == 1)
		{
			printf("%d %s %s %d/%d/%d\n", e.id, e.name, e.cpf, e.date.day, e.date.month, e.date.year);
		}
		fclose(p);

		printf("Digite 1 para listar novamente ou 2 para voltar ao menu: ");
		scanf("%d", &option);
		system("clear");

	} while ((option == 1));
}

void setIdEmployee()
{

	EMPLOYEE e;
	FILE *p;
	p = fopen("funcionarios.csv", "rb");
	if (!p)
	{
		printf("Arquivo de banco de dados não encontrato");
		menu();
	}

	int max = 0;

	while (fread(&e, sizeof(EMPLOYEE), 1, p) == 1)
	{
		if (e.id > max)
		{
			max = e.id;
		}
	}

	fclose(p);

	id = max + 1;
}

void main()
{
	setIdEmployee();
	menu();
}
