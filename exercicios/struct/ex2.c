/*
Defina uma estrutura que irá representar bandas de música. Essa estrutura deve ter o nome da banda, que tipo de música ela toca, 
o número de integrantes e em que posição do ranking essa banda está dentre as suas 5 bandas favoritas. 
Crie um looping para preencher um vetor com 5 estruturas de bandas. 
Após criar e preencher, exiba todas as informações das bandas/registros.
*/
#include <stdio.h>
#include <string.h>

//Estrutra das bandas

struct Banda{
    char nome[20]; 
    char tipo_musica[20]; 
    int ranking; 
};

void main(){

    struct Banda bandas_favoritas[5];  
    
    int posicao = 0; 

    for(int x = 0; x < 5; x++){
        printf("Digite o nome da banda %d: ",x+1);
        fgets( bandas_favoritas[x].nome,20,stdin);
        printf("Digite o tipo de música da banda %d: ",x+1);
        fgets( bandas_favoritas[x].tipo_musica,20,stdin);
        printf("Em qual posição de 1 a 5 que essa banda está? ");
        scanf("%d", &posicao);
        bandas_favoritas[x].ranking = posicao;      
    }

      for(int x = 0; x < 5; x++){
        printf("Banda %d: Nome: %s | Tipo: %s | Ranking %d \n",x+1,bandas_favoritas[x].nome,bandas_favoritas[x].tipo_musica, bandas_favoritas[x].ranking );
      }

}