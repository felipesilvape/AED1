#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 505
#define INF 0x3f3f3f3f // Infinito

int adj[MAX_N][MAX_N];
int dist[MAX_N];
int visitado[MAX_N];
int N, E;

int dijkstra(int origem, int destino) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }

    dist[origem] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;
        int min_val = INF;

        // Encontrar o vértice não visitado com menor distância
        for (int j = 1; j <= N; j++) {
            if (!visitado[j] && dist[j] < min_val) {
                min_val = dist[j];
                u = j;
            }
        }

        if (u == -1 || dist[u] == INF) break;
        if (u == destino) return dist[u];

        visitado[u] = 1;

        for (int v = 1; v <= N; v++) {
            if (adj[u][v] != INF && !visitado[v]) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }

    return dist[destino];
}

int main() {
    int K, x, y, h;

    while (scanf("%d %d", &N, &E)) {
        if (N == 0 && E == 0) break;

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                adj[i][j] = INF;
            }
        }

        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &x, &y, &h);
            adj[x][y] = h; // Grafo direcionado
            
            if (adj[y][x] != INF) {
                adj[x][y] = 0;
                adj[y][x] = 0;
            }
        }

        scanf("%d", &K);
        while (K--) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);

            int resultado = dijkstra(origem, destino);

            if (resultado == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", resultado);
            }
        }
        printf("\n"); // Linha em branco após cada caso de teste
    }

    return 0;
}