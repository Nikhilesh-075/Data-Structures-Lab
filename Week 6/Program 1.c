#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void insertLeft(struct Node** head,int value,int targetValue)
{
    struct Node* newNode=createNode(value);
    struct Node* current=*head;
    while(current!=NULL && current->data!=targetValue)
    {
        current=current->next;
    }
    if(current==NULL)
    {
        printf("Node with value %d not found.\n",targetValue);
        free(newNode);
        return;
    }
    if(current->prev!=NULL)
    {
        current->prev->next=newNode;
        newNode->prev=current->prev;
    }
    else
    {
        *head=newNode;
    }
    newNode->next=current;
    current->prev=newNode;
}

void deleteNode(struct Node** head,int value)
{
    struct Node* current=*head;
    while(current!=NULL && current->data!=value)
    {
        current=current->next;
    }
    if(current==NULL)
    {
        printf("Node with value %d not found.\n",value);
        return;
    }
    if (current->prev!=NULL)
    {
        current->prev->next=current->next;
    }
    else
    {
        *head=current->next;
    }
    if(current->next!=NULL)
    {
        current->next->prev=current->prev;
    }
    free(current);
}

void displayList(struct Node* head)
{
    struct Node* current=head;

    while(current!=NULL)
    {
        printf("%d",current->data);
        current = current->next;
    }
}

int main()
{
    struct Node* head=NULL;
    int choice,value,targetValue;
    do
    {
        printf("\nEnter 1 to create a doubly linked list\n");
        printf("Enter 2 to insert a node to the left of a node\n");
        printf("Enter 3 to delete a node based on a specific value\n");
        printf("Enter 4 to display the contents of the list\n");
        printf("Enter 5 to exit\n");
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if (head!=NULL)
                {
                    printf("Doubly linked list already created.\n");
                }
                else
                {
                    printf("Enter the value for the node: ");
                    scanf("%d",&value);
                    head=createNode(value);
                    printf("Doubly linked list created successfully.\n");
                }
                break;
            case 2:
                if(head==NULL)
                {
                    printf("List is empty. Please create a list first.\n");
                }
                else
                {
                    printf("Enter the value to insert:\n");
                    scanf("%d",&value);
                    printf("Enter the value of the node to the left of which to insert:\n");
                    scanf("%d",&targetValue);
                    insertLeft(&head,value,targetValue);
                }
                break;
            case 3:
                if(head==NULL)
                {
                    printf("List is empty. Please create a list first.\n");
                }
                else
                {
                    printf("Enter the value to delete:\n");
                    scanf("%d",&value);
                    deleteNode(&head,value);
                }
                break;
            case 4:
                if(head==NULL)
                {
                    printf("List is empty. Please create a list first.\n");
                }
                else
                {
                    printf("The contents of the list are:\n");
                    displayList(head);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");break;
        }
    } while(choice!=5);
    return 0;
}
