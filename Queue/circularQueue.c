#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

enum bool{false, true};

typedef struct{
    int q[SIZE];
    int f, r;
}Queue;

void init (Queue *queue)
{
    queue->f=queue->r=-1;
}

int isFull(Queue *queue)
{
    if (((queue->f==0)&&(queue->r==SIZE-1))|| (queue->f==(queue->r+1)%SIZE))
        return true;
    else
        return false;
}

int isEmpty(Queue *queue)
{
    if (queue->f==-1)
        return true;
    else
        return false;
}

void enqueue(Queue *queue,int ele)
{
    if (isFull(queue))
    {
        printf("\n Queue Overflow");
        return;
    }
    if (queue->f==-1)
        queue->f=0;
    queue->r=(queue->r+1)%SIZE;
    queue->q[queue->r]=ele;
}

int dequeue(Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("\n Queue Underflow");
        return -1;
    }
    int ele=queue->q[queue->f];
    queue->f=(queue->f+1)%SIZE;
    return ele;
}

void display (Queue *queue)
{
    if (isEmpty(queue))
        printf("Queue is empty");
    int i;
    printf("\n Queue Elements are: ");
    for (i=queue->f;i!=queue->r;i=(i+1)%SIZE)
        printf(" %d",queue->q[i]);
    printf(" %d",queue->q[i]);
}

int main()
{
    Queue *queue;
    queue = (Queue *)malloc(sizeof(Queue));
    init(queue);
    enqueue(queue, 10); display(queue);
    enqueue(queue, 20); display(queue);
    enqueue(queue, 30); display(queue);
    printf("\n Dequeued elemnet is : %d",dequeue(queue));
    display(queue);
    enqueue(queue, 40); display(queue);
    enqueue(queue, 50); display(queue);
    enqueue(queue, 60); display(queue);
    enqueue(queue, 70); display(queue);
}
