#include <stdio.h>

int main(void){
	
	int valor = 0; 
        int qtd = 0;	
	int parar = 1; 
	int media = 0; 

	while(parar != 0){
	   int e; 
        		
	   printf("Digite um número ou zero para sair");
           scanf("%d", &e);
		
	   if(e == 0){
		parar = 0; 
	   }else{
		qtd++; 
                valor = valor + e; 
	   }
		
			
	}
	
	if(valor > 0){
		media = valor / qtd;
	}
	printf("Média: %d \n",media); 
	
	
	return 0;

}



