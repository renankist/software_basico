/*
04. Escreva uma função que receba um número inteiro que representa um intervalo de tempo medido em minutos 
e devolva uma struct contendo o número equivalente de horas e minutos 
(por exemplo, 131 minutos equivalem a 2 horas e 11 minutos).
*/
#include <stdio.h>

struct Hora{
    int hora;
    int minutos; 
}; 

struct Hora transformarEmHorasEminutos(int minutos){
        struct Hora h; 
        h.hora = minutos / 60; 
        h.minutos = minutos - ((minutos / 60) * 60);
        return h; 
}

void main(){
    struct Hora hora = transformarEmHorasEminutos(131);
    printf("%d hora(s) e %d minuto(s).",hora.hora, hora.minutos);
}