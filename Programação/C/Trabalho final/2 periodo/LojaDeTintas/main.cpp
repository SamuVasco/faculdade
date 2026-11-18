#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

struct Cliente{
	char nome[30];
	char sexo;
	int idade;	
};

typedef struct Cliente cliente;

struct Compra {
	cliente cliente;
	int itens;
	int franquia;
	float total;
};

typedef struct Compra compra;


void CadastrarNovasCompras();
void PesquisarCompra();
void VerTodasCompras();
int ContarCompras();

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int quantidadeCompras = ContarCompras();
	compra *comprasSalvas = NULL;
	FILE *arquivo;
	
	// Verifica se existem compras salvas
	if(quantidadeCompras > 0){
	
	    // Aloca memoria para as compras existentes
	    comprasSalvas = (compra *) malloc(quantidadeCompras * sizeof(compra));
	
	    if(comprasSalvas == NULL){
	        printf("\n[ERRO] Falha na alocacao de memoria!\n");
	        return 1;
	    }
	
	    // Abre o arquivo para leitura
	    arquivo = fopen("tintas.txt", "r");
	
	    if(arquivo == NULL){
	        printf("\n[ERRO] Nao foi possivel abrir o arquivo!\n");
	        free(comprasSalvas);
	        return 1;
	    }
	
	    // Carrega as compras para o vetor
	    for(int i = 0; i < quantidadeCompras; i++){
	
	        fscanf(arquivo, " %29[^/]/%c/%d/%d/%d/%f",
	            comprasSalvas[i].cliente.nome,
	            &comprasSalvas[i].cliente.sexo,
	            &comprasSalvas[i].cliente.idade,
	            &comprasSalvas[i].itens,
	            &comprasSalvas[i].franquia,
	            &comprasSalvas[i].total);
	    }
	
	    fclose(arquivo);
	    printf("\nCompras carregadas: %d\n", quantidadeCompras);

		for(int i = 0; i < quantidadeCompras; i++){
		    printf("Cliente: %s\n", comprasSalvas[i].cliente.nome);
		}
	}
	
	int opcao; // opção que o usuário digitar
	
	
	printf("===== BEM VINDO A TINTAS STORE =====\n");
	
	// Menu principal
	
	do {
		printf("\n========================= MENU DE OPÇÕES ==================================\n");
		printf("[ 1 ] Cadastrar novas compras \n");
		printf("[ 2 ] Ver informações de uma compra específica, baseado no nome do cliente \n");
		printf("[ 3 ] Ver informações de todas as compras \n");
		printf("[ 0 ] Encerrar o programa \n");
		printf("Digite a opção: ");
		scanf("%d", &opcao);	
		
		if(opcao < 0 || opcao > 3){
			printf("\n=============================================================\n");
			printf("\n[ERRO] Opção inválida. Escolhe entre uma das opções do MENU. \n");
			printf("\n=============================================================\n");
		}
		
		if(opcao == 1){
		    CadastrarNovasCompras();
		
		    // Libera o vetor antigo
		    free(comprasSalvas);
		    comprasSalvas = NULL;
		
		    // Conta novamente as compras do arquivo
		    quantidadeCompras = ContarCompras();
		
		    if(quantidadeCompras > 0){
		
		        // Aloca memoria para a nova quantidade
		        comprasSalvas = (compra *) malloc(quantidadeCompras * sizeof(compra));
		
		        if(comprasSalvas == NULL){
		            printf("\n[ERRO] Falha na alocacao de memoria!\n");
		            return 1;
		        }
		
		        // Abre o arquivo para atualizar o vetor
		        arquivo = fopen("tintas.txt", "r");
		
		        if(arquivo == NULL){
		            printf("\n[ERRO] Nao foi possivel abrir o arquivo!\n");
		            free(comprasSalvas);
		            return 1;
		        }
		
		        for(int i = 0; i < quantidadeCompras; i++){
		            fscanf(arquivo, " %29[^/]/%c/%d/%d/%d/%f",
		                comprasSalvas[i].cliente.nome,
		                &comprasSalvas[i].cliente.sexo,
		                &comprasSalvas[i].cliente.idade,
		                &comprasSalvas[i].itens,
		                &comprasSalvas[i].franquia,
		                &comprasSalvas[i].total);
		        }
		
		        fclose(arquivo);
		    }
		}else if(opcao == 2){
			PesquisarCompra();
		}else if(opcao == 3){
			VerTodasCompras();
		}
		
	}while(opcao != 0);
	
	free(comprasSalvas);

	return 0;
}

void CadastrarNovasCompras(){
	
	int qtde;
	int escolha;
	
	do {
	
	printf("\n=============================================================\n");
	printf("\n[1] Para cadastrar novas compras digite a quantidade abaixo\n");
	printf("\nDigite a quantidade de novas compras: ");
	scanf("%d", &qtde);
	
	// Impedir o cadastro de valores negativos e informar este erro. 
	while(qtde <= 0){
		printf("\n=============================================================\n");
		printf("\n[ERRO] Digite uma quantidade válida e tente novamente.\n");
		printf("\n=============================================================\n");
		printf("\nDigite a quantidade de novas compras: ");
		scanf("%d", &qtde);
	}
	printf("\n=============================================================\n");
	
	compra *compras;
	
	compras = (compra *) malloc(qtde * sizeof(compra));
	
	if(compras == NULL){
		printf("\n[ERRO] Alocação de memória falhou!\n");
		return;
	}
	
	getchar();
	
	for(int i = 0; i < qtde; i++){
		
		printf("\n===== CADASTRAR COMPRA %d =====\n", i+1);
		
		printf("\n--- DADOS DO CLIENTE ---\n");
		
		// Lê o nome do cliente
		printf("Nome: ");
		fgets(compras[i].cliente.nome, sizeof(compras[i].cliente.nome), stdin);
		
		compras[i].cliente.nome[strcspn(compras[i].cliente.nome, "\n")] = '\0';
		
		
		// Impedir o cadastro se o nome do cliente possuir menos de 4 letras e informar este erro.
		while(strlen(compras[i].cliente.nome) < 4){
			printf("\n\n[ERRO] O nome do cliente deve possuir PELO MENOS 4 LETRAS! Digite o nome novamente.\n\n");
			
			printf("Nome: ");
			fgets(compras[i].cliente.nome, sizeof(compras[i].cliente.nome), stdin);
			compras[i].cliente.nome[strcspn(compras[i].cliente.nome, "\n")] = '\0';
		}
		
		// Lê o sexo do cliente
		printf("\nDigite o sexo em letra minúscula [m/f/n]: ");
		scanf(" %c", &compras[i].cliente.sexo);
		
		// Impedir o cadastro quando o sexo do cliente for inválido (diferente de m, f ou n) e informar este erro. 
		while(compras[i].cliente.sexo != 'm' && compras[i].cliente.sexo != 'f' && compras[i].cliente.sexo != 'n'){
			printf("\n\n[ERRO] Digite o sexo válido e tente novamente.\n\n");
			
			printf("Digite o sexo em letra minúscula [m/f/n]: ");
			scanf(" %c", &compras[i].cliente.sexo);
		}
		
		// Lê a idade do cliente
		printf("\nDigite a idade: ");
		scanf("%d", &compras[i].cliente.idade);
		
		while(compras[i].cliente.idade <= 0){
			printf("\n\n[ERRO] Digite uma idade válida e tente novamente.\n\n");
			
			printf("Digite a idade: ");
			scanf("%d", &compras[i].cliente.idade);
		}
		
		printf("\n--- DADOS DA COMPRA ---\n\n");
		
		// Lê o número de itens da compra
		printf("Número de itens: ");
		scanf("%d", &compras[i].itens);
		
		while(compras[i].itens <= 0){
			printf("\n\n[ERRO] Digite uma quantidade de itens válida e tente novamente.\n\n");
			
			printf("Número de itens: ");
			scanf("%d", &compras[i].itens);
		}
		
		// Lê a franquia
		printf("\nDigite franquia 1,2 ou 3: ");
		scanf("%d", &compras[i].franquia);
		
		while(compras[i].franquia <= 0 || compras[i].franquia > 3){
			printf("\n\n[ERRO] Digite um número de franquia válida e tente novamente.\n\n");
			printf("\nAs opções são [1], [2] ou [3]\n\n");
			
			printf("Digite franquia 1,2 ou 3: ");
			scanf("%d", &compras[i].franquia);
		}
		
		// Lê o valor total da compra
		printf("Valor da compra: R$");
		scanf("%f", &compras[i].total);
		
		// Deixei 0 pq pode ser que alguma compra saia de graça pra algum cliente
		while(compras[i].total < 0){
			printf("\n\n[ERRO] O valor da compra NÃO pode ser um valor negativo! Digite um valor válido e tente novamente.\n\n");
			printf("Valor da compra: R$");
			scanf("%f", &compras[i].total);
		}
		
		getchar(); 
		
		printf("\n\n===== DADOS DA COMPRA %d REGISTRADOS COM SUCESSO! =====\n\n", i+1);	
	}
	
	// Após o término de todo o cadastro salve as informações em um bloco de notas nomeado de “tintas.txt”.
	FILE *arquivo;
	
	arquivo = fopen("tintas.txt", "a");
	
	if(arquivo == NULL){
		printf("\n[ERRO] Não foi possível abrir o arquivo!\n");
		free(compras);
		return;
	}
	
	for(int i = 0; i < qtde; i++){
    	fprintf(arquivo, "%s/%c/%d/%d/%d/%.2f\n",
	        compras[i].cliente.nome,
	        compras[i].cliente.sexo,
	        compras[i].cliente.idade,
	        compras[i].itens,
	        compras[i].franquia,
	        compras[i].total);
	}
	
	fclose(arquivo);

	printf("\nCompras salvas no arquivo tintas.txt com sucesso!\n");
	
	free(compras);
	
	do {
	        printf("\n[ 1 ] Cadastrar mais compras\n");
	        printf("[ 2 ] Voltar ao menu principal\n");
	        printf("Digite sua escolha: ");
	        scanf("%d", &escolha);
	
	        if(escolha < 1 || escolha > 2){
	            printf("\n\n[ERRO] Opção invalida!\n\n");
	        }

    	}while(escolha < 1 || escolha > 2);

	}while(escolha == 1); // Repete TODO o cadastro se escolher 1
}

void PesquisarCompra(){
	
	char nomeCliente[30];
	compra compraLida; // armazena os dados de uma compra lida do arquivo
	FILE *arquivo;
	int escolha;
	
	do {
		
		int encontradas = 0; // conta quantas compras pertence ao cliente pesquisado
		float soma = 0; // acumula os valores das compras pra calcular a média
	
		getchar();
		
		printf("\n=============================================================\n");
		printf("\n[2] Para ver informações de uma compra específica, digite o nome do cliente\n");
		printf("\nDigite nome do cliente: ");
		fgets(nomeCliente, sizeof(nomeCliente), stdin);
		
		nomeCliente[strcspn(nomeCliente, "\n")] = '\0';
		
		arquivo = fopen("tintas.txt", "r");
		
		if(arquivo == NULL){
			printf("\n[ERRO] Não foi possível abrir o arquivo!\n");
			return;
		}else{
			printf("\n\n===== COMPRAS FEITAS PELO(A) CLIENTE: %s ===== \n", nomeCliente);
		}
		
		while(fscanf(arquivo, " %29[^/]/%c/%d/%d/%d/%f",
		    compraLida.cliente.nome,
		    &compraLida.cliente.sexo,
		    &compraLida.cliente.idade,
		    &compraLida.itens,
		    &compraLida.franquia,
		    &compraLida.total) != EOF){
	
	    	if(strcmp(nomeCliente, compraLida.cliente.nome) == 0){
	
	        	printf("\nValor da compra: R$%.2f\n", compraLida.total);
	        	printf("Franquia: %d\n", compraLida.franquia);
	        	printf("Numero de itens: %d\n", compraLida.itens);
	
	        		encontradas++;
	        		soma += compraLida.total;
	    		}
			}
		
		fclose(arquivo);
		
		// Para não dividir por 0
		if(encontradas > 0){
	    	float media = soma / encontradas;
	
	    	printf("\nMedia das compras: R$%.2f\n", media);
		}else{
	    	printf("\n[ERRO] Nenhuma compra encontrada para o cliente %s.\n", nomeCliente);
		}
		
		printf("\n=============================================================\n");
		
		do {
			printf("\n[ 1 ] Pesquisar novamente\n");
		    printf("[ 2 ] Voltar ao menu principal\n");
		    printf("Digite sua escolha: ");
		    scanf("%d", &escolha);
		
		    if(escolha < 1 || escolha > 2){
		        printf("\n[ERRO] Opcao invalida!\n");
		    }
		
		}while(escolha < 1 || escolha > 2);

	}while(escolha == 1);
}

void VerTodasCompras(){
	
	printf("\n=============================================================\n");
	printf("\n[3] Exibindo informações de todas as compras\n");

    FILE *arquivo;
    compra compraLida;
    int compras70a150 = 0;
	int compras2Itens = 0;
	int comprasFranquias = 0;
	int compradoresFeminino = 0;
	float totalMaiores50 = 0;
	float totalCompras = 0;
	int quantidadeCompras = 0;
	float media = 0;
	char nomeMaior[30] = "";
	char nomeMaisVelho[30] = "";
	int maiorIdade = -1;
	int escolha;

    arquivo = fopen("tintas.txt", "r");

    if(arquivo == NULL){
        printf("\n[ERRO] Não foi possível abrir o arquivo!\n");
        return;
    }

    printf("\n===== INFORMAÇÕES DE TODAS AS COMPRAS =====\n");

    while(fscanf(arquivo, " %29[^/]/%c/%d/%d/%d/%f",
        compraLida.cliente.nome,
        &compraLida.cliente.sexo,
        &compraLida.cliente.idade,
        &compraLida.itens,
        &compraLida.franquia,
        &compraLida.total) != EOF){

		    // Conta compras entre R$70 e R$150 (inclusive)
			if(compraLida.total >= 70 && compraLida.total <= 150){
			    compras70a150++;
			}
		
			// Conta compras com exatamente 2 itens
			if(compraLida.itens == 2){
			    compras2Itens++;
			}
			
			// Conta as compras realizadas nas franquias 1 ou 2
			if(compraLida.franquia == 1 || compraLida.franquia == 2){
			    comprasFranquias++;
			}
		
			// Conta os registros de compras de clientes do sexo feminino
			if(compraLida.cliente.sexo == 'f'){
			    compradoresFeminino++;
			}
			
			// Soma as compras realizadas por clientes com mais de 50 anos
			if(compraLida.cliente.idade > 50){
			    totalMaiores50 += compraLida.total;
			}
	
			// Soma o valor de todas as compras
			totalCompras += compraLida.total;
			
			// Conta a quantidade total de compras
			quantidadeCompras++;
			
			// Identifica o cliente com o maior nome
			if(strlen(compraLida.cliente.nome) > strlen(nomeMaior)){
			    strcpy(nomeMaior, compraLida.cliente.nome);
			}
	
			// Identifica o cliente mais velho
			if(compraLida.cliente.idade > maiorIdade){
			    maiorIdade = compraLida.cliente.idade;
			    strcpy(nomeMaisVelho, compraLida.cliente.nome);
			}
		}
		
		// Exibir os dados da compra do desgraçado com o maior nome
		if(quantidadeCompras > 0){

		    printf("\n===== COMPRAS DO CLIENTE COM O MAIOR NOME =====\n");
		    printf("Cliente: %s\n", nomeMaior);
		
		    rewind(arquivo); // Isso aqui volta pro inicio do arquivo
		
		    while(fscanf(arquivo, " %29[^/]/%c/%d/%d/%d/%f",
		        compraLida.cliente.nome,
		        &compraLida.cliente.sexo,
		        &compraLida.cliente.idade,
		        &compraLida.itens,
		        &compraLida.franquia,
		        &compraLida.total) != EOF){
		
		        if(strcmp(compraLida.cliente.nome, nomeMaior) == 0){
		
		            printf("\nNome: %s\n", compraLida.cliente.nome);
		            printf("Sexo: %c\n", compraLida.cliente.sexo);
		            printf("Idade: %d\n", compraLida.cliente.idade);
		            printf("Numero de itens: %d\n", compraLida.itens);
		            printf("Franquia: %d\n", compraLida.franquia);
		            printf("Valor: R$%.2f\n", compraLida.total);
		        }
		    }
		    
			    printf("\n===== COMPRAS DO CLIENTE MAIS VELHO =====\n");
				printf("Cliente: %s\n", nomeMaisVelho);
				
				rewind(arquivo);
				
				while(fscanf(arquivo, " %29[^/]/%c/%d/%d/%d/%f",
				    compraLida.cliente.nome,
				    &compraLida.cliente.sexo,
				    &compraLida.cliente.idade,
				    &compraLida.itens,
				    &compraLida.franquia,
				    &compraLida.total) != EOF){
				
				    if(strcmp(compraLida.cliente.nome, nomeMaisVelho) == 0){
				
				        printf("\nNome: %s\n", compraLida.cliente.nome);
				        printf("Sexo: %c\n", compraLida.cliente.sexo);
				        printf("Idade: %d\n", compraLida.cliente.idade);
				        printf("Numero de itens: %d\n", compraLida.itens);
				        printf("Franquia: %d\n", compraLida.franquia);
				        printf("Valor: R$%.2f\n", compraLida.total);
				    }
				}
			}
		
		    fclose(arquivo);
		    printf("\n=============================================================\n");
		    printf("\nQuantidade de compras entre R$70 e R$150: %d\n", compras70a150);
			printf("Quantidade de compras com exatamente 2 itens: %d\n", compras2Itens);
			printf("Quantidade de compras nas franquias 1 ou 2: %d\n", comprasFranquias);
			printf("Quantidade de compradores do sexo feminino: %d\n", compradoresFeminino);
			printf("\nValor total comprado por clientes com mais de 50 anos: R$%.2f\n", totalMaiores50);
			printf("Valor total de todas as compras: R$%.2f\n", totalCompras);
			
			// Calcula a média somente se existirem compras
			if(quantidadeCompras > 0){
			    media = totalCompras / quantidadeCompras;
			
			    printf("Valor medio de uma compra: R$%.2f\n", media);
			}else{
			    printf("Não existem compras para calcular a média.\n");
			}
	
	do {
	    printf("\n=============================================================\n");
	    printf("\n[ 1 ] Voltar ao menu principal\n");
	    printf("[ 2 ] Encerrar o programa\n");
	    printf("Digite sua escolha: ");
	    scanf("%d", &escolha);
	
	    if(escolha < 1 || escolha > 2){
	        printf("\n[ERRO] Opcao invalida!\n");
	    }
	
	}while(escolha < 1 || escolha > 2);

	if(escolha == 2){
	    printf("\nEncerrando o programa...\n");
	    exit(0); // Ja que a função não retorna nada, pesquisei e descobri a função exit(0) da biblioteca stdlib que encerra o programa
	}
}

int ContarCompras(){
    FILE *arquivo;
    char linha[150];
    int quantidade = 0;

    arquivo = fopen("tintas.txt", "r");

    if(arquivo == NULL){
        return 0;
    }

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        quantidade++;
    }

    fclose(arquivo);

    return quantidade;
}
