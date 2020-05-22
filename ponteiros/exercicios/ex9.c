/*
09. Escreva uma função que determine a média e a situação de um aluno em uma disciplina.
 A função recebe como parâmetros as três notas de um aluno (p1, p2, e p3), 
 seu número de faltas (faltas), o número total de aulas da disciplina (aulas)
  e o ponteiro para uma variável (media), conforme o seguinte protótipo: 
char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media);
*/

#include <stdio.h>

char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media)
{
    *media = (p1 + p2 + p3) / 3.0;
    char situacao = 'A';
    if (*media < 6)
    {
        situacao = 'R';
    }

    if ((faltas * 100) / aulas > 25)
    {
        situacao = 'F';
    }
    return situacao;
}

int main()
{
    float p1, p2, p3, media;
    int aulas, faltas;
    ;
    p1 = 0.0;
    p2 = 0.0;
    p3 = 0.0;
    media = 0;

    printf("Digite o valor da nota 1: ");
    scanf("%f", &p1);

    printf("Digite o valor da nota 2: ");
    scanf("%f", &p2);

    printf("Digite o valor da nota 3: ");
    scanf("%f", &p3);

    printf("Digite o número de aulas: ");
    scanf("%d", &aulas);

    printf("Digite o número de faltas: ");
    scanf("%d", &faltas);

    char situacao_aluno = situacao(p1, p2, p3, faltas, aulas, &media);

    printf("Média de notas do aluno na disciplina: %.1f \n", media);

    if(situacao_aluno == 'R'){
        printf("Aluno reprovado por não alcançar a média da discplina.\n");
    }
    if(situacao_aluno == 'F'){
        printf("Aluno reprovado por faltas.\n");
    }

    if(situacao_aluno == 'A'){
        printf("Aluno aprovado.\n");
    }

    return 0;
}