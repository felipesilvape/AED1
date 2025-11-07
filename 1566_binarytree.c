#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* novoNo(int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = valor;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return novoNo;
}

Node* insert(Node* root, int valor) {
    if (root == NULL) {
        return novoNo(valor);
    }

    if (valor < root->data) {
        root->left = insert(root->left, valor);
    } else {
        root->right = insert(root->right, valor);
    }
    return root;
}

void inOrder(Node* root, int* first) {
    if (root != NULL) {
        inOrder(root->left, first);

        if(!(*first)) {
            printf(" ");
            *first = 0;
        } else {
            *first = 0;
        }

        printf("%d", root->data);
        inOrder(root->right, first);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }    
}

int main() {
    int numCase;
    scanf("%d", &numCase);

    while(numCase--) {  
        int qnt;   
        scanf("%d", &qnt);
        Node* root = NULL;
        int alt;

        for (int j = 0; j < qnt; j++) {
            scanf("%d", &alt);
            root = insert(root, alt);
        }

        int first = 1;    
        inOrder(root, &first);
        printf("\n");

        freeTree(root);
    }

    return 0;
}