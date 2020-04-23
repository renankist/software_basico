#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//STRUCTS
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
	char cpf[16];
	char name[20];
	char start_date[20];
};
typedef struct Employee EMPLOYEE;

struct Point
{
	EMPLOYEE employee;
	DATE date;
	HOUR hour;
	char type;		 //e (in) s (out)
	char work_shift; // turno da saída m (manhã) t(tarde)
};
typedef struct Point POINT;

//FUNCTIONS
int getIdEmployee();		   // Retorna o ID a ser utilizado em um novo cadastro de funcionário
int employee_register(int id); // Recebe o ID a ser utilizado no novo usuário e devolve 1 se sucesso
void employee_list();		   // Lista os funcionários cadastrados
void employee_report(int id);  // Trás o relatório do registro de pontos de um funcionário, conforme ID
EMPLOYEE getEmployee(int id);  // Recebe um ID e retorna a struct de funcionnário correspondente
void employees_report();	   // Mostra o relatório de pendências dos funcionários
int employee_punch(int id);	   //Função que recebe o ID do usuário a qual sera usado para registrar um pónto e retorna 1 se sucesso
int hour_is_correct(int hour, int minute, char type, char work_shift); // Função que veriica se a hora do ponto está dentro do intervalo "normal" de cada turno e tipo de movimentação
void menu(); // Função que possui a logica da aplicação
void showEmployee(); // Solicita um id de funcionário e retorna se ele existir na base de dados 

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
			int resp = 1;

			do
			{
				if (employee_register(getIdEmployee()) != 1)

				{
					printf("Falha ao tentar inserir usuário!");
				}

				printf("Funcionário cadastrado com sucesso! \n");
				printf("Digite 1 para cadastrar outro funcionário ou 2 para voltar ao menu: ");
				scanf("%d", &resp);
				system("clear");

			} while ((resp == 1));
			break;

		case 2:
			system("clear");
			employee_list();
			break;
		case 3:
			system("clear");
			int control = 1;
			int id_employee_tmp;
			EMPLOYEE e;
			do
			{
				printf("--------------------------------------------------------\n");
				printf("|Sistema de controle de ponto (Listagem de pontos)      | \n");
				printf("--------------------------------------------------------\n");
				printf("Digite o id do funcionário: ");
				scanf("%d", &id_employee_tmp);
				e = getEmployee(id_employee_tmp);
				if (e.id == id_employee_tmp)
				{
					system("clear");
					break;
				}
				printf("Funcionário de ID %d não encontrado. \n", id_employee_tmp);

			} while (control == 1);
			employee_report(e.id);
			break;
		case 4:
			system("clear");
			employees_report();
			break;
		case 5:
			system("clear");
			int resp2 = 1;
			do
			{
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
				if (employee_punch(id_employee_tmp) != 1)
				{
					printf("Erro ao tentar cadastrar ponto! \n");
				}
				printf("Digite 1 para fazer outro lançamento de ponto ou 2 para voltar ao menu: ");
				scanf("%d", &resp2);
				system("clear");
			} while ((resp2 == 1));

			break;
		case 6:
			system("clear");
			showEmployee();
			break;
		default:
			printf("Valor inválido");
		}
	} while (option != 0);
}

int getIdEmployee()
{

	EMPLOYEE e;
	FILE *p;
	p = fopen("funcionarios.csv", "rb");
	if (!p)
	{
		printf("Arquivo de banco de dados não encontrato");
		return;
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

	return max + 1;
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

int hour_is_correct(int hour, int minute, char type, char work_shift)
{

	//Entrada manhã 7:55 a 8:05
	if (work_shift == 'm' && type == 'e')
	{
		// verifica se a hora está entre 07:55 e 08:05
		if (hour != 7 && hour != 8)
		{
			return -1;
		}
		if (hour == 8 && minute > 5)
		{
			return -1;
		}
		if (hour == 7 && minute < 55)
		{
			return -1;
		}
	}

	//Saída manhã 11:55 a 12:05
	if (work_shift == 'm' && type == 's')
	{
		// verifica se a hora está entre 11:55 e 12:05
		if (hour != 11 && hour != 12)
		{
			return -1;
		}
		if (hour == 12 && minute > 5)
		{
			return -1;
		}
		if (hour == 11 && minute < 55)
		{
			return -1;
		}
	}

	//Entrada tarde 13:25 a 13:35
	if (work_shift == 't' && type == 'e')
	{
		// verifica se a hora está entre 13:25 e 13:35
		if (hour != 13)
		{
			return -1;
		}
		if (minute > 35 || minute < 25)
		{
			return -1;
		}
	}

	//Saída tarde 17:55 a 18:05
	if (work_shift == 't' && type == 's')
	{
		// verifica se a hora está entre 17:55 e 18:05
		if (hour != 17 && hour != 18)
		{
			return -1;
		}
		if (hour == 18 && minute > 5)
		{
			return -1;
		}
		if (hour == 17 && minute < 55)
		{
			return -1;
		}
	}

	return 1;
}

void employee_report(int id)
{
	int option;
	do
	{
		printf("--------------------------------------------------------\n");
		printf("|Sistema de controle de ponto (Listagem de pontos)      | \n");
		printf("--------------------------------------------------------\n");
		POINT p;
		p.employee = getEmployee(id);
		printf("Funcionário: %s \n", p.employee.name);
		printf("Data de admissão: %s\n", p.employee.start_date);
		printf("? Tipo de registro: e = entrada s = saída\n");
		printf("? Turno do registro: m = manhã t = tarde\n");
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
			if (p.employee.id == id)
			{
				printf("%d/%d/%d         %d:%d              %c             %c\n", p.date.day, p.date.month, p.date.year, p.hour.hour, p.hour.minute, p.type, p.work_shift);
			}
		}
		fclose(f);

		printf("Digite 1 para listar novamente ou 2 para voltar ao menu: ");
		scanf("%d", &option);
		system("clear");

	} while ((option == 1));
}

void employees_report()
{
	int option;

	do
	{
		system("clear");
		printf("--------------------------------------------------------\n");
		printf("|Sistema de controle de ponto (Listagem de pendências)  | \n");
		printf("--------------------------------------------------------\n");
		printf("? Tipo de registro: e = entrada s = saída\n");
		printf("? Turno do registro: m = manhã t = tarde\n");
		printf("----------------------Pendências------------------------\n");

		POINT p;

		FILE *f;
		f = fopen("ponto.csv", "rb");

		if (!f)
		{
			printf("Arquivo de banco de dados não encontrato");
			menu();
		}
		int amount = 0;
		printf(" Data       | Hora  |  Tipo  |  Turno  | Funcionário  \n");
		while (fread(&p, sizeof(POINT), 1, f) == 1)
		{

			if (hour_is_correct(p.hour.hour, p.hour.minute, p.type, p.work_shift) == -1)
			{
				printf(" %d/%d/%d    %d:%d      %c    	 %c       %s\n", p.date.day, p.date.month, p.date.year, p.hour.hour, p.hour.minute, p.type, p.work_shift, p.employee.name);
				amount++;
			}
		}
		fclose(f);

		printf("--------------------------------------------------------\n");
		printf("Quantidade de pendências: %d\n\n", amount);

		printf("Digite 1 para listar novamente ou 2 para voltar ao menu: ");
		scanf("%d", &option);
		system("clear");

	} while ((option == 1));
}

int employee_punch(int id)
{

	POINT p;
	p.employee = getEmployee(id);

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
	printf("Turno do registro: m(manhã), t(tarde): ");
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
		return -1;
	}

	fwrite(&p, sizeof(POINT), 1, f);

	fclose(f);
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
	printf("Digite o CPF do funcionário (###.###.###-##): ");
	fgets(e.cpf, 16, stdin);
	e.cpf[strlen(e.cpf) - 1] = '\0';
	printf("Digite a data de admissão do funcionário (dd/mm/aaaa): ");
	e.cpf[strlen(e.start_date) - 1] = '\0';
	fgets(e.start_date, 20, stdin);

	char resposta;
	printf("Deseja cadastrar o funcionário? [s/n] ");
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
		return -1;
	}
	fwrite(&e, sizeof(EMPLOYEE), 1, p);

	fclose(p);

	return 1;
}

void showEmployee()
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
			printf("ID  |       NOME        |     CPF       | DATA DE NASCIMENTO\n");
			printf("%d    %s       %s  %s\n", e.id, e.name, e.cpf, e.start_date);
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

void employee_list()
{
	int option;

	do
	{
		printf("------------------------------------------------------------\n");
		printf("| Sistema de controle de ponto (Lista de funcionários)     | \n");
		printf("------------------------------------------------------------\n");
		printf("ID  |       NOME        |     CPF       | DATA DE NASCIMENTO\n");
		EMPLOYEE e;
		FILE *p;
		p = fopen("funcionarios.csv", "rb");
		if (!p)
		{
			printf("Arquivo de banco de dados não encontrato");
			menu();
		}

		int amount = 0;
		while (fread(&e, sizeof(EMPLOYEE), 1, p) == 1)
		{

			//Verificar tamanho de cada nome dos funcionarios
			int tmp_name_size = 0;
			for (int i = 0; e.name[i] != '\0'; i++)
			{
				tmp_name_size++;
			}
			//Preenche os caracteres após o nome para deixar tudo alinhado
			for (int x = tmp_name_size + 1; tmp_name_size < 19; tmp_name_size++)
			{
				e.name[tmp_name_size] = '-';
			}

			//Verificar tamanho de cada cpff dos funcionarios
			int tmp_cpf_size = 0;
			for (int i = 0; e.cpf[i] != '\0'; i++)
			{
				tmp_cpf_size++;
			}
			//Preenche os caracteres após o cpf para deixar tudo alinhado
			for (int x = tmp_cpf_size + 1; tmp_cpf_size < 14; tmp_cpf_size++)
			{
				e.cpf[tmp_cpf_size] = '-';
			}

			printf("%d    %s %s   %s\n", e.id, e.name, e.cpf, e.start_date);
			amount++;
		}
		printf("------------------------------------------------------------\n");
		printf("Quantidade de registros: %d\n\n", amount);
		fclose(p);

		printf("Digite 1 para listar novamente ou 2 para voltar ao menu: ");

		scanf("%d", &option);
		system("clear");

	} while ((option == 1));
}

void main()
{
	system("clear");
	menu();
}
