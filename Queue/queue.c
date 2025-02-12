#include<stdio.h>
#include<stdlib.h>
#define MAX 5

enum bool {false, true};

typedef struct
{
    int q[MAX];
    int front;
    int rear;
}Queue;

void init(Queue *queue)
{
    queue->front=queue->rear=-1;
}

int isFull(Queue *queue)
{
    if ((queue->rear+1)==MAX)
        return true;
    else
        return false;
}

int isEmpty(Queue *queue)
{
    if (((queue->front==-1)&&(queue->rear==-1))||(queue->front==queue->rear+1))
        return true;
    else
        return false;
}

void enqueue(Queue *queue, int ele)
{
    if (isFull(queue)) {
        printf("\nQueue Overflow");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->q[++queue->rear] = ele;
}

int dequeue(Queue *queue)
{
    if(!isEmpty(queue))
        return (queue->q[queue->front++]);
    else
        printf("\nQueue Underflow");
}

void display(Queue *queue)
{
     if (isEmpty(queue))
    {
        printf("\nQueue is empty");
        return;
    }
    int i=queue->front;
    printf("\nQueue elements are:");
    for(;i<=queue->rear;i++)
        printf("  %d",queue->q[i]);
}

int main()
{
    Queue *queue;
    queue=(Queue *)malloc(sizeof(Queue));
    init(queue);
    enqueue(queue,10); display(queue);
    enqueue(queue,20); display(queue);
    enqueue(queue,30); display(queue);
    printf("\nDequeued elements is: %d",dequeue(queue));
    enqueue(queue,40); display(queue);
    enqueue(queue,50); display(queue);
    printf("\nDequeued elements is: %d",dequeue(queue));
    enqueue(queue,60); display(queue);
}
