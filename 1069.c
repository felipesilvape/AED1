#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char linha[1001]; // Armazenará a linha de entrada (máximo de 1000 caracteres)
        scanf("%s", linha); // Lê a linha com a sequência de caracteres

        int diamantes = 0;
        int pilha = 0;

        // Percorre cada caractere na sequência
        for (int i = 0; i < strlen(linha); i++) {
            if (linha[i] == '<') {
                pilha++;
            } else if (linha[i] == '>' && pilha > 0) {
                pilha--; // Retira um '<' da pilha, formando um diamante
                diamantes++; // Incrementa o contador de diamantes
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}