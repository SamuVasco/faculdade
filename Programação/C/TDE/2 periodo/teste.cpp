#include <stdio.h>

int main(){
	
	int a[2][3], b[3][4], r[2][4] = {0};
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			printf("elemento[%i][%i]: ", i, j);
			scanf("%i", &a[i][j]);
		}
	}
	
	printf("\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			printf("elemento[%i][%i]: ", i, j);
			scanf("%i", &b[i][j]);
		}
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 3; k++){
				r[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
	printf("\n");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			printf("%i ", r[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}


