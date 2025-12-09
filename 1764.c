#include <stdio.h>
#include <stdlib.h>

#define MAX_M 40005 // Vértices (Cidades)
#define MAX_N 50005 // Arestas (Rotas)

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX_N];
int parent[MAX_M];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

int join(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    
    if (root_i != root_j) {
        parent[root_i] = root_j; // Conecta as raízes
        return 1; // Sucesso: eram conjuntos separados
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int main() {
    int M, N;

    while (scanf("%d %d", &M, &N) && (M || N)) {
        
        for (int i = 0; i < M; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        }

        qsort(edges, N, sizeof(Edge), compare);

        int totalWeight = 0;
        int edgesCount = 0; // Contador para parar cedo se a árvore estiver completa

        for (int i = 0; i < N; i++) {
            // Tenta unir. Se retornar 1, somamos o peso.
            if (join(edges[i].u, edges[i].v)) {
                totalWeight += edges[i].weight;
                edgesCount++;
            }
            
            if (edgesCount == M - 1) break; 
        }
        printf("%d\n", totalWeight);
    }

    return 0;
}