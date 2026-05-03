#include <stdio.h>
#include <locale.h>


int main() {
	setlocale(LC_ALL, "Portuguese");
	
	// 1. Escreva um programa que imprima todos os números de 1 a 100 usando while.
	/*
	int um_a_cem = 1;
	while(true){
		printf("%i\n", um_a_cem);
		if(um_a_cem >= 100) break;
		um_a_cem++;
	}
	*/
	
	// 2. Leia um número inteiro positivo e use while para: contar quantos números pares existem de 1 até ele
	/*
	int inteiro_positivo, c=1, pares=0;
	
	printf("Digite um número inteiro positivo: ");
	scanf("%i", &inteiro_positivo);
	
	while(c <= inteiro_positivo){
		printf("| %i | ", c);
		if(c % 2 == 0){
			pares++;
		}
		c++;
	}
	printf("\nEntre 1 e %i existem %i valores pares.", inteiro_positivo, pares);
	*/
	
	// 3. Leia números do usuário até que ele digite -1.
	// Ao final, mostre: A soma dos números digitados / A quantidade de números
	/*
	int numeros_usuario = 0, soma = 0, co = 0;
	
	while(true){
		printf("Digite qualquer valor [-1 para PARAR]: ");
		scanf("%i", &numeros_usuario);
		
		if(numeros_usuario == -1){
			break;
		}else {
			soma += numeros_usuario;
			co++;
		}
	}
	printf("A soma dos números digitados: %i\n", soma);
	printf("A quantidade de números: %i", co);
	*/
	
	// 4. Leia vários números até que o usuário digite 0. Exiba: o maior número digitado
	/*
	int numero_digitado=1, maior=0, con=0;
	
	while(numero_digitado != 0){
		printf("Digite qualquer valor [0 para PARAR]: ");
		scanf("%i", &numero_digitado);
		
		if(numero_digitado >= maior){
			maior = numero_digitado;
			con++;
		}
	}
	printf("Foram digitados %i valores e o maior deles foi: %i", con, maior);
	*/
	
	// 5. Peça ao usuário uma senha.
	/*
	int senha;
	
	while(senha != 1234){
		printf("Digite a senha: ");
		scanf("%i", &senha);
	}
	*/
	
	// 6. Leia um número n e imprima de n até 0.
	/*
	int numero_ate_zero;
	
	printf("==============================\n");
	printf("Digite um número: ");
	scanf("%i", &numero_ate_zero);
	printf("==============================\n");
	
	while (numero_ate_zero >= 0){
		printf("%i\n", numero_ate_zero);
		numero_ate_zero--;
	}
	printf("==============================\n");
	*/
	
	// 7. Mostre os primeiros n termos da sequência de Fibonacci usando while.
	/*
	int n_termo, cont=3, t1=0, t2=1, tn=0;
	
	printf("Quantos termos mostrar? ");
	scanf("%i", &n_termo);
	printf("%i -> %i", t1, t2);
	while(cont <= n_termo){
		tn = t1 + t2;
		printf(" -> %i", tn);
		t1 = t2;
		t2 = tn;
		cont++;
	}
	printf(" -> FIM");
	*/
	
	// 8. Implemente a divisão inteira de dois números usando apenas subtrações e while.
	//Exemplo: 10 / 3 = 3 (resto 1)
	/*
    int dividendo = 10;
    int divisor = 3;
    int quociente = 0;
    int resto = dividendo;

    while (resto >= divisor) {
        resto -= divisor;
        quociente++;
    }

    printf("%d / %d = %d (resto %d)\n", dividendo, divisor, quociente, resto);
	*/
	
	// 9. Verifique se um número é primo usando while.
	/*
	int n_primo=0, conta=1, div=0;
	
	printf("Digite um número (maior que 1) para saber se é PRIMO: ");
	scanf("%i", &n_primo);
	
	while(conta <= n_primo){
		if(n_primo % conta == 0){
			div++;
		}
		conta++;
	}
	if(div <= 2){
		printf("O número %i É PRIMO", n_primo);
	}else{
		printf("O número %i NÃO É primo", n_primo);
	}
	printf("\nFIM");
	*/
	
	// 10. Crie um programa que: leia números até o usuário digitar 0
	// conte: quantos são pares, quantos são ímpares, calcule a média dos números (exceto o 0)
	/*
	int n_user=1, n_par=0, n_impar=0, contad=0, n_soma=0, med=0;
	
	while(n_user != 0){
		printf("Digite um número [0 para PARAR]: ");
		scanf("%i", &n_user);
		
		if(n_user > 0){
			if(n_user % 2 == 0){
				n_par++;
				n_soma += n_user;
			}else{
				n_impar++;
				n_soma += n_user;
			}
			contad++;
		}	
	}
	med = n_soma / contad;
	
	printf("Quantidade de valores PARES digitados: %i\n", n_par);
	printf("Quantidade de valores IMPARES digitados: %i\n", n_impar);
	printf("A média dos números é: %i", med);
	*/
	
	int opcao=0;
	float saldo=1000, sacar, depositar;
	
	while(opcao != 3){
		printf("\n======== CAIXA ELETRÔNICO DO BANCO MASTER ========\n" );
		printf("--------------------------------------------------\n");
		printf("\nSaldo: %.1f\n", saldo);
		printf("\n--------------------------------------------------\n");
		printf("[ 1 ] Sacar\n");
		printf("[ 2 ] Depositar\n");
		printf("[ 3 ] Sair\n");
		printf("--------------------------------------------------\n");
		
		printf("Digite a opção: ");
		scanf("%i", &opcao);
		
		if(opcao > 3 || opcao < 1){
			printf("\n**************************************************\n");
			printf("\nOPÇÃO INVÁLIDA. Tente novamente.\n");
			printf("\n**************************************************\n");
		}else if(opcao == 1){
			sacar = 0;
			printf("\n==================================================\n");
			printf("\nQuanto deseja sacar? R$");
			scanf("%f", &sacar);
			printf("\n==================================================\n");
			
			if(sacar > saldo){
				printf("\nVocê NÃO têm saldo disponível.\n");
			}else{
				printf("\nSacando: R$%.1f\n", sacar);
				saldo -= sacar;
				printf("\nVocê sacou R$%.1f e o seu novo saldo é: R$%1.f\n", sacar, saldo);
			}
			printf("\n==================================================\n");
		}else if(opcao == 2){
			depositar = 0;
			printf("\n==================================================\n");
			printf("\nQuanto deseja depositar? R$");
			scanf("%f", &depositar);
			printf("\n==================================================\n");
			saldo += depositar;
			printf("\nVocê depositou R$%.1f e seu novo saldo é: R$ %.1f \n", depositar, saldo);
			printf("\n==================================================\n");
		}
	}
	printf("\nFim do programa.");
	
	
	
	
	
	/* ===== QUESTÕES =====
	
	12. O laço while em C é mais indicado quando:
	
	RESPOSTA: B) Não sabemos previamente o número de iterações e dependemos de uma condição.
	
	
	13. Qual das afirmações sobre while é verdadeira?
	
	RESPOSTA: B) O while verifica a condição antes de executar o bloco. (APENAS 1 AFIRMAÇÃO É VERDADEIRA)
	
	
	14. Em C, quando o bloco do while possui uma única instrução, é correto:
	
	RESPOSTA: B) O uso de chaves é opcional.
	
	
	15. Sobre loops infinitos em C, assinale a alternativa correta:
	
	RESPOSTA: A) Um while com condição sempre verdadeira (while(1)) pode ser interrompido usando break.

	
	16. O uso de continue dentro de um while:
	
	RESPOSTA: B) Passa para a próxima iteração ignorando o restante do bloco atual.
	
	
	17. Sobre o while aninhado (loop dentro de loop), é correto afirmar:
	
	RESPOSTA: C) Cada loop mantém seu próprio escopo de variáveis, podendo haver variáveis com o mesmo nome nos dois.
	
	
	18. Qual das situações abaixo pode causar um loop infinito em C?
	
	RESPOSTA: A) Atualizar a variável de controle incorretamente dentro do laço.
	
	
	19. Sobre a condição de término do while, assinale a correta:
	
	RESPOSTA: A) Pode ser qualquer expressão que retorne um valor inteiro.
	
	
	20. Qual das alternativas é uma boa prática em while?
	
	RESPOSTA: A) Garantir que a condição eventualmente se torne falsa para evitar loops infinitos.
	*/
	
	
	
	
	
	
	
	
	
		
	return 0;
}
