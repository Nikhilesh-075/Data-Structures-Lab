#include<stdio.h>
#include<string.h>
void main()
{
    int n,i;
    printf("Enter the number of strings:\n");
    scanf("%d",&n);
    char st[n][100];
    printf("Enter the strings:\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",st[i]);
    }
    sort_string(st,n);
}
void sort_string(char arr[][100],int n)
{
    char temp[50];
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (strcmp(arr[i],arr[j])>0)
            {
                strcpy(temp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],temp);
            }
        }
    }
    printf("The lexicographically sorted strings are:\n");
    for(i=0;i<n;i++)
        printf("%s\n",arr[i]);
}
