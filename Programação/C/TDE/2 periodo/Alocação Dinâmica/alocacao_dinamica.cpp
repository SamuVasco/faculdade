#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	//1. Aloque dinamicamente memória para um array de inteiros e peça ao usuário para 
	//preenchê-lo com números. Em seguida, calcule a soma de todos os elementos do 
	//array e exiba o resultado.
	
	
	int tamanho, soma = 0;
	int *array;
	
	printf("Tamanho do array: ");
	scanf("%d", &tamanho);
	
	array = (int *) malloc(tamanho * sizeof(int));

	if(array == NULL){
		printf("\n[ERRO] ALOCAÇÃO FALHOU!");
		return 1;
	}
	
	for(int i = 0; i < tamanho; i++){
		printf("Posição %d recebe o valor: ", i);
		scanf("%d", &array[i]);
		soma += array[i];
	}
	
	for(int i = 0; i < tamanho; i++){
		printf("POSIÇÃO %d | VALOR %d \n", i, array[i]);
	}
	
	printf("\nSoma dos valores: %d", soma);
	
	free(array);
	array = NULL;
	
	
	 	
	
	
	return 0;
}
