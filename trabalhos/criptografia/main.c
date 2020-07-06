#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_MSG 20
#define TAMANHO_SENHA 20
#define TAMANHO_NOME_ARQUIVO 12

struct Historico
{
    char operacao;
    char nome_arquivo[TAMANHO_NOME_ARQUIVO];
    char mensagem[TAMANHO_MSG];
    char senha[TAMANHO_SENHA];
};
typedef struct Historico HISTORICO;

struct Mensagem
{
    char msg_criptografada[TAMANHO_MSG];
    int checksum;
};
typedef struct Mensagem MENSAGEM;

int conta_char(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {

        i++;
    }
    return i;
}
int descriptografa(char *mensagem_cript, char *senha, char *mensagem_descrip)
{
    int indice_senha = conta_char(senha) - 1;
    int checksum = 0;
    int i = 0;
    int tam_mensagem = conta_char(mensagem_cript);
    int senha_menor_que_mensagem = 0;

    for (i = 0; i < tam_mensagem; i++)
    {
        if (senha_menor_que_mensagem == 0)
        {
            mensagem_descrip[i] = mensagem_cript[i] ^ senha[indice_senha];
        }
        else
        {
            mensagem_descrip[i] = mensagem_cript[i] ^ (senha[indice_senha] + 1);
        }

        if (indice_senha == 0)
        {
            indice_senha = conta_char(senha) - 1;
            senha_menor_que_mensagem = 1;
        }
        else
        {
            indice_senha--;
        }
        checksum += mensagem_descrip[i];
    }
    mensagem_descrip[tam_mensagem] = '\0';

    return checksum;
}

int criptografa(char *mensagem, char *senha, char *mensagem_cript)
{
    int indice_senha = conta_char(senha) - 1;
    int checksum = 0;
    int i;
    int tam_mensagem = conta_char(mensagem);
    int senha_menor_que_mensagem = 0;

    for (i = 0; i < tam_mensagem; i++)
    {
        if (senha_menor_que_mensagem == 0)
        {
            mensagem_cript[i] = mensagem[i] ^ senha[indice_senha];
        }
        else
        {
            mensagem_cript[i] = mensagem[i] ^ (senha[indice_senha] + 1);
        }

        if (indice_senha == 0)
        {
            indice_senha = conta_char(senha) - 1;
            senha_menor_que_mensagem = 1;
        }
        else
        {
            indice_senha--;
        }

        checksum += mensagem[i];
    }

    mensagem_cript[tam_mensagem] = '\0';

    return checksum;
}

void gera_senha(char *senha_aleatoria)
{
    char key_lchar[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int quant = 1;
    int n = 0;

    srand(time(NULL));

    for (n = 0; n <= quant; n++)
    {
        senha_aleatoria[n] = key_lchar[rand() % 57];
    }

}

void quebrar_senha()
{

    printf("----------------------------------------------------\n");
    printf("|     CriptoSystem (Quebrar senha)                 | \n");
    printf("----------------------------------------------------\n");

    int retorno = 0;
    int checksum = 1;
    MENSAGEM m;

    char senha[TAMANHO_SENHA];
    char nome_arquivo[TAMANHO_NOME_ARQUIVO];
    char msg_descriptografada[TAMANHO_MSG];
    char msg_criptografada[TAMANHO_MSG];
    int checksum_msg_original;

    printf("Digite o nome do arquivo que contem a mensagem a ser quebrada: ");
    fgets(nome_arquivo, TAMANHO_NOME_ARQUIVO, stdin);

    //Abrir arquivo e ler mensagem
    FILE *f;
    f = fopen(nome_arquivo, "rb");
    if (!f)
    {
        printf("Arquivo de banco de dados não encontrato");
    }
    while (fread(&m, sizeof(MENSAGEM), 1, f) == 1)
    {
        strcpy(msg_criptografada, m.msg_criptografada);
        checksum_msg_original = m.checksum;
    }

    fclose(f);

    printf("Mensagem original %d: ", checksum_msg_original);

  
}

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
    while (fread(&h, sizeof(HISTORICO), 1, f) == 1)
    {
        printf("Operação: %c\n", h.operacao);
        printf("Nome arquivo: %s", h.nome_arquivo);
        printf("Mensagem: %s", h.mensagem);
        printf("Senha: %s\n", h.senha);
        printf("----------------------------------------------------\n");
        amount++;
    }
    fclose(f);
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

int menu_descriptografar()
{
    printf("----------------------------------------------------\n");
    printf("|     CriptoSystem (Descriptografar mensagem)      | \n");
    printf("----------------------------------------------------\n");

    int retorno = 0;
    int checksum = 0;
    MENSAGEM m;
    HISTORICO h;

    char senha[TAMANHO_SENHA];
    char nome_arquivo[TAMANHO_NOME_ARQUIVO];
    char msg_descriptografada[TAMANHO_MSG];
    char msg_criptografada[TAMANHO_MSG];
    int checksum_msg_original;

    printf("Digite o nome do arquivo de origem: ");
    fgets(nome_arquivo, TAMANHO_NOME_ARQUIVO, stdin);

    printf("Digite a senha para descriptografar a mensagem: ");
    fgets(senha, TAMANHO_SENHA, stdin);
    senha[strlen(senha) - 1] = '\0';

    //Abrir arquivo e ler mensagem
    FILE *f;
    f = fopen(nome_arquivo, "rb");

    if (!f)
    {
        printf("Arquivo de banco de dados não encontrato");
        return 0;
    }

    while (fread(&m, sizeof(MENSAGEM), 1, f) == 1)
    {
        strcpy(msg_criptografada, m.msg_criptografada);
        checksum_msg_original = m.checksum;
    }

    fclose(f);

    checksum = descriptografa(msg_criptografada, senha, msg_descriptografada);

    checksum = checksum - checksum_msg_original;

    if (checksum == 0)
    {
        printf("Mensagem descriptografada: %s\n", msg_descriptografada);
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
        retorno = checksum;
    }

    return retorno;
}

int menu_criptografar()
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

    printf("Digite a senha usada para criptografar a mensagem: ");

    fgets(senha, TAMANHO_SENHA, stdin);
    senha[strlen(senha) - 1] = '\0';

    printf("Digite o nome do arquivo de destino para a mensagem criptografada: ");
    fgets(nome_arquivo_destino, TAMANHO_NOME_ARQUIVO, stdin);

    m.checksum = criptografa(msg_original, senha, m.msg_criptografada);

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
            if (menu_criptografar() == 1)
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
            if (menu_descriptografar() == 1)
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
            system("clear");
            quebrar_senha();
            option = -1;
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
