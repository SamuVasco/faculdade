#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	// Questão 1: O programa deve oferecer um menu com as opções: 1: Converter de Celsius para Fahrenheit / 2: Converter de Fahrenheit para Celsius

	float temp, c, f;
	int o;
	
	
	while(o < 1 || o > 2){
		printf("Digite um valor: ");
		scanf("%f", &temp);
		
		printf("\n[1] Converter de Celsius para Fahrenheit\n");
		printf("[2] Converter de Fahrenheit para Celsius\n");
		printf("[3] Sair\n");
		printf("Opção: ");
		scanf("%i", &o);
		
		switch(o){
			case 1:
				f = (temp * 1.8) + 32;
				printf("%.1f°C = %.1f°F\n", temp, f);
				break;
			case 2:
				c = (temp - 32) / 1.8;
				printf("%.1f°F = %.1f°C\n", temp, c);
				break;
			default:
				printf("\nOpção inválida\n");
				break;
		}
	}
	printf("\nFIM\n");
	
	
	// Questão 2: O programa deve pedir ao usuário que escolha uma forma geométrica: 1: Quadrado 2: Retângulo 3: Triângulo 4: Círculo
	
	float area, lado, base, altura, raio;
	int op;
	
	printf("\n[1] Quadrado\n");
	printf("[2] Retângulo\n");
	printf("[3] Triângulo\n");
	printf("[4] Círculo\n");
	printf("Opção: ");
	scanf("%i", &op);
	
	switch(op){
		case 1:
			printf("\nQual valor do lado do quadrado? ");
			scanf("%f", &lado);
			area = lado * lado;
			printf("A área do QUADRADO vale: %.2f", area);
			break;
		case 2:
			printf("\nBase: ");
			scanf("%f", &base);
			
			printf("Altura: ");
			scanf("%f", &altura);
			
			area = base * altura;
			
			printf("A área do RETÂNGULO vale: %.2f", area);
			break;
		case 3:
			printf("\nBase: ");
			scanf("%f", &base);
			
			printf("Altura: ");
			scanf("%f", &altura);
			
			area = (base * altura) / 2;
			
			printf("A área do TRIÂNGULO vale: %.2f", area);
		case 4:
			printf("\nRaio: ");
			scanf("%f", &raio);
			
			area = 3.14 * (raio * raio);
			
			printf("A área do CÍRCULO vale: %.2f", area);
		default:
			printf("");
	}
	
	printf("\nFIM\n");
	
	// Questão 3: Dois jogadores escolhem uma opção: 1: Pedra 2: Papel 3: Tesoura
	
	int jog1, jog2;
	
	printf("\n[1] PEDRA\n");
	printf("[2] PAPEL\n");
	printf("[3] TESOURA\n");
	
	printf("\nJOGADOR 1: ");
	scanf("%i", &jog1);
	
	printf("\nJOGADOR 2: ");
	scanf("%i", &jog2);
	
	if(jog1 == jog2){
		printf("\nEmpate\n");
	}else{
		switch(jog1){  
			case 1: // Jogador 1 escolheu Pedra
				switch(jog2){
					case 2: // Jogador 2 escolheu Papel
						printf("\nJOGADOR 2 VENCE! (Pedra x Papel)\n");
						break;
					case 3: // Jogador 2 escolheu Tesoura
						printf("\nJOGADOR 1 VENCE (Pedra x Tesoura)\n");
						break;
					default:
						printf("\nEscolha inválida do JOGADOR 2\n");
						break;
				}
				break;
				
			case 2: // Jogador 1 escolheu Papel
				switch(jog2){
					case 1: // Jogador 2 escolheu Pedra
						printf("\nJOGADOR 1 VENCE! (Papel x Pedra)\n");
						break; 
					case 3: // Jogador 2 escolheu Tesoura
						printf("\nJOGADOR 2 VENCE! (Papel x Tesoura)\n");
						break;
					default:
						printf("\nEscolha inválida do JOGADOR 2\n");	
						break;
				}
				break;
			
			case 3: // Jogador 1 escolheu Tesoura
				switch(jog2){
					case 1:
						printf("\nJOGADOR 2 VENCE! (Tesoura x Pedra)\n");
						break;
					case 2:
						printf("\nJOGADOR 1 VENCE! (Tesoura x Papel)\n");
						break;
					default:
						printf("\nEscolha inválida do JOGADOR 2\n");
						break;
				}	
				break;
				
			default:
				printf("\nEscolha inválida do JOGADOR 1\n");
				break;
		}
	}
	
	printf("\nFIM\n");
	
	// Questão 4: Crie um menu com as opções: 1: Ver saldo 2: Depositar 3: Sacar 4: Sair
	
	int opc = 0;
	float saldo = 100, depositar, sacar;
	
	while(opc != 4){
		printf("\n[1] Ver saldo\n");
		printf("[2] Depositar\n");
		printf("[3] Sacar\n");
		printf("[4] Sair\n");
		printf("Opção: ");
		scanf("%i", &opc);
		
		if(opc == 4){
			break;
		}else{
			switch(opc){
				case 1:
					printf("\nSALDO: [ R$ %.2f ]\n", saldo);
					break;
					
				case 2:
					depositar = 0;
					printf("\nDigite o valor que quer DEPOSITAR: R$");
					scanf("%f", &depositar);
					
					saldo += depositar;
					
					break;
					
				case 3:
					sacar = 0;
					printf("\nDigite o valor que quer SACAR: R$");
					scanf("%f", &sacar);
					
					saldo -= sacar;
					
					break;
				case 4:
					break;
			}
			if(opc == 4){
				break;
			}
		}
	}
	
	printf("\nFim\n");
	
	
	// Questão 5: O programa deve converter: 1: Quilômetros -> Milhas  2: Metros -> Pés  3: Quilogramas -> Libras  4: Litros -> Galões
	
	float valor5, con5;
	int op5;
	
	printf("\nDigite um valor: ");
	scanf("%f", &valor5);
	
	printf("\n 1: Quilômetros -> Milhas\n");
	printf(" 2: Metros -> Pés\n");
	printf(" 3: Quilogramas -> Libras\n ");
	printf("4: Litros -> Galões \n");
	printf("\nOpção: ");
	scanf("%i", &op5);
	
	switch(op5){
		case 1:
			con5 = valor5 * 0.621371;
			printf("\n%.2f Km -> %.6f mi\n", valor5, con5);
			break;
			
		case 2:
			con5 = valor5 * 3.28084;
			printf("\n%.2f m -> %.5f pés\n", valor5, con5);
			break;
			
		case 3:
			con5 = valor5 * 2.20462;
			printf("\n%.2f Kg -> %.5f lbs\n", valor5, con5);
			break;
		
		case 4:
			con5 = valor5 * 0.264172;
			printf("\n%.2f l -> %.6f Galão americano\n", valor5, con5);
			break;
		default:
			printf("\nOpção inválida\n");
	}
	
	printf("\nFim\n");

	
	/*
	Questão 6: Qual das opções abaixo descreve corretamente como a instrução switch
	funciona na linguagem C?
	
	RESPOSTA: C) Compara o valor de uma variável com múltiplos casos constantes
	
	
	Questão 7: Analise o seguinte código:
		
	int x = 2;
	
	switch (x) {
		case 1:
			printf("A");
		case 2:
			printf("B");
		case 3:
			printf("C");
			break;
		default:
			printf("D");
	}
	
	O que será impresso na tela?
	
	RESPOSTA: C) BC
	
	
	Questão 8: Qual é a finalidade do default em um switch?
	
	
	RESPOSTA: C) Especificar o bloco de código executado se nenhum case for
	
	*/
	return 0;
}
