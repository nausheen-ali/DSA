//BST OPERATIONS
#include <stdio.h>
#include <stdlib.h>


struct Node {
    struct Node *left;
    int data;
    struct Node *right;
} *root;

struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node *createTree(int value)
{
    int x;
    struct Node *node;
    node=createNode(x);
    if(value!=0)
    {
        node->data=value;
        printf("\nEnter left child for %d:", value);
        scanf("%d",&x);
        node->left=createTree(x);
        printf("\nEnter right child for %d:", value);
        scanf("%d",&x);
        node->right=createTree(x);
        return node;
    }
    return NULL;
}

struct Node *insert(struct Node *node, int key) {
    if (node == NULL) {
        return createNode(key);
    } else if (key < node->data) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

void inorder(struct Node *node) {
    if (node != NULL){
    inorder(node->left);
    printf("|%p|%d|%p|->", node->left, node->data, node->right);
    inorder(node->right);}
}

struct Node *search(struct Node *node, int key) {
    if (node == NULL || node->data == key) {
        return node;
    } else if (key < node->data) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

struct Node *minValue(struct Node *node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct Node *maxValue(struct Node *node) {
    while (node && node->right != NULL) {
        node = node->right;
    }
    return node;
}

struct Node *deleteNode(struct Node *node, int key) {
    if (node == NULL) {
        return NULL;
    } else if (key < node->data) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->data) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == NULL) {
            struct Node *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
        struct Node *temp = minValue(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

int printAncestors(struct Node *root, int key)
{
    if (root==NULL){
        return 0;
    }
    if(root->data==key){
        return 1;
    }
    if (printAncestors(root->left,key)||printAncestors(root->right,key)){
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

int main() {
    int a[] = {45, 23, 15, 12, 36, 25, 39, 52, 55, 59, 93, 89, 76, 65};
    int n = sizeof(a) / sizeof(int);

    root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, a[i]);
    }

     // Ask user for the root value
     /*int rootValue;

    printf("Enter the root value: ");
    scanf("%d", &rootValue);

    // Create the tree
    struct Node* root = createTree(rootValue);*/

    printf("\nThe inorder of BST is:\n");
    inorder(root);    printf("\n");

    int searchKey = 23;
    if (search(root, searchKey) != NULL) { printf("\nNode with value %d found in the binary tree.\n", searchKey); }
    else { printf("\nNode with value %d not found in the binary tree.\n", searchKey); }

    root = deleteNode(root, 39);

    printf("\nThe inorder of BST after deletion is:\n");
    inorder(root);    printf("\n");

    printf("\nMinimum value %d\n",minValue(root)->data);
    printf("\nMaximum value %d\n",maxValue(root)->data);
    int key = 93;
    printf("\nAncestors of %d are:", key);
    if(!printAncestors(root,key)){
        printf("Node not found");
    }
    return 0;
}

