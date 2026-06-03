#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	/* 1. Faça um programa que leia 10 números e os coloque em um vetor.Ao final,
	apresente na tela os valores armazenados nas posições pares
	*/
	
	/*
	printf("\n=========================================\n");
	int v1[9], n1;
	
	printf("Digite 10 valores INTEIROS\n");
	for(int i = 0; i < 10; i++){
		printf("Digite o %i° valor: ", i+1);
		scanf("%i", &v1[i]);
	}
	
	for(int i = 0; i < 5; i++){
		printf("\nValor: %i | Posição: %i\n", v1[i], i);
	}
	*/
	
	/* 2. Desenvolva um programa que inicialize um vetor de 15 elementos com os valores
	   3,6,9,12...45 e ao final, imprime o vetor no formato de uma tabela índice / valor.
	*/
	
	/*
	printf("\n=========================================\n");
	
	int v2[15] = {3,6,9,12,15,18,21,24,27,30,33,36,39,42,45};
	
	printf("\n");
	printf("\nVetor que inicializa com 15 elementos...\n");
	printf("\n-------------------------\n");
	for(int i = 0; i < 15; i++){
		printf("Índice: %i  /  Valor:  %i\n", i, v2[i]);
		printf("-------------------------\n");
	}
	*/
	
	/* 3. Leia um vetor de 20 posições.
	
	   a) Permite que o usuário consulte o valor armazenado a partir de um índice;
	   
	   b) Permita que o usuário consulte pelo índice quantos valores precisar. Para a
	   consulta apenas quando um valor de índice inválido for fornecido(menor que 0 e
	   >=20).
	   
	   c) Leia um número n do usuário e o busque no vetor. Ao final, diga se ele existe ou
	   não existe no vetor.
	   
	*/
	
	int v3[20], op, valor3 = 0;
	
	for(int i = 0; i < 20; i++){
		printf("Digite o %i° valor: ", i+1);
		scanf("%i", &v3[i]);
	}
	
	do {
		printf("[ 1 ] Consulte o valor a partir de um índice\n");
		printf("[ 2 ] Digite o índice para saber o valor \n");
		printf("[ 0 ] Sair\n");
		printf("Digite a opção: ");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				printf("\n");
				printf("\nDigite o valor: ");
				scanf("%i", &valor3);
				printf("\n");
				for(int i = 0; i < 20; i++){
					if(valor3 == v3[i]){
						printf("Valor: %i | Índice: %i\n", v3[i], i);
					}
				}
				printf("\nFim da consulta.\n");
				printf("\n");
				break;
				
			case 2:
				while(1){
					printf("\n");
					printf("Digite o índice [maior ou igual a 20 ou menor que 0 para SAIR]: ");
					scanf("%i", &valor3);
					if(valor3 < 0 || valor3 >= 20){
						break;
					}else{
						printf("\n");
						printf("Índice: %i | Valor: %i\n", valor3, v3[valor3]);
						printf("\n");
					}
				}
				break;

			case 0:
				break;
			break;
			
			default:
				printf("\nOpção inválida\n");
				break;
		}
	}while(op != 0);
		
	return 0;
}
