//reversal & palindrome

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum bool{false,true};

typedef struct {
    int size;
    int top;
    char *s;
}stack ;

void create(stack *st, int size) {
    st->size = size;
    st->top = -1;
    st->s = (char *)malloc(st->size * sizeof(char));
}

int isEmpty(stack st) {
    return st.top == -1;
}

int isFull(stack st) {
    return st.top == st.size - 1;
}

void push(stack *st, char x) {
    if (isFull(*st))
        printf("Stack overflow\n");
    else
        st->s[++st->top] = x;
}

char pop(stack *st) {
    if (isEmpty(*st)) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return st->s[st->top--];
    }
}

void reverseString(char *str) {
    stack st;
    int len = strlen(str);
    create(&st, len);

    for (int i = 0; i < len; i++) {
        push(&st, str[i]);
    }

    for (int i = 0; i < len; i++) {
        str[i] = pop(&st);
    }

    free(st.s);
}

int isPalin(char *s)
{
stack st;
int len = strlen(s);
create(&st, len);
for(int i = 0; i < len; i++)
push(&st, s[i]);
for(int i = 0; i < len; i++)
{
    if(s[i] != pop(&st))
        return 0;
}
return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);
    printf("Reversed string: %s\n", str);

    if (isPalin(str))
        printf("The string is a palindrome\n");
    else
        printf("The string is not a palindrome\n");

    return 0;
}
