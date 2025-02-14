#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right
}*node;

struct Node *createNode(int key)
{
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
};

struct Node *createTree(int value)
{
    int x;
    struct Node *node;
    node=createNode(x);
    if(value!=0)
    {
        node->data=value;
        printf("\n Enter L Child for %d:", value);
        scanf("%d",&x);
        node->left=createTree(x);
        printf("\n Enter R Child for %d:", value);
        scanf("%d",&x);
        node->right=createTree(x);
        return node;
    }
    return NULL;
};

void inorder(struct Node *node)
{
    if(node==NULL) return;
    inorder(node->left);
    printf("%d\t", node->data);
    inorder(node->right);
}

int main()
{
    struct Node *root = NULL;
    int value;
    printf("Enter the root value (0 for no node): ");
    scanf("%d", &value);
    root = createTree(value);
    printf("\nIn-order traversal of the binary tree: ");
    inorder(root);
    return 0;
}
