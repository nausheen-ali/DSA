//program to copy a string to other using recursion
#include<stdio.h>

void copystr(char *str1, char *str2)
{
    if(*str1=='\0')
    {
        *str2='\0';
        return;
    }
    *str2=*str1;
    copystr(str1+1, str2+1);
}

int main()
{
    char str1[100];
    printf("\nEnter string:");
    fgets(str1, sizeof(str1),stdin);
    char str2[100];
    copystr(str1,str2);
    printf("\nCopied string: %s", str2);
}
