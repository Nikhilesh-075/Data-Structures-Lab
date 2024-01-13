#include<stdio.h>
void main()
{
    int a[100],i,n,num1;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    printf("Enter the elements in a sorted manner\n");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=",i);
        scanf("%d",&a[i]);
    }
    printf("Enter the number to find:\n");
    scanf("%d",&num1);
    binary_search(a,n,num1);
}
void binary_search(int arr[],int n1, int num2)
{
    int beg=0,end=n1-1,mid,pos,flag=0;
    while (beg<=end)
    {
        mid=(beg+end)/2;
        if (arr[mid]==num2)
        {
            pos=mid+1;
            printf("The number is found at position %d\n",pos);
            flag=1;
            break;
        }
        if (arr[mid]>num2)
            end=mid-1;
        else
            beg=mid+1;
    }
    if (flag==0)
        printf("The element is not found in the array\n");
}
