#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void push_list(struct Node **head,int new_data)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=NULL;
    struct Node *last=*head;
    if(*head==NULL)
        *head=new_node;
    else
    {
        while(last->next!=NULL)
            last=last->next;
        last->next=new_node;
    }
}

void pop_listStack(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *last=head;
    struct Node *pre;
    while(last->next!=NULL)
    {
        pre=last;
        last=last->next;
    }
    free(last);
    pre->next=NULL;
}

void enqueue_list(struct Node **head,int new_data)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=NULL;
    struct Node *last=*head;
    if(*head==NULL)
        *head=new_node;
    else
    {
        while(last->next!=NULL)
            last=last->next;
        last->next=new_node;
    }
}

void dequeue_list(struct Node **head)
{
    if(*head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp=(*head)->next;
    free(*head);
    *head=temp;
}

void display_listStack(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Stack:\n");
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
}

void display_listQueue(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Queue:\n");
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head=NULL;
    struct Node *head1=NULL;
    int c,c1=0,elem1,elem2;
    while(c1==0)
    {
        printf("\nEnter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display stack list\n");
        printf("Enter 4 to enqueue\n");
        printf("Enter 5 to dequeue\n");
        printf("Enter 6 to display queue list\n");
        printf("Enter 0 to exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 0: printf("Exiting...\n");c1=1;break;
            case 1:
                printf("Enter the value to push:\n");
                scanf("%d",&elem1);
                push_list(&head,elem1);
                display_listStack(head);
                break;
            case 2:
                pop_listStack(head);
                display_listStack(head);
                break;
            case 3: display_listStack(head);break;
            case 4:
                printf("Enter the value to enqueue:\n");
                scanf("%d",&elem2);
                enqueue_list(&head1,elem2);
                display_listQueue(head1);
                break;
            case 5:
                dequeue_list(&head1);
                display_listQueue(head1);
                break;
            case 6: display_listQueue(head1);break;
            default: printf("Invalid choice.\n");break;
        }
    }
    return 0;
}
