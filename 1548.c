#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

int main() {
    int numCasos;
    scanf("%d", &numCasos);
    
    while(numCasos--) {
        int numAlunos;
        scanf("%d", &numAlunos);
        
        int* notasOriginais = (int*)malloc(numAlunos * sizeof(int));
        int* notasOrdenadas = (int*)malloc(numAlunos * sizeof(int));
        
        for (int i = 0; i < numAlunos; i++) {
            scanf("%d", &notasOriginais[i]);
            notasOrdenadas[i] = notasOriginais[i];
        }
        
        selectionSort(notasOrdenadas, numAlunos);
        
        int count = 0;
        for (int i = 0; i < numAlunos; i++) {
            if (notasOriginais[i] == notasOrdenadas[i]) {
                count++;
            }
        }
        
        printf("%d\n", count);
        free(notasOriginais);
        free(notasOrdenadas);
    }
 
    return 0;
}