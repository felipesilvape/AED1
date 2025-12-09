#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 255
#define INF 0x3f3f3f3f // Infinito seguro

int adj[MAX_N][MAX_N];
int dist[MAX_N];
int visitado[MAX_N];
int N, M, C, K;

int dijkstra() {
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    dist[K] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;
        int min_val = INF;

        for (int j = 0; j < N; j++) {
            if (!visitado[j] && dist[j] < min_val) {
                min_val = dist[j];
                u = j;
            }
        }

        if (u == -1 || min_val == INF) break;
        
        visitado[u] = 1;
        
        if (u == C - 1) return dist[u];
        if (u < C - 1) {
            int v = u + 1;
            if (adj[u][v] != INF && !visitado[v]) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        } 
        else if (u >= C) {
            // Posso ir para qualquer vizinho
            for (int v = 0; v < N; v++) {
                if (adj[u][v] != INF && !visitado[v]) {
                    if (dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                    }
                }
            }
        }
    }

    return dist[C - 1];
}

int main() {
    while (scanf("%d %d %d %d", &N, &M, &C, &K)) {
        if (N == 0 && M == 0 && C == 0 && K == 0) break;

        // Limpa matriz de adjacência
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = INF;
            }
        }

        // Leitura das estradas
        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            
            if (w < adj[u][v]) { // Garante pegar o menor peso se houver arestas repetidas
                adj[u][v] = w;
                adj[v][u] = w;
            }
        }

        printf("%d\n", dijkstra());
    }

    return 0;
}