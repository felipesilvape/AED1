#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11000 

int dist[MAX];
int visited[MAX];
int queue[MAX];
int visit_token = 0;

int reverse(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}

int bfs(int start, int target) {
    if (start == target) return 0;
    
    int front = 0, rear = 0;
    
    // Configuração inicial
    queue[rear++] = start;
    dist[start] = 0;
    visited[start] = visit_token; // Marca como visitado NESTA geração
    
    while (front < rear) {
        int current = queue[front++];
        
        // Calculamos os dois possíveis próximos estados
        int next_moves[2];
        next_moves[0] = current + 1;
        next_moves[1] = reverse(current);
        
        for(int i = 0; i < 2; i++) {
            int next = next_moves[i];
            
            if (next < MAX && visited[next] != visit_token) {
                visited[next] = visit_token; // Atualiza para a geração atual
                dist[next] = dist[current] + 1;
                
                if (next == target) return dist[next];
                
                queue[rear++] = next;
            }
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    memset(visited, 0, sizeof(visited));
    
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
    
        visit_token++; 
        printf("%d\n", bfs(A, B));
    }
    
    return 0;
}