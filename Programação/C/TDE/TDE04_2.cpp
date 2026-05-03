#include <stdio.h>
#include <locale.h>

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	// 1. Crie um programa com menu usando do...while: 1 -> Mostrar "Olá, usuário" / 2 -> Mostrar "Aprendendo C" / 0 -> Sair
	
	int s=0;
	
	do {
		printf("\n--------------------------------\n");
		printf("\n[ 1 ] Mostrar -> Olá, usuário\n");
		printf("[ 2 ] Mostrar -> Aprendendo C\n");
		printf("[ 0 ] Sair\n");
		printf("Digite: ");
		scanf("%i", &s);
		printf("\n--------------------------------\n");
		
		if(s == 1){
			printf("Olá, usuário");
		}else if(s == 2){
			printf("Aprendendo C");
		}else if(s == 0){
			printf("Fim");
			break;
		}else{
			printf("Opção inválida.");
		}
	} while (1);
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	
	
	// 2. Faça um programa que: Permita digitar números / Some todos eles / Pare quando o usuário digitar 0 / Mostre a soma final
	
	int sa, n, valor, soma;
	
	do {
		printf("\n----------------------------------------------------------------\n");
		printf("Digite a quantidade de valores a serem lidos [0 para SAIR]: ");
		scanf("%i", &n);
		soma = 0;
		
		if (n == 0){
			printf("\nFim");
			break;
		}
		
		for(int i = 1; i <= n; i++){
			printf("Digite o %i° valor: ", i);
			scanf("%i", &valor);
			soma += valor;
		}
		printf("\n==================================\n");
		printf("A soma dos valores é igual a: %i", soma);
		printf("\n==================================\n");
		printf("\n----------------------------------------------------------------\n");
	} while (1);
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	
	
	// 3. Leia números até o usuário digitar 0 e informe: Quantos são pares / Quantos são ímpares
		
	int u, par=0, impar=0;
	
	printf("\n-------------------------------------\n");
	do {
		printf("Digite um valor [0 para PARAR]: ");
		scanf("%i", &u);
		if(u == 0){
			break;
		}else{
			if(u % 2 == 0){
				par++;
			}else{
				impar++;
			}
		}
	} while(1);
	printf("\n-------------------------------------\n");
	printf("Quantidade de valores PARES: %i\n", par);
	printf("Quantidade de valores IMPARES: %i\n", impar);
	printf("\n-------------------------------------\n");
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	
	// 4. Leia vários números até digitar 0 e calcule: A média dos valores
	
	int v4, s4=0, c4=0, m4;
	printf("\n-------------------------------------\n");
	do{
		printf("Digite um valor [0 para PARAR]: ");
		scanf("%i", &v4);
		if(v4 != 0){
			s4 += v4;
			c4++;
		}
	}while(v4 != 0);
	
	if(c4 == 0){
		printf("Nenhum valor digitado.\n");
	}else{
		m4 = s4 / c4;
	}
	printf("\n-------------------------------------\n");
	printf("A média dos valores é: %i", m4);
	printf("\n-------------------------------------\n");
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	

	// 5. Menu: 1 -> Mostrar tabuada de um número / 0 -> Sair
	
	int x;
	printf("\n-------------------------------------\n");
	do {
		printf("Digite um número para ver a tabuada [0 para PARAR]: ");
		scanf("%i", &x);
		if(x == 0){
			break;
		}else{
			printf("\n-------------------------------------\n");
			for(int i = 1; i <= 10; i++){
				printf("%i x %i = %i\n", x, i, x*i);
			}
			printf("\n-------------------------------------\n");
		}
		printf("\n-------------------------------------\n");
	}while(x != 0);
	printf("Fim");
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	
	// 6. Menu: 1 -> Verificar se número é positivo/negativo  / 2 -> Verificar se é par/ímpar / 0 -> Sair
	
	int y, opcao=4;
	
	do {
		printf("\nDigite um valor INTEIRO: ");
		scanf("%i", &y);
		printf("\n-----------------------------------------------\n");
		printf("\n[ 1 ] Verificar se número é positivo/negativo\n");
		printf("[ 2 ] Verificar se é par/ímpar\n");
		printf("[ 0 ] Sair\n");
		printf("\n-----------------------------------------------\n");
		printf("Digite a opção: ");
		scanf("%i", &opcao);
		printf("\n-----------------------------------------------\n");
		
		if(opcao >= 1 && opcao < 3){
			printf("\n-----------------------------------------------\n");
			if(opcao == 1){
				if(y > 0){
					printf("O valor %i é POSITIVO", y);
				}else{
					printf("O valor %i é NEGATIVO", y);
				}
			}else if(opcao == 2){
				if(y % 2 == 0){
					printf("O valor %i é PAR", y);
				}else{
					printf("O valor %i é ÍMPAR", y);
				}
			}else if(opcao < 1 || opcao >= 3){
				printf("\n-----------------------------------------------\n");
				printf("\nOpção inválida\n");
				printf("\n-----------------------------------------------\n");
			}
			printf("\n-----------------------------------------------\n");
		}
	} while(opcao != 0);
	printf("Fim");
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	
	
	// 7. Leia números até 0 e mostre: O maior número informado
	
	int user7, maior7;
	
	do {
		printf("Digite um número [0 para PARAR]: ");
		scanf("%i", &user7);
		
		if(user7 > maior7){
			maior7 = user7;
		}
		
	} while(user7 != 0);
	
	printf("\nO maior valor digitado foi: %i\n", maior7);
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	
	
	// 8. Menu: 1 -> Calcular fatorial  /  0 -> Sair
	
	int op8, user8, fatorial;
	
	do {
		printf("\n[ 1 ] Calcular fatorial\n");
		printf("[ 0 ] Sair\n");
		printf("Digite a opção: ");
		scanf("%i", &op8);
		
		if (op8 < 0 || op8 > 1){
			printf("\nOPÇÃO INVÁLIDA\n");
		}else if(op8 == 1){
			printf("\n=============================================\n");
			fatorial = 1;
			printf("Digite o valor para calular o fatorial: ");
			scanf("%i", &user8);
			printf("\n===============\n");
			printf("%i! ", user8);
			for(int i=user8; i >= 1; i--){
				fatorial *= i;
			}
			printf(" = %i", fatorial);
			printf("\n===============\n");
		}
	} while(op8 != 0);
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	
	
	// 9.Peça dois números e calcule: A soma de todos os números entre eles
	
	int a9=0, b9=0, soma9=0;
	
	do {
		printf("Digite o 1° valor: ");
		scanf("%i", &a9);
		printf("Digite o 2° valor: ");
		scanf("%i", &b9);
		printf("A soma dos valores entre %i e %i", a9,b9);
		
		for(a9=a9; a9 <= b9; a9++){
			soma9 += a9;
		}
		
	} while(a9 <= b9);
	
	printf(" é igual a: %i", soma9);
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	
	
	// 10. Peça notas até digitar -1 e informe:  Média  /  Quantidade de notas
	
	float nota10=0, contador_notas10=0, soma10=0, media10=0;
	
	do {
		printf("Digite uma nota [-1 para PARAR]: ");
		scanf("%f", &nota10);
		if (nota10 != -1){
			contador_notas10++;
			soma10 += nota10;	
		}
	} while(nota10 != -1);
	media10 = soma10 / contador_notas10;
	if (contador_notas10 > 0){
		printf("A soma das notas é: %.1f\n", soma10);
		printf("Foram digitadas %.1f notas\n", contador_notas10);
		printf("A média das notas é: %.1f\n", media10);
	}else {
		printf("Nenhuma nota digitada.");	
	}
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	
	/* ===== QUESTÕES =====
	
	11. Sobre o do...while, marque a correta:
	
	RESPOSTA: B) Executa pelo menos uma vez
	
	
	12. Qual a principal diferença entre while e do...while?
	
	RESPOSTA: C) O do...while testa a condição no final
	
	
	13. O que faz o código abaixo?
	
	int x = 5;
	do {
	printf("%d", x);
	x++;
	} while (x < 5);
	
	RESPOSTA: C) Executa 1 vez
	
	
	14. Qual estrutura é melhor para menus?
	
	RESPOSTA: C) do...while
	
	
	16. O que faz o break dentro de um loop?
	
	RESPOSTA: B) Encerra o loop
	
	*/
	
	
	return 0;
}
