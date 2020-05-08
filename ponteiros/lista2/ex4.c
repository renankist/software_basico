/*
Reescreva o programa abaixo usando ponteiros:
int main (){
    float matrx [50][50];
    int i, j;
    for (i = 0; i < 50; i++){
        for (j = 0; j < 50; j++){
            matrx[i][j] = 0.0;
        }
    }
    return(0);
}
*/

int main()
{
    float matrx[50][50];
    float *p = matrx[0];
    int i;
    for (i = 0; i < 2500; i++)
    {
        *p = 0.0;
         p++;
    }
    return (0);
}