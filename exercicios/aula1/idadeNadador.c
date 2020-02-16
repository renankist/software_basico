#include <stdio.h>



char * classificacaoNadador(int idade){

    if(idade >= 5 && idade <= 7){
        return "Infantil A";
    }else if(idade >= 8 && idade <= 11){
        return "Infantil B";
    }else if(idade >=12 && idade <= 13){
        return "Juvenil A";
    }else if(idade >= 14 && idade <=17){
        return "Juvenil B";
    }else if(idade >= 18){
        return "Adulto"; 
    }


    return "Idade não enquadrada em nenhuma categoria";

} 


int main(void){

    int b = 0 ; 

    printf("Nadador: Digite sua idade: ");
    scanf("%d", &b);

    printf("Categoria do nadador: %s", classificacaoNadador(b));
    return 0; 
}

