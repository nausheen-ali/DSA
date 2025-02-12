#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

enum bool {false, true};

typedef struct
{
    char st[SIZE];
    int sp;
} Stack;

void init(Stack *stack)
{
    stack->sp = -1;
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

void push(Stack *stack, char ch) {
    if (isFull(stack))
   {
        printf("\nOverflow");
        return;
    }
   else
{
    stack->st[++stack->sp] = ch;
}
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\nUnderflow");
        return '\0';
    }
    return stack->st[stack->sp--];
}



int isOperand(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

char top(Stack *stack) {
    return stack->st[stack->sp];
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void replaceParentheses(char *exp) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

void infixToPrefix(char *infix, char *prefix) {
    reverse(infix);
    replaceParentheses(infix);

    Stack stack;
    init(&stack);
    int i = 0, p = 0;
    while (infix[i] != '\0')
        {
        char ch = infix[i];
        if (isOperand(ch))
        {
            prefix[p++] = ch;
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&stack) && top(&stack) != '(')
            {
                prefix[p++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from stack
        }
        else
        {
            while (!isEmpty(&stack) && precedence(ch) <= precedence(top(&stack)))
            {
                prefix[p++] = pop(&stack);
            }
            push(&stack, ch);
        }
        i++;
    }
    while (!isEmpty(&stack))
    {
        prefix[p++] = pop(&stack);
    }
    prefix[p] = '\0';

    reverse(prefix);
}

int main() {
    char infix[SIZE], prefix[SIZE];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}
