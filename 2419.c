#include <stdio.h>
#include <string.h>

#define MAX 1005 

char mapa[MAX][MAX]; 

int main() {
    int M, N; // M linhas, N colunas
    if (scanf("%d %d", &M, &N) != 2) return 0;

    memset(mapa, '.', sizeof(mapa));

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            scanf(" %c", &mapa[i][j]);
        }
    }

    int counter = 0;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            // Se for terra
            if(mapa[i][j] == '#') {
                if (mapa[i-1][j] == '.' || // Cima
                    mapa[i+1][j] == '.' || // Baixo
                    mapa[i][j-1] == '.' || // Esquerda
                    mapa[i][j+1] == '.')   // Direita
                {
                    counter++;
                }
            }
        }
    }
    printf("%d\n", counter);

    return 0;
}