/*Seja o trecho de código abaixo, que valor de c s
 erá impresso no comando printf? Tente obter o resultado sem escrever e executar 
 o código.
int a = 5, b = 12, c;//
int *p;
int *q;
p = &a;
q = &b;
c = *p + *q;
printf("c = %d", c);*/

int main()
{

    int a = 5, b = 12, c; // a = 5; b = 12; c = ?
    int *p; // a = 5; b = 12; c = ?
    int *q; // a = 5; b = 12; c = ?
    p = &a; // a = 5; b = 12; c = ?
    q = &b; // a = 5; b = 12; c = ?
    c = *p + *q; // a = 5; b = 12; c = 17
    printf("c = %d", c);

    return 0;
}