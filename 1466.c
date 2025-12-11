#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

No* criarNo(int v) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = v;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

No* inserir(No* raiz, int v) {
    if(raiz == NULL) return criarNo(v);

    if(v < raiz->valor) {
        raiz->esq = inserir(raiz->esq, v);
    } else {
        raiz->dir = inserir(raiz->dir, v);
    }

    return raiz;
}

void bfs(No* raiz) {
    if(raiz == NULL) return;

    /* Desenho mental:
         10
        /  \
      20    30
    */
    No* fila[1000];  // O banco de espera (cadeiras vazias)
    int frente = 0; // O painel que chama a senha
    int tras = 0;   // Onde as novas senhas são geradas

    fila[tras] = raiz; // Coloca o 10 na cadeira 0
    tras++;            // Próxima vaga livre é a cadeira 1

    int primeiro = 1; // Resolve os problemas de espaço do Beecrowd

    while (frente < tras) {
        No* atual = fila[frente]; // Pega o 10 da posição 0
        frente++;                 // Painel muda para 1. (10 já era!)

        // IMPRESSÃO sem espaço no final (logica do primeiro)
        if(primeiro) {
            printf("%d", atual->valor);
            primeiro = 0;
        } else {
            printf(" %d", atual->valor);
        }

        if(atual->esq != NULL) {
            fila[tras] = atual->esq; // Põe 20 na cadeira 1
            tras++;                  // Próxima vaga: cadeira 2
        }
        if(atual->dir != NULL) {
            fila[tras] = atual->dir; // Põe 30 na cadeira 2
            tras++;                  // Próxima vaga: cadeira 3
        }
    }
    printf("\n");
}

void liberar(No* raiz) {
    if(raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}


int main() {
    int N, C, valor;

    scanf("%d", &C);

    for(int i = 1; i <= C; i++) {
        scanf("%d", &N);
        No* arvore = NULL;

        for(int j = 0; j < N; j++) {
            scanf("%d", &valor);
            arvore = inserir(arvore, valor);
        }

        printf("Case %d:\n", i);
        bfs(arvore);
        printf("\n");

        liberar(arvore);
    }
    return 0;
}