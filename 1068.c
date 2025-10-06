#include <stdio.h>
#include <string.h>

int main() {
    char expression[1002];  // Buffer para armazenar cada expressão (até 1000 chars + \n + \0)
    int balance;

    while (fgets(expression, sizeof(expression), stdin)) {
        balance = 0;  // Reinicia o contador para cada nova expressão
        int len = strlen(expression);
        
        // Remove o caractere de nova linha (\n) se presente
        if (len > 0 && expression[len - 1] == '\n') {
            expression[len - 1] = '\0';
        }

        int correct = 1;

        for (int i = 0; expression[i] != '\0'; i++) {
            if (expression[i] == '(') {
                balance++;  // Encontrou um parêntese de abertura - incrementa o contador
            } else if (expression[i] == ')') {
                balance--;  // Encontrou um parêntese de fechamento - decrementa o contador
                
                // Se o contador ficar negativo, há um fechamento sem abertura correspondente
                if (balance < 0) {
                    correct = 0;
                    break;
                }
            }
        }

        if (balance != 0) {
            correct = 0;
        }

        if (correct) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}