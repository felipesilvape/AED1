#include <stdio.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f // Infinito
#define MAX_C 10005
#define MAX_E 100005

int head[MAX_C];
int to[MAX_E];
int next[MAX_E];
int weight[MAX_E];
int edge_count = 0;

void add_edge(int u, int v, int w) {
    to[edge_count] = v;
    weight[edge_count] = w;
    next[edge_count] = head[u];
    head[u] = edge_count++;
}

typedef struct {
    int cost;
    int u;
    int parity; // 0 = Par, 1 = Ímpar
} Node;

Node heap[MAX_E * 2]; // Tamanho seguro para o heap
int heap_size = 0;

void push(int cost, int u, int parity) {
    int i = heap_size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].cost <= cost) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i].cost = cost;
    heap[i].u = u;
    heap[i].parity = parity;
}

Node pop() {
    Node ret = heap[0];
    Node x = heap[--heap_size];
    int i = 0;
    while (i * 2 + 1 < heap_size) {
        int child = i * 2 + 1;
        if (child + 1 < heap_size && heap[child + 1].cost < heap[child].cost) {
            child++;
        }
        if (heap[child].cost >= x.cost) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = x;
    return ret;
}

int dist[MAX_C][2]; 

int main() {
    int C, V;
    
    // Inicializa a lista de adjacência com -1
    for(int i = 0; i < MAX_C; i++) head[i] = -1;

    if (scanf("%d %d", &C, &V) != 2) return 0;

    for (int i = 0; i < V; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    // Inicializa distâncias com infinito
    for (int i = 1; i <= C; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    // Dijkstra
    dist[1][0] = 0;
    push(0, 1, 0);

    while (heap_size > 0) {
        Node current = pop();
        int d = current.cost;
        int u = current.u;
        int p = current.parity;

        // Se já encontramos um caminho melhor para esse estado, ignora
        if (d > dist[u][p]) continue;

        // Percorre os vizinhos
        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];
            int w = weight[e];
            int next_p = 1 - p; // Alterna a paridade (0->1, 1->0)

            if (dist[u][p] + w < dist[v][next_p]) {
                dist[v][next_p] = dist[u][p] + w;
                push(dist[v][next_p], v, next_p);
            }
        }
    }

    // O resultado é a distância para chegar em C com paridade PAR (0)
    int ans = dist[C][0];

    if (ans == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}