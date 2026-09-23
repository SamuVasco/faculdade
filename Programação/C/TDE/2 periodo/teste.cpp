#include <stdio.h>

void multiplicar_escalar(int *v1, int *v2, int x, int n);

int main(void){
    
	int v1[3] = {1,2,3}, v2[3], x = 1, n = 0;
	
	n = sizeof(v1) / sizeof(v1[0]); // numero de elementos dentro do v1
	
	printf("\nDigite o valor do escalar: ");
	scanf("%i", &x);
	
	printf("\nVetor v1: v1[3] = {1,2,3}\n");
	
	printf("\nResultado\n");
	
	multiplicar_escalar(v1, v2, x, n);
	
	for(int i = 0; i < n; i++){
		printf("%i ", *(v2 + i));
	}
	
    return 0;
}

void multiplicar_escalar(int *v1, int *v2, int x, int n){
	
	for(int i = 0; i < n; i++){
		*(v2 + i) = *(v1 + i) * x;
	}
}


