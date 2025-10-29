#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *n;
    int *resultado;

    // Alocação para n e resultado
    n = (int *)malloc(sizeof(int));
    resultado = (int *)malloc(sizeof(int));
    
    if (n == NULL || resultado == NULL) {
        printf("Erro de alocação\n");
        return 1;
    }
    scanf("%d", n);


    for (int a = 0; a < *n; a++) {
        int ***matriz;

        matriz = (int ***)malloc(sizeof(int **));
        *matriz = (int **)malloc(9 * sizeof(int *));
        
        if (matriz == NULL || *matriz == NULL) {
            printf("Erro de alocação\n");
            return 1;
        }
    
        for(int i = 0; i < 9; i++) {
            (*matriz)[i] = (int *)malloc(9 * sizeof(int));
            if ((*matriz)[i] == NULL) {
                printf("Erro de alocação\n");
            return 1;
            }
        }
    
        //Arrays para verificação com ponteiros
        int *linhas = (int *)malloc(9 * sizeof(int));
        int *colunas = (int *)malloc(9 * sizeof(int));
        int *square = (int *)malloc(9 * sizeof(int));
        
        if (linhas == NULL || colunas == NULL || square == NULL) {
            printf("Erro de alocação\n");
            return 1;
        }

        *resultado = 1; //Reinicia para instância

        // Lê a matriz
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                scanf("%d", &(*matriz)[i][j]);
            }
        }

        // Verifica linhas
        for (int i = 0; i < 9 && *resultado; i++){
            for (int m = 0; m < 9; m++) linhas[m] = 0;
            for (int j = 0; j < 9 && *resultado; j++){
                int num = (*matriz)[i][j] - 1;
                if (num < 0 || num >= 9 || linhas[num] == 1) {
                    *resultado = 0;
                } else {
                    linhas[num] = 1;
                }
            }
        }

        // Verifica colunas
        for (int j = 0; j < 9 && *resultado; j++){
            for (int m = 0; m < 9; m++) colunas[m] = 0;
            for (int i = 0; i < 9 && *resultado; i++){
                int num = (*matriz)[i][j] - 1;
                if (num < 0 || num >= 9 || colunas[num] == 1) {
                    *resultado = 0;
                } else {
                    colunas[num] = 1;
                }
            }
        }

        // Verifica quadrados 3x3
        for (int linha = 0; linha < 9 && *resultado; linha += 3){
            for (int coluna = 0; coluna < 9 && *resultado; coluna += 3){
                for (int m = 0; m < 9; m++) square[m] = 0;
                for (int i = 0; i < 3 && *resultado; i++){
                    for (int j = 0; j < 3 && *resultado; j++){
                        int num = (*matriz)[linha + i][coluna + j] - 1;
                        if (num < 0 || num >= 9 || square[num] == 1) {
                            *resultado = 0;
                        } else {
                            square[num] = 1;
                        }
                    }
                }
            }
        }

        //Imprime resultado
        if (*resultado == 1){
            printf("Instancia %d\nSIM\n\n", a + 1);
        } else {
            printf("Instancia %d\nNAO\n\n", a + 1);
        }

        //Libera memória
        free(linhas);
        free(colunas);
        free(square);
        
        for (int i = 0; i < 9; i++){
            free((*matriz)[i]);
        }
        free(*matriz);
        free(matriz);
    }

    free(n);
    free(resultado);
    return 0;
}