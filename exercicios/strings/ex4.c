/*
04. Escreva um programa que defina quatro strings: "vovo", "viu", "a" e "uva".
 Primeiro, você deve criar uma string frase1 com a concatenação destas quatro strings, 
 usando a função strcpy() para copiar a primeira string e strcat() para as demais 
 (reserve espaço suficiente para o resultado ao criar a string frase1). Depois, 
 você deve usar a função sprintf() para construir uma segunda concatenação chamada frase2, 
 agora usando um formato adequado e adicionando espaço entre as strings iniciais.
 Imprima as duas strings resultantes.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


void main(){
    char vovo[5] = "vovo"; 
    char viu[4]  = "viu";
    char a[2] = "a";
    char uva[4] = "uva";

    char frase1[18];

    strcpy(frase1, vovo);
    strcat(frase1," ");
    strcat(frase1, viu);
    strcat(frase1," ");
    strcat(frase1,a);
    strcat(frase1," ");
    strcat(frase1,uva);

    printf("%s\n",frase1);


    char frase2[18];
    
    sprintf(frase2, "%s %s %s %s",vovo,viu,a,uva);

    printf("%s\n",frase2);
}   