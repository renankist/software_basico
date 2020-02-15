#include <stdio.h>

double converter(double f){
    return (f-32.0)*(5.0/9.0); 
}


int main(void)
{
    
     double a; 

	 printf("Digite uma temperatura em Fahrenheit: ");
     
     scanf("%lf", &a);


     printf("temperatura em GRAU CELCIUS = %lf", converter(a));

    
}

