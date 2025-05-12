#include <stdio.h>
#include <stdlib.h>  // para abs()

#define LINHAS 10
#define COLUNAS 10
#define TAM_HABILIDADE 5

int main() {
    char tabuleiro[LINHAS][COLUNAS];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializa tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    // Adiciona navios
    for (int j = 0; j < 3; j++) tabuleiro[1][j] = '3';           // Horizontal
    for (int i = 4; i < 7; i++) tabuleiro[i][5] = '3';           // Vertical
    for (int i = 6; i < 9; i++) tabuleiro[i][i] = '3';           // Diagonal principal
    tabuleiro[0][9] = '3'; tabuleiro[1][8] = '3'; tabuleiro[2][7] = '3'; // Diagonal secundária

    // Criar Cone
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Criar Cruz
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Criar Octaedro (losango)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Aplicar habilidades no tabuleiro (posição centralizada)
    int origemLinha, origemColuna;

    // Aplicar Cone em (2, 2)
    origemLinha = 2;
    origemColuna = 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + i - TAM_HABILIDADE / 2;
            int colTab = origemColuna + j - TAM_HABILIDADE / 2;
            if (linhaTab >= 0 && linhaTab < LINHAS && colTab >= 0 && colTab < COLUNAS) {
                if (cone[i][j] == 1 && tabuleiro[linhaTab][colTab] == '0') {
                    tabuleiro[linhaTab][colTab] = '5';
                }
            }
        }
    }

    // Aplicar Cruz em (5, 5)
    origemLinha = 5;
    origemColuna = 5;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + i - TAM_HABILIDADE / 2;
            int colTab = origemColuna + j - TAM_HABILIDADE / 2;
            if (linhaTab >= 0 && linhaTab < LINHAS && colTab >= 0 && colTab < COLUNAS) {
                if (cruz[i][j] == 1 && tabuleiro[linhaTab][colTab] == '0') {
                    tabuleiro[linhaTab][colTab] = '5';
                }
            }
        }
    }

    // Aplicar Octaedro em (8, 8)
    origemLinha = 8;
    origemColuna = 8;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + i - TAM_HABILIDADE / 2;
            int colTab = origemColuna + j - TAM_HABILIDADE / 2;
            if (linhaTab >= 0 && linhaTab < LINHAS && colTab >= 0 && colTab < COLUNAS) {
                if (octaedro[i][j] == 1 && tabuleiro[linhaTab][colTab] == '0') {
                    tabuleiro[linhaTab][colTab] = '5';
                }
            }
        }
    }

    // Imprimir cabeçalho
    printf("   ");
    for (int j = 0; j < COLUNAS; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    // Imprimir tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
