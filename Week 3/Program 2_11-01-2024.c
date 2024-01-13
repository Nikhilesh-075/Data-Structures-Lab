#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *head=NULL;
    int c=0,a,b;
    while(c!=3)
    {
        printf("\nEnter 1 to insert\n");
        printf("Enter 2 to display\n");
        printf("Enter 3 to exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the value to be inserted:\n");
                scanf("%d",&a);
                int c2;
                printf("\nEnter 1 to insert at the front\n");
                printf("Enter 2 to insert after a given node\n");
                printf("Enter 3 to insert at the end\n");
                printf("\nEnter your choice:\n");
                scanf("%d",&c2);
                switch(c2)
                {
                    case 1:
                        insertFront(&head,a);
                        break;
                    case 3:
                        insertEnd(&head,a);
                        break;
                    case 2:
                        printf("Enter the value after which to insert:\n");
                        scanf("%d",&b);
                        struct Node *temp=head;
                        while(temp!=NULL && temp->data!=b)
                            temp=temp->next;
                        if(temp==NULL)
                            printf("Element not found in the list\n");
                        else
                        {
                            insertMiddle(temp,a);
                        }
                        break;
                    default: printf("Invalid Choice\n");break;
                }
            case 2: display(head);break;
            default: printf("Invalid choice\n");break;

        }
    }
    return 0;
}
void insertFront(struct Node **head,int new_data)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=(*head);
    (*head)=new_node;
}
void insertMiddle(struct Node *previous,int new_data)
{
    if (previous==NULL)
    {
        printf("The previous node entered cannot be NULL\n");
        return;
    }
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=previous->next;
    previous->next=new_node;
}
void insertEnd(struct Node **head,int new_data)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node *last=*head;
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    last->next=new_node;
}
void display(struct Node *node)
{
    printf("The contents of the list are:\n");
    while(node!=NULL)
    {
        printf("%d",node->data);
        node=node->next;
    }
    printf("\n");
}
