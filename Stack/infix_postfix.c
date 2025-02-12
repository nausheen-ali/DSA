#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

enum bool {false,true};

typedef struct
{
    char st[SIZE];
    int sp;
}Stack;

void init(Stack *stack)
{
    stack->sp=-1;
}

int isFull(Stack *stack)
{
    if (stack->sp==SIZE-1)
        return true;
    else
        return false;
}

int isEmpty(Stack *stack)
{
    if (stack->sp==-1)
        return true;
    else
        return false;
}

void push(Stack *stack, char ch)
{
    if (isFull(stack))
    {
        printf("\n Overflow");
        return;
    }
    else
    {
        stack->sp++;
        stack->st[stack->sp]=ch;
        //stack->st[++stack->sp]=ch;
    }
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\n Underflow");
        return '\0';
    }
    else
    {
        char ch=stack->st[stack->sp];
        stack->sp--;
        return ch;
        // return ch=stack->st[stack->sp--];
    }
}

int isOperand(char ch)
{
    if(((ch>='A')&&(ch<='Z')) || ((ch>=97) && (ch<=122)))
        return true;
    else
        return false;
}

char top(Stack *stack)
{
    return (stack->st[stack->sp]);
}

int prec(char ch)
{
    switch(ch)
    {
        case '^': return 3;
        case '/':
        case '*':
        case '%': return 2;
        case '+':
        case '-': return 1;
        case '(':
        case '#': return -1;
        default : return 0;
    }
}

int main()
{
    char infix[100], postfix[100];
    Stack *stack;
    stack=(Stack *)malloc(sizeof(Stack));
    init(stack);
    push (stack,'#');
    printf("\n Enter Infix Expression:");
    scanf("%s", infix);
    int i=0,p=0;
    while(infix[i]!='\0')
    {
        char ch=infix[i];
        if (isOperand(ch))
        {
            postfix[p++]=ch;
        }
        else
        {
            if (ch=='(')
            {
                push(stack,ch);
            }
            else if (ch == ')')
            {
                char c;
                while((c=pop(stack))!='(')
                        postfix[p++]=c;
            }
            else
            {
                int p1,p2;
                char c = top(stack);
                p1=prec(ch);
                p2=prec(c);
                if(p1>=p2)
                {
                    push(stack,ch);
                }
                else
                {
                    c=pop(stack);
                    postfix[p++]=c;
                    push(stack,ch);
                }
            }
        }
        i++;
    }
    char c;
    if(stack->sp>0)
    {
        while((c=pop(stack))!='#')
            postfix[p++]=c;
    }
    postfix[p]='\0';
    printf("\n The postfix expression is : %s",postfix);
}
