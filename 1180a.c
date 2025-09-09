// FELIPE PEREIRA SILVA - AED I - ARLINDO
//188204

#include <stdio.h>
 
int main() {
    int N, menor, pos;
    
    scanf("%d", &N);
    int X[N];
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    
    menor = X[0];
    pos = 0;
    
    for(int i = 1; i < N; i++) {
        if(menor > X[i]) {
            menor = X[i];
            pos = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);
 
    return 0;
}