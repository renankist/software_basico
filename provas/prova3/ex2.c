/*
02. (2 pontos) Crie um programa que receba uma string do usuário e 
envie para uma função, que irá retornar o tamanho, um vetor dinamicamente 
alocado com as vogais encontradas na string e um segundo 
vetor dinamicamente alocado com as posições (índices) em que cada uma das 
vogais ocorreu na string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int e_vogal(char c){
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'I' || c == 'i' || c == 'o' || c == 'O' || c == 'U' || c == 'u'){
        return 1;
    }
    return 0;
}


void retorna_vogais_e_seus_indices(char *string, char *vogais, int *indice, int *tamanho_vetores_vogais_e_string){

    int i;
    *tamanho_vetores_vogais_e_string = 0;

    for(i = 0; string[i] != '\0';i++){
        if(e_vogal(string[i])==1){
            vogais[*tamanho_vetores_vogais_e_string] = string[i];
            indice[*tamanho_vetores_vogais_e_string] = i;

            *tamanho_vetores_vogais_e_string =   *tamanho_vetores_vogais_e_string + 1;

            vogais = realloc(vogais, (*tamanho_vetores_vogais_e_string + 1) * sizeof(char));
            indice = realloc(indice, (*tamanho_vetores_vogais_e_string + 1) * sizeof(int));
        }
    }

     indice = realloc(indice, *tamanho_vetores_vogais_e_string  * sizeof(int));
     indice = realloc(indice, *tamanho_vetores_vogais_e_string  * sizeof(int));

}

int main (){

    char string_usuario[15];
    char *string_com_vogais =  (char *) malloc(sizeof(char));    
    int  *indice_vogais = (int *) malloc(sizeof(int));
    printf("Digite uma string: ");
    fgets(string_usuario, 14, stdin);
    int tamanho_vetores_vogais_e_string; 

    retorna_vogais_e_seus_indices(string_usuario, string_com_vogais, indice_vogais, &tamanho_vetores_vogais_e_string);

    //imprime vetor de vogais
    int i = 0; 

    printf("Vogais: ");
    for(i = 0; i < tamanho_vetores_vogais_e_string; i++){
        printf("%c", string_com_vogais[i]);
    }

    printf("\nÍndices: ");
    for(i = 0; i < tamanho_vetores_vogais_e_string; i++){
        printf("%d", indice_vogais[i]);
    }


    free(string_com_vogais);
    free(indice_vogais);

    return 0; 

}