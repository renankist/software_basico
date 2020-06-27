/*
Escreva um programa que solicita ao usuário a quantidade de alunos de uma turma e aloca um 
vetor de notas (números reais). 
Depois de ler as notas, imprime a média aritmética. 
Ao final, liberar a área de memória alocada.
*/
#include <stdio.h>
#include <stdlib.h>


int main(){

    int qtd_aluno = 0;
    double *p, media; 

   printf("Informe a quantidade de alunos na turma: ");
   scanf("%d", &qtd_aluno);
   
    
    p =  (double *) malloc(qtd_aluno * (double) sizeof(double));

    //pega as notas
    for(int i = 0; i < qtd_aluno; i++){
           printf("Informe a nota do aluno %d: ", i+1);
           scanf("%lf", &p[i]);
           media = media + p[i];
    }

    printf("A média da turma é: %lf", media/qtd_aluno);

    free(p);

    return 0; 
}
