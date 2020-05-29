#include <stdio.h>
#define TAMANHO_MSG 20
#define TAMANHO_SENHA 8
#define TAMANHO_NOME_ARQUIVO 12

struct Mensagem
{
	char msg[TAMANHO_MSG];
	int checksum;

};
typedef struct Mensagem MENSAGEM;

int descriptografar(){
    printf("----------------------------------------------------\n");
    printf("|     CriptoSystem (Descriptografar mensagem)      | \n");
    printf("----------------------------------------------------\n");
    
    int retorno = 0;

    MENSAGEM m; 
    char senha[TAMANHO_SENHA];
    char nome_arquivo[TAMANHO_NOME_ARQUIVO];

    printf("Digite o nome do arquivo de origem: ");
	fgets(nome_arquivo,TAMANHO_NOME_ARQUIVO, stdin); 

    printf("Digite a senha para descriptografar a mensagem: ");
	fgets(senha, TAMANHO_SENHA, stdin);    

    /*descriptogragar
        Se der ok retorno = 0; 
        Se der numero diferente retornar o nível do erro.
    */ 

    /*
        if retorno  = 0 { 
            IMPRIMIR MENSAGEM DESCRIPTOGRAFADA
        }
    */

    return retorno;
}


int criptografar(){
    printf("----------------------------------------------------\n");
    printf("|     CriptoSystem (Criptografar mensagem)          | \n");
    printf("----------------------------------------------------\n");
    
    int retorno = 0;

    MENSAGEM m; 
    char senha[TAMANHO_SENHA];
    char nome_arquivo_destino[TAMANHO_NOME_ARQUIVO];

    printf("Digite a mensagem a ser criptografada: ");
	fgets(m.msg, TAMANHO_MSG, stdin); 

    printf("Digite a senha usada para criptografar a mensagem: ");
	fgets(senha, TAMANHO_SENHA, stdin);    

    printf("Digite o nome do arquivo de destino para a mensagem criptografada: ");
	fgets(nome_arquivo_destino, TAMANHO_NOME_ARQUIVO, stdin);    

    //int retorno = gera_arquivo_binario(m, senha, nome_arquivo_destino);

    return retorno;
}


int main()
{
    int option;
    do
    {

        printf("----------------------------------------------------\n");
        printf("|               CriptoSystem (Menu)                | \n");
        printf("----------------------------------------------------\n");
        printf("| [1] Criptografar mensagem                        |\n");
        printf("| [2] Descriptografar mensagem                     |\n");
        printf("| [3] Quebrar senha                                |\n");
        printf("| [4] Histórico de criptografias e descriptografias|\n");
        printf("| [0] Sair do sistema                              |\n");
        printf("----------------------------------------------------\n");
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
            criptografar();
            break;
        case 2:
            system("clear");
            descriptografar();
            break;
        case 3:
            system("clear");
            break;
        case 4:
            system("clear");
            break;
        default:
            printf("Valor inválido");
        }
    } while (option != 0);

    return 0;
}
