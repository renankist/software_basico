/*
05. Uma empresa comercial possui um programa para controle das receitas e despesas em seus 10 projetos. 
Os projetos são numerados de 0 até 9. Faça um programa C que controle a entrada e saída de recursos dos projetos.
 O programa deverá ler um conjunto de informações contendo: Número do projeto, valor, tipo despesa ("R" - Receita e "D" - Despesa).
  O programa termina quando o valor do código do projeto for igual a -1. 
  Sabe-se que Receita deve ser somada ao saldo do projeto e despesa subtraída do saldo do projeto. Ao final do programa, 
  imprirmir o saldo final de cada projeto. Dica: Usar uma estrutura do tipo vetor para controlar os saldos dos projetos.
 Usar o conceito de struct para agrupar as informações lidas.
*/
#include <stdio.h>

struct Lancamento{
    int projeto;
    double valor;
    char tipo;  
}; 

void main(){
    double projetos[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    int controle = 0; 
    struct Lancamento l; 
    while(controle != -1){
        printf("A qual projeto este lançamento pertence? (Digite o código)");
        scanf("%d", &l.projeto);
        
        if(l.projeto == -1){
            controle = -1;
        }else{
            
            printf("Qual é o tipo do lançamento? E (Entrada) ou S (Saída)");
            scanf("\n%c", &l.tipo);
           
            printf("Qual é o valor do lançamento?");
            scanf("%lf", &l.valor);
             
            if(l.tipo == 'E'){
                projetos[l.projeto] =  projetos[l.projeto] + l.valor; 
             }else{
                projetos[l.projeto] =  projetos[l.projeto] - l.valor; 
            }
        }
    }

    for(int i =0; i<= 10; i++){
        printf("Saldo projeto %d é: %lf ",i,projetos[i]);
    }
}