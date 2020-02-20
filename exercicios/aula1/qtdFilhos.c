#include <stdio.h>

int main(void){
	
	int a = 0; 
        int b = 0;
        int c = 0;
        int d = 0;	
	int contador = 1;
	
	while(contador <= 8){
	   int e; 
        		
	   printf("Quantos filhos você tem? ");
           scanf("%d", &e);
	
	   if(e >= 1 && e <= 3){
	      a++;
              printf("1 a 3 filhos: %d \n",a); 
	
           }else if(e >= 4 && e <= 7){
              b++;
           }else if(e >= 8){
              c++;
           }else{
              d++; 			
           }


	   contador++;
		
	}

	printf("1 a 3 filhos: %d \n 3 a 7 filhos: %d \n mais de 8 filhos: %d \n nenhum filho: %d \n",a,b,c,d); 
	//printf("1 a 3 filhos: %d \n",a); 
	
	return 0;

}



