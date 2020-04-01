/*
01. Defina um registro (struct) empregado para guardar os dados (código, nome e salário) de um empregado de uma empresa.  
Defina um vetor de empregados para armazenar todos os empregados de uma empresa. Faça um algoritmo para preencher este 
vetor e depois exibi-lo.
*/

#include <stdio.h>

typedef struct{
    int codigo;
    char* nome; 
    double salario; 
} Empregado; 

void main(){

    Empregado empregados[4]; 

    for(int x = 0; x <=3; x++){
        empregados[x].codigo = 1; 
        empregados[x].nome = "teste"; 
        empregados[x].salario = 2500.00;
    }

    //print first employer
    printf("Código: %d\n",empregados[0].codigo);
    printf("Nome: %s\n",empregados[1].nome);
    printf("Salário: %lf\n",empregados[2].salario);

}

