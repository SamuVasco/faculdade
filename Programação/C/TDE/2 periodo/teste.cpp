#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char* preencherAlfabeto(int tam);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int tam = 10;
	char *vetor;
	
	vetor = preencherAlfabeto(tam);
	
	for(int i = 0; i < tam; i++){
		printf(" %c", vetor[i]);
	}
	
	free(vetor);
	vetor = NULL;
	
	return 0;
}

char* preencherAlfabeto(int tam){
	
	char *vetor = (char *) malloc(tam * sizeof(char));
	
	if(vetor == NULL){
		printf("\n[ERRO] malloc falhou\n");
		exit(1);
	}
	
	for(int i = 0; i < tam; i++){
		vetor[i] = 'a' + i;
	}
	
	return vetor;
}





