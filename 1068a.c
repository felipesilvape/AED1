#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cria um nó
typedef struct No {
    char caractere;
    struct No* proximo;
} No;

//definir pilha
typedef struct {
    No* topo;
} Pilha;

//funcao para criar pilha
Pilha* criar_pilha() {
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    nova_pilha->topo = NULL;
    return nova_pilha;
}

//funcao para empilhar
void empilhar(Pilha* pilha, char caractere) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->caractere = caractere;
    novo_no->proximo = pilha->topo;
    pilha->topo = novo_no;
}

//funcao para desempilhar
void desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        return;
    }
    No* no_remover = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(no_remover);
}

//funcao para verificar balanceamento
int verificar_balanceamento(char* expressao) {
    Pilha* pilha = criar_pilha();

    for (int i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(') {
            empilhar(pilha, '(');
        }
        else if (expressao[i] == ')') {
            if (pilha->topo == NULL) {
                while (pilha->topo != NULL) {
                    desempilhar(pilha);
                }
                free(pilha);
                return 0;
            }
            else {
                desempilhar(pilha);
            }
        }
    }
    
    int resultado = (pilha->topo == NULL) ? 1 : 0;
    
    while (pilha->topo != NULL) {
        desempilhar(pilha);
    }

    free(pilha);
    return resultado;
}

int main() {
    char *expressao = NULL;
    size_t size = 0;
    size_t read;

    while((read = getline(&expressao, &size, stdin)) != -1) {
        if(read > 0 && expressao[read - 1] == '\n') {
            expressao[read - 1] = '\0';
        }

        if(check_string(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    free(expressao);
    return 0;
}