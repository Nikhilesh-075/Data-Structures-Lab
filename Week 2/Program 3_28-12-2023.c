#include<stdio.h>
#define SIZE 5
int front=-1,rear=-1;
int queue[SIZE];
int main()
{
    int c,elem,c1=0;
    while(c1==0)
    {
        printf("\nEnter 1 to insert into the queue\n");
        printf("Enter 2 to delete from the queue\n");
        printf("Enter 3 to display the contents of the queue\n");
        printf("Enter 0 to exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 0: printf("Exiting...\n");c1=1;break;
            case 1:
                printf("Enter the element to be inserted:\n");
                scanf("%d",&elem);
                enqueue(elem);
                break;
            case 2: dequeue();break;
            case 3: display_q();break;
            default: printf("Invalid choice. Please enter a valid option\n");
        }
    }
    return 0;
}
void enqueue(int elem)
{
    if(rear==SIZE-1)
    {
        printf("Queue is full. Cannot insert\n");
        exit(0);
    }
    if(front==-1)
    {
        front=0;
    }
    queue[++rear]=elem;
    printf("Element %d inserted successfully\n",elem);
}
void dequeue()
{
    if(front==-1||front>rear)
    {
        printf("Queue is empty. Cannot delete\n");
        exit(0);
    }
    printf("The element deleted is %d\n",queue[front]);
    front++;
}
void display_q()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        exit(0);
    }
    printf("The elements of the queue are:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d",queue[i]);
    }
}
