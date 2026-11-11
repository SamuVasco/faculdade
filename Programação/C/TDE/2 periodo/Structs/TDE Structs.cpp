#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

	// 1. Crie uma estrutura chamada Livro com campos para o título, autor e número de 
	// páginas. Crie uma função que recebe um livro como argumento e imprime todas as 
	// informações do livro.
	
	/*
struct Livro {
	char titulo[30];
	char autor[30];
	int paginas;
};

typedef struct Livro Livro;

void exibirLivro(Livro livro);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Livro livro;
	
	printf("Titulo do livro: ");
	fgets(livro.titulo, sizeof(livro.titulo), stdin);
	
	printf("Nome do autor: ");
	fgets(livro.autor, sizeof(livro.autor), stdin);
	
	printf("Num. de paginas: ");
	scanf("%d", &livro.paginas);
	
	exibirLivro(livro);
	
	return 0;
}

void exibirLivro(Livro livro){
	printf("\nTitulo: %s\n", livro.titulo);
	printf("Autor: %s\n", livro.autor);
	printf("Paginas: %d\n", livro.paginas);	
}
*/

	// 2. Crie uma estrutura chamada Aluno com campos para o nome, número de matrícula e 
	// notas em três disciplinas. Escreva uma função que calcula a média das notas de um 
	// aluno e imprime o resultado. 

/*

struct Aluno {
	char nome[30];
	int matricula;
	float notas[3];
};

typedef struct Aluno Aluno;

void imprimirMedia(Aluno aluno);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Aluno aluno;
	
	printf("\n=== FICHA DO ALUNO ===\n");
	
	printf("Nome: ");
	fgets(aluno.nome, sizeof(aluno.nome), stdin);
	
	aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
	
	printf("Num. da matricula: ");
	scanf("%d", &aluno.matricula);
	
	printf("\n=== NOTAS ===\n");
	
	for(int i = 0; i < 3; i++){
		printf("Nota %d: ", i+1);
		scanf("%f", &aluno.notas[i]);
	}
	
	imprimirMedia(aluno);
	
	return 0;
}

void imprimirMedia(Aluno aluno){
	float media = 0, soma = 0;
	
	for(int i = 0; i < 3; i++){
		soma += aluno.notas[i];
	}
	
	media = soma / 3;
	
	printf("\nA media das notas é: %.2f", media);
}
*/

	// 3. Crie uma estrutura Data com campos para dia, mês e ano. Em seguida, crie uma 
	// estrutura Aluno com campos para nome, número de matrícula e data de nascimento. 
	// Crie uma função que recebe um aluno como argumento e imprime todas as 
	// informações dele, incluindo a data de nascimento. 

/*
struct Data {
	int dia;
	int mes;
	int ano;
};

typedef struct Data Data;

struct Aluno {
	char nome[30];
	int matricula;
	Data dataNasc;
};

typedef struct Aluno Aluno;

void imprimirAluno(Aluno aluno);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Aluno aluno;
	
	printf("\n=== Ficha ALUNO ===\n");
	
	printf("Nome: ");
	fgets(aluno.nome, sizeof(aluno.nome), stdin);
	
	aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
	
	printf("Num. da matricula: ");
	scanf("%d", &aluno.matricula);
	
	printf("\n=== DATA DE NASCIMENTO ===\n");
	
	printf("Dia: ");
	scanf("%d", &aluno.dataNasc.dia);
	
	printf("Mes: ");
	scanf("%d", &aluno.dataNasc.mes);
	
	printf("Ano: ");
	scanf("%d", &aluno.dataNasc.ano);
	
	imprimirAluno(aluno);
	
	return 0;
}

void imprimirAluno(Aluno aluno){
	
	printf("\n=== INFOS DO ALUNO ===\n");
	printf("Nome: %s\n", aluno.nome);
	printf("Num. da matricula: %d\n", aluno.matricula);
	printf("Data de nascimento: %d/%d/%d", aluno.dataNasc.dia, aluno.dataNasc.mes, aluno.dataNasc.ano);	
}
*/

	// 4. Crie uma estrutura Tempo com campos para hora, minuto e segundo. Em seguida, 
	// crie uma estrutura DataHora que inclui uma estrutura Data com campos para dia, 
	// mês e ano e uma estrutura Tempo. Aninhe essas estruturas para representar uma data 
	// e hora completa. Crie funções para imprimir a data e a hora separadamente. 

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Tempo {
	int hora;
	int minuto;
	int segundo;
};

typedef struct Tempo Tempo;

struct Data {
	int dia;
	int mes;
	int ano;
};

typedef struct Data Data;

struct DataHora{
	Tempo tempo;
	Data data;
};

typedef struct DataHora dth;

void imprimirData(dth dh);
void imprimirHora(dth dh);

int main(){
	setlocale(LC_ALL, "Portuguese");

	dth dh;
	
	printf("\n=== Struct TEMPO ===\n");
	
	printf("Hora(s): ");
	scanf("%d", &dh.tempo.hora);
	
	printf("Minuto(s): ");
	scanf("%d", &dh.tempo.minuto);
	
	printf("Segundo(s): ");
	scanf("%d", &dh.tempo.segundo);
	
	printf("\n=== Struct DATA ===\n");
	
	printf("Dia: ");
	scanf("%d", &dh.data.dia);
	
	printf("Mes: ");
	scanf("%d", &dh.data.mes);
	
	printf("Ano: ");
	scanf("%d", &dh.data.ano);
	
	imprimirData(dh);
	imprimirHora(dh);
	
	return 0;
}
void imprimirData(dth dh){
	printf("\nData completa: %d/%d/%d", dh.data.dia, dh.data.mes, dh.data.ano);
}

void imprimirHora(dth dh){
	printf("\nHora completa: %d:%d:%d", dh.tempo.hora, dh.tempo.minuto, dh.tempo.segundo);
}
*/

	// 5. Crie uma estrutura chamada ContaBancaria com campos para o número da conta, o 
	// nome do titular e o saldo. Escreva funções para depositar dinheiro na conta, sacar 
	// dinheiro da conta e imprimir o saldo atual. 
	
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct ContaBancaria {
	int numConta;
	char nome[30];
	float saldo;
};

typedef struct ContaBancaria ContaBancaria;

void depositar(ContaBancaria *cb);
void sacar(ContaBancaria *cb);
void mostrarSaldo(ContaBancaria *cb);

int main(){
	setlocale(LC_ALL, "Portuguese");

	ContaBancaria cb;
	int opc = 5;

	printf("\n=== DADOS ===\n");
	
	printf("Num. da conta: ");
	scanf("%d", &cb.numConta);
	
	getchar();
	
	printf("Nome: ");
	fgets(cb.nome, sizeof(cb.nome), stdin);
	
	cb.nome[strcspn(cb.nome, "\n")] = '\0';
	
	printf("Saldo: R$");
	scanf("%f", &cb.saldo);
	
	do {
		printf("\n\n=== MENU ===\n");
		printf("\n[1] Depositar dinheiro\n");
		printf("[2] Sacar dinheiro\n");
		printf("[3] Imprimir saldo atual\n");
		printf("[0] Sair\n");
		printf(">>>Opcao: ");
		scanf("%d", &opc);
		
		if(opc < 0 || opc > 3){
			printf("\n[ERRO] opcao invalida!\n");
		}else{
			if(opc == 1){
				depositar(&cb);
			}else if(opc == 2){
				sacar(&cb);
			}else if(opc == 3){
				mostrarSaldo(&cb);
			}
		}
	}while(opc != 0);
	
	return 0;
}

void depositar(ContaBancaria *cb){
	
	float qtde = 0;
	
	printf("\n=== 1 Depositar ===\n");
	printf("Quantia para deposito: R$");
	scanf("%f", &qtde);
	
	if(qtde > 0){
		cb->saldo += qtde;
	}else{
		printf("\n[ERRO] Valor invalido!\n");
	}
}

void sacar(ContaBancaria *cb){
	
	float qtde = 0;
	
	printf("\n=== 2 Sacar ===\n");
	printf("Quantia para saque: R$");
	scanf("%f", &qtde);
	
	if(qtde > 0 && qtde <= cb->saldo){
		cb->saldo -= qtde;
	}else {
		printf("\n[ERRO] Valor invalido ou saldo insuficiente!\n");
	}	
}

void mostrarSaldo(ContaBancaria *cb){
	
	printf("\n=== 3 Saldo Atual ===\n");
	printf("Seu saldo atual: R$%.2f\n", cb->saldo);
}
*/

	// 6. Crie uma estrutura chamada Carro com campos para a marca, o modelo e o ano de 
	// fabricação. Declare um array de 3 carros e preencha-o com informações de 
	// diferentes carros. Em seguida, escreva um programa que percorra o array e imprima 
	// as informações de cada carro. 
	
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Carro {
	char marca[20];
	char modelo[20];
	int ano;
};

typedef struct Carro Carro;

void mostrarCarros(Carro *carros);

int main(){
	setlocale(LC_ALL, "Portuguese");

	Carro carros[3];
	
	for(int i = 0; i < 3; i++){
		printf("\n=== Carro %d ===\n", i+1);
		
		printf("Marca: ");
		fgets(carros[i].marca, sizeof(carros[i].marca), stdin);
		
		carros[i].marca[strcspn(carros[i].marca, "\n")] = '\0';
	
		printf("Modelo: ");
		fgets(carros[i].modelo, sizeof(carros[i].modelo), stdin);
		
		carros[i].modelo[strcspn(carros[i].modelo, "\n")] = '\0';
		
		printf("Ano de fabricacao: ");
		scanf("%d", &carros[i].ano);
		
		getchar();	
	}
	
	mostrarCarros(carros);
	
	return 0;
}

void mostrarCarros(Carro *carros){
	
	printf("\n\n=== INFOS CARROS ===\n");
	for(int i = 0; i < 3; i++){
		printf("\n=== CARRO %d ===\n", i+1);
		
		printf("Marca: %s\n", carros[i].marca);
		printf("Modelo: %s\n", carros[i].modelo);
		printf("Ano de Fabricacao: %d\n", carros[i].ano);
	}
	printf("\nFIM\n");
}
*/

	// 7. Faça um programa em C para manipular registros de produtos, conforme a estrutura 
	// a seguir. 
	//
	// struct produto{  
	// 		int codigo; 
	// 		char descricao[30]; 
	//		float preco; 
	// }; 
	//
	// O programa deve: 
	// a) Declarar um vetor que armazene os 10 diferentes produtos com o layout da estrutura; 
	// b) Cadastrar os produtos e exibir todos os produtos. 
	// c) Usuário informará um percentual de aumento de preços. Reajuste o preço de cada 
	// produto e exiba a estrutura após o reajuste.

/*
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
*/
