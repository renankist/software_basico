/*
08. Crie um programa para calcular a área e o perímetro de um hexágono. 
O seu programa deve implementar uma função chamada calcula_hexagono que 
calcule a área e o perímetro de um hexágono regular de lado L. A função 
deve obedecer o seguinte protótipo: 
void calcula_hexagono(float l, float *area, float *perimetro);
*/

#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
    *area = (3* pow(l,2) * sqrt(3)) / 2;
    *perimetro = 6 *l;
}


int main(){
    float l, area, perimetro; 

    l = 10; 

    calcula_hexagono(l, &area, &perimetro);

    printf("Área igual: %.2f  Perímetro igual: %.2f ",area, perimetro);

    return 0; 
}