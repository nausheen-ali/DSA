#include<stdio.h>

void toh(int n, char source, char aux, char dest, int *count)
{
    if(n==1)
    {
        printf("\n Move disk from %c to %c", source, dest);
        (*count)++;
        return;
    }
    toh(n-1,source, dest, aux, count);
    printf("\n Move disk from %c to %c", source, dest);
    (*count)++;
    toh(n-1, aux, source, dest, count);

}

int main()
{
    int n;
    int count=0;
    printf("\n Enter no of disks:");
    scanf("%d", &n);
    toh(n,'S', 'A', 'D', &count);
    printf("\n Number of moves: %d", count); // 2^n-1
}
