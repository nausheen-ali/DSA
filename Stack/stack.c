#include<stdio.h>
#include<stdlib.h>
#define MAX 5

enum bool {false, true};

typedef struct
{
    int s[MAX];
    int sp;
}Stack;

void init(Stack *st)
{
    st->sp=-1;
}

int isFull(Stack *st)
{
    if (st->sp==MAX-1)
        return true;
    else
        return false;
}

int isEmpty(Stack *st)
{
    if(st->sp==-1)
        return true;
    else
        return false;
}

void push(Stack *st,int value)
{
    if(!isFull(st))
    {
        st->sp++;
        st->s[st->sp]=value;
        //st->s[++st->sp]=value;
        return;
    }
    else
    {
        printf("\n Overflow");
    }
}

int pop(Stack *st)
{
    if (!isEmpty(st))
    {
        int value=st->s[st->sp];
        st->sp--;
        return value;
        //return st->s[st->sp--];
    }
    else
    {
        printf("\n Underflow");
        return -1;
    }
}

void display(Stack *st)
{
    if(isEmpty(st))
    {
        printf("\n Stack is empty");
        return;
    }
    else
    {
         printf("\n Stack elements are: ");
        for(int i=0; i<=st->sp; i++)
            printf("  %d",st->s[i]);
    }
}

int main()
{
    Stack *st;
    st=(Stack *)malloc(sizeof(Stack));
    init(st);
    printf("\n SP value: %d",st->sp);
    display(st);
    push (st,10);
    push (st,20);
    push (st,30);
    printf("\n Popped value is: %d",pop(st));
    display(st);
    push (st,40);
    printf("\n Popped value is: %d",pop(st));
    printf("\n Popped value is: %d",pop(st));
    display(st);
    push (st,50);
    push (st,60);
    push (st,70);
    push (st,75);
    push (st,80);
    display(st);
}
