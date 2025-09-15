//FELIPE PEREIRA SILVA - AED1 - ARLINDO
//188204

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // N alocado dinamicamente
    int *N = malloc(sizeof(int));
    scanf("%d", N);

    // Vetor dinâmico
    int *vetor = malloc((*N) * sizeof(int));
    if (vetor == NULL) { free(N); return 1; }

    int *ptr = vetor;                 
    int *end = vetor + (*N);          

    // leitura usando ponteiros
    while (ptr < end) {
        if (scanf("%d", ptr) != 1) { 
            free(vetor); free(N);
            return 1;
        }
        ptr++;
    }

    int *menor = vetor;             
    int *p = vetor + 1;       
    int *pos = malloc(sizeof(int));   
    if (pos == NULL) { free(vetor); free(N); return 1; }
    *pos = 0;

    for (; p < end; ++p) {
        if (*p < *menor) {
            menor = p;
            *pos = (int)(p - vetor);
        }
    }

    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", *pos);

    free(pos);
    free(vetor);
    free(N);
    return 0;
}