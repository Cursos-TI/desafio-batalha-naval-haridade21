#include <stdio.h>

void exibirTabuleiro(int tabuleiro[10][10]) {

    printf("  0 1 2 3 4 5 6 7 8 9\n");

   
    for (int i = 0; i < 10; i++) {
        printf("%c ", 'A' + i);  
        
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
   
    int tabuleiro[10][10] = {0};


    for (int i = 0; i < 3; i++) {
        tabuleiro[9][3 + i] = 3;
    }


    for (int i = 0; i < 3; i++) {
        tabuleiro[5 + i][9] = 3;
    }
    
    for (int i = 0; i < 1; i++) {
        tabuleiro[5 + i][1] = 3;
    }
    
    for (int i = 0; i < 1; i++) {
        tabuleiro[6 + i][2] = 3;
    }

    for (int i = 0; i < 1; i++) {
        tabuleiro[7 + i][3] = 3;
    }

    for (int i = 0; i < 1; i++) {
        tabuleiro[5 + i][7] = 3;
    }

    for (int i = 0; i < 1; i++) {
        tabuleiro[6 + i][6] = 3;
    }

    for (int i = 0; i < 1; i++) {
        tabuleiro[7 + i][5] = 3;
    }





    exibirTabuleiro(tabuleiro);

    return 0;
}