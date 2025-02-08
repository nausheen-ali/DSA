#include<stdio.h>

int binSearch(int a[], int l, int h, int key)
{
    if(l<=h)
    {
        int mid=(l+h)/2;
        if(a[mid]==key)
            return mid;
        else if (key<a[mid])
            return binSearch(a,l, mid-1,key);
        else
            return binSearch(a,mid+1,h,key);
    }
    else
        return -1;
}

int main()
{
    int n;
    printf("\nEnter size:");
    scanf("%d", &n);

    int a[n], i;
    printf("\nEnter elements in sorted order:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    int key;
    printf("\nEnter key to be searched:");
    scanf("%d", &key);

    int pos=binSearch(a,0,n-1,key);
    if (pos==-1)
        printf("\nElement not found!");
    else
        printf("\nElement found at %d position", pos);
}
