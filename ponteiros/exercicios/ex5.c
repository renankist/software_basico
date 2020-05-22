/*
05. Escreva uma função hm que converta minutos em horas e minutos. 
]A função recebe um inteiro mnts e os endereços de duas variáveis 
inteiras (h e m), e atribui valores a essas variáveis de modo que 
m seja menor que 60 e que 60*h + m seja igual a mnts. 
Escreva também uma função main que use a função hm.
*/

#include <stdio.h>

void hm(int mnts, int *h, int *m){
	*h = mnts / 60;
	*m = mnts % 60;
}

int main(void){
	int total_minutos = 66;
	int horas;
	int minutos;
	hm(total_minutos, &horas, &minutos);
	printf("Horas: %d\n", horas);
	printf("Minutos: %d\n", minutos);
	return 0;
}