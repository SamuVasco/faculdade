#include <stdio.h> 

int main() {
    
    //1. Faça o cálculo a seguir, considerando a matriz A 2x4. Os valores devem ser perguntados ao usuário: 2 . Matriz A.
    /*
    
    int matrizA[2][4];
    
    printf("\nEscrita da MATRIZ A\n");
	for(int i = 0; i < 2; i++){
    	for(int j = 0; j < 4; j++){
    		printf("Digite o elemento[%i][%i]: ", i, j);
    		scanf("%i", &matrizA[i][j]);
		}
	}
	
	printf("\nMatriz A\n");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			printf("%i ", matrizA[i][j]);
		}
		printf("\n");
	}
	*/
	
	// 2. Faça o cálculo a seguir, considerando as matrizes A e B 3x3. Os valores devem ser perguntados ao usuário: (3 . Matriz A) – Matriz B.
	/*
	
	int matrizA[3][3], matrizB[3][3], resultado[3][3];
	
	printf("\nEscrita da matriz A\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("Digite o elemento[%i][%i]: ", i, j);
			scanf("%i", &matrizA[i][j]);
		}
	}

	printf("\nEscrita da matriz B\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("Digite o elemento[%i][%i]: ", i, j);
			scanf("%i", &matrizB[i][j]);
		}
	}	
	
	printf("\nMatriz A\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%i ", matrizA[i][j]);
		}
		printf("\n");
	}	
	
	printf("\nMatriz B\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%i ", matrizB[i][j]);
		}
		printf("\n");
	}	
	
	// matrizA - matrizB
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			resultado[i][j] = matrizA[i][j] - matrizB[i][j];
		}
	}
	
	printf("\nResultado\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%i ", resultado[i][j]);
		}
		printf("\n");
	}
	*/
	
	// 3. Exiba a matriz original e a matriz transposta de uma matriz 5x2. Os valores devem ser perguntados ao usuário.
	/*
	
	int matrizO[5][2], transposta[2][5];
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 2; j++){
			printf("Digite o elemento[%i][%i]: ", i, j);
			scanf("%i", &matrizO[i][j]);
		}
	}
	
	printf("\nMatriz Original\n");
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 2; j++){
			printf("%i ", matrizO[i][j]);
		}
		printf("\n");
	}
	
	// atribuindo valores a matriz transposta
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 2; j++){
			transposta[j][i] = matrizO[i][j];
		}
	}
	
	printf("\nMatriz Transposta\n");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 5; j++){
			printf("%i ",transposta[i][j]);
		}
		printf("\n");
	}
	*/
	
	// 4. Faça o produto entre duas matrizes, sendo a primeira uma matriz 4x2 e a segunda matriz 2x4. Os valores devem ser perguntados ao usuário. Exiba as 3 matrizes.
	/*
	
	int matrizA[4][2], matrizB[2][4], resultado[4][4];
	
	printf("\nEscrita da Matriz A\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			printf("Digite o elemento[%i][%i]: ", i, j);
			scanf("%i", &matrizA[i][j]);
		}
	}
	
	printf("\nEscrita da matriz B\n");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			printf("Digite o elemento[%i][%i]: ", i, j);
			scanf("%i", &matrizB[i][j]);
		}
	}
	
	printf("\nMATRIZ A\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			printf("%i ", matrizA[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMATRIZ B\n");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			printf("%i ", matrizB[i][j]);
		}
		printf("\n");
	}
	
	// matrizA * matrizB
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			resultado[i][j] = 0; // Para não pegar um numero aleatorio na memoria, antes de atribuir o valor, essa linha vai fazer o elemento ser 0.
			for(int k = 0; k < 2; k++){
				resultado[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
	
	printf("\nResultado\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%i ", resultado[i][j]);
		}
		printf("\n");
	}
	*/
	
	// 5. Exiba todos os valores do triângulo superior de uma matriz 3x3 acima da diagonal principal. 
	// Exiba no formato de matriz e se a posição não estiver no triângulo superior exiba “*” no lugar do número.
	/*
	
	int matriz[3][3];
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("Elemento[%i][%i]: ", i, j);
			scanf("%i", &matriz[i][j]);
		}
	}
	
	printf("\nMATRIZ 3x3\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%i ", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\nTRIANGULO SUPERIOR\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i >= j){ // triangulo inferior ou diagonal principal
				printf("* ");
			}else{
				printf("%i ", matriz[i][j]);	
			}
		}
		printf("\n");
	}
	*/
	
	// 6. Some todos os valores do triângulo inferior da diagonal principal, incluindo a diagonal principal de uma matriz 4x4.
	/*
	
	int matriz[4][4], soma = 0;
	
	printf("\nEscrita da matriz\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("Elemento[%i][%i]: ", i, j);
			scanf("%i", &matriz[i][j]);
		}
	}
	
	printf("\nMATRIZ\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%i ", matriz[i][j]);
		}
		printf("\n");
	}
	
	// Pegando os valores do triangulo inferior da diagonal principal
	
	printf("\nDiagonal principal e triangulo inferior\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i >= j){ // triangulo inferior
				printf("%i ", matriz[i][j]);
			}else{
				printf("* ");
			}
		}
		printf("\n");
	}
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i >= j){ // triangulo inferior
				soma += matriz[i][j];
			}
		}
	}
	
	printf("\nSoma: %i\n", soma);
	*/
	
	// 7. Informe o maior valor acima da diagonal secundária de uma matriz 3x3.
	/*
	
	int matriz[3][3], maior = 0;
	
	printf("\nEscrita da matriz\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("Elemento[%i][%i]: ", i, j);
			scanf("%i", &matriz[i][j]);
		}
	}
	
	printf("\nMATRIZ\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%i ", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\nDiagonal secundaria e triangulo superior\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == 0 && j == 0){
				maior = matriz[i][j];
			}else{
				if(j < (3-i-1)){
				if(matriz[i][j] > maior){
					maior = matriz[i][j];
					}
				}		
			}		
		}
	}
	
	printf("Maior: %i", maior);
	*/
	
	// 8. Informe a média de valores abaixo da diagonal secundária de uma matriz 4x4.
	
	int matriz[4][4], soma = 0, cont = 0;
	float media = 0;
	
	printf("\nEscrita da MATRIZ\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("Elemento[%i][%i]: ", i, j);
			scanf("%i", &matriz[i][j]);
		}
	}
	
	printf("\nMATRIZ\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%i ", matriz[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\nTriangulo inferior da diagonal secundaria\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(j >= 4 - i){
				printf("%i ", matriz[i][j]);
			}else{
				printf("* ");
			}
		}
		printf("\n");
	}
	
	//Pega apenas os valores do Triangulo inferior da diagonal secundaria
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(j >= 4 - i){
				soma += matriz[i][j];
				cont++;
			}
		}
	}
	
	
	media = soma / cont;
	
	printf("\nSoma: %i\nCont: %i\nMedia: %.2f", soma, cont, media);
	    
    return 0;
}

