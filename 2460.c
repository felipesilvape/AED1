#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Stack;

void enfileirar(Stack* fila, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    
    if(fila->inicio == NULL) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

void removerValor(Stack* fila, int valorAlvo) {
    if(fila->inicio == NULL) return;
    
    No* atual = fila->inicio;
    No* anterior = NULL;
    
    while(atual != NULL) {
        if(atual->valor == valorAlvo) {
            if(anterior == NULL) {
                fila->inicio = atual->proximo;
                if(fila->fim == atual) fila->fim = NULL;
            } else {
                anterior->proximo = atual->proximo;
                if(fila->fim == atual) fila->fim = anterior;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void imprimirFila(No* inicio) {
    if(inicio == NULL) return;
    if(inicio->proximo != NULL) {
        printf("%d ", inicio->valor);
    } else {
        printf("%d\n", inicio->valor);
    }
    imprimirFila(inicio->proximo);
}

void liberarFila(Stack* fila) {
    No* atual = fila->inicio;
    while(atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}
 
int main() {
    Stack fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    
    int quantidade;
    scanf("%d", &quantidade);
    while (quantidade--) {
        int numero;
        scanf("%d", &numero);
        enfileirar(&fila, numero);
    }
    
    scanf("%d", &quantidade);
    while (quantidade--) {
        int numero;
        scanf("%d", &numero);
        removerValor(&fila, numero);
    }
    
    imprimirFila(fila.inicio);
    liberarFila(&fila);
    
    return 0;
}