#include <stdio.h>

void trocaValores(int a, int b){

    int c = a; 

    a = b; 
    b = c;

    printf("Valor A = %d e Valor de B = %d",a,b); 

}



int main(void){

    int a,b; 

    printf("Número A: ");
     scanf("%d", &a);

     printf("Número B: ");
     scanf("%d", &b);

    trocaValores(a,b);

    return 0; 

}

