/*
01. Criar um algoritmo que recebe como argumentos em linha de comando o nome de
 um arquivo e um número X. O algoritmo gravar no arquivo especificado X linhas de texto, 
 solicitadas ao usuário. Ao final do algoritmo, 
abrir novamente o arquivo e mostrar na tela o conteúdo presente nele.
*/

#include <stdio.h> 
#include <stdlib.h>



void main(){

    FILE *p; 

    char file_name[30]; 
    int number;

    printf("Digite um nome de arquivo:\n");
    fgets(file_name,30,stdin); 
    printf("Digite um número:\n");
    scanf("%d", &number);
    p = fopen(file_name,"w");

    if(!p){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for(int i = 0;i < number; i++){
        fputs("file\n", p);
    }

    fclose(p);

}