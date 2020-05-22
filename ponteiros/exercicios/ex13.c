/*
13. Escreva uma função que recebe dois ponteiros para string.
 O primeiro ponteiro deve conter o nome de uma pessoa e o segundo irá 
 retornar as iniciais deste nome. Por exemplo, 
a entrada de "ozzy osbourne" deve retornar a saída de "OO". Testar a função criada.
*/

#include <stdio.h>
#include <ctype.h>

void retorna_iniciais(char *nome, char *iniciais){
    
    int tmp = 1;
    while(*nome != '\0'){

        if(tmp == 1){
            *iniciais = *nome;
             iniciais++; 
             tmp = 0;
        }

        if(isspace(*nome)){
            tmp = 1;  
        }

        nome++; 
    }

    *iniciais = '\0';

}

int main(){ 

    char nome[] = "Renan Luis Kist";
    char iniciais[4] = "";   

    int b = 0; 
 
    retorna_iniciais(nome, iniciais);

    int i = 0; 
    while(iniciais[i] != '\0'){
        printf("%c", iniciais[i]);
      
        i++;
    }
    printf("\n");

    return 0;
}