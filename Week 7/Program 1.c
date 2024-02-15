#include<stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root,int value)
{
    if(root==NULL)
        return createNode(value);
    if(value<root->data)
        root->left=insert(root->left,value);
    else if(value>root->data)
        root->right=insert(root->right,value);
    return root;
}

void inOrderTraversal(struct Node* root)
{
    if(root!=NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root)
{
    if(root!=NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}

void display(struct Node* root)
{
    printf("Elements in the tree: ");
    inOrderTraversal(root);
    printf("\n");
}

int main()
{
    struct Node* root=NULL;
    int c,value;
    do {
        printf("\nEnter 1 to insert an element\n");
        printf("Enter 2 to Display elements\n");
        printf("Enter 3 to perform In-order traversal\n");
        printf("Enter 4 to perform Pre-order traversal\n");
        printf("Enter 5 to perform Post-order traversal\n");
        printf("Enter 0 to Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&value);
                root=insert(root,value);
                break;
            case 2:
                display(root);
                break;
            case 3:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Pre-order traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(c!=0);
    return 0;
}

