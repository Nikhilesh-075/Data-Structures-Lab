#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};
void initialize(struct Stack *stack);
void push(struct Stack *stack);
void pop(struct Stack *stack);
void display(const struct Stack *stack);
int main()
{
    struct Stack stack;
    int c,c1=0;
    initialize(&stack);
    while(c1==0)
    {
        printf("Enter 1 to push an element into the stack\n");
        printf("Enter 2 to pop an element from the stack\n");
        printf("Enter 3 display the contents of the stack\n");
        printf("Enter 0 to exit\n");
        printf("Enter your choice");
        scanf("%d",&c);
        switch(c)
        {
            case 0: c1=1;break;
            case 1: push(&stack);break;
            case 2: pop(&stack);break;
            case 3: display(&stack);break;
            default: printf("Invalid choice\n");break;
        }
    }
    return 0;
}
void initialize(struct Stack *stack)
{
    stack->top=-1;
}
void push(struct Stack *stack)
{
    int value;
    printf("Enter the element to push into the stack:\n");
    scanf("%d",&value);
    if(stack->top==MAX_SIZE-1)
    {
        printf("Stack Overflow: Cannot push %d, stack is full.\n",value);
    }
    else
    {
        stack->arr[++(stack->top)]=value;
        printf("Pushed %d onto the stack.\n",value);
    }
}
void pop(struct Stack *stack)
{
    int poppedElement;
    if (stack->top==-1)
    {
        printf("Stack Underflow: Cannot pop from an empty stack.\n");
    }
    else
    {
        poppedElement=stack->arr[(stack->top)--];
        printf("The popped element is: %d\n",poppedElement);
    }
}
void display(const struct Stack *stack)
{
    if (stack->top==-1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack Contents: ");
        for (int i=0;i<=stack->top;i++)
        {
            printf("%d ",stack->arr[i]);
        }
        printf("\n");
    }
}
