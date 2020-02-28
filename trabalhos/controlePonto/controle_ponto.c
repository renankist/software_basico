#include <stdio.h>

void menu(){

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
	

int  employee_register(int id){

	printf("--------------------------------------------------------\n"); 
	printf("|Sistema de controle de ponto (Cadastro de funcionário)| \n"); 
	printf("--------------------------------------------------------\n"); 
		



	return 0; 

}



int main(void){

	menu();

}