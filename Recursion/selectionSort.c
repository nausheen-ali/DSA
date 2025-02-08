#include<stdio.h>

void selectionSort(int *ptr, int size)
{
    for(int i=0; i<size-1; i++)
    {
        int mini=i;
        for(int j=i+1;j<size;j++)
        {
            if(ptr[j]<ptr[mini])
            {
                mini=j;
            }
        }
        int temp=ptr[mini];
        ptr[mini]=ptr[i];
        ptr[i]=temp;
    }
}

int main()
{
    int *arr,n,i;
    printf("\n Enter size:");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("\n Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d", arr+i);
    selectionSort(arr,n);
    printf("\n Sorted array: \n");
    for(i=0; i<n; i++)
        printf("%d  ", arr[i]);
    free(arr);
}
