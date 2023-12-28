#include <stdio.h>
#include <stdlib.h>
#define Max 100
int stack[Max];
int top=-1;
void push(int element)
{
    if(top==Max-1)
    {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top]=element;
}
int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}
int main()
{
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            int op2=pop();
            int op1=pop();
            switch(postfix[i])
            {
                case '+': push(op1 + op2);break;
                case '-': push(op1 - op2);break;
                case '*': push(op1 * op2);break;
                case '/': push(op1 / op2);break;
                default: printf("Invalid operator\n");exit(EXIT_FAILURE);
            }
        }
    }
    int result=pop();
    printf("Result: %d\n",result);
    return 0;
}
