#include<stdio.h>
#include<stdlib.h>
#define Max 100
char stack[Max];
int top=-1;
void push(char item)
{
    if(top==Max-1)
    {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top]=item;
}
char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}
int precedence(char operator)
{
    switch(operator)
    {
        case '^': return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default: return 0;
    }
}
int main()
{
    char infix[Max];
    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s",infix);
    char postfix[Max];
    int i,j;
    i=j=0;
    while(infix[i]!='\0')
    {
        char symbol=infix[i];
        if((symbol>='a' && symbol<='z')||(symbol>='A' && symbol<='Z'))
            postfix[j++]=symbol;
        else if(symbol=='(')
            push(symbol);
        else if(symbol==')')
        {
            while(top!=-1 && stack[top]!='(')
                postfix[j++]=pop();
            if(top==-1)
            {
                printf("Invalid Expression due to parentheses mismatch\n");
                exit(EXIT_FAILURE);
            }
            pop();
        }
        else
        {
            while(top!=-1 && precedence(stack[top])>=precedence(symbol))
                postfix[j++]=pop();
            push(symbol);
        }
        i++;
    }
    while(top!=-1)
    {
        if(stack[top]=='(')
        {
            printf("Invalid Expression due to parentheses mismatch\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
