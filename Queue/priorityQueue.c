#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int items [MAX];
    int size;
}PQ;

void enqueue(PQ *q, int v)
{
    if (q->size==MAX){
        printf("Queue overflow");
        return;}
    q->items[q->size++]=v;
}

int dequeue(PQ *q)
{
    if (q->size==0){
        printf("Queue Underflow");
        return -1;}
    int minIdx=minIndex(q),minVal=q->items[minIdx];
    for (int i=minIdx;i<q->size-1;i++)
        q->items[i]=q->items[i+1];
    q->size--;
    return minVal;
}

int minIndex(PQ *q)
{
    int minIdx=0;
    for(int i=1;i<q->size;i++)
        if(q->items[i]<q->items[minIdx])
            minIdx=i;
    return minIdx;
}

int peek (PQ *q)
{
    printf("\nQueue elements are:");
    for (int i=0;i<q->size;i++)
        printf("  %d",q->items[i]);
    printf("\n");
}

int main()
{
    PQ q={{0},0};
    enqueue(&q,3);
    enqueue(&q,15);
    enqueue(&q,30);
    enqueue(&q,2);
    enqueue(&q,14);
    peek(&q);
    printf("Dequeued element %d",dequeue(&q));
    peek(&q);
    enqueue(&q,1);
    peek(&q);
    enqueue(&q,140);
    peek(&q);
}
