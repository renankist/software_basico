/*
14. Escreva uma função que recebe dois ponteiros para string. 
A função deverá retornar no segundo ponteiro uma nova string que 
substitui cada letra da primeira string pela letra seguinte circularmente
 (A é substituído por B, … e Z é substituido por A).
Escreva uma segunda função que realize o processo inverso. 
Escreva também a função main para testar o algoritmo implementado.
*/

#include <stdio.h>


void substitui_circulamente(char *s1, char *s2){
    int tamanho_string = 0; 
    while(*s1 != '\0'){
        tamanho_string++;
        s1++;
    }
    printf("%d", tamanho_string);

    s1 = s1[0];
    while((*s1 != '\0'){

    }


}

int main(){

    char s1[] = "BACDEFG";
    char s2[10];

    substitui_circulamente(s1,s2);
    
    return 0; 
}

