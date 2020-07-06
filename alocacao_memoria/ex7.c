/*07. Implemente a função concat que concatena duas strings recebidos como argumentos. A função deve retornar um ponteiro para o string resultante da concatenação. O espaço para o resultado deve ser alocado dinamicamente pela função.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* concat(char *s1, char *s2){
  int i; 
  int indice_nova_string = 0 ;
  char *retorno = (char *)malloc(sizeof(char));  

  //Prenche string 1
  for(i = 0; s1[i] != '\0'; i++){
    retorno[indice_nova_string] = s1[i];
    retorno = realloc(retorno, indice_nova_string+2 * sizeof(char));
    indice_nova_string++;
  }
  //Prenche string 2
   for(i = 0; s2[i] != '\0'; i++){
    retorno[indice_nova_string] = s2[i];
    retorno = realloc(retorno, indice_nova_string+2 * sizeof(char));
    indice_nova_string++;
  }

  return retorno;



}


int main(void) {

  char string_1[] = "dasdsadsadasd1  ";
  char string_2[] = "Prodasdadsadas323ucao";
  char *s1, *s2, *s3; 
  s1 = string_1;
  s2 = string_2;

  s3 = concat(s1, s2);

  printf("%s", s3);

  free(s3);

  return 0;
}
