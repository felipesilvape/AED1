#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200005 

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX_N];
int parent[MAX_N];

// Função Find com Compressão de Caminho (Essencial)
int find(int i) {
    if (parent[i] == i)
        return i;
    // Atualiza o pai recursivamente para achatar a árvore
    return parent[i] = find(parent[i]);
}

int unionSets(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    
    if (root_i != root_j) {
        parent[root_i] = root_j; // Uniu
        return 1; // Sucesso
    }
    return 0; 
}

int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int main() {
    int M, N; // M = Vértices, N = Arestas
    
    while (scanf("%d %d", &M, &N) && (M || N)) {
        for (int i = 0; i < M; i++) {
            parent[i] = i;
        }

        int totalGraphWeight = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
            totalGraphWeight += edges[i].weight;
        }

        qsort(edges, N, sizeof(Edge), compareEdges);

        int mstWeight = 0;
        int edgesCount = 0;

        // Kruskal
        for (int i = 0; i < N; i++) {
            // Tenta unir. Se retornar 1, é porque são de comp. diferentes
            if (unionSets(edges[i].u, edges[i].v)) {
                mstWeight += edges[i].weight;
                edgesCount++;
            }
            // Pequena otimização: Se já temos M-1 arestas, a MST está completa
            if (edgesCount == M - 1) break;
        }

        printf("%d\n", totalGraphWeight - mstWeight);
    }
    return 0;
}