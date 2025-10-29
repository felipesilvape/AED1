#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Estrutura para representar uma pilha
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Funções para manipular a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (!cheia(p)) {
        p->dados[++(p->topo)] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (!vazia(p)) {
        return p->dados[(p->topo)--];
    }
    return -1;
}

int topo(Pilha *p) {
    if (!vazia(p)) {
        return p->dados[p->topo];
    }
    return -1;
}

int main() {
    int N;
    int objetivo[MAX];
    
    while (scanf("%d", &N) && N != 0) {
        
        while (1) {
            // Lê a primeira posição para verificar se é 0
            scanf("%d", &objetivo[0]);
            if (objetivo[0] == 0) {
                printf("\n");
                break;
            }
            
            for (int i = 1; i < N; i++) {
                scanf("%d", &objetivo[i]);
            }
            
            Pilha estacao;
            inicializar(&estacao);
            int proximo = 1; 
            int possivel = 1; 
            
            for (int i = 0; i < N; i++) {
                int vagaoDesejado = objetivo[i];
                
                // Empilha vagões até encontrar o vagão desejado
                while (proximo <= N && (vazia(&estacao) || topo(&estacao) != vagaoDesejado)) {
                    empilhar(&estacao, proximo);
                    proximo++;
                }
                
                // Se o topo da pilha é o vagão desejado, desempilha
                if (!vazia(&estacao) && topo(&estacao) == vagaoDesejado) {
                    desempilhar(&estacao);
                } else {
                    possivel = 0;
                    break;
                }
            }
            
            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    
    return 0;
}