#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

int isQueueFull(Queue* q) {
    return q->rear == SIZE - 1;
}

void enqueue(Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

typedef struct {
    Queue q1, q2;
} Stack;

void initStack(Stack* s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(Stack* s, int value) {
    enqueue(&s->q2, value);
    while (!isQueueEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(Stack* s) {
    if (isQueueEmpty(&s->q1)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

void display(Stack* s) {
    if (isQueueEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = s->q1.front; i <= s->q1.rear; i++) {
        printf("%d ", s->q1.items[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10); display(&s);
    push(&s, 20); display(&s);
    push(&s, 30); display(&s);

    printf("Popped element: %d\n", pop(&s)); display(&s);
    printf("Popped element: %d\n", pop(&s)); display(&s);
    printf("Popped element: %d\n", pop(&s)); display(&s);

    return 0;
}
