#include <stdio.h>
#include <string.h>
#define TAMANHO_MSG 20
#define TAMANHO_SENHA 12
#define TAMANHO_NOME_ARQUIVO 12

struct Historico
{
    char operacao;
    char nome_arquivo[TAMANHO_NOME_ARQUIVO];
    char mensagem[TAMANHO_MSG];
    char senha[6];
};
typedef struct Historico HISTORICO;

struct Mensagem
{
    char msg_criptografada[TAMANHO_MSG];
    int checksum;
};
typedef struct Mensagem MENSAGEM;

//Funções auxiliares:

int mostra_historico()
{

    printf("----------------------------------------------------\n");
    printf("|     CriptoSystem (Listagem de operações)         | \n");
    printf("----------------------------------------------------\n");

    HISTORICO h;

    FILE *f;
    f = fopen("historico.txt", "rb");

    if (!f)
    {
        printf("Arquivo de banco de dados não encontrato");
        return 0;
    }
    int amount = 0;
    printf(" Operação (c/d) |      Arquivo      |          Mensagem           |     Senha \n");
    while (fread(&h, sizeof(HISTORICO), 1, f) == 1)
    {
        printf(" %c                %s         %s  %s \n", h.operacao, h.nome_arquivo, h.mensagem, h.senha);
        amount++;
    }
    fclose(f);

    printf("--------------------------------------------------------\n");
    printf("Quantidade de operações: %d\n\n", amount);
}

int salva_historico(HISTORICO hist)
{

    FILE *p;

    p = fopen("historico.txt", "ab");

    if (!p)
    {
        printf("Arquivo de banco de dados não encontrato");
        return 0;
    }

    fwrite(&hist, sizeof(HISTORICO), 1, p);

    fclose(p);

    return 1;
}

int conta_char(char str[])
{
    int i = 0;
    do
    {
        ++i;
    } while (str[i] != '\0');
    return i;
}
//-------------------

int gera_arquivo_binario(MENSAGEM m, char arquivo[TAMANHO_NOME_ARQUIVO])
{
    FILE *p;

    p = fopen(arquivo, "ab");

    if (!p)
    {
        printf("Arquivo de banco de dados não encontrato");
        return 0;
    }

    fwrite(&m, sizeof(MENSAGEM), 1, p);

    fclose(p);

    return 1;
}

int descriptografar()
{
    printf("----------------------------------------------------\n");
    printf("|     CriptoSystem (Descriptografar mensagem)      | \n");
    printf("----------------------------------------------------\n");

    int retorno = 0;

    MENSAGEM m;
    HISTORICO h;

    char senha[TAMANHO_SENHA];
    char nome_arquivo[TAMANHO_NOME_ARQUIVO];
    char msg_descriptografada[TAMANHO_MSG];

    printf("Digite o nome do arquivo de origem:");
    fgets(nome_arquivo, TAMANHO_NOME_ARQUIVO, stdin);

    printf("Digite a senha para descriptografar a mensagem:");
    fgets(senha, TAMANHO_SENHA, stdin);
   // strcpy(senha, "admin");
    //Ler arquivo para tentar descriptografar
    FILE *p;
    p = fopen(nome_arquivo, "rb");

    if (!p)
    {
        printf("Arquivo não encontrato");
        retorno = -1;
    }
    else
    {
        int checksum;
        while (fread(&m, sizeof(MENSAGEM), 1, p) == 1)
        {
            //Descriptografar mensagem
            int indice_senha = 0; //Cria um índice da senha para caso dela ser menor que a mensagem
            int i;

            for (i = 0; m.msg_criptografada[i] != '\0'; i++)
            {
                msg_descriptografada[i] =  m.msg_criptografada[i] ^ (senha[indice_senha]) ;

                if (indice_senha == conta_char(senha) - 1)
                {
                    indice_senha = 0;
                }
                else
                {
                    indice_senha++;
                }

                checksum = checksum + m.msg_criptografada[i];
            }
            printf("Mensagem descriptografada: %s\n", msg_descriptografada);
            printf("Checksum descript: %d\n", checksum);
            //checksum = m.checksum - checksum;
        }

        if (checksum == 0)
        {
            printf("Mensagem descriptografa:%s\n", msg_descriptografada);
            //Salva historico
            strcpy(h.mensagem, msg_descriptografada);
            strcpy(h.nome_arquivo, nome_arquivo);
            strcpy(h.senha, senha);
            h.operacao = 'd';
            salva_historico(h);

            retorno = 1;
        }
        else
        {
            printf("Erro! Checksum = %d\n", checksum);
            printf("Senha: %s%d\n", senha, conta_char(senha));
            retorno = checksum;
        }
    }

    return retorno;
}

int criptografar()
{
    printf("----------------------------------------------------\n");
    printf("|     CriptoSystem (Criptografar mensagem)          | \n");
    printf("----------------------------------------------------\n");

    int retorno = 0;

    MENSAGEM m;
    HISTORICO h;
    char senha[TAMANHO_SENHA];
    char nome_arquivo_destino[TAMANHO_NOME_ARQUIVO];
    char msg_original[TAMANHO_MSG];

    printf("Digite a mensagem a ser criptografada: ");
    fgets(msg_original, TAMANHO_MSG, stdin);
    //strcpy(msg_original, "admin");

    printf("Digite a senha usada para criptografar a mensagem: ");
    fgets(senha, TAMANHO_SENHA, stdin);
    //strcpy(senha, "admin");

    printf("Digite o nome do arquivo de destino para a mensagem criptografada: ");
    fgets(nome_arquivo_destino, TAMANHO_NOME_ARQUIVO, stdin);

    //Criptografando mensagem
    int indice_senha = 0; //Cria um índice da senha para caso dela ser menor que a mensagem
    int i;

    for (i = 0; msg_original[i] != '\0'; i++)
    {
        m.msg_criptografada[i] = msg_original[i] ^ (senha[indice_senha]);
        if (indice_senha == conta_char(senha) - 1)
        {
            indice_senha = 0;
        }
        else
        {
            indice_senha++;
        }

        m.checksum = m.checksum + msg_original[i];

    
    }

    printf("Checksum criptografia:  %d", *msg_original);

    retorno = gera_arquivo_binario(m, nome_arquivo_destino);

    if (retorno != 1)
    {
        printf("Erro ao gerar arquivo binário");
    }
    else
    {
        strcpy(h.mensagem, msg_original);
        strcpy(h.nome_arquivo, nome_arquivo_destino);
        strcpy(h.senha, senha);
        h.operacao = 'c';
        salva_historico(h);
    }
    return retorno;
}

int main(int args, char *argv[])
{

    int option = -1;
    //Se o número de argumentos for maior que 1, seta o valor da variavel "option" para abrir uma função especifica sem pedir ao usuario
    if (args > 1)
    {
        if (strcmp(argv[1], "-c") == 0)
        {
            option = 1;
        }
        else if (strcmp(argv[1], "-d") == 0)
        {
            option = 2;
        }
        else if (strcmp(argv[1], "-q") == 0)
        {
            option = 3;
        }
        else if (strcmp(argv[1], "-l") == 0)
        {
            option = 4;
        }
    }

    do
    {
        if (option == -1)
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
        }

        switch (option)
        {
        case 0:
            printf("Sistema finalizando..\n ");
            break;
        case 1:
            system("clear");
            if (criptografar() == 1)
            {
                printf("Mensagem criptografada e salva em um arquivo com sucesso!\n");
                option = -1;
            }
            else
            {
                printf("Problemas para criptografar e gerar arquivo\n");
                option = -1;
            }
            break;
        case 2:
            system("clear");
            if (descriptografar() == 1)
            {
                printf("Sucesso!\n");
                option = -1;
            }
            else
            {
                printf("Problemas ao tentar descriptografar\n");
                option = -1;
            }
            break;
        case 3:

            break;
        case 4:
            system("clear");
            mostra_historico();
            option = -1;
            break;
        default:
            printf("Valor inválido");
        }
    } while (option != 0);

    return 0;
}
