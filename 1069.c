#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

// Definição da pilha
typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

// Operações da pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, char valor) {
    if (p->topo < MAX - 1) {
        p->dados[++p->topo] = valor;
    }
}

char pop(Pilha *p) {
    if (!esta_vazia(p)) {
        return p->dados[p->topo--];
    }
    return '\0';
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char linha[1001];
        scanf("%s", linha);
        
        Pilha pilha;
        inicializar(&pilha);
        int diamantes = 0;

        for (int i = 0; i < strlen(linha); i++) {
            if (linha[i] == '<') {
                push(&pilha, '<');  // empilha o '<'
            } else if (linha[i] == '>') {
                if (!esta_vazia(&pilha)) {
                    pop(&pilha);    // desempilha um '<'
                    diamantes++;
                }
            }
        }

        printf("%d\n", diamantes);
    }
    return 0;
}