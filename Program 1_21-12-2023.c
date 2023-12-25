#include <stdio.h>
void swapNumbers(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n1,n2;
    printf("Enter the first number: ");
    scanf("%d", &n1);
    printf("Enter the second number: ");
    scanf("%d", &n2);
    printf("Before swapping: \n");
    printf("First number: %d\n",n1);
    printf("Second number: %d\n",n2);
    swapNumbers(&n1, &n2);
    printf("\nAfter swapping: \n");
    printf("First number: %d\n", n1);
    printf("Second number: %d\n", n2);
    return 0;
}
