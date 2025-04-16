#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    char tabuleiro[LINHAS][COLUNAS];

    // Inicializar o tabuleiro 
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    // Posicionar navios com '3'

    // Navio na horizontal 
    for (int j = 0; j < 4; j++) {
        tabuleiro[1][j] = '3';
    }

    // Navio na vertical 
    for (int i = 4; i < 7; i++) {
        tabuleiro[i][5] = '3';
    }


    // Cabeçalho 
    printf("   ");
    for (int j = 0; j < COLUNAS; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    // Linhas 
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1); // número da linha
        for (int j = 0; j < COLUNAS; j++) {
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
