#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr1,*arr2;
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    arr1=(int *)malloc(n*sizeof(int));
    if(arr1==NULL)
    {
        printf("Memory allocation failed for arr1\n");
        return 1;
    }
    printf("Memory allocation successful for arr1\n");
    printf("Enter the elements of arr1:\n");
    for(int i=0;i<n;i++)
    {
        printf("\narr1[%d]=",i);
        scanf("%d", &arr1[i]);
    }
    printf("Contents of arr1: ");
    for(int i=0;i<n;i++)
    {
        printf("\narr1[%d]=%d",i,arr1[i]);
    }
    printf("\n");
    //free(arr1);
    //printf("Memory deallocation successful for arr1\n");
    printf("Enter the size of the new array:\n");
    scanf("%d", &n);
    arr2=(int *)calloc(n,sizeof(int));
    if(arr2==NULL)
    {
        printf("Memory allocation failed for arr2\n");
        return 1;
    }
    printf("Memory allocation successful for arr2\n");
    printf("Contents of arr2 (initialized to zero): ");
    for(int i=0;i<n;i++)
    {
        printf("\narr2[%d]=%d ",i,arr2[i]);
    }
    printf("\n");
    printf("Enter the new size for arr1:\n");
    scanf("%d",&n);
    arr1 = (int *)realloc(arr1,n*sizeof(int));
    if(arr1==NULL)
    {
        printf("Memory reallocation failed for arr1\n");
        return 1;
    }
    printf("Memory reallocation successful for arr1\n");
    printf("Enter the elements of arr1:\n");
    for(int i=0;i<n;i++)
    {
        printf("\narr1[%d]=",i);
        scanf("%d",&arr1[i]);
    }
    printf("Contents of arr1: ");
    for(int i=0;i<n;i++)
    {
        printf("\narr1[%d]=%d",i,arr1[i]);
    }
    printf("\n");
    free(arr1);
    free(arr2);
    printf("Memory deallocation successful for arr1 and arr2\n");
    return 0;
}
