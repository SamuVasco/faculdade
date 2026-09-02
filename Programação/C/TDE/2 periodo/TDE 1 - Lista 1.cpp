#include <stdio.h> 

float somar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);

int main() {
	
	// 9 . 9. Faça uma calculadora que realize operações com 2 números fornecidos pelo
   //usuário. Após obter os números, pergunte ao usuário qual a operação que ele deseja
  //fazer. Crie uma função para cada tipo de operação. Mostre o resultado ao usuário.
  
	float a, b, resultado;
	int opc = 1;
  
	printf("Digite A: ");
	scanf("%f", &a);
  
	printf("Digite B: ");
	scanf("%f", &b);
	
	do {
		printf("\n1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n5 - Novos valores\n0 - Sair\n");
		printf("Opcao: ");
		scanf("%i", &opc);
		
		switch(opc){
			case 1:
				resultado = somar(a,b);
				printf("\n%.1f + %.1f = %.1f\n", a,b,resultado);
				break;
			case 2:
				resultado = subtrair(a,b);
				printf("\n%.1f - %.1f = %.1f\n", a,b,resultado);
				break;
			case 3:
				resultado = multiplicar(a,b);
				printf("\n%.1f x %.1f = %.1f\n", a,b,resultado);
				break;
			case 4:
				resultado = dividir(a,b);
				printf("\n%.1f / %.1f = %.1f\n", a,b,resultado);
				break;
			case 5:
				printf("\nNovo valor de A: ");
				scanf("%f", &a);
				
				printf("\nNovo valor de B: ");
				scanf("%f", &b);
				break;
			case 0:
				printf("\nPROGRAMA ENCERRADO\n");
				break;
			default:
				printf("\nENTRADA INVALIDA\n");
		}
	}while(opc != 0);
	
  
  
	    
    return 0;
}

float somar(float a, float b){
	return a + b;
}

float subtrair(float a, float b){
	return a - b;
}

float multiplicar(float a, float b){
	return a * b;
}

float dividir(float a, float b){
	return a / b;
}
