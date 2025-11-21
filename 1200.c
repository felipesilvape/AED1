#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OUTPUT 1000 // Buffer para garantir a formatação da saída

typedef struct node {
    char value;
    struct node *left;
    struct node *right;
} Node;

char output_buffer[MAX_OUTPUT];
int output_index;

Node* newNode(char val) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) exit(1);
    novoNo->value = val;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return novoNo;
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

Node* insert(Node* root, char val) {
    if (root == NULL) {
        return newNode(val);
    }
    
    if (val < root->value) {
        root->left = insert(root->left, val);
    } else if (val > root->value) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Busca um caractere na ABB (P n)
int search(Node* root, char val) {
    if (root == NULL) return 0;
    if (root->value == val) return 1;
    
    if (val < root->value) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// Adiciona o caractere ao buffer, com espaço antes se não for o primeiro.
void buffer_char(char val) {
    if (output_index > 0) {
        output_buffer[output_index++] = ' ';
    }
    output_buffer[output_index++] = val;
}

// InOrder (INFIXA)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        buffer_char(root->value);
        inOrder(root->right);
    }
}

// PreOrder (PREFIXA)
void preOrder(Node* root) {
    if (root != NULL) {
        buffer_char(root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// PostOrder (POSFIXA)
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        buffer_char(root->value);
    }
}

int main() {
    char comando[10]; 
    char valor;
    Node* root = NULL;

    while (scanf("%s", comando) != EOF) {
        
        if (strcmp(comando, "I") == 0) {
            // Insere. ' %c' garante que caracteres de espaço/nova linha sejam ignorados.
            if (scanf(" %c", &valor) == 1) {
                root = insert(root, valor);
            }
        
        } else if (strcmp(comando, "P") == 0) {
            // Busca. ' %c' garante que o valor seja lido corretamente.
            if (scanf(" %c", &valor) == 1) {
                if (search(root, valor)) {
                    printf("%c existe\n", valor);
                } else {
                    printf("%c nao existe\n", valor);
                }
            }
        
        } else if (strcmp(comando, "INFIXA") == 0) {
            output_index = 0;
            inOrder(root);
            output_buffer[output_index] = '\0'; // Encerra a string
            printf("%s\n", output_buffer); // Impressão segura
        
        } else if (strcmp(comando, "PREFIXA") == 0) {
            output_index = 0;
            preOrder(root);
            output_buffer[output_index] = '\0';
            printf("%s\n", output_buffer);
        
        } else if (strcmp(comando, "POSFIXA") == 0) {
            output_index = 0;
            postOrder(root);
            output_buffer[output_index] = '\0';
            printf("%s\n", output_buffer);
        }
    }

    freeTree(root);
    return 0;
}