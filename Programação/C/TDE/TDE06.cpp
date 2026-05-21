#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	// Questão 1: O programa deve oferecer um menu com as opções: 1: Converter de Celsius para Fahrenheit / 2: Converter de Fahrenheit para Celsius
	/*
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
	
	printf("[1] Quadrado\n");
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
	*/
	
	// Questão 3: Dois jogadores escolhem uma opção: 1: Pedra 2: Papel 3: Tesoura
	
	int jog1, jog2;
	
	printf("[1] PEDRA\n");
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
	


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



	
	
	
	
	return 0;
}
