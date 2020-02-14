#include <stdio.h>

int main(void)
{
    int a, b;
    
    a = 25;
    b = 30;
    
    if ((a > 20) && (b >= 30))
    {
        printf("ok, são maiores\n");
    }
    else
    {
        printf("não são maiores\n");
    }

	return 0;
}
