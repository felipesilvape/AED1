#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore binária
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na árvore BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Percursos da árvore
void preOrder(Node* root) {
    if (root != NULL) {
        printf(" %d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d", root->data);
    }
}

// Função para liberar a memória da árvore
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int C, N, value;
    scanf("%d", &C);
    
    for (int caseNum = 1; caseNum <= C; caseNum++) {
        Node* root = NULL;
        
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &value);
            root = insert(root, value);
        }
        
        printf("Case %d:\n", caseNum);
        
        printf("Pre.:");
        preOrder(root);
        printf("\n");
        
        printf("In..:");
        inOrder(root);
        printf("\n");
        
        printf("Post:");
        postOrder(root);
        printf("\n\n");
        
        // Liberar memória para o próximo caso
        freeTree(root);
    }
    
    return 0;
}