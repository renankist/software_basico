#include <stdio.h>

// String para Int 

// int x = atoi(argv[1]);
// int x = atoi(argv[2]);


int main(int argc, char *argv[]){

	int i;

	for(int i = 0; i < argc; i++){
		printf("%d Parametro: %s\n",i,argv[i]);
	}

	return 0;

}