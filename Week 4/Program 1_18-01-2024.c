#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    struct Node* head = NULL;
    insertEnd(&head,1);
    insertEnd(&head,2);
    insertEnd(&head,3);
    insertEnd(&head,4);
    insertEnd(&head,5);
    insertEnd(&head,6);
    printf("Initial List:\n");
    display_q(head);
    int c,c1=0;
    while(c1==0)
    {
        printf("\nEnter 1 to delete from the beginning\n");
        printf("Enter 2 to delete at the end\n");
        printf("Enter 3 to delete from a specific position\n");
        printf("Enter 4 to display\n");
        printf("Enter 0 to exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 0: printf("Exiting...\n");c1=1;break;
            case 1: delete_beg(&head);display_q(head);break;
            case 2: delete_end(&head);display_q(head);break;
            case 3: delete_mid(&head);display_q(head);break;
            case 4: display_q(head);break;
            default: printf("Invalid choice. Please enter a valid option\n");break;
        }
    }
    return 0;
}

void delete_beg(struct Node** head)
{
    if(*head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node* ptr=*head;
        *head=(*head)->next;
        free(ptr);
        printf("Node deleted from beginning\n");
    }
}

void delete_end(struct Node** head)
{
    struct Node* ptr;
    struct Node* ptr1=NULL;
    if(*head==NULL)
    {
        printf("List is empty\n");
    }
    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
        printf("Deleted the only node in the list\n");
    }
    else
    {
        ptr=*head;
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
        printf("Deleted the last node from the list\n");
    }
}

void delete_mid(struct Node** head)
{
    struct Node* ptr;
    struct Node* ptr1=NULL;
    int loc;
    printf("Enter the location of the node to be deleted:\n");
    scanf("%d",&loc);
    ptr=*head;
    for(int i=0;i<loc;i++)
    {
        ptr1=ptr;
        ptr=ptr->next;
        if(ptr==NULL)
        {
            printf("Less elements than required in the list\n");
            return;
        }
    }
    ptr1->next=ptr->next;
    free(ptr);
    printf("Node deleted from position %d\n",loc);
}

void display_q(struct Node* head)
{
    struct Node* current=head;
    if(current==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    else
    {
        printf("The contents of the list are:\n");
        while(current!=NULL)
        {
            printf("%d",current->data);
            current=current->next;
        }
        printf("\n");
    }
}

struct Node* createLinkedList(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data)
{
    struct Node* newNode=createLinkedList(data);

    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        struct Node* current=*head;
        while(current->next != NULL)
        {
            current=current->next;
        }
        current->next=newNode;
    }
}
