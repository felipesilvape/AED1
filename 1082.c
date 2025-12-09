#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

int adj[MAX][MAX];
int visitado[MAX];
int V, E;

int compare(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

void dfs(int u, char *buffer, int *tam) {
    visitado[u] = 1;
    buffer[(*tam)++] = u + 'a';

    for (int v = 0; v < V; v++) {
        // Se existe aresta E não foi visitado
        if (adj[u][v] && !visitado[v]) {
            dfs(v, buffer, tam);
        }
    }
}

int main() {
    int testes;
    scanf("%d", &testes);

    for (int caso = 1; caso <= testes; caso++) {
        scanf("%d %d", &V, &E);

        memset(adj, 0, sizeof(adj));
        memset(visitado, 0, sizeof(visitado));

        // Leitura das arestas
        for (int i = 0; i < E; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            adj[u - 'a'][v - 'a'] = 1;
            adj[v - 'a'][u - 'a'] = 1; // Grafo não direcionado
        }

        printf("Case #%d:\n", caso);

        int componentes = 0;
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                char buffer[MAX]; // Armazena os nós do componente atual
                int tam = 0;
                
                dfs(i, buffer, &tam);
                qsort(buffer, tam, sizeof(char), compare);

                // Imprime
                for (int j = 0; j < tam; j++) {
                    printf("%c,", buffer[j]);
                }
                printf("\n");
                componentes++;
            }
        }
        
        printf("%d connected components\n\n", componentes);
    }

    return 0;
}