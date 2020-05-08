/*03. Escreva  um  programa  que  contenha  duas  variáveis  inteiras.  
Em seguida, compare seus endereços e exiba o conteúdo da variável 
que possui o maior endereço.*/

void main(){

    int x; 
    int z;  
    int *a, *b; 
    a = &x;
    b = &z;

     printf("%p  %p\n", a,b); 


    if(a > b){
        printf("%p", a); 
    }else{
        printf("%p", b); 
    }


    return 0; 



}