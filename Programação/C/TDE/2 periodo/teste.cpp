#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct produto{  
	int codigo; 
	char descricao[30]; 
	float preco; 
}; 

typedef struct produto produto;

int main(){
	setlocale(LC_ALL, "Portuguese");

	// a) Declarar um vetor que armazene os 10 diferentes produtos com o layout da estrutura;
	produto prod[10];
	int opc = 3;
	float aumento = 1;
	
	// b) Cadastrar os produtos e exibir todos os produtos.
	for(int i = 0; i < 10; i++){
		printf("\n=== PRODUTO %d ===\n", i+1);
		
		printf("Codigo: ");
		scanf("%d", &prod[i].codigo);
		
		getchar();
		
		printf("Descricao: ");
		fgets(prod[i].descricao, sizeof(prod[i].descricao), stdin);
		
		prod[i].descricao[strcspn(prod[i].descricao, "\n")] = '\0';
		
		printf("Preco: R$");
		scanf("%f", &prod[i].preco);
		
	}
	
	printf("\n=== Produtos cadastrados. ===\n");
	
	do {
		printf("\n\n=== MENU ===\n\n");
		
		printf("[1] Exibir todos os produtos\n");
		printf("[2] Percentual de aumento de precos\n");
		printf("[0] Sair\n\n");
		printf(">>>Opcao: ");
		scanf("%d", &opc);
		
		if(opc < 0 || opc > 2){
			printf("\n[ERRO] Opcao invalida!\n");
		}else{
			if(opc == 1){
				printf("\n\n=== 1. PRODUTOS CADASTRADOS ===\n\n");
				
				for(int i = 0; i < 10; i++){
	
					printf("\n=== Produto %d ===\n", i+1);
					
					printf("Codigo: %d\n", prod[i].codigo);
					printf("Descricao: %s\n", prod[i].descricao);
					printf("Preco: %.2f\n", prod[i].preco);
				}
			}else if(opc == 2){
				// c) Usuário informará um percentual de aumento de preços. Reajuste o preço de cada 
				// produto e exiba a estrutura após o reajuste.
				printf("\n\n=== 2. Percentual de aumento de precos ===\n\n");
				
				printf("Informe o percentual de aumento: ");
				scanf("%f", &aumento);
				
				for(int i = 0; i < 10; i++){
					prod[i].preco += prod[i].preco * aumento / 100;
				}
				
				printf("\n=== PRODUTOS DEPOIS DO AJUSTE ===\n");
				
				for(int i = 0; i < 10; i++){
	
					printf("\n=== Produto %d ===\n", i+1);
					
					printf("Codigo: %d\n", prod[i].codigo);
					printf("Descricao: %s\n", prod[i].descricao);
					printf("Preco: %.2f\n", prod[i].preco);
				}
			}
		}
	}while(opc != 0);
	
	printf("\nFIM\n");

	return 0;
}


