//searching, inserting, deletion, copy
//find height, node, leave nodes, ancestors
//max and min value of node
//equality checking

#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* Nodeptr;

// Function to create a new node
Nodeptr createNode(int data) {
    Nodeptr newNode = (Nodeptr)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
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

// Function to search for a node in the binary tree
Nodeptr search(Nodeptr root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum value node in the binary tree
Nodeptr minValueNode(Nodeptr node) {
    Nodeptr current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
// Function to find the maximum value node in the binary tree
Nodeptr maxValueNode(Nodeptr node) {
    Nodeptr current = node;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Function to delete a node from the binary tree
Nodeptr deleteNode(Nodeptr root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Nodeptr temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Nodeptr temp = root->left;
            free(root);
            return temp;
        }
        Nodeptr temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to copy a binary tree
Nodeptr copyTree(Nodeptr root) {
    if (root == NULL) {
        return NULL;
    }
    Nodeptr newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    return newNode;
}

int Equal(Nodeptr root1, Nodeptr root2) {
    return ((!root1 && !root2) ||
            (root1 && root2 &&
            (root1->data == root2->data) &&
            Equal(root1->left, root2->left) &&
            Equal(root1->right, root2->right)));
}


// Function to find the height of the binary tree
int findHeight(Nodeptr root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int count_nodes( Nodeptr root)
{
 static int count = 0;
if(root!=NULL)
{
count_nodes(root->left);
count++;
count_nodes(root->right);
}
 return count;
}

int count_leafnodes( Nodeptr root){
static int count = 0;
if(root!=NULL){
if(root->left==NULL && root->right==NULL)
 count++;
 count_leafnodes(root->left);
count_leafnodes(root->right);
}
return count;
}

int printAncestors(Nodeptr root, int key)
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

// Function to perform inorder traversal
void inorder(Nodeptr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Nodeptr root = NULL;
    int arr[] = {20,10,40,50,30,60};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    printf("Inorder traversal of the binary tree is:\n");
    inorder(root);
    printf("\n");

    int height = findHeight(root);
    printf("Height of the binary tree is: %d\n", height);

    printf("No of nodes is %d\n", count_nodes(root));

    printf("No of leaf nodes is %d\n", count_leafnodes(root));

    printf("Minimum value %d\n",minValueNode(root)->data);
    printf("Maximum value %d\n",maxValueNode(root)->data);

    int key = 30;
    root = deleteNode(root, key);
    printf("\nInorder traversal after deleting %d:\n", key);
    inorder(root);
    printf("\n");

    int searchKey = 5;
    Nodeptr searchResult = search(root, searchKey);
    if (searchResult != NULL) { printf("Node with value %d found in the binary tree.\n", searchKey); }
    else { printf("Node with value %d not found in the binary tree.\n", searchKey); }

    Nodeptr copiedTree = copyTree(root);
    printf("Inorder traversal of the copied tree is:\n");
    inorder(copiedTree);
    printf("\n");

    if(Equal(root, copiedTree)) printf("Copied tree is equal\n");
    else printf("Not equal\n");

    int k=10;
    printf("Ancestors of node %d are:", k);
    if(!printAncestors(root,k)){
        printf("Node not found");
    }

    return 0;
}
