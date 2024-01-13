#include<stdio.h>
#include<string.h>
void main()
{
    char str1[100],str2[100];
    printf("Enter the larger string:\n");
    gets(str1);
    printf("Enter the substring:\n");
    gets(str2);
    check(str1,str2);
}
void check(char s1[],char s2[])
{
    int i=0,j=0;
    while (s1[i]!='\0' && s2[j]!='\0')
    {
        if (s1[i]!=s2[j])
        {
            i++;
            j=0;
        }
        else
        {
            j++;
            i++;
        }
    }
    if (s2[j]=='\0')
        printf("The substring is found in the larger string\n");
    else
        printf("The substring is not found in the larger string\n");
}
