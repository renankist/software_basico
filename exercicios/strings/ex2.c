/*
02. Crie uma função literal() que receba uma string (como um vetor de caracteres, 
terminado pelo caracter zero) e que reconheça se ela corresponde ao nome de um número 
inteiro ("zero", "um", "dois", até "nove"), retornando o valor inteiro correspondente. 
Retorne -1 se não for encontrado um valor conhecido. Teste esta função.
*/
#include <stdio.h>
#include <string.h>




int literal(char string[7]){
    char nove[7] = "nove";
    if(strcmp(string, nove) == 0){
        printf("Retorno: 9");
    }
     char oito[7] = "oito";
    if(strcmp(string, oito) == 0){
        printf("Retorno: 8");
    }
     char sete[7] = "sete";
    if(strcmp(string, sete) == 0){
        printf("Retorno: 7");
    }
     char seis[7] = "seis";
    if(strcmp(string, seis) == 0){
        printf("Retorno: 6");
    }
     char cinco[7] = "cinco";
    if(strcmp(string, cinco) == 0){
        printf("Retorno: 5");
    }
     char quatro[7] = "quatro";
    if(strcmp(string, quatro) == 0){
        printf("Retorno: 4");
    }
     char tres[7] = "tres";
    if(strcmp(string, tres) == 0){
        printf("Retorno: 3");
    }
     char dois[7] = "dois";
    if(strcmp(string, dois) == 0){
        printf("Retorno: 2");
    }
     char um[7] = "um";
    if(strcmp(string, um) == 0){
        printf("Retorno: 1");
    }
     char zero[7] = "zero";
    if(strcmp(string, zero) == 0){
        printf("Retorno: 0");
    }

}

void main(){
    char nove[7] = "nove";
    literal(nove);
}
