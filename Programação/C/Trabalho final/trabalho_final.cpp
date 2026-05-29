#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int op;           // Opção que o usuário vai digitar
	int n = 25;      // Tive que colocar um valor aqui inicialmente, pois acontece um bug de memória, coloquei no comentário na entrega do trabalho no classroom
	float notas[n]; // Vetor com tamanho que ainda vai ser definido pelo usuário
	float soma = 0;
	float media = 0;
	float maior, menor;
	int cont_notas = 0, y, x = 0, aprovados = 0, reprovados = 0;
	
	do{
		printf("\n1 - Cadastrar notas\n");
		printf("2 - Mostrar soma e média\n");
		printf("3 - Mostrar maior e menor nota\n");
		printf("4 - Listar notas\n");
		printf("5 - Buscar nota\n");
		printf("6 - Contador de aprovados/reprovados\n");
		printf("0 - Sair\n");
		printf("Digite a opção: ");
		scanf("%i", &op);
		
		if(op == 0){ // Se digitar 0 o programa encerra
			break;
		}
		
		switch(op){
			case 1:
				soma = 0; // Resetar as variáveis quando for ler outros valores pra não correr o risco de dar erro
				media = 0;
				maior = 0;
				menor = 0;
				x = 0;
				aprovados = 0;
				reprovados = 0;
				cont_notas = 0;
				
				
				printf("\n---------------------------------------------------------");
				printf("\n=========================================================\n");
				printf("Digite quantas notas você quer cadastrar: ");
				scanf("%i", &n);
				printf("=========================================================\n");
				
				for(int i = 0; i < n; i++){
					printf("Digite a %i° nota: ", i+1);
					scanf("%f", &notas[i]);
				}
				printf("==========================================================\n");
				printf("\nNotas cadastradas\n");
				for(int i = 0; i < n; i++){
					printf("%i°  nota  ->  [ %.2f ]\n", i+1,notas[i]);
				}
				printf("\n=========================================================\n");
				printf("----------------------------------------------------------\n");
				break;
				
			case 2:
				printf("\n---------------------------------------------------------");
				printf("\n=========================================================\n");
				for(int i = 0; i < n; i++){
					soma += notas[i];
				}
				media = soma / n;
				
				printf("\nA soma das notas vale: %.2f\n", soma);
				printf("\nA média vale: %.2f\n", media);
				
				printf("\n=========================================================\n");
				printf("----------------------------------------------------------\n");
				break;
				
			case 3:
				maior = notas[0];
				menor = notas[0];
				printf("\n---------------------------------------------------------");
				printf("\n=========================================================\n");
				for(int i = 0; i < n; i++){
					if(notas[i] > maior){
						maior = notas[i];
					}
					
					if(notas[i] < menor){
						menor = notas[i];
					}
				}
				
				printf("\nA maior nota é: %.2f", maior);
				printf("\nA menor nota é: %.2f\n", menor);
				printf("\n=========================================================\n");
				printf("----------------------------------------------------------\n");
				break;
			
			case 4:
				printf("\n---------------------------------------------------------");
				printf("\n=========================================================\n");
				printf("                           NOTAS\n");
				printf("\n");
				if(n != 25){
					for(int i = 0; i < n; i++){
						printf("[ %.2f ]", notas[i]);
					}
				}
				printf("\n");
				printf("\n=========================================================");
				printf("\n---------------------------------------------------------\n");
				break;
				
			case 5:
				printf("\n---------------------------------------------------------");
				printf("\n=========================================================\n");
				if(n == 25){
					printf("\nCadastre ao menos 1 nota.\n");
				}else{
					printf("\nQual nota deseja buscar? ");
					scanf("%i", &y);
					
					while(x < n){
						if(notas[x] == y){
							printf("\nNota: %.2f | Posição: %i\n", notas[x], x);
							cont_notas++;
						}
						x++;
					}
					printf("\nForam encontradas %i notas de valor %i\n", cont_notas, y);
				}
				printf("\n---------------------------------------------------------");
				printf("\n=========================================================\n");
				break;
				
			case 6:
				printf("\n---------------------------------------------------------");
				printf("\n=========================================================\n");
				if(n == 25){
					printf("\nCadastre ao menos 1 nota.\n");	
				}else{
					for(int i = 0; i < n; i++){
						if(notas[i] >= 6){
							aprovados++;
						}else{
							reprovados++;
						}
					}
					printf("\nNúmero de APROVADOS: %i", aprovados);
					printf("\nNúmero de REPROVADOS: %i\n", reprovados);
				}
				printf("\n---------------------------------------------------------");
				printf("\n=========================================================\n");
				break;
				
			default:
				printf("\nOpção inválida\n");
		}
			

	}while(1);
	
	
	
	return 0;
}
