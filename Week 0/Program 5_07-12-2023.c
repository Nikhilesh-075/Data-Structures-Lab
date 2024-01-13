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
    printf("Enter the number whose index of last occurrence has to be found:\n");
    scanf("%d",&num1);
    index1(a,n,num1);
}
void index1(int arr[],int n1,int num2)
{
    int i,index,flag=0;
    for(i=0;i<n1;i++)
    {
        if (arr[i]==num2)
        {
            index=i;
            flag=1;
        }
    }
    if (flag==0)
        printf("The element does not occur even once in the array\n");
    else
        printf("The index of the last occurrence of the number is %d\n",index);
}
