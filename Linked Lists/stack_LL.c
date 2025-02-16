//stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node *next;
} *top = NULL;

 int isEmpty()
{
 if(top == NULL)
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

 void push(int x)
 {
 struct Node *t = (struct Node *)malloc(sizeof(struct Node));
 if(isFull())
 printf("Stack Overflow");
 else
 {
 t -> data = x;
 t -> next = top;
 top = t;
 }
 }

 int pop()
 {
 int x = -1;
 struct Node *t = (struct Node *)malloc(sizeof(struct Node));
 if(isEmpty())
 printf("Stack Underflow");
 else
 {
 t = top;
 top = top -> next;
 x = t -> data;
 free(t);
 }
 return x;
 }

 void display(struct Node *p)
 {
 while(p)
 {
 printf("  %d", p->data);
 p = p -> next;
 }
 }

 int main()
 {
 int i;
 int a[] = {1,2,3,4,5};
 for(i = 0; i < 5; i++)
 {
 push(a[i]);
 }
 display(top);
 printf("\npopped element is %d\n", pop());
 display(top);
 }
