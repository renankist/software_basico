/*
15. Defina um registro (struct) pessoa para guardar os dados 
(código, nome e idade). Crie um ponteiro para este struct,
 preencha os valores do struct e exiba na tela através do ponteiro.
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

    struct Pessoa pessoa;
    struct Pessoa *p = &pessoa;

    (*p).codigo = 1;
    p->idade = 25;
    strcpy(p->nome, "Renan");

    return 0;
}