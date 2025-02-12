#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

enum bool {false, true};

typedef struct {
    char* st[SIZE];
    int sp;
} Stack;

void init(Stack *stack) {
    stack->sp = -1;
}

int isFull(Stack *stack) {
    return stack->sp == SIZE - 1;
}

int isEmpty(Stack *stack) {
    return stack->sp == -1;
}

void push(Stack *stack, char* str) {
    if (isFull(stack)) {
        printf("\nOverflow");
        return;
    }
    stack->st[++stack->sp] = str;
}

char* pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\nUnderflow");
        return NULL;
    }
    return stack->st[stack->sp--];
}

int isOperand(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

char* postfixToInfix(char* exp) {
    Stack stack;
    init(&stack);
    for (int i = 0; exp[i] != '\0'; i++)
        {
        if (isOperand(exp[i]))
        {
            char* op = (char*) malloc(2 * sizeof(char));
            op[0] = exp[i];
            op[1] = '\0';
            push(&stack, op);
        }
        else
        {
            char* op1 = pop(&stack);
            char* op2 = pop(&stack);
            char* temp = (char*) malloc((strlen(op1) + strlen(op2) + 4) * sizeof(char));
            sprintf(temp, "(%s%c%s)", op2, exp[i], op1);
            push(&stack, temp);
        }
    }
    return pop(&stack);
}

int main()
{
    char exp[SIZE];
    printf("Enter Postfix Expression: ");
    scanf("%s", exp);
    char* infix = postfixToInfix(exp);
    printf("Infix Expression: %s\n", infix);
    free(infix);
    return 0;
}
