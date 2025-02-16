#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node *next;
} *head, *tail;

void init() {
    head = tail = NULL;
}

struct Node *createNode(char *data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void insertRight(char *data) {
    struct Node *ptr = createNode(data);
    if (head == NULL) {
        head = tail = ptr;
    } else {
        tail->next = ptr;
        tail = ptr;
    }
}

void traverse() {
    struct Node *ptr;
    printf("\nLinked List is: ");
    for (ptr = head; ptr; ptr = ptr->next) {
        printf("%s ", ptr->data);
    }
    printf("\n");
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main() {
    init();
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Split the sentence into words and insert into the linked list
    char *token = strtok(str, " \n");
    while (token != NULL) {
        insertRight(token);
        token = strtok(NULL, " \n");
    }

    printf("\nOriginal ");
    traverse();

    head = reverseList(head);

    printf("\nReversed ");
    traverse();

    return 0;
}
