#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void sort_list(struct Node *head)
{
    struct Node *p,*q;
    int temp;
    for(p=head;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(p->data>q->data)
            {
                temp=q->data;
                q->data=p->data;
                p->data=temp;
            }
        }
    }
}

void reverse_list(struct Node **head)
{
    struct Node *cur=*head;
    struct Node *pre=NULL;
    struct Node *next=NULL;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    *head=pre;
}

void concat_list(struct Node *head1,struct Node *head2)
{
    struct Node *head3;
    struct Node *temp;
    if(head1==NULL)
    {
        head3=head2;
        display_list(head3);
    }
    else if(head2==NULL)
    {
        head3=head1;
        display_list(head3);
    }
    else
    {
        temp=head1;
        head3=head1;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=head2;
        display_list(head3);
    }
}

void display_list(struct Node* head)
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

int main()
{
    struct Node* head = NULL;
    insertEnd(&head,3);
    insertEnd(&head,1);
    insertEnd(&head,4);
    insertEnd(&head,2);
    insertEnd(&head,6);
    insertEnd(&head,5);
    struct Node* head1 = NULL;
    insertEnd(&head1,1);
    insertEnd(&head1,3);
    insertEnd(&head1,4);
    insertEnd(&head1,2);
    struct Node* head2 = NULL;
    insertEnd(&head2,3);
    insertEnd(&head2,1);
    insertEnd(&head2,4);
    insertEnd(&head2,2);
    struct Node* head3 = NULL;
    printf("Initial List:\n");
    display_list(head);
    int c,c1=0;
    while(c1==0)
    {
        printf("\nEnter 1 to sort the linked list\n");
        printf("Enter 2 to reverse the linked list\n");
        printf("Enter 3 to concatenate 2 linked lists\n");
        printf("Enter 4 to display\n");
        printf("Enter 0 to exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 0: printf("Exiting...\n");c1=1;break;
            case 1: sort_list(head);display_list(head);break;
            case 2: reverse_list(&head);display_list(head);break;
            case 3:
                printf("The 2 lists being concatenated are:\n");
                display_list(head1);
                printf("and\n");
                display_list(head2);
                printf("Concatenated list:\n");
                concat_list(head1,head2);break;
            case 4: display_list(head);break;
            default: printf("Invalid choice. Please enter a valid option\n");break;
        }
    }
    return 0;
}
