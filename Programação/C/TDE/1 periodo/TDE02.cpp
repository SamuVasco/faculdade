#include <stdio.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int n1, n2, soma, sub, multi, div, resto;
 	
	printf("Exercício 1: Aritméticos Simples\n");
	
	printf("Digite o n1: ");
	scanf("%i", &n1);
	
	printf("Digite o n2: ");
	scanf("%i", &n2);
	
	soma = n1 + n2;
	sub = n1 - n2;
	multi = n1 * n2;

	printf("Soma: %i\n", soma);
	printf("Subtração: %i\n", sub);
	printf("Multi: %i\n", multi);
	if(n2 != 0){
		div = n1 / n2;
		printf("Divisão: %i\n", div);
	}
	if(n2 != 0){
		resto = n1 % n2;
		printf("Resto: %i\n", resto);	
	}
	
	printf("===============================================================================\n");
	printf("Exercício 2: Verificando Paridade\n");
	
	int num;
	
	printf("Informe um número INTEIRO: ");
	scanf("%i", &num);
	
	if(num % 2 == 0){
		printf("%i é PAR\n", num);
	}
	else{
		printf("%i é ÍMPAR\n", num);
	}
	
	printf("===============================================================================\n");
	printf("Exercício 3: Calculadora de Média\n");
	
	float nota1, nota2, nota3, media;
	
	printf("Digite as 3 Notas do aluno: ");
	scanf("%f %f %f", &nota1, &nota2, &nota3);
	
	media = (nota1 + nota2 + nota3) / 3;
	
	printf("A média entre %.1f, %.1f e %.1f é igual a %.1f\n", nota1,nota2,nota3,media);
	
	if(media >= 6){
		printf("Aluno APROVADO\n");
	}else{
		printf("Aluno REPROVADO\n");
	}
	
	printf("===============================================================================\n");
	printf("Exercício 4: Maior Número\n");
	
	int num1, num2;
	
	printf("Digite 2 valores INTEIROS: ");
	scanf("%i %i", &num1, &num2);
	
	if(num1 > num2){
		printf("%i é maior que %i\n", num1,num2);
	}else if(num2 > num1){
		printf("%i é maior que %i\n", num2,num1);
	}else{
		printf("%i é igual a %i\n", num2,num1);
	}
	
	printf("===============================================================================\n");
	printf("Exercício 5: Verificando a Idade\n");
	
	int idade;
	
	printf("Digite sua idade: ");
	scanf("%i", &idade);
	
	
	if(idade >= 18){
		printf("Essa pessoa é MAIOR DE IDADE\n");
	}else{
		printf("Essa pessoa é MENOR DE IDADE\n");
	}
	
	printf("===============================================================================\n");
	printf("Exercício 6: Condição de Par ou Ímpar\n");
	
	int x, y;
	
	printf("Digite 2 valores INTEIROS: ");
	scanf("%i %i", &x, &y);
	
	if(x % 2 == 0){
		printf("O valor %i é PAR\n", x);
	}
	else{
		printf("O valor %i é ÍMPAR\n", x);
	}
	
	if(y % 2 == 0){
		printf("O valor %i é PAR\n", y);
	}
	else{
		printf("O valor %i é ÍMPAR\n", y);
	}
	
	printf("===============================================================================\n");
	printf("Exercício 7: Calculando o Preço com Desconto\n");
	
	float produto, desconto;
	
	printf("Digite o preço do produto: R$");
	scanf("%f", &produto);
	
	if(produto > 100){
		desconto = produto - (10 * produto / 100);
		printf("O produto com desconto: R$ %.2f\n", desconto);
	}
	else{
		printf("O valor do produto é: R$%.2f\n", produto);
	}
	
	printf("===============================================================================\n");
	printf("Exercício 8: Verificando Se um Número Está Dentro de um Intervalo\n");
	
	int z;
	
	printf("Digite um número INTEIRO: ");
	scanf("%i", &z);
	
	if(z > 10 && z <= 20){
		printf("O valor SE ENCONTRA entre 10 e 20 (inclusive)\n");
	}else{
		printf("O valor NÃO se encontra entre 10 e 20 (inclusive)\n");
	}
	
	printf("===============================================================================\n");
	printf("Exercício 9: Condição de Votação\n");
	
	int idad;
	
	printf("Informe sua idade: ");
	scanf("%i", &idad);
	
	if(idad >= 16 && idad <= 70){
		printf("Essa pessoa PODE votar\n");
	}else if(idad > 70){
		printf("Essa pessoa PODE ou NÃO votar (facultativo)\n");
	}
	else{
		printf("Essa pessoa NÃO pode votar\n");
	}

	printf("===============================================================================\n");
	printf("Exercício 10: Operadores Lógicos\n");
	
	int ida;
	float sal;
	
	printf("Digite sua idade: ");
	scanf("%i", &ida);
	
	printf("Digite o seu salário: R$");
	scanf("%f", &sal);
	
	if(ida > 18 && sal > 2000){
		printf("Você tem mais de 18 anos e um bom salário.\n");
	}else{
		printf("Condição não atendida.\n");
	}
	
	return 0;
}
