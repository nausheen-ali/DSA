// recursive function to create binary tree
// all 3 traversal techniques
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}*Nodeptr;


Nodeptr createNode(int data) {
    Nodeptr newNode = (Nodeptr)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Nodeptr createTree(int value)
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

void inorder(Nodeptr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(Nodeptr root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Nodeptr root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 100);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    free(queue);
}


int main() {
    Nodeptr root = NULL;
    int item;

    printf("Creating the tree:\n");
    printf("Enter the root: ");
    scanf("%d", &item);
    root = createTree(item);


    printf("\nInorder traversal of the binary tree is:\n");
    inorder(root);
    printf("\nPreorder traversal of the binary tree is:\n");
    preorder(root);
    printf("\nPostorder traversal of the binary tree is:\n");
    postorder(root);
    printf("\nLevel Order Traversal of the binary tree is:\n");
    levelOrderTraversal(root);
    return 0;
}

