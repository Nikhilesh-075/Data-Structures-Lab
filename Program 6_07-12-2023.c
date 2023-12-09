#include<stdio.h>
void main()
{
    int a[100],i,n,num1;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=",i);
        scanf("%d",&a[i]);
    }
    printf("Enter the number to find:\n");
    scanf("%d",&num1);
    linear_search(a,n,num1);
}
void linear_search(int arr[],int n1,int num2)
{
    int i,pos,flag=0;
    for(i=0;i<n1;i++)
    {
        if (arr[i]==num2)
        {
            pos=i+1;
            printf("The number is found at position %d\n",pos);
            flag=1;
        }
    }
    if (flag==0)
        printf("The number is not present in the array\n");
}
