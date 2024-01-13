#include<stdio.h>
void main()
{
    int a[100],n,i,number;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=",i);
        scanf("%d",&a[i]);
    }
    printf("Enter the element to check:\n");
    scanf("%d",&number);
    check(a,number,n);
}
void check(int arr[],int num,int num1)
{
    int i,flag=0;
    for(i=0;i<num1;i++)
    {
        if (arr[i]==num)
        {
            printf("The element %d is present in the array\n",num);
            flag=1;
        }
    }
    if (flag==0)
        printf("Element not present in the array\n");
}
