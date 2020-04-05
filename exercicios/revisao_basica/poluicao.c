#include <stdio.h>


void indice (double i){

    if(i == 0.3){
        printf("Você está dentro do primeiro grupo de poluição: %lf ",i);
    }else if(i == 0.4){
         printf("Você está dentro do primeiro e segundo grupo de poluição: %lf ",i);
    }else if(i==0.5){
        printf("Você está dentro do primeiro,segundo e terceiro grupo de poluição: %lf ",i);
    }

}



int main(void){

    double b = 0.0; 

    printf("Digite o índice de poluição: ");
    scanf("%lf", &b);

    indice(b);

    return 0; 
}