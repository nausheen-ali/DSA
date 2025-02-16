#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node *next;
} *front = NULL, *rear = NULL;

 int isEmpty()
{
 if(front == NULL)
 return 1;
 return 0;
}

 int isFull()
 {
 struct Node *t = (struct Node *)malloc(sizeof(struct Node));
 if(t == NULL)//when heap memory is full
 return 1;
 return 0;
 }

 void enqueue(int x)
 {
 struct Node *t = (struct Node *)malloc(sizeof(struct Node));
 if(isFull())
 printf("Queue is full\n");
 else
 {
 t -> data = x;
 t -> next = NULL;
 if(front == NULL)
 front = rear = t;
 else
 {
 rear -> next = t;
 rear = t;
 }
 }
 }

 int dequeue()
 {
 struct Node *t;
 int x = -1;
 if(isEmpty())
 printf("Queue is empty");
 else
 {
 t = front;
 front = front -> next;
 x = t -> data;
 free(t);
 }
 return x;
 }

void display()
{
 struct Node *t = front;
 while(t)
 {
 printf("%d  ", t -> data);
 t = t -> next;
 }
 printf("\n");
}

 int main()
 {
 int i;
 int a[] = {1,2,3,4,5};
 for(i = 0; i < 5; i++)
 {
 enqueue(a[i]);
 }
 display(front);
 printf("dequeued element is %d\n", dequeue());
 display(front);
 }
