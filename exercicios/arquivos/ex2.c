/*
Desenvolver um programa em C que lê o conteúdo de um arquivo e cria um arquivo com o mesmo conteúdo, 
mas com todas as letras minúsculas convertidas para maiúsculas. Os nomes dos arquivos serão fornecidos 
por argumentos em linha de comando. A função que converte maiúscula para minúscula é o toupper(). 
Ela é aplicada em cada caractere da string.
*/
#include <stdio.h>



void main(){

    FILE *p;
    FILE *q; 

    char first_file_name[30];
    char second_file_name[30];

    printf("Digite o nome do arquivo a ser copiado:\n");
    fgets(first_file_name,30,stdin); 
    printf("Digite o nome do arquivo a receber o conteúdo:\n");
    fgets(second_file_name,30,stdin); 

    p = fopen(first_file_name,"r");
    q = fopen(second_file_name,"w");
    



}