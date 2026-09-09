#include <stdio.h> 

//6. Pergunte ao usuário a quantidade de vitórias, empates e derrotas do time de futebol
//dele. Através de uma função informe ao usuário o número de pontos do time dele,
//considerando a vitória do time 3 pontos, o empate 1 ponto e a derrota não concede
//pontos. Com os pontos, crie uma função que retorne a média de pontos por jogo do time dele.

int calcular_pontos(int v, int e);
float media(float pontos, float jogos);

int main(){
	
	int vitorias, empates, derrotas, pontos, jogos;
	float m;
	
	printf("vitorias: ");
	scanf("%i", &vitorias);
	
	printf("empates: ");
	scanf("%i", &empates);
	
	pontos = calcular_pontos(vitorias, empates);
	
	printf("derrotas: ");
	scanf("%i", &derrotas);
	
	// descobrir quantidade de jogos
	jogos = vitorias + empates + derrotas;
	printf("\nJogos: %i\n", jogos);
	
	printf("\nPontos: %i\n", pontos);
	
	m = media(pontos, jogos);
	
	printf("\nMedia de pontos por jogo: %.1f", m);
	
	return 0;
}

int calcular_pontos(int v, int e){
	return (v * 3) + e;
}

float media(float pontos, float jogos){
	return pontos / jogos;
}
