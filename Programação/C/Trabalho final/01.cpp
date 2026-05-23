#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int opcao;
	
	do{
		printf("\n1 - Cadastrar notas\n");
		printf("2 - Mostrar Média\n");
		printf("3 - Mostrar maior nota\n");
		printf("4 - Mostrar menor nota\n");
		printf("5 - Listar notas\n");
		printf("0 - Sair\n");
		
		printf("Opção: ");
		scanf("%i", &opcao);
		
		if(opcao < 0 || opcao > 5){
			printf("\n================\n");
			printf("\nOPÇÃO INVÁLIDA\n");
			printf("\n================\n");
		}
		
	}while(1);
	
	
	
	return 0;
}
