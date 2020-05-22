 
/*
01. Implementar uma função de nome troca1 que tem como parâmetros dois inteiros, 
valor1 e valor2, e não retorna nada. Essa função deve trocar os valores de valor1 e valor2 e 
imprimir os seus valores trocados. Exemplo: se a função receber como parâmetros valor1=32 e 
valor2=99, então a função deve imprimir a mensagem fim da função: 
valor1=99 e valor2=32 ao final da sua execução (ainda dentro da função).
*/

void troca1(int valor1, int valor2){
    int aux = valor1; 
    valor1 = valor2; 
    valor2 = aux; 
    printf("Valor1: %d  Valor2: %d\n",valor1,valor2);
}

void main(){
    int valor1 = 8;
    int valor2 = 10;
    printf("Valor1: %d  Valor2: %d\n",valor1,valor2);
    troca1(valor1,valor2);
}