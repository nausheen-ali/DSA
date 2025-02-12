#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum bool {false, true};

typedef struct {
    int size;
    int top;
    char *s;
} stack;

void create(stack *st, char *x) {
    st->size = strlen(x);
    st->top = -1;
    st->s = (char *)malloc(st->size * sizeof(char));
}

int isEmpty(stack st) {
    return st.top == -1 ? true : false;
}

int isFull(stack st) {
    return st.top == st.size - 1 ? 1 : 0;
}

void push(stack *st, char x) {
    if (isFull(*st))
        printf("stack overflow");
    else
        st->s[++st->top] = x;
}

char pop(stack *st) {
    if (isEmpty(*st)) {
        printf("stack underflow");
        return '\0';
    } else {
        return st->s[st->top--];
    }
}

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    else if (char1 == '{' && char2 == '}') return 1;
    else if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

int isBalanced(char *exp) {
    stack st;
    create(&st, exp);
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&st, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(st) || !isMatchingPair(pop(&st), exp[i])) {
                return false;
            }
        }
    }
    return isEmpty(st) ? true : false;
}

int main() {
    char x[100];
    printf("Enter expression: ");
    scanf("%s", x);

    if (isBalanced(x)) {
        printf("Balanced\n");
    } else {
        printf("Unbalanced\n");
    }

    return 0;
}
