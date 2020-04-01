/*
Imprima todas as combinações possíveis com exatamente três dígitos 1, 2 e 3. 
u seja, imprima 111, 123, 223, e assim por diante. Use repetições encaixadas.
*/
#include <stdio.h> 
//#include <string.h>

void main(){
    for(int x = 1; x <= 3; x++){
        for(int y = 1; y <= 3; y++){
            for(int z = 1; z <= 3; z++){
                printf("%d%d%d",x,y,z);
            }
        }

    }

}

