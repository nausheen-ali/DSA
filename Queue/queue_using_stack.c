#include <stdio.h>
#include <stdlib.h>

typedef struct {
 int size;
 int top;
 int *Q;
}Stack ;

void create(Stack *st)
{
 st->size = 40;
 st->top = -1;
 st->Q = (int *)malloc(st->size*sizeof(int));
}

int isFull(Stack *st)
{
 if(st->top == st->size -1)
 return 1;
 return 0;
}

int isEmpty( Stack *st)
{
 if(st->top == -1)
 return 1;
 return 0;
}

void push(Stack *st, int x)
{
 if(isFull(st))
 printf("Stack overflow\n");
 else
 {
 st->Q[++st->top] = x;
 }
}

int pop(  Stack *st)
{
 int x = -1;
 if(isEmpty(st))
 printf("Stack underflow\n");
 else
 {
 x = st->Q[st->top--];
 }
 return x;
}

void display(Stack *st)
{
 int i;
 for(i = st->top; i >= 0; i--)
 printf("%d ", st->Q[i]);
 printf("\n");
}

void enqueue(Stack *s1, int x)
{
 if(isFull(s1))
    printf("Queue is Full\n");
 else
    push(s1, x);
}

int dequeue(  Stack *s1,   Stack *s2)
{
 int x = -1;
 if(isEmpty(s1))
 {
    if(isEmpty(s2))
    {
        printf("Queue is Empty\n");
        return x;
    }
    else
    {
        while(!isEmpty(s1))
        push(s2, pop(s1));
    }
 }
 return pop(s2);
}

int main()
{
Stack *s1 = (Stack *)malloc(sizeof(Stack));
Stack *s2 = (Stack *)malloc(sizeof(Stack));
create(s1);
create(s2);
enqueue(s1, 10);
enqueue(s1, 20);
enqueue(s1, 30);
display(s1);
dequeue(s2,s1);
display(s1);
}
