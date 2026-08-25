#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("1. Escreva um programa que receba dois números inteiros do usuário e exiba a soma deles.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	int numero1, numero2, soma;
	
	printf("Digite o numero 1: ");
	scanf("%i", &numero1);
	
	printf("Digite o numero 2: ");
	scanf("%i", &numero2);
	
	soma = numero1 + numero2;
	
	printf("A soma entre %i e %i é igual a %i\n", numero1, numero2, soma);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	printf("2. Crie um programa que receba um valor em Reais e exiba o equivalente em Dólares, considerando a cotação fixa de 5.00. \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	float real, dolar;
	
	printf("Valor em Real: R$");
	scanf("%f", &real);
	
	dolar = real / 5;
	
	printf("O valor de R$%.1f Reais, em dólar, é igual a U$%.1f\n", real, dolar);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	printf("3. Receba o raio de um círculo e calcule sua área.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	float raio, area;
	printf("Raio: ");
	scanf("%f", &raio);
	
	area = 3.14 * raio * raio;
	
	printf("A área é igual a: %f\n", area);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	printf("4. Receba duas notas. Calcule a média sabendo que a primeira nota tem peso 3 e a segunda tem peso 7.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	float nota1, nota2, media, mediap;
	printf("Digite a nota 1: ");
	scanf("%f", &nota1);
	
	printf("Digite a nota 2: ");
	scanf("%f", &nota2);
	
	media = (nota1 * 3 + nota2 * 7) / 2;
	
	mediap = (nota1 * 3 + nota2 * 7) / 10; // media ponderada = (nota1 * 3) + (nota2 * 7) / (peso 3 + peso 7 = 10)
	
	printf("Média Normal: %.1f\n", media);
	printf("Média Ponderada: %.1f\n", mediap);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	printf("5. Peça um número inteiro e imprima o seu antecessor e o seu sucessor. \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	int numero;
	printf("Digite um número INTEIRO: ");
	scanf("%i", &numero);
	
	printf("O ANTECESSOR de %i é: %i\n", numero, numero - 1);
	printf("O SUCESSOR de %i é: %i\n", numero, numero + 1);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	printf("6. Peça a idade do usuário e imprima 1 se ele for maior ou igual a 18 anos, e 0 caso contrário.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	int idade;
	printf("Digite sua idade: ");
	scanf("%i", &idade);
	
	printf("Idade maior ou igual a 18? %i\n", idade >= 18); 
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); 
	
	printf("7. Receba dois números, A e B. Imprima 1 se eles forem diferentes e 0 se forem iguais.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	float a, b;
	printf("Digite o valor de A: ");
	scanf("%f", &a);
	
	printf("Digite o valor de B: ");
	scanf("%f", &b);
	
	printf("A e B são diferentes? %i\n", a != b);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	printf("8. Receba um número e usando operadores relacionais, exiba 1 se o número for maior que zero.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	float num;
	
	printf("Digite um número: ");
	scanf("%f", &num);
	
	printf("%.2f é maior que 0? %i\n", num, num > 0);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	printf("9. Receba o preço de um produto e exiba o novo preço com 10% de desconto.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	float preco, desconto;
	
	printf("Preço do produto: R$");
	scanf("%f", &preco);
	
	desconto = preco - (preco * 10 / 100);
	
	printf("O produto com 10 porcento de desconto vai custar R$%.2f\n", desconto);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	printf("10.Receba um número inteiro. Exiba 1 se o número for negativo e 0 se for positivo ou zero.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	int x;
	
	printf("Digite um número INTEIRO: ");
	scanf("%i", &x);
	
	printf("Número é negativo? %i\n", x <= -1);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Fim do programa.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
	return 0;
}
