#include<stdio.h>

int isPalindrome(char str[], int l, int h)
{
    if(l>=h)
        return 1;
    else if (str[l]==str[h])
        isPalindrome(str,l+1,h-1);
    else
        return 0;
}

int main()
{
    char str[100];
    printf("\nEnter string:");
    scanf("%s", str);

    int res=isPalindrome(str,0,strlen(str)-1);
    if(res==0)
        printf("\n Not Palindrome");
    else
        printf("It is Palindrome");
}
