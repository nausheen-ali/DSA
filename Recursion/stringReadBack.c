//to read a line of text and write it out backwards using Recursion

#include<stdio.h>

void reverseString(char *str, int index, int len)
{
    if(index >= len)
        return;
    reverseString(str, index + 1, len);
    printf("%c", str[index]);
}

int main()
{
    char str[100];
    printf("Enter a line of text: ");
    fgets(str, sizeof(str), stdin);
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n')
        len++;
    printf("Reversed text: ");
    reverseString(str, 0, len);
}
