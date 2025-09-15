#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // Alocação dinâmica das instâncias e verificação
    int *N = malloc(sizeof(int));
    if (N == NULL) return 1;
    if(scanf("%d", N) != 1) { free(N); return 1; }
    if(*N <= 0) { free(N); return 1; }

    // Criando uma instância para fazer a leitura de todos os tabuleiros
    int *inst = malloc(sizeof(int));
    if (inst == NULL) { free(inst); return 1; }
    *inst = 0;

    while (*inst < *N) {
        int linha [9 * 9] = {0};
        int coluna [9 * 9] = {0};
        int square [9 * 9] = {0};


    }


    free(N);
    free(inst);
    return 0;
}