#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum bool{false,true};

typedef struct
{
 int size;
 int top;
 int *s;
}Stack;

void create( Stack *st, int len)
{
 st->size = len;
 st->top = -1;
 st->s = (int *)malloc(st->size * sizeof(int));
}

int isEmpty(Stack *st)
{
 if (st->top==-1)
    return true;
 else
    return false;
}

int isFull(Stack *st)
{
 if (st->top == st->size -1)
    return true;
 else
    return false;
}

void push(Stack *st, int x)
{
 if(isFull(st))
 printf("Stack Overflow\n");
 else
 {
 st->s[++st->top] = x;
 }
}

int pop(Stack *st)
{
 if(isEmpty(st))
 printf("Stack underflow\n");
 else
 {
 return st->s[st->top--];
 }
}

int isOperand(char x)
{
 if(x == '+' || x == '-' || x == '*' || x == '/')
 return false;
 return true;
}

int eval(char *s)
{
 Stack st;
 create(&st, strlen(s));
 int i, x1, x2, r;
 for(i = strlen(s) - 1; i >= 0; i--)
 {
 if(isOperand(s[i]))
 push(&st, s[i]-'0');
 else
 {
 x1 = pop(&st);
 x2 = pop(&st);
 switch(s[i])
 {
 case '+' : r = x1 + x2; push(&st, r); break;
 case '-' : r = x1 - x2; push(&st, r); break;
 case '*' : r = x1 * x2; push(&st, r); break;
 case '/' : r = x1 / x2; push(&st, r); break;
 }
 }
 }
 return pop(&st);
}

int main() {
    char ex[100];
    printf("Enter a prefix expression: ");
    scanf("%s", ex);
    int result = eval(ex);
    printf("%d\n", result);
}
