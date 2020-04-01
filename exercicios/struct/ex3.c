/*
03. Crie uma struct chamada dma que represente uma data. Escreva uma função que receba duas structs do 
tipo dma, cada uma representando uma data válida, e devolva o número de dias que decorreram
 entre as duas datas.
*/
#include <stdio.h>
#include <string.h>


struct dma{
    int dia;
    int ano; 
    int mes; 
}; 


void main(){

    int meses[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    struct dma data1;  

    data1.ano = 2018;
    data1.mes = 1;
    data1.dia = 5; 

    struct dma data2;  

    data2.ano = 2019;
    data2.mes = 3;
    data2.dia = 31; 

    //Pegar dados data1
    //Verificar a quantidade de dias até o ano anterior ao indicado na data
    int dias_data_um = data1.ano  * 365;
    //Verificar a quantidade de dias até o mes anterior ao indicado na data
    for(int x = 0; x < data1.mes; x++){
        dias_data_um = dias_data_um + meses[x];
    } 
    dias_data_um = dias_data_um + data1.dia;

//Pegar dados data2
    //Verificar a quantidade de dias até o ano anterior ao indicado na data
    int dias_data_dois = data2.ano  * 365;
    //Verificar a quantidade de dias até o mes anterior ao indicado na data
    for(int x = 0; x < data2.mes; x++){
        dias_data_dois = dias_data_dois + meses[x];
    } 
    dias_data_dois = dias_data_dois + data2.dia;

    int diferenca_dias =dias_data_um - dias_data_dois; 


//Transformar valor negativo em positivo (caso haja necessidade)
    if(diferenca_dias < 0){
        diferenca_dias = diferenca_dias * -1;
    }

    printf("Diferença de dias é igual a: %d ", diferenca_dias);

}