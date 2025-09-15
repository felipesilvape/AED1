// FELIPE PEREIRA SILVA - ARLINDO - AED1
//188204

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;

    scanf("%d", &N);
    int X[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    int *menor = &X[0];
    for(int i = 0; i < N; i++) {
        if(*menor > X[i]) {
            menor = &X[i];
        }
    }

    int *pos = menor;

    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", (int)(pos - X));

    return 0;
}