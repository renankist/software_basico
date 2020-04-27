/*
03. Implemente um programa para usar e testar as duas funções criadas anteriormente. 
Para isso, neste programa, crie duas variáveis inteiras: x=1 e y=100. Depois imprimir o conteúdo dos 
endereços de end_valor1 e end_valor2 ao final da sua execução.
Depois disso, faça as seguintes operações:
a. Chame a função troca1 passando as variáveis x e y como parâmetros.
b. Imprima na tela os valores de x e de y na função main.
c. Chame a função troca2 passando as variáveis x e y como parâmetros e nesta ordem. 
Note que a função troca2 não recebe inteiros como parâmetros, mas endereços de memória de inteiros.
d. Imprima na tela os valores de x e y na função main.
*/

void troca1(int valor1, int valor2){
    int aux = valor1; 
    valor1 = valor2; 
    valor2 = aux; 
}

void troca2(int *end_valor1, int *end_valor2){

    int aux; 
    aux = *end_valor1;
    *end_valor1 = *end_valor2;
    *end_valor2 = aux; 


}

void main(){
    int x = 1;
    int y = 100;
    int *end_valor1 = &x;
    int *end_valor2 = &y;
    printf("Valor de x = %d e Valor de Y %d \n", *end_valor1, *end_valor2);
    troca1(x,y);
    printf("Valor de x = %d e Valor de Y %d \n", x,y);
    troca2(end_valor1, end_valor2);
    printf("Valor de x = %d e Valor de Y %d \n", x,y);

}