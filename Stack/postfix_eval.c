#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum bool{false,true};

typedef struct
{
 int size;
 int top;
 int *n;
}stack;

void create(stack *st, char *ex)
{
 st->size = strlen(ex);
 st->top = -1;
 st->n = (int *)malloc(st->size * sizeof(int));
}

int isEmpty(stack st)
{
 if(st.top == -1)
 return true;
 return false;
}

int isFull(stack st)
{
 if(st.top == st.size -1)
 return true;
 return false;
}

void push(stack *st, int key)
{
 if(isFull(*st))
 printf("stack overflow\n");
 else
 {
 st->n[++st->top] = key;
 }
}

int pop(stack *st)
{
 if(isEmpty(*st))
 printf("Stack underflow\n");
 else
 {
 return st->n[st->top--];
 }
}

int isOperand(char x)
{
 if(x == '+' || x == '-' || x == '/' || x == '*')
 return false;
 return true;
}

int Eval(char *postfix)
{
 stack st;
 create(&st, postfix);
 int i, x1, x2, r;
 for(i = 0; postfix[i] != '\0'; i++)
 {
    if(isOperand(postfix[i]))
        push(&st, postfix[i] - '0');
    else
    {
        x1 = pop(&st);
        x2 = pop(&st);
        switch(postfix[i])
        {
            case '+' : r = x2 + x1; push(&st, r); break;
            case '-' : r = x2 - x1; push(&st, r); break;
            case '*' : r = x2 * x1; push(&st, r); break;
            case '/' : r = x2 / x1; push(&st, r); break;
        }
    }
 }
 return pop(&st);
}

int main()
{
 char ex[100];
 printf("Enter a postfix expression: ");
 scanf("%s", ex);
 int result = Eval(ex);
 printf("%d\n", result);
}
