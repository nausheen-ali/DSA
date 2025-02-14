#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int leftThread;
    int rightThread;
};

typedef struct Node* Nodeptr;

// Function to create a new node
Nodeptr createNode(int data) {
    Nodeptr newNode = (Nodeptr)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->leftThread = newNode->rightThread = 1;
    return newNode;
}

// Function to insert a node into the double-threaded binary tree
Nodeptr insert(Nodeptr root, int data) {
    Nodeptr ptr = root;
    Nodeptr parent = NULL;

    // Find the parent node
    while (ptr != NULL) {
        if (data == ptr->data) {
            printf("Duplicate key!\n");
            return root;
        }
        parent = ptr;
        if (data < ptr->data) {
            if (ptr->leftThread == 0)
                ptr = ptr->left;
            else
                break;
        } else {
            if (ptr->rightThread == 0)
                ptr = ptr->right;
            else
                break;
        }
    }

    // Create a new node
    Nodeptr newNode = createNode(data);

    if (parent == NULL) {
        root = newNode;
    } else if (data < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = 0;
        parent->left = newNode;
    } else {
        newNode->left = parent;
        newNode->right = parent->right;
        parent->rightThread = 0;
        parent->right = newNode;
    }

    return root;
}

// Function to find the inorder predecessor
Nodeptr inorderPredecessor(Nodeptr ptr) {
    if (ptr->leftThread == 1)
        return ptr->left;
    ptr = ptr->left;
    while (ptr->rightThread == 0)
        ptr = ptr->right;
    return ptr;
}

// Function to find the inorder successor
Nodeptr inorderSuccessor(Nodeptr ptr) {
    if (ptr->rightThread == 1)
        return ptr->right;
    ptr = ptr->right;
    while (ptr->leftThread == 0)
        ptr = ptr->left;
    return ptr;
}

// Function to perform inorder traversal
void inorder(Nodeptr root) {
    if (root == NULL)
        return;

    Nodeptr ptr = root;
    while (ptr->leftThread == 0)
        ptr = ptr->left;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = inorderSuccessor(ptr);
    }
}

int main() {
    Nodeptr root = NULL;
    int arr[] = {6,3,1,5,8,7,11,9,13};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    printf("Inorder traversal of the double-threaded binary tree is:\n");
    inorder(root);
    printf("\n");

    return 0;
}
