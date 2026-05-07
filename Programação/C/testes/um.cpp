#include <stdio.h>
#include <locale.h>

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int i, j;
	
	for(i = 0; i <= 6; i++){
		if(i % 2 == 0){
			printf("%i ", i);
		}
	}
	
	return 0;
}
