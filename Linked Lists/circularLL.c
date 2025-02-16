#include <stdio.h>
#include <stdlib.h>

typedef struct{
 int data;
 struct Node* next;
}Node;

Node* createNode(int data) {
 Node* newNode = (Node*) malloc(sizeof(Node));
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}

void insertEnd(Node** head, int data) {
 Node* newNode = createNode(data);
 if (*head == NULL) {
 *head = newNode;
 newNode->next = *head;
 }
 else {
 Node* temp = *head;
 while (temp->next != *head) {
 temp = temp->next;
 }
 temp->next = newNode;
 newNode->next = *head;
 }
}

void deleteBegin(Node** head) {
 if (*head == NULL) {
 printf("List is empty.\n");
 return;
 }
 Node* temp = *head;
 if (temp->next == *head) {
 *head = NULL;
 free(temp);
 return;
 }
 Node* last = *head;
 while (last->next != *head) {
 last = last->next;
 }
 *head = temp->next;
 last->next = *head;
 free(temp);
}

void displayList(Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return;
 }

 Node* temp = head;
 do {
 printf("%d -> ", temp->data);
 temp = temp->next;
 } while (temp != head);
 printf("HEAD\n");
}

int main() {
 Node* head = NULL;
 insertEnd(&head, 1);
 insertEnd(&head, 2);
 insertEnd(&head, 3);
 insertEnd(&head, 4);

 printf("Circular Linked List: ");
 displayList(head);

 deleteBegin(&head);

 printf("After deleting from the beginning: ");
 displayList(head);

 return 0;
}
