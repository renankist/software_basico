#include <stdio.h>

void show_binary(unsigned int n){
    int shift;
    for(shift = sizeof(int) * 8 - 1; shift >= 0; shift--){
        if (n >> shift & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}


int main (void){
  int numero; 
  printf("Informe um número: ");
  scanf("%d", &numero);
  
  while(numero > 10){
   numero = numero >> 1; 
   show_binary(numero);
  }
	
}