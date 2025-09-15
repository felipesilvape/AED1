//FELIPE PEREIRA SILVA - AED1 - ARLINDO
//188204

#include<stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    for(int a = 1; a <= N; a++){
        int linha[9][9] = {0};
        int coluna[9][9] = {0};
        int square[9][9] = {0};
        int valid = 1;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9;j++){
                int num;
                scanf("%d", &num);
                num--;
                if(linha[i][num] == 1)valid = 0;
                if(coluna[j][num] == 1)valid = 0;
                int q = (i / 3) * 3 + (j / 3);
                if(square[q][num] == 1)valid = 0;
                square[q][num] = 1;
                linha[i][num] = 1;
                coluna[j][num] = 1;
            }
        }
        printf("Instancia %d\n", a);
        if(valid){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    return 0;
}