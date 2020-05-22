/*
16. Usando ponteiros, defina um vetor de structs para armazenar 5 pessoas. 
Faça um algoritmo para preencher este vetor e depois exibi-lo.
*/
#include <stdio.h>
#include <string.h>

struct Pessoa
{
	int codigo;
	char nome[20];
	int  idade;
};


int main(){

    struct Pessoa pessoas[5];
    struct Pessoa *p = pessoas;

    (*p).codigo = 1;
    p->idade = 25;
    strcpy(p->nome, "Renan");

    return 0;
}