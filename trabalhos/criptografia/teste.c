#include <stdio.h>

int conta_char(char str[])
{
    int i = 0;
    do
    {
        ++i;
    } while (str[i] != 0);
    return i;
}


void main(int args, char *argv[]){
    printf("Total de argumentos: %d\n", conta_char("adminsd"));
}  

