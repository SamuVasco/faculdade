#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Algumas observacoes
// Usei o while para repetir as perguntas caso o usuario digitasse algo invalido, para que nao precisasse digitar tudo de novo se ocorresse algum erro
// Ao inves de fazer gambiarra retornando um numero inteiro com a funcao VerTodasCompras, pesquisei e descobri exit(0) que encerra o programa com apenas uma linha
// De resto, tentei comentar o codigo ao maximo pra tentar deixar claro
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
	
	int quantidadeCompras = ContarCompras();
	compra *comprasSalvas = NULL;
	FILE *arquivo;
	
	// Confere se ja tem compras salvas
	if(quantidadeCompras > 0){
	
	    // Reserva espaco pra compras que ja estavam no arquivo
	    comprasSalvas = (compra *) malloc(quantidadeCompras * sizeof(compra));
	
	    if(comprasSalvas == NULL){
	        printf("\n[ERRO] Falha na alocacao de memoria!\n");
	        return 1;
	    }
	
	    arquivo = fopen("tintas.txt", "r");
	
	    if(arquivo == NULL){
	        printf("\n[ERRO] Nao foi possivel abrir o arquivo!\n");
	        free(comprasSalvas);
	        return 1;
	    }
	
	    // Coloca as compras no vetor
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
	
	int opcao;
	
	
	printf("===== BEM VINDO A TINTAS STORE =====\n");
	
	// Menu da loja
	
	do {
		printf("\n========================= MENU DE OPCOES ==================================\n");
		printf("[ 1 ] Cadastrar novas compras \n");
		printf("[ 2 ] Ver informacoes de uma compra especifica, baseado no nome do cliente \n");
		printf("[ 3 ] Ver informacoes de todas as compras \n");
		printf("[ 0 ] Encerrar o programa \n");
		printf("Digite a opcao: ");
		scanf("%d", &opcao);	
		
		if(opcao < 0 || opcao > 3){
			printf("\n=============================================================\n");
			printf("\n[ERRO] Opcao invalida. Escolhe entre uma das opcoes do MENU. \n");
			printf("\n=============================================================\n");
		}
		
		if(opcao == 1){
		    CadastrarNovasCompras();
		
		    // Libera o vetor anterior
		    free(comprasSalvas);
		    comprasSalvas = NULL;
		
		    // Confere quantas compras tem
		    quantidadeCompras = ContarCompras();
		
		    if(quantidadeCompras > 0){
		
		        // Reserva espaco pro total atualizado
		        comprasSalvas = (compra *) malloc(quantidadeCompras * sizeof(compra));
		
		        if(comprasSalvas == NULL){
		            printf("\n[ERRO] Falha na alocacao de memoria!\n");
		            return 1;
		        }
		
		        // Abre o arquivo de novo pra atualizar o vetor
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
	
	// Nao deixa cadastrar quantidade zero ou negativa
	while(qtde <= 0){
		printf("\n=============================================================\n");
		printf("\n[ERRO] Digite uma quantidade valida e tente novamente.\n");
		printf("\n=============================================================\n");
		printf("\nDigite a quantidade de novas compras: ");
		scanf("%d", &qtde);
	}
	printf("\n=============================================================\n");
	
	compra *compras;
	
	compras = (compra *) malloc(qtde * sizeof(compra));
	
	if(compras == NULL){
		printf("\n[ERRO] Alocacao de memoria falhou!\n");
		return;
	}
	
	getchar();
	
	for(int i = 0; i < qtde; i++){
		
		printf("\n===== CADASTRAR COMPRA %d =====\n", i+1);
		
		printf("\n--- DADOS DO CLIENTE ---\n");
		
		// Pega o nome do cliente
		printf("Nome: ");
		fgets(compras[i].cliente.nome, sizeof(compras[i].cliente.nome), stdin);
		
		compras[i].cliente.nome[strcspn(compras[i].cliente.nome, "\n")] = '\0';
		
		
		// Se o nome tiver menos de 4 letras, pede de novo
		while(strlen(compras[i].cliente.nome) < 4){
			printf("\n\n[ERRO] O nome do cliente deve possuir PELO MENOS 4 LETRAS! Digite o nome novamente.\n\n");
			
			printf("Nome: ");
			fgets(compras[i].cliente.nome, sizeof(compras[i].cliente.nome), stdin);
			compras[i].cliente.nome[strcspn(compras[i].cliente.nome, "\n")] = '\0';
		}
		
		// Pega o sexo do cliente
		printf("\nDigite o sexo em letra minuscula [m/f/n]: ");
		scanf(" %c", &compras[i].cliente.sexo);
		
		// So aceita m, f ou n
		while(compras[i].cliente.sexo != 'm' && compras[i].cliente.sexo != 'f' && compras[i].cliente.sexo != 'n'){
			printf("\n\n[ERRO] Digite o sexo valido e tente novamente.\n\n");
			
			printf("Digite o sexo em letra minuscula [m/f/n]: ");
			scanf(" %c", &compras[i].cliente.sexo);
		}
		
		// Pega a idade do cliente
		printf("\nDigite a idade: ");
		scanf("%d", &compras[i].cliente.idade);
		
		while(compras[i].cliente.idade <= 0){
			printf("\n\n[ERRO] Digite uma idade valida e tente novamente.\n\n");
			
			printf("Digite a idade: ");
			scanf("%d", &compras[i].cliente.idade);
		}
		
		printf("\n--- DADOS DA COMPRA ---\n\n");
		
		// Pega a quantidade de itens
		printf("Numero de itens: ");
		scanf("%d", &compras[i].itens);
		
		while(compras[i].itens <= 0){
			printf("\n\n[ERRO] Digite uma quantidade de itens valida e tente novamente.\n\n");
			
			printf("Numero de itens: ");
			scanf("%d", &compras[i].itens);
		}
		
		// Pega a franquia da compra
		printf("\nDigite franquia 1,2 ou 3: ");
		scanf("%d", &compras[i].franquia);
		
		while(compras[i].franquia <= 0 || compras[i].franquia > 3){
			printf("\n\n[ERRO] Digite um numero de franquia valida e tente novamente.\n\n");
			printf("\nAs opcoes sao [1], [2] ou [3]\n\n");
			
			printf("Digite franquia 1,2 ou 3: ");
			scanf("%d", &compras[i].franquia);
		}
		
		// Pega o valor final da compra
		printf("Valor da compra: R$");
		scanf("%f", &compras[i].total);
		
		// Deixei 0 pq alguma compra pode ter saido de graca pra algum cliente
		while(compras[i].total < 0){
			printf("\n\n[ERRO] O valor da compra NAO pode ser um valor negativo! Digite um valor valido e tente novamente.\n\n");
			printf("Valor da compra: R$");
			scanf("%f", &compras[i].total);
		}
		
		getchar(); 
		
		printf("\n\n===== DADOS DA COMPRA %d REGISTRADOS COM SUCESSO! =====\n\n", i+1);	
	}
	
	// Depois dos cadastros, salva tudo no tintas.txt
	FILE *arquivo;
	
	arquivo = fopen("tintas.txt", "a");
	
	if(arquivo == NULL){
		printf("\n[ERRO] Nao foi possivel abrir o arquivo!\n");
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
	            printf("\n\n[ERRO] Opcao invalida!\n\n");
	        }

    	}while(escolha < 1 || escolha > 2);

	}while(escolha == 1); // Se escolher 1, cadastra mais compras
}

void PesquisarCompra(){
	
	char nomeCliente[30];
	compra compraLida; // guarda uma compra por vez enquanto le o arquivo
	FILE *arquivo;
	int escolha;
	
	do {
		
		int encontradas = 0; // conta as compras encontradas desse cliente
		float soma = 0; // soma os valores pra calcular a media
	
		getchar();
		
		printf("\n=============================================================\n");
		printf("\n[2] Para ver informacoes de uma compra especifica, digite o nome do cliente\n");
		printf("\nDigite nome do cliente: ");
		fgets(nomeCliente, sizeof(nomeCliente), stdin);
		
		nomeCliente[strcspn(nomeCliente, "\n")] = '\0';
		
		arquivo = fopen("tintas.txt", "r");
		
		if(arquivo == NULL){
			printf("\n[ERRO] Nao foi possivel abrir o arquivo!\n");
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
		
		// Evita fazer a divisao por zero
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
	printf("\n[3] Exibindo informacoes de todas as compras\n");

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
        printf("\n[ERRO] Nao foi possivel abrir o arquivo!\n");
        return;
    }

    printf("\n===== INFORMACOES DE TODAS AS COMPRAS =====\n");

    while(fscanf(arquivo, " %29[^/]/%c/%d/%d/%d/%f",
        compraLida.cliente.nome,
        &compraLida.cliente.sexo,
        &compraLida.cliente.idade,
        &compraLida.itens,
        &compraLida.franquia,
        &compraLida.total) != EOF){

		    // Compras de 70 a 150 reais, incluindo os dois valores
			if(compraLida.total >= 70 && compraLida.total <= 150){
			    compras70a150++;
			}
		
			// Compras que tiveram 2 itens
			if(compraLida.itens == 2){
			    compras2Itens++;
			}
			
			// Compras feitas nas franquias 1 ou 2
			if(compraLida.franquia == 1 || compraLida.franquia == 2){
			    comprasFranquias++;
			}
		
			// Compras feitas por clientes do sexo feminino
			if(compraLida.cliente.sexo == 'f'){
			    compradoresFeminino++;
			}
			
			// Soma as compras de quem tem mais de 50 anos
			if(compraLida.cliente.idade > 50){
			    totalMaiores50 += compraLida.total;
			}
	
			// Soma o valor de todas as compras
			totalCompras += compraLida.total;
			
			// Conta o total de compras
			quantidadeCompras++;
			
			// Guarda o nome mais comprido
			if(strlen(compraLida.cliente.nome) > strlen(nomeMaior)){
			    strcpy(nomeMaior, compraLida.cliente.nome);
			}
	
			// Guarda o nome do cliente mais velho
			if(compraLida.cliente.idade > maiorIdade){
			    maiorIdade = compraLida.cliente.idade;
			    strcpy(nomeMaisVelho, compraLida.cliente.nome);
			}
		}
		
		// Mostra as compras de quem tem o nome mais comprido
		if(quantidadeCompras > 0){

		    printf("\n===== COMPRAS DO CLIENTE COM O MAIOR NOME =====\n");
		    printf("Cliente: %s\n", nomeMaior);
		
		    rewind(arquivo); // Volta pro comeco do arquivo pra ler de novo
		
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
			
			// So faz a media se tiver compras
			if(quantidadeCompras > 0){
			    media = totalCompras / quantidadeCompras;
			
			    printf("Valor medio de uma compra: R$%.2f\n", media);
			}else{
			    printf("Nao existem compras para calcular a media.\n");
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
	    exit(0); // Encerra o programa inteiro, nao so essa funcao
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
