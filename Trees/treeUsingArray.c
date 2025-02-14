// creation of binary tree using array
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* Nodeptr;

Nodeptr createNode(int data) {
    Nodeptr newNode = (Nodeptr)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Nodeptr insert(Nodeptr root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

Nodeptr createBinaryTree(int arr[], int n) {
    Nodeptr root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Nodeptr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    //int arr[] = {8,5,1,7,10,12};
    int arr[] = {45, 23, 15, 12, 36, 25, 39, 52, 55, 59, 93, 89, 76, 65};
    int n = sizeof(arr) / sizeof(arr[0]);
    Nodeptr root = createBinaryTree(arr, n);

    printf("Inorder traversal of the binary tree is:\n");
    inorder(root);

    return 0;
}

