#include <stdio.h>

double media(double t1, double t2, double t3){
    return (t1 + t2 + t3 ) / 3; 
}

int main(void)
{
    printf("A média final do aluno é: %lf", media(8,8,8));
}

