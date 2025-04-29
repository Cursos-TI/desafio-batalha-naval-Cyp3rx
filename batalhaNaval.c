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

    // Navio horizontal 
    for (int j = 0; j < 3; j++) {
        tabuleiro[1][j] = '3';
    }

    // Navio vertical 
    for (int i = 4; i < 7; i++) {
        tabuleiro[i][5] = '3';
    }

    // Navio diagonal principal ↘ 
    for (int i = 6; i < 9; i++) {
        tabuleiro[i][i] = '3';
    }

    // Novo navio diagonal secundária ↙ 
    tabuleiro[0][9] = '3';
    tabuleiro[1][8] = '3';
    tabuleiro[2][7] = '3';

    // Imprimir o cabeçalho
    printf("   ");
    for (int j = 0; j < COLUNAS; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    // Imprimir o tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
