#include <stdio.h>
#include <string.h>

void contar_digitos(int n, int *contagem) {
    if (n == 0) return;

    long long p = 1;

    while (p <= n) {
        int esquerda = n / (p * 10);
        int resto = n % (p * 10);
        int digito_atual = resto / p;
        int direita = resto % p;

        for (int d = 0; d < 10; d++) {
            contagem[d] += esquerda * p;

            if (d == 0) {
                contagem[d] -= p;
            }

            if (digito_atual > d) {
                contagem[d] += p;
            } else if (digito_atual == d) {
                contagem[d] += direita + 1;
            }
        }

        p *= 10;
    }
}

int main() {
    int A, B;

    while (scanf("%d %d", &A, &B) && (A || B)) {
        if (A > B) {
            int temp = A; A = B; B = temp;
        }

        int contagemA[10] = {0};
        int contagemB[10] = {0};

        contar_digitos(B, contagemB);
        contar_digitos(A - 1, contagemA);

        // Imprime o resultado (B - A)
        for (int i = 0; i < 10; i++) {
            printf("%d%s", contagemB[i] - contagemA[i], (i == 9) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}