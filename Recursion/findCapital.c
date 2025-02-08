//To find the first capital letter in a string using Recursion

#include<stdio.h>
#include<ctype.h>

char findFirstCapital(char *str)
{
    if (*str == '\0')
        return '\0';
    if (isupper(*str))
        return *str;
    return findFirstCapital(str + 1);
}

int main()
{
    char str[100];
    printf("\nEnter a string: ");
    fgets(str, sizeof(str), stdin);
    char result = findFirstCapital(str);
    if (result != '\0')
        printf("\nFirst capital letter: %c\n", result);
    else
        printf("\nNo capital letter found.\n");
    return 0;
}
