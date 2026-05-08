#include <stdio.h>
#include <locale.h>

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	do {
		printf("a");
	}while(1);
	
	return 0;
}
