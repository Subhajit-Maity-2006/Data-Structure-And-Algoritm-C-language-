#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct dll
{
    int val;
    struct dll *prev;
    struct dll *next;
};
struct dll *start=NULL;

void createlist(struct dll *);
void displaylist(struct dll *);
void insertbegin(struct dll *);
void insertend(struct dll *);
void deletefirst(struct dll *);
void deleteend(struct dll *);

int main()
{
    struct dll *node;
    int choice;
    node=(struct dll *)malloc(sizeof(struct dll));

    if(node==NULL)
    {
        printf("Memory is not allocated:");
        exit(1);
    }

    createlist(node);
    start=node;
   do
    {
        printf("\n\n===== DOUBLY LINKED LIST MENU =====");
        printf("\n1. Display List");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at End");
        printf("\n4. Delete First");
        printf("\n5. Delete End");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                displaylist(start);
                break;

            case 2:
                insertbegin(start);
                break;

            case 3:
                insertend(start);
                break;

            case 4:
                deletefirst(start);
                break;

            case 5:
                deleteend(start);
                break;

            case 6:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    }while(choice!=6);

    return 0;
}


void createlist(struct dll *node)
{
    struct dll *new;
    char ch;
    int i=1;

    printf("Enter the %d element:",i);
    scanf("%d",&node->val);

    node->next=NULL;
    node->prev=NULL;

    i++;

    printf("Enter q to quit and another to continue:");
    scanf(" %c",&ch);

    while(ch!='q')
    {
        new=(struct dll *)malloc(sizeof(struct dll));

        if(new==NULL)
        {
            printf("Memory is not allocated");
            exit(1);
        }

        node->next=new;
        new->prev=node;
        new->next=NULL;

        printf("Enter the value of new node:");
        scanf("%d",&new->val);

        node=new;

        printf("Enter q to quit and other to continue:");
        scanf(" %c",&ch);
    }
}

void displaylist(struct dll *node)
{
   struct dll *temp;
   printf("\nForward traversing:");
   temp=node;
    while(temp!=NULL){
       
        printf("%d ",temp->val);
        if(temp->next==NULL){
            break;
        }
        temp=temp->next;
    }
    printf("\nBackward traversing:");
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->prev;
    }

}
//Insert a new node at the begining
void insertbegin(struct dll *node){
    struct dll *new;
    new=(struct dll *)malloc(sizeof(struct dll));
    if(new == NULL){
        printf("Memory is not allocated");
        exit(1);
    }
    //connecting new node to the begining
    printf("\nEnter the value of node:");
    scanf("%d",&new->val);
    new->next=NULL;
    new->prev=NULL;
    new->next=node;
    if(node!=NULL){
        node->prev=new;
    }
    start = new;
}
//insert a new node at the begining
void insertend(struct dll *node){
    struct dll *new;
    new=(struct dll *)malloc(sizeof(struct dll));
    if(new == NULL){
        printf("Memory is not allocated");
        exit(1);
    }
    //Traverse to the end of the list
    while(node->next!=NULL){
        node=node->next;
    }
        printf("Enter the value of new node:");
        scanf("%d",&new->val);
        new->next=NULL;
        new->prev=node;
       node->next=new;
    
}

void deletefirst(struct dll *node){
    struct dll *temp;
    //Zero node
    if(node==NULL){
        printf("\nList is empty");
        return;
    }
    //only one node
    if(node->next==NULL){
        temp=node;
        free(temp);
        start=NULL;
        return;
    }
    temp=node;
    node=node->next;
    node->prev=NULL;
    free(temp);
    start = node;
}

void deleteend(struct dll *node){
    struct dll *temp;
    //no node
    if(node==NULL){
        printf("\nList is empty:");
        return;
    }
    //Only one node
    if(node->next == NULL){
        temp=node;
        free(temp);
        start=NULL;
        return;
    }
    while(node->next!=NULL){
        node=node->next;
    }
    //delete last node
    temp=node;
    node=node->prev;
    node->next=NULL;
    free(temp);
}
