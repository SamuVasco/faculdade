#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");	
	
	/*
		OBS: COMO TÊM MUITAS VARIÁVEIS COM O MESMO NOME, EXECUTE CADA BLOCO DE CÓDIGO INDIVIDUALMENTE.
			 RETIRE O COMENTÁRIO, EXECUTE O CÓDIGO E ANTES DE EXECUTAR OUTRO, COMENTE O CÓDIGO DE NOVO. 
	*/
	
	
	/*
	printf("---------- ex.1 numeros de 1 a 10 ----------\n");
	
	int n;
	printf("=============================================================\n");
	for (n = 1; n <= 10; n++){
		printf("%i\n", n);
	}
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("---------- ex.2 numeros de 1 a 20 ----------\n");
	
	int nu;
	printf("=============================================================\n");
	for (nu = 1; nu <= 20; nu++){
		printf("%i\n", nu);
	}
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("---------- ex.3 numeros impares de 1 a 20 ----------\n");
	
	int impar;
	printf("=============================================================\n");
	for (impar = 1; impar <= 20; impar++){
		if (impar % 2 == 1){
			printf("%i\n", impar);
		}		
	}
	
	printf("Fim");
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("---------- ex.4 ler n numero e quantos são positivos ----------\n");
	
	int positivo, ate, contador=0;
	printf("=============================================================\n");
	printf("Quantos valores? ");
	scanf("%i", &ate);
	
	for (int i = 1; i <= ate; i++){
		printf("Digite o %i° valor INTEIRO: ", i);
		scanf("%i", &positivo);
		
		if (positivo > 0){
			contador++;
		}
	}
	
	printf("Foram digitados %i valores POSITIVOS.", contador);
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("---------- ex.5 Leia números até o usuário digitar 0, calcule a soma (break). ----------\n");
	
	int valor=0, soma=0, i;
	printf("=============================================================\n");
	for(i = 1; i != 0; i++){
		printf("Digite o %i° valor: ", i);
		scanf("%i", &valor);
		
		if (valor == 0){
			break;
		}
		soma += valor;
	}
	printf("Foram digitados %i valores e a soma entre eles é %i\n", i-1, soma);
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("---------- ex.6 Imprima números de 1 a 20, ignore múltiplos de 6, pare ao chegar em 21 (break + continue). ----------\n");
	
	printf("=============================================================\n");
	for (int i=0; i <= 21; i++){
		if (i % 6 == 0){
			continue;
		} else {
			printf("%i\n", i);
		}
	}
	printf("FIM\n");
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("---------- ex.7 Leia n números, ignore negativos (continue) e conte positivos. ----------\n");
		
	
	int loop, nume, cont_pos;
	
	printf("=============================================================\n");
	printf("Quantos NÚMEROS você quer ler? Digite um número INTEIRO: ");
	scanf("%i", &loop);
	
	for (int i = 1; i <= loop; i++){
		printf("Digite o %i° valor: ", i);
		scanf("%i", &nume);
		
		if (nume > 0){
			cont_pos++;
		}
	}
	printf("Ao todo, foram digitados %i valores positivos.\n", cont_pos);
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("-------- ex.8 Leia vários números até encontrar um número >100 (break), e mostre soma e quantidade de números válidos. --------\n");
	
	int user, i, s=0;
	
	printf("==============================");
	for (i = 0; i != -1; i++){
		printf("Digite o %i° valor ou 100+ para parar: ", i);
		scanf("%i", &user);
		
		if (user >= 100){
			break;
		} else {
			s += user;
		}
	}
	printf("A quantidade de VALORES VÁLIDOS digitados foram: %i\n", i);
	printf("A soma dos VALORES DIGITADOS é: %i", s);
	printf("==============================");
	*/
	
	
	/*
	printf("-------- ex.9 Preencha uma matriz 3x3 e imprima apenas elementos pares. --------\n");
	
	printf("=============================================================\n");
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j != 2; j++){
			for (int x = 1; x !=2; x++){
				printf("%i %i %i\n", i*2, j*2, x*4);
			}
		}
	}
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("-------- ex.10 Imprima um triângulo de asteriscos usando laços aninhados. --------\n");
	
	int x;
	printf("=============================================================\n");
	printf("Digite o número de linhas do triângulo: ");
	scanf("%i", &x);
	
	for (int linhas = 1; linhas <= x; linhas++){
		for (int colunas = 1; colunas <= linhas; colunas++){
			printf("*");
		}
		printf("\n");
	}
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("-------- ex.11 Leia 10 números inteiros e calcule a média apenas dos números pares. --------\n");
	
	int valor, media, soma, cont_pares=0;
	
	printf("=============================================================\n");
	for (int i = 1; i <= 10; i++){
		printf("Digite o %i° valor: ", i);
		scanf("%i", &valor);
		if (valor == 0){
			continue;
		}else if (valor % 2 == 0){
			soma += valor;
			cont_pares++;
		}
	}
	if (cont_pares > 1){
		media = soma / cont_pares;
		printf("Foram digitados %i PARES. A média entre eles é: %i\n", cont_pares, media);
	}else{
		printf("Nenhum valor PAR digitado.\n");
	}
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("-------- ex.12 Leia n números inteiros (n fornecido pelo usuário) e informe o maior e o menor valor digitado. --------\n");
	
	int vezes, valor, maior, menor;
	
	printf("Digite quantos valores você quer ler: ");
	scanf("%i", &vezes);
	
	for (int i = 1; i <= vezes; i++){
		printf("Digite o %i° valor: ", i);
		scanf("%i", &valor);
		if (valor > maior){
			maior = valor;
		} else{
			menor = valor;
		}
	}
	
	printf("O MAIOR valor digitado foi: %i\n", maior);
	printf("O MENOR valor digitado foi: %i", menor);
	*/
	
	
	/*
	printf("-------- ex.13 Imprima os números de 100 até 0, decrementando de 5 em 5. --------\n");
	
	printf("-----\n");
	for (int i = 0; i <= 100; i+=5){
		printf("%i\n ", i);
	}
	printf("-----");
	*/
	
	
	/*
	printf("-------- ex.14 Leia um número N e imprima todos os números primos de 2 até N. --------\n");

	int N, i, j, divisores;

    printf("Digite N: ");
    scanf("%d", &N);

    for (i = 2; i <= N; i++) {
        divisores = 0;

        // Conta quantos divisores o número i tem entre 1 e ele mesmo
        for (j = 1; j <= i; j++) {
            if (i % j == 0) {
                divisores++;
            }
        }

        // Se tiver exatamente 2 divisores (1 e ele mesmo), imprime
        if (divisores == 2) {
            printf("%d ", i);
        }
    }
    */
    
    
    /*
	printf("ex.15 Leia 5 idades. Se uma idade for menor que 0 ou maior que 120, ignore (continue). Ao final, imprima a média das idades válidas.\n");
	
	int idade=0, soma=0, idade_valida=0;
	float media;
	
	for (int i = 1; i <= 5; i++){
		printf("Digite a %i° idade: ", i);
		scanf("%i", &idade);
		
		if (idade > 0 && idade < 120){
			idade_valida++;
			soma += idade;
		} else{
			continue;
		}
	}
	printf("%i\n", idade_valida);
	media = soma / idade_valida;
	
	printf("A média das idade é: %.1f", media);
	*/
	
	
	/*
	printf("ex.16 Crie um programa que leia um número e verifique se ele está fora do intervalo entre 20 e 40 (inclusive).\n");
	printf("Caso esteja fora, imprima Fora do intervalo, caso contrário, Dentro do intervalo.\n");
	
	int o_num;
	
	printf("Digite um número: ");
	scanf("%i", &o_num);
	
	if(o_num >= 20 && o_num <= 40){
		printf("DENTRO DO INVERVALO!\n");
	} else{
		printf("FORA DO INVERVALO...\n");
	}
	*/
	
	
	/*	
	printf("ex.17 Escreva um programa que leia dois números e calcule a soma entre eles.\n");
	printf("Se a soma for par, imprima Soma par, caso contrário, Soma ímpar\n.");
	
	int a, b, somando;
	
	printf("=============================================================\n");
	printf("Digite dois valores seguidos: ");
	scanf("%i %i", &a, &b);
	
	somando = a + b;
	printf("Somando %i + %i = %i\n", a, b, somando);
	
	if(somando % 2 == 0){
		printf("Soma PAR");
	} else {
		printf("Soma ÍMPAR");
	}
	*/
	
	
	/*
	printf("ex.18 Crie um programa que leia o preço de um produto. Aplique um acréscimo:\n");
	printf("Se o preço for menor que R$ 50, acrescente 20 porcento.\n");
	printf("Caso contrário, acrescente 10 porcento.\n");
	
	printf("=============================================================\n");
	
	float preco, acres;
	
	printf("=============================================================\n");
	printf("Preço do produto: R$");
	scanf("%f", &preco);
	
	if (preco < 50){
		acres = preco + (preco * 20 / 100);
		printf("Acréscimo de 20 porcento.\n");
	} else {
		acres = preco + (preco * 10 / 100);
		printf("Acréscimo de 10 porcento.\n");
	}
	printf("O produto que custava R$%.2f, agora custa: R$%.2f\n", preco, acres);
	printf("=============================================================\n");
	*/
	
	
	/*
	printf("ex.19 Escreva um programa que leia um número inteiro e verifique se ele é um número primo ou não.\n");
	
	int o_valor, tot;
	
	printf("Digite um número: ");
	scanf("%i", &o_valor);
	
	for (int i = 1; i <= o_valor; i++){
		if (o_valor % i == 0){
			tot++;
		}
	}
	
	if (tot <= 2){
		printf("O %i É PRIMO.\n", o_valor);
	} else{
		printf("O %i NÃO é primo.\n", o_valor);
	}
	*/
	
	
	
	/*
	-------------------  QUESTÕES  ------------------------------
	-------------------------------------------------------------	
				
	21.Qual expressão lógica avalia para verdadeiro (1) em C?

	RESPOSTA: b) (4 == 4) || (3 > 5)
	
	
	22. Qual expressão é verdadeira para números pares em C?
	
	REPOSTA: c) n % 2 == 0
	
	
	23. Qual resultado será impresso?
	
	int a = 4, b = 2;
	if (a > b && b > 0)
		printf("Sim");
	else
		printf("Nao");
	
	RESPOSTA: b) Sim
	
	
	24. Quantas vezes o laço abaixo será executado?
	
	for (int i = 0; i < 10; i += 2)
		printf("%d ", i);
	
	REPOSTA: a) 5
	
	
	25. Qual operador é usado para “diferente de” em C?
	
	RESPOSTA: a) !=
	
	
	26. Qual valor será impresso?
	
	int x = 3, y = 5;
	if (x > 5 || y < 10)
		printf("%d", x + y);
	else
		printf("%d", x - y);

	
	RESPOSTA: b) 8	
	------------------------------------------------------------
	*/
	
	return 0;
}
