#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

enum bool{false,true};

typedef struct
{
    char items[MAX][MAX];
    int front, rear;
}Deque;

void init(Deque *d)
{
    d->front=d->rear=-1;
}

int isFull(Deque *d)
{
    if (((d->front==0) && (d->rear==MAX-1))||(d->front==d->rear+1))
        return true;
    else
        return false;
}

int isEmpty(Deque *d)
{
    if (d->front==-1)
        return true;
    else
        return false;
}

void insertLeft(Deque *d, char *str)
{
    if(isFull(d))
        return;
    if (d->front==-1)
        d->front=d->rear=0;
    else if (d->front==0)
        d->front=MAX-1;
    else
        d->front--;
    strcpy(d->items[d->front],str);
}

void insertRight(Deque *d, char *str)
{
    if(isFull(d))
        return;
    if (d->front==-1)
        d->front=d->rear=0;
    else if (d->rear==MAX-1)
        d->rear=0;
    else
        d->rear++;
    strcpy(d->items[d->rear],str);
}

void deleteLeft(Deque *d)
{
    if (isEmpty(d))
        return;
    if(d->front==d->rear)
        d->front=d->rear+1;
    else if (d->front==MAX-1)
            d->front=0;
    else
        d->front++;
}

void deleteRight(Deque *d)
{
    if (isEmpty(d))
        return;
    if(d->front==d->rear)
        d->front=d->rear+1;
    else if (d->rear==0)
            d->rear=MAX-1;
    else
        d->rear--;
}

void display(Deque *d)
{
    if (isEmpty(d))
        {printf("Queue is empty\n");
        return;}
    int i=d->front;
    while(i!=d->rear)
    {
        printf("%s",d->items[i]);
        i=(i+1)%MAX;
    }
    printf("%s\n",d->items[i]);
}

int main()
{
    Deque *dq;
    dq=(Deque *)malloc(sizeof(Deque));
    init(dq);
    display(dq);
    insertRight(dq,"to ");
    insertLeft(dq,"Welcome ");
    insertLeft(dq,"Hello ");
    insertRight(dq,"Python ");
    display(dq);
    deleteRight(dq);
    deleteLeft(dq);
    display(dq);
}
