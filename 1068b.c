#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char caractere;
    struct No* proximo;
} No;

No* criar_pilha() {
    return NULL;
}

No* empilhar(No* topo, char caractere) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->caractere = caractere;
    novo_no->proximo = topo;  // Novo nó aponta para o antigo topo
    return novo_no;           // Retorna o novo topo
}

No* desempilhar(No* topo) {
    if (topo == NULL) {
        return NULL;
    }
    No* no_remover = topo;    
    No* novo_topo = topo->proximo;  
    free(no_remover);           
    return novo_topo;         
}

int pilha_vazia(No* topo) {
    return topo == NULL; 
}

void liberar_pilha(No* topo) {
    No* atual = topo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int verificar_balanceamento(char* expressao) {
    No* pilha = criar_pilha();  // Pilha é só o topo agora
    int i;
    
    for (i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(') {
            pilha = empilhar(pilha, '(');
        }
        else if (expressao[i] == ')') {
            if (pilha_vazia(pilha)) {
                liberar_pilha(pilha);  
                return 0;
            }
            else {
                pilha = desempilhar(pilha);
            }
        }
    }
    
    int resultado = (pilha_vazia(pilha)) ? 1 : 0;

    liberar_pilha(pilha);
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