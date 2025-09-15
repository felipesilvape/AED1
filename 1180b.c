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

    int *ptr = vetor;                 // iterador começando no primeiro elemento
    int *end = vetor + (*N);          // ponteiro para "uma-passa-além" do último

    // leitura usando ponteiros
    while (ptr < end) {
        if (scanf("%d", ptr) != 1) {  // lê direto para onde ptr aponta
            free(vetor); free(N);
            return 1;
        }
        ptr++; // avançar para a próxima posição
    }

    int *menor = vetor;               // aponta para o menor (começa no primeiro)
    int *p = vetor + 1;               // percorre do segundo elemento até end
    int *pos = malloc(sizeof(int));   // armazena posição em memória alocada
    if (pos == NULL) { free(vetor); free(N); return 1; }
    *pos = 0;                         // começa com posição 0

    for (; p < end; ++p) {
        if (*p < *menor) {
            menor = p;
            *pos = (int)(p - vetor); // diferença de ponteiros -> índice
        }
    }

    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", *pos);

    free(pos);
    free(vetor);
    free(N);
    return 0;
}