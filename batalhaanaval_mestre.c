#include <stdio.h>

#define LINHA 10
#define NAVIO 3
#define AGUA 0
#define EFEITO 5

void inicializarTabuleiro(int tabuleiro[LINHA][LINHA]) {
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < LINHA; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}
void imprimirTabuleiro(int tabuleiro[LINHA][LINHA]) {
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < LINHA; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


void aplicarHabilidade(int tabuleiro[LINHA][LINHA], int habilidade[5][5], int x, int y) {
    int offset = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int nx = x + i - offset;
            int ny = y + j - offset;
            if (nx >= 0 && nx < LINHA && ny >= 0 && ny < LINHA && habilidade[i][j] == 1) {
                tabuleiro[nx][ny] = EFEITO;
            }
        }
    }
}
void criarCone(int habilidade[5][5]) {
    int padrao[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = padrao[i][j];
}
void criarCruz(int habilidade[5][5]) {
    int padrao[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = padrao[i][j];
}
void criarOctaedro(int habilidade[5][5]) {
    int padrao[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = padrao[i][j];
}

int main() {
    int tabuleiro[LINHA][LINHA];
    inicializarTabuleiro(tabuleiro);
    
 
    tabuleiro[4][4] = NAVIO;
    tabuleiro[5][4] = NAVIO;
    tabuleiro[6][4] = NAVIO;

    int cone[5][5], cruz[5][5], octaedro[5][5];
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    

    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 7);
    aplicarHabilidade(tabuleiro, octaedro, 7,2 );
    
  
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}
