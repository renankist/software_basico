/*02. Implementar uma função de nome troca2 que tem como parâmetros duas variáveis capazes de 
armazenar endereços de memória de inteiros (que tipo de variável é capaz de fazer isso?), 
end_valor1 e end_valor2. Essa função deve trocar o conteúdo dos endereços armazenados nessas 
variáveis, ou seja, o conteúdo armazenado pelo primeiro parâmetro deve ser armazenado no endereço 
do segundo parâmetro e vice-versa. Assim como na função anterior, essa função deve imprimir o valor
 das duas variáveis no final da função.
*/

void troca2(int *end_valor1, int *end_valor2){

    int aux = *end_valor1;
    *end_valor1 = *end_valor2;
    *end_valor2 = aux; 

    printf("Valor1 %d  Valor2 %d\n",*end_valor1,*end_valor2);

}

void main(){
    int valor1 = 10; 
    int valor2 = 11; 
    int *end_valor1 = &valor1; 
    int *end_valor2 = &valor2;

    troca2(end_valor1, end_valor2);

}