#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



int main() {
    FILE *arquivo;
    int ch;

    arquivo = fopen("saida.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    printf("Digite um texto e pressione Enter: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        putc(ch, arquivo);
    }

    fclose(arquivo);

    printf("Texto salvo com sucesso!\n");

    return 0;
}


