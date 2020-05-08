/*
01. Seja o trecho de código abaixo, quais serão os valores de x, y e *p no comando printf? 
Tente obter o resultado sem escrever e executar o código.
int x, y, *p; 
y = 0; 
p = &y;
x = *p;
x = 4;
(*p)++;
--x;
(*p) += x;
printf("x=%d  y=%d *p=%d", x, y, *p);

*/
void main()
{
    int x, y, *p; // x = 0; y = 0; *p = null?; 
    y = 0; // y = 0
    p = &y; // p = 0
    x = *p; // x = 0
    x = 4; // x = 4
    (*p)++; // p = 1; y = 1  
    --x; // x = 3
    (*p) += x; // p = 4; y = 4 
    printf("x=%d  y=%d *p=%d", x, y, *p);
}
