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
    newNode->next = newNode->prev = newNode;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* last = (*head)->prev;
        struct Node* temp = *head;
        *head = (*head)->next;
        (*head)->prev = last;
        last->next = *head;
        free(temp);
    }
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* last = (*head)->prev;
        struct Node* secondLast = last->prev;
        secondLast->next = *head;
        (*head)->prev = secondLast;
        free(last);
    }
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void displayReverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head->prev;
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    printf("List in forward direction: ");
    displayForward(head);

    printf("List in reverse direction: ");
    displayReverse(head);

    deleteFromBeginning(&head);
    deleteFromEnd(&head);

    printf("List after deletion from beginning and end: ");
    displayForward(head);

    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    deleteAtPosition(&head, 2);

    printf("Final List: ");
    displayForward(head);

    return 0;
}
