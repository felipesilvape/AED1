#include <stdio.h>
#define N 9

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int k = 1; k <= n; k++) {
        int matriz[N][N];
        char resul[4] = "SIM";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (scanf("%d", &matriz[i][j]) != 1) {
                    matriz[i][j] = 0;
                }
            }
        }



    }

    return 0;
}