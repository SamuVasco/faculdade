#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	//1. Aloque dinamicamente memória para um array de inteiros e peça ao usuário para 
	//preenchê-lo com números. Em seguida, calcule a soma de todos os elementos do 
	//array e exiba o resultado.
	
	/*
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
	*/
	
	//2. Peça ao usuário para inserir o tamanho de um array de inteiros e aloque 
	//dinamicamente memória para o array. Em seguida, peça ao usuário para preencher o 
	//array com números. Depois disso, crie uma cópia do array em outra região de 
	//memória e exiba a cópia.
	
	/*
	int n = 1 ;
	int *array, *copia;
	
	printf("Insira o tamanho do array: ");
	scanf("%d", &n);
	
	array = (int *) malloc(n * sizeof(int));
	copia = (int *) malloc(n * sizeof(int));
	
	if(array == NULL || copia == NULL){
		printf("\n[ERRO] ALOCAÇÃO FALHOU!");
		free(array);
		free(copia);
		return 1;
	}
	
	printf("\nPreencha o array\n\n");
	
	for(int i = 0; i < n; i++){
		printf("Posição %d recebe o valor: ",  i);
		scanf("%d", &array[i]);
		copia[i] = array[i];
	}
	
	printf("\nARRAY de endereço: %d\n", array);
	for(int i = 0; i < n; i++){
		printf("\nPosição %d | valor %d ", i, array[i]);
	}
	
	printf("\n\nCOPIA de endereço: %d\n", copia);
	for(int i = 0; i < n; i++){
		printf("\nPosição %d | valor %d ", i, copia[i]);
	}
	
	free(array);
	array = NULL;
	
	free(copia);
	copia = NULL;
	*/
	
	//3. Aloque dinamicamente memória para um array de inteiros e peça ao usuário para 
	//preenchê-lo com números. Em seguida, permita que o usuário escolha um elemento
	//para remover do array. Reduza o tamanho do array e reorganize os elementos, se 
	//necessário, para manter a ordem. 
	
	/*
	int n, x, contador = 0; // contador -> se o contador for igual a 0 então o valor não foi encontrado para ser removido no array
	int *array;
	
	printf("Tamanho do array: ");
	scanf("%d", &n);
	
	array = (int *) malloc(n * sizeof(int));
	
	if(array == NULL){
		printf("\n[ERRO] Alocação falhou!");
		return 1;
	}
	
	printf("\nPreencha o array\n\n");
	
	for(int i = 0; i < n; i++){
		printf("Posição %d recebe o valor: ", i);
		scanf("%d", &array[i]);
	}
	
	printf("\n\nARRAY\n");
	for(int i = 0; i < n; i++){
		printf("\nPosição %d | valor %d ", i, array[i]);
	}
	
	printf("\nEscolha um elemento para remover do array: ");
	scanf("%d", &x);
		
	for(int i = 0; i < n; i++){
        if(x == array[i]){
        	
        	contador++; // se o contador for igual a 0, então o valor não foi encontrado para ser removido no array

            // desloca os elementos para a esquerda (elemento da posição anterior recebe valor da posição seguinte)
            for(int j = i; j < n - 1; j++){
                array[j] = array[j + 1];
            }

            n--; // atualiza o tamanho do array para usar corretamente no realloc

            if(n > 0){
                int *temp = (int *) realloc(array, n * sizeof(int));

                if(temp != NULL){
                    array = temp;
                }else{
                	printf("\n[ERRO] realloc falhou!");
				}
            } else {
                free(array);
                array = NULL;
            }

            break; // se o elemento for achado e removido, encerra o laço for
        }
    }
    
    if(contador == 0){
    	printf("\nVALOR NÃO ENCONTRADO!\n");
	}

    printf("\n\nARRAY ATUALIZADO\n");

    for(int i = 0; i < n; i++){
        printf("\nPosição %d | valor %d ", i, array[i]);
    }

    free(array);
    array = NULL;
	*/

	// 4. Aloque dinamicamente memória para uma matriz bidimensional. Peça ao usuário 
	// para inserir os valores da matriz e, em seguida, peça ao usuário para inserir um 
	// escalar. Multiplique todos os elementos da matriz pelo escalar e exiba a matriz 
	// resultante.	
	
	/*
	int linhas, colunas, escalar;

    printf("Qtde de linhas: ");
    scanf("%d", &linhas);

    printf("Qtde de colunas: ");
    scanf("%d", &colunas);

    int **matriz = (int **) malloc(linhas * sizeof(int *));

	// Aloca memoria para as colunas de cada linha
    for (int i = 0; i < linhas; i++) { 
        matriz[i] = (int *) malloc(colunas * sizeof(int));
    }

    printf("\n=== PREENCHER MATRIZ ===\n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nDigite o Escalar: ");
    scanf("%d", &escalar);

    // Multiplica os elementos pelo escalar
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] *= escalar;
        }
    }

    printf("\n=== MATRIZ RESULTANTE ===\n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }

    free(matriz);
    */
    
    // 5. Crie uma estrutura Funcionario com campos para nome e salário. Crie um programa 
	// que permita ao usuário digitar o número de funcionários e, em seguida, aloque 
	// dinamicamente um array de Funcionarios. Permita que o usuário insira o nome e o 
	// salário de cada funcionário e, em seguida, calcule e imprima o salário médio dos 
	// funcionários. 
	
	/*
	struct Funcionario {
		char nome[30];
		float salario;
	};

	typedef struct Funcionario Funcionario;
	
	int main(void) {
		setlocale(LC_ALL, "Portuguese");
	
	    Funcionario *funcionarios;
	    int qtde = 0;
	    float soma = 0, media = 0;
	    
	    printf("Digite a qtde. de funcionários: ");
	    scanf("%d", &qtde);
	    
	    getchar(); // Para limpar o buffer antes de ler com fgets
	    
	    funcionarios = (Funcionario *) malloc(qtde * sizeof(Funcionario));
	    
	    if(funcionarios == NULL){
	    	printf("\n[ERRO] ALOCAÇÃO FALHOU!");
			return 1;
		}
		
		for(int i = 0; i < qtde; i++){
			printf("\n=== Funcionário %d ===\n", i+1);
			printf("Nome: ");
			fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
			
		
			
			printf("Salário em R$: ");
			scanf("%f", &funcionarios[i].salario);
			getchar(); // limpar o buffer antes fazer outro loop
			soma += funcionarios[i].salario;	
		}
		
		media = soma / qtde;
		
		printf("\nA média dos salários é R$ %.2f\n", media);
		
		free(funcionarios);
		funcionarios = NULL;
	*/
	
	// 6. Crie uma estrutura Cliente com campos para nome e idade. Crie um programa que 
	// permita ao usuário digitar o número de clientes e, em seguida, aloque 
	// dinamicamente um array de Clientes. Permita que o usuário insira o nome e a idade 
	// de cada cliente e, em seguida, identifique e imprima o cliente mais velho. 
	
	/*
	struct Cliente {
		char nome[30];
		int idade;
	};

	typedef struct Cliente Cliente;

	int main(void) {
		setlocale(LC_ALL, "Portuguese");
		
		Cliente *clientes;
		int qtde, indiceVelho = 0;
		
		printf("Qtde. de Clientes: ");
		scanf("%d", &qtde);
		
		getchar();
		
		clientes = (Cliente *) malloc(qtde * sizeof(Cliente));
		
		if(clientes == NULL){
			printf("\n[ERRO] ALOCAÇÃO FALHOU!");
			return 1;
		}
		
		for(int i = 0; i < qtde; i++){
			printf("\n=== Cliente %d ===\n", i+1);
			
			printf("Nome: ");
			fgets(clientes[i].nome, sizeof(clientes[i].nome), stdin);
			
			clientes[i].nome[strcspn(clientes[i].nome, "\n")] = '\0';
			
			printf("Idade: ");
			scanf("%d", &clientes[i].idade);
			
			if(i == 0 || clientes[i].idade > clientes[indiceVelho].idade){
				indiceVelho = i;
			}
			
			getchar();
		}
		
		printf("\n=== CLIENTE MAIS VELHO\n");
		printf("Nome: %s\n", clientes[indiceVelho].nome);
		printf("Idade: %d\n", clientes[indiceVelho].idade);
	
	    free(clientes);
	    clientes = NULL;
	*/
	
	// 7. Crie uma estrutura Produto com campos para nome, preço e quantidade em estoque. 
	// Crie um programa que permita ao usuário digitar o número de produtos e, em 
	// seguida, aloque dinamicamente um array de Produtos. Permita que o usuário insira o 
	// nome, o preço e a quantidade em estoque de cada produto e, em seguida, calcule e 
	// imprima o valor total em estoque.
	
	/*
	struct Produto {
		char nome[30];
		float preco;
		int qtdeEstoque;
	};
	
	typedef struct Produto Produto;
	
	int main(void) {
		setlocale(LC_ALL, "Portuguese");
		
		Produto *produtos;
		int qtde = 0;
		float totalValorEstoque = 0;
		
		printf("Núm. de produtos: ");
		scanf("%d", &qtde);
		
		getchar();
		
		produtos = (Produto *) malloc(qtde * sizeof(Produto));
		
		if(produtos == NULL){
			printf("\n[ERRO] ALOCAÇÃO FALHOU!");
			return 1;
		}
		
		for(int i = 0; i < qtde; i++){
			printf("\n=== PRODUTO %d ===\n", i+1);
			printf("Nome: ");
			fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
			
			produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
			
			printf("Preço R$");
			scanf("%f", &produtos[i].preco);
			
			printf("Qtde em Estoque: ");
			scanf("%d", &produtos[i].qtdeEstoque);
			
			totalValorEstoque += produtos[i].preco * produtos[i].qtdeEstoque;
			
			getchar();
		}
		
		printf("\nValor total em estoque: R$ %.2f\n", totalValorEstoque);
		
		free(produtos);
		produtos = NULL;
	*/
	
	// 8. Foi feita uma pesquisa visando identificar as características físicas da população de 
	// uma região, coletando-se os seguintes dados dos seus habitantes: 
	// sexo (M ou F); 
	// cor dos olhos (azul, verde, castanho); 
	// cor dos cabelos (loiro, castanho, preto, ruivo); 
	// idade. 
	// Utilizando alocação dinâmica de um vetor desta estrutura, faça um programa que 
	// leia estes dados de um conjunto desconhecido de habitantes, calcule e imprima: 
	// a) homem mais novo; 
	// b) número de pessoas entrevistadas; 
	// c) idade média das mulheres; 
	// d) percentagem de habitantes de cabelos louros e olhos azuis.
	
	
	struct Pessoa {
		char sexo;
		char corOlhos;
		char corCabelos;
		int idade;
	};

	typedef struct Pessoa Pessoa;

	int main(void) {
		setlocale(LC_ALL, "Portuguese");
		
		Pessoa *pessoas;
		int qtde = 0, indiceIdadeNovo = -1, qtdeMulheres = 0;
		float contadorLouroAzul = 0, somaIdade = 0, mediaMulheres = 0;
		
		printf("Qtde de pessoas: ");
		scanf("%d", &qtde);
		
		getchar();
	
		pessoas = (Pessoa *) malloc(qtde * sizeof(Pessoa));
		
		if(pessoas == NULL){
			printf("\n[ERRO] ALOCAÇÃO FALHOU!");
			return 1;
		}
		
		for(int i = 0; i < qtde; i++){
			printf("\n=== PESSOA %d ===\n", i+1);
			
			printf("Sexo [m/f]: ");
			scanf(" %c", &pessoas[i].sexo);
			
			printf("Cor dos Olhos [A]zul, [V]erde, [C]astanho: ");
			scanf(" %c", &pessoas[i].corOlhos);
			
			printf("Cor dos cabelos [L]oiro, [C]astanho, [P]reto, [R]uivo: ");
			scanf(" %c", &pessoas[i].corCabelos);
			
			if(pessoas[i].corOlhos == 'a' && pessoas[i].corCabelos == 'l'){
				contadorLouroAzul++;
			}
			
			printf("Idade: ");
			scanf("%d", &pessoas[i].idade);
			printf("\n===========================================================================\n");
			
			if(pessoas[i].sexo == 'm'){
				if(indiceIdadeNovo == -1 || pessoas[i].idade < pessoas[indiceIdadeNovo].idade){
					indiceIdadeNovo = i;
				}
			}
			
			if(pessoas[i].sexo == 'f'){
				qtdeMulheres++;
				somaIdade += pessoas[i].idade;
			}
		}
		
		//homem mais novo
		if(indiceIdadeNovo == -1){
			printf("\na) Nenhum homem cadastrado.\n");
		}else {
			printf("\na) O homem mais novo tem %d anos\n", pessoas[indiceIdadeNovo].idade);
		}
		
		// número de pessoas entrevistadas
		printf("\nb) Número de pessoas entrevistadas: %d\n", qtde);
		
		// idade média das mulheres
		if(qtdeMulheres == 0){
			printf("\nc) Nenhuma mulher cadastrada.\n");
		}else{
			mediaMulheres = somaIdade / qtdeMulheres;
			printf("\nc) Idade média das mulheres: %.1f\n", mediaMulheres);
		}
		
		// percentagem de habitantes de cabelos louros e olhos azuis
		if(contadorLouroAzul == 0){
			printf("\nd) Percentagem de habitantes de cabelos louros e olhos azuis: 0%%\n");
		}else {
			contadorLouroAzul = (contadorLouroAzul / qtde) * 100;
			printf("\nd) Percentagem de habitantes de cabelos louros e olhos azuis: %.1f%%", contadorLouroAzul);
		}
		
		printf("\n===========================================================================\n");
	
		free(pessoas);
		pessoas = NULL;
	
	return 0;
}
