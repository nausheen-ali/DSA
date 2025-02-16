#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNodeAtPosition(struct Node** head, int position) {
    if (*head == NULL || position <= 0) {
        return;
    }

    struct Node* temp = *head;

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (*head == temp) {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

void displayList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nTraversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 6);
    insertFront(&head, 7);
    insertFront(&head, 1);
    insertEnd(&head, 4);
    insertEnd(&head, 8);

    printf("Created Doubly Linked List:\n");
    displayList(head);

    deleteNodeAtPosition(&head, 2);
    printf("List after deletion of node at position 2:\n");
    displayList(head);

    deleteNodeAtPosition(&head, 1);
    printf("List after deletion of node at position 1:\n");
    displayList(head);

    deleteNodeAtPosition(&head, 3);
    printf("List after deletion of node at position 3:\n");
    displayList(head);

    return 0;
}
