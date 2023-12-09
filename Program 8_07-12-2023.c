#include<stdio.h>
void main()
{
    int a[100],i,n;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=",i);
        scanf("%d",&a[i]);
    }
    printf("\nThe minimum element in the array is:\n");
    min_ar(a,n);
    printf("\nThe maximum element in the array is:\n");
    max_ar(a,n);
}
void min_ar(int arr[],int num)
{
    int m=999999;
    int i;
    for(i=0;i<num;i++)
    {
        if (arr[i]<m)
            m=arr[i];
    }
    printf("%d",m);
}
void max_ar(int arr[],int num)
{
    int m=-999999;
    int i;
    for(i=0;i<num;i++)
    {
        if (arr[i]>m)
            m=arr[i];
    }
    printf("%d",m);
}
