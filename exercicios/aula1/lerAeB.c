#include <stdio.h>

int adicionar(int a , int b){
    return a + b; 
}

int subtrair(int a , int b){
    return a - b; 
}

int multiplicar(int a , int b){
    return a * b; 
}

int main(void)
{
   
	int a, b; 

	 printf("Digite um numero inteiro: ");
     scanf("%d", &a);

     printf("Digite outro numero inteiro: ");
     scanf("%d", &b);
     
     printf("O soma dos valores é:%d\n",adicionar(a,b));    

     printf("O subtração dos valores é:%d\n",subtrair(a,b));  

     printf("O multiplicação dos valores é:%d\n",multiplicar(a,b));  
    
}

