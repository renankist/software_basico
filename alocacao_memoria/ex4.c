/*
04. Faça um laço de entrada de dados, 
onde o usuário deve digitar uma seqüência de
 números, sem limite, sendo que o laço deve parar 
 apenas quando o usuário informar o valor -1. Todos os 
 dados digitados
 pelo usuário devem ser armazenados em um vetor dinâmico e ao final, exibidos.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numero_digitado_usuario, quantidade_numeros_digitados = 0;
    int *p;

    do
    {

        printf("Informe um número: ");
        scanf("%d", &numero_digitado_usuario);
        
        if (numero_digitado_usuario != -1)
        {
            quantidade_numeros_digitados++;

            if (quantidade_numeros_digitados == 1)
            {
                p = (int *)malloc(quantidade_numeros_digitados * sizeof(int));
                *p = numero_digitado_usuario;
            }
            else
            {
                p = realloc(p, quantidade_numeros_digitados * sizeof(int));
                p[quantidade_numeros_digitados - 1 ] = numero_digitado_usuario ;
            }
        }

       
    } while (numero_digitado_usuario !=-1);


    for(int i = 0; i < quantidade_numeros_digitados; i++){
        printf("%d \n", p[i]);
    }

    free(p);

    return 0;
}