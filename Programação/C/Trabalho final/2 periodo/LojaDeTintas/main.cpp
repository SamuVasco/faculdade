#include <stdio.h>
#include <locale.h>

void CadastrarNovasCompras();

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int opcao; // opção que o usuário digitar
	
	
	printf("===== BEM VINDO A TINTAS STORE =====\n");
	
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
		}
		
	}while(opcao != 0);
	
	
	
	return 0;
}

void CadastrarNovasCompras(){
	int qtde;
	
	printf("\n=============================================================\n");
	printf("\n[1] Para cadastrar novas compras digite a quantidade abaixo\n");
	printf("\nDigite a quantidade de novas compras: ");
	scanf("%d", &qtde);
	printf("\n=============================================================\n");
}
