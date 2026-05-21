#include <stdio.h>
#include <locale.h>

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int x, fatorial, i = 1, f = 1;
	
	printf("Digite um número: ");
	scanf("%i", &x);
	
	printf("Calculando %i! : ", x);
	
		
	for (i = x ; i > 0 ; i--){
		
		printf("%i", i);
		
		if(i > 1){
			printf(" x ");
		}else {
			printf(" = ");
		}
		
		f *= i;
	}
	printf("%i", f);
	
	
	return 0;
}
