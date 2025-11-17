#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
    No* base;
} Stack;

typedef struct {
    No* inicio;
    No* fim;
} Queue;

void empilhar(Stack* pilha, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    
    if (pilha->base == NULL) {
        pilha->base = novoNo;
    }
}

void desenfileirar(Queue* fila) {
    if (fila->inicio == NULL) return;
    
    No* noRemovido = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(noRemovido);
}

void enfileirar(Queue* fila, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    
    if (fila->inicio == NULL) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

void removerCarta(Stack* pilha) {
    if (pilha->topo == NULL) return;
    
    No* noRemovido = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(noRemovido);

    if (pilha->topo != NULL && pilha->topo->proximo != NULL) {
        No* temp = pilha->topo;
        pilha->topo = pilha->topo->proximo;

        pilha->base->proximo = temp;
        pilha->base = temp;
        pilha->base->proximo = NULL;
    }
}

int main() {
    int numeroCartas;
    
    while (scanf("%d", &numeroCartas) == 1 && numeroCartas != 0) {
        Stack baralho = {NULL, NULL};
        
        // Preenche a pilha com as cartas em ordem decrescente
        for (int i = numeroCartas; i > 0; i--) {
            empilhar(&baralho, i);
        }
        
        Queue cartasDescartadas = {NULL, NULL};
        
        // Processa as cartas até sobrar apenas uma
        while (baralho.topo->proximo != NULL) {
            int carta = baralho.topo->valor;
            enfileirar(&cartasDescartadas, carta);
            removerCarta(&baralho);
        }
        
        // Imprime as cartas descartadas
        printf("Discarded cards: ");
        if (cartasDescartadas.inicio != NULL) {
            printf("%d", cartasDescartadas.inicio->valor);
            desenfileirar(&cartasDescartadas);
        }
        
        while (cartasDescartadas.inicio != NULL) {
            printf(", %d", cartasDescartadas.inicio->valor);
            desenfileirar(&cartasDescartadas);
        }
        
        printf("\nRemaining card: %d\n", baralho.topo->valor);
        removerCarta(&baralho);
    }
    
    return 0;
}